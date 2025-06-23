#pragma once
#include<iostream>

class Date{
    private: 
    int day ;
    std::string month;
    int year;

    protected:
    void setDay(int d);
    int getDay();
    void setMonth(std::string m);
    std::string getMonth();
    void setYear(int y);
    int  getYear();

    public:
    Date();
    Date(int d, std::string m, int y);
    Date(Date &other);
    ~Date();

    void setDate(int d, std::string m, int y);
    Date getDate();

    friend std::ostream& operator << (std::ostream& out , Date &other);
    void display();

};