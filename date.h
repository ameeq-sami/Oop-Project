#pragma once
#include<iostream>

class Date{
    private: 
    int day ;
    std::string month;
    int year;

    protected:
    void setDay(int d);
    void setMonth(std::string m);
    void setYear(int y);
    
    public:
    int getDay();
    std::string getMonth();
    int  getYear();
    Date();
    Date(int d, std::string m, int y);
    Date(Date &other);
    ~Date();

    void setDate(int d, std::string m, int y);
    Date getDate();

    friend std::ostream& operator << (std::ostream& out , Date &other);
    void display();

};