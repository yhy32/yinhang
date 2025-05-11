#include <iostream>
#include <cstdlib>
#include "date.h"
#include <stdexcept>
#include <sstream>
using namespace std;

namespace {  //namespaceʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч

	const int DAYS_BEFORE_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	//31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	//3���ж�����=month[3]-month[2]=90-59=3�죻
}                                     //getMaxDay()�Դ�Ϊ�������㵱ǰ���������


Date::Date(int year, int month, int day) :year(year), month(month), day(day)
{

	if (day <= 0 || day > getMaxDay())
	{
        std::ostringstream oss;
        oss << "Invalid date: " << year << "-" << month << "-" << day;
        throw std::runtime_error(oss.str());
    
	}
	int years = year - 1;   //��׼����Ϊ��ԪԪ��1��1�գ���1��1��1��
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
	//DAYS_BEFORE_MONTH[month - 1]��õ�ǰmonth��1���뱾��1��1������������������в�ѯ��֪
	if (isLeapYear() && month > 2)
	{
		totalDays++;   //���꣬���Ҵ���2��ʱ��������+1
	}
}
//�õ���ǰ�µ�������getMaxDay����
int Date::getMaxDay() const
{
	//�ж�month�Ƕ��٣�Ȼ����DAYS_BEFORE_MONTH�������ҵ���Ӧ����
	if (isLeapYear() && month == 2)
	{
		return 29;
	}
	else
	{
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
	}
}

//��������ǰ���������show����
void Date::show() const
{
	cout << getYear() << "-" << getMonth() << "-" << getDay();

	//cout<<year <<"-"<<month<<"-"<<day <<endl;
}
//�����жϵ�ǰ������ָ���������������distance����


Date::~Date()
{
}
Date Date::read()
{
	int a, b, c;
	cin >> a;
	cout << "/";
    cin >> b;
	cout << "/";
	cin >> c;
	cout << "/";
	Date arr(a, b, c);
	return arr;
};
