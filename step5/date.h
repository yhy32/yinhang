#ifndef _DATE_H_
#define _DATE_H_
class Date  //日期类
{
public:
	Date() {};
	Date(int year, int month, int day);
	~Date();
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;//得到当前月的天数的getMaxDay函数
	bool isLeapYear() const  //判断当前年是否闰年isLeapYear函数
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	static Date read();
	void show() const;  //用来将当前日期输出的show函数
	int distance(const Date& date) const  //用来判断当前日期与指定日期相差天数的distance函数
	{
		return totalDays - date.totalDays;
		//当前日期-之前以有日期（为已创建的Date类的对象）
	}
	int operator - (const Date & date)const
	{
		return(totalDays - date.totalDays);
	}
	bool operator<(const Date& date)const
	{
		if (totalDays < date.totalDays)
			return true;
		else
			return false;
	}
	bool operator>(const Date& date)const
	{
		if (totalDays > date.totalDays)
			return true;
		else
			return false;
	}
private:
	int year;
	int month;
	int day;
	int totalDays;    //该日期是从公元元年1月1日开始的第几天 
};
#endif //_DATE_H_