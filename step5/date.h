#ifndef _DATE_H_
#define _DATE_H_
class Date  //������
{
public:
	Date() {};
	Date(int year, int month, int day);
	~Date();
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;//�õ���ǰ�µ�������getMaxDay����
	bool isLeapYear() const  //�жϵ�ǰ���Ƿ�����isLeapYear����
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	static Date read();
	void show() const;  //��������ǰ���������show����
	int distance(const Date& date) const  //�����жϵ�ǰ������ָ���������������distance����
	{
		return totalDays - date.totalDays;
		//��ǰ����-֮ǰ�������ڣ�Ϊ�Ѵ�����Date��Ķ���
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
	int totalDays;    //�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ��� 
};
#endif //_DATE_H_