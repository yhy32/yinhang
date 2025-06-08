#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

namespace {  

	const int DAYS_BEFORE_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	
}                                   


Date::Date(int year, int month, int day) :year(year), month(month), day(day)
{
	if (day <= 0 || day > getMaxDay())
	{
		cout << "Invalid date: ";
	}
	int years = year - 1;  
	totaldays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
	if (isLeapYear() && month > 2)
	{
		totaldays++;  
	}
}
int Date::getMaxDay() const
{
	if (isLeapYear() && month == 2)
	{
		return 29;
	}
	else if (month == 2)
	{
		return 28;
	}
    return 31 - month % 7 % 2;
}
void Date::show() const
{
	cout << getYear() << "-" << getMonth() << "-" << getDay();

}



Date::~Date()
{
}

