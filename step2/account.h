#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include"date.h"
#include<string>
class  SavingsAccount
{
    std::string  id; 
    double  balance;  
    double  rate;  
    Date  lastDate; 
    double  accumulation = 0; 
    double static total;
    double  accumulate(const Date& date); 
	 
public:
    SavingsAccount(const Date& date, const std::string& id, double rate); 
    void  deposit(const Date& date, double amount, const std::string& c); 
    void  withdraw(const Date& date, double amount, const std::string& c);  
    void  settle(const Date& date); 
    void  show();   
    std::string getId() { return id; }
    double  getBalance() { return balance; }
    double  getRate() { return rate; }
    double static getTotal();
    void record(const Date& date, double amount, const std::string& desc);
};
#endif // ACCOUNT_H_INCLUDED
