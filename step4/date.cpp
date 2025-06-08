#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

namespace {  //namespace使下面的定义只在当前文件中生效

	const int DAYS_BEFORE_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	//31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	//3月有多少天=month[3]-month[2]=90-59=3天；
}                                     //getMaxDay()以此为基础计算当前月最大天数


Date::Date(int year, int month, int day) :year(year), month(month), day(day)
{
	if (day <= 0 || day > getMaxDay())
	{
		cout << "Invalid date: "; show(); cout << endl; exit(1);
	}
	int years = year - 1;   //基准日期为公元元年1月1日，即1年1月1日
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
	//DAYS_BEFORE_MONTH[month - 1]获得当前month月1日与本年1月1日相差天数，在数组中查询得知
	if (isLeapYear() && month > 2)
	{
		totalDays++;   //闰年，并且大于2月时，总天数+1
	}
}
//得到当前月的天数的getMaxDay函数
int Date::getMaxDay() const
{
	//判断month是多少，然后在DAYS_BEFORE_MONTH数组中找到对应日期
	if (isLeapYear() && month == 2)
	{
		return 29;
	}
	else
	{
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
	}
}

//用来将当前日期输出的show函数
void Date::show() const
{
	cout << getYear() << "-" << getMonth() << "-" << getDay();

	//cout<<year <<"-"<<month<<"-"<<day <<endl;
}
//用来判断当前日期与指定日期相差天数的distance函数


Date::~Date()
{
}

