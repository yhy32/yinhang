#include "date.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<stdexcept>



using namespace std;

namespace {	//namespace使下面的定义只在当前文件中有效
//存储平年中某个月1日之前有多少天，为便于getMaxDay函数的实现，该数组多出一项
const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}


Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    try {
        if (day <= 0 || day > getMaxDay()) {
            cout << "Invalid date: ";
            show();
            cout << endl;

            throw runtime_error("wrong day");
        }
        if (month < 0 || month>12)
        {
            cout << "Invalid date: ";
            show();
            cout << endl;

            throw runtime_error("wrong month");
        }
    }
    catch (runtime_error) {
        cerr << "请重新输入正确日期" << endl;


    }

    int years = year - 1;
    totalDays = years * 365 + years / 4 - years / 100 + years / 400
                + DAYS_BEFORE_MONTH[month - 1] + day;
    if (isLeapYear() && month > 2) totalDays++;
}

//Date Date::read() {
//    int year, month, day;
//    char c1, c2;
//    cin >> year >> c1 >> month >> c2 >> day;
//    return Date(year, month, day);
//}

int Date::getMaxDay() const {
    if (isLeapYear() && month == 2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}



