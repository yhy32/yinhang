#ifndef _DATE_H_
#define _DATE_H_
class Date 
{
    private:
        int year;
        int month;
        int day;
        int totaldays;
    public:
        Date(int year, int month, int day);
        ~Date();
        int getYear() const { return year; }
        int getMonth() const { return month; }
        int getDay() const { return day; }
        int getMaxDay() const;
        bool isLeapYear() const
        {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
        void show() const;  
        int distance(const Date& date) const 
        {
            return totaldays - date.totaldays;
        }

};
#endif
