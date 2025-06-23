#include "date.h"

void Date::setDay(int d)
{
    day = d;
}

void Date::setMonth(std::string m)
{
    month = m;
}

void Date::setYear(int y)
{
    year =y;
}
//hi
int Date::getDay()
{
    return day;
}

std::string Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

Date::Date()
{
    setDay(0);
    setMonth("0");
    setYear(0);
}

Date::Date(int d, std::string m, int y)
{
    setDay(d);
    setMonth(m);
    setYear(y);
}

Date::Date(Date &other)
{
    setDay(other.getDay());
    setMonth(other.getMonth());
    setYear(other.getYear());
}

Date::~Date()
{
}

void Date::setDate(int d, std::string m, int y)
{
    setDay(d);
    setMonth(m);
    setYear(y);
}

Date Date::getDate()
{
    Date copy(getDay(), getMonth(), getYear());
    return copy;
}

std::ostream &operator<<(std::ostream &out, Date &other)
{
    out<<other.getDay()<<" : "<<other.getMonth()<<" : "<<other.getYear()<<std::endl;
    return out;
}

void Date::display()
{
    std::cout<<*this;
}