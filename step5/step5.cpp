#include "account.h"
#include "date.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include"AccountException.h"
#include <sstream>

using namespace std;

struct deleter {
    template <class T>
    void operator()(T* p) { delete p; }
};

void executeCommand(const string& input, Date& date, vector<Account*>& accounts) {
    istringstream iss(input);
    char cmd;
    iss >> cmd;

    char type;
    int index, day;
    double amount, credit, rate, fee;
    string id, desc;
    Account* account;
    Date date1, date2;

    switch (cmd) {
        case 'a':
            iss >> type >> id;
            if (type == 's') {
                iss >> rate;
                account = new SavingsAccount(date, id, rate);
            } else {
                iss >> credit >> rate >> fee;
                account = new CreditAccount(date, id, credit, rate, fee);
            }
            accounts.push_back(account);
            break;
            case 'd':
                iss >> index >> amount;
                getline(iss, desc);
                try {
                    accounts[index]->deposit(date, amount, desc);
                } catch (const AccountException& e) {
                    cerr << "错误: " << e.what() << endl;
                    if (e.getAccount()) {
                        cerr << "发生错误的账户：";
                        e.getAccount()->show();
                        cerr << endl;
                    }
                }
                break;

            case 'w':
                iss >> index >> amount;
                getline(iss, desc);
                try {
                    accounts[index]->withdraw(date, amount, desc);
                } catch (const AccountException& e) {
                    cerr << "错误: " << e.what() << endl;
                    if (e.getAccount()) {
                        cerr << "发生错误的账户：";
                        e.getAccount()->show();
                        cerr << endl;
                    }
                }
                break;
        case 'c':
            iss >> day;
            if (day < date.getDay())
                cout << "You cannot specify a previous day";
            else if (day > date.getMaxDay())
                cout << "Invalid day";
            else
                date = Date(date.getYear(), date.getMonth(), day);
            break;
        case 'n':
            if (date.getMonth() == 12)
                date = Date(date.getYear() + 1, 1, 1);
            else
                date = Date(date.getYear(), date.getMonth() + 1, 1);
            for (auto acc : accounts)
                acc->settle(date);
            break;
        case 'q':
            date1 = Date::read();
            date2 = Date::read();
            Account::query(date1, date2);
            break;
        case 's':
            for (size_t i = 0; i < accounts.size(); i++) {
                cout << "[" << i << "] ";
                accounts[i]->show();
                cout << endl;
            }
            break;
    }
}

int main() {
    Date date(2008, 11, 1);
    vector<Account*> accounts;

    cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day "
            "(n)next month (q)query (e)exit"
         << endl;

    // 读取历史命令并执行
    ifstream infile("commands.txt");
    string line;
    while (getline(infile, line)) {
        if (!line.empty()) {
            executeCommand(line, date, accounts);
        }
    }
    infile.close();

    // 正常用户交互
    string input;
    while (true) {
        date.show();
        cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";
        getline(cin, input);
        if (input.empty()) continue;
        if (input == "e") break;

        // 保存命令
        ofstream outfile("commands.txt", ios::app);
        outfile << input << endl;
        outfile.close();

        // 执行命令
        executeCommand(input, date, accounts);
    }

    for_each(accounts.begin(), accounts.end(), deleter());
    return 0;
}