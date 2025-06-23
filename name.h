#pragma once
#include<iostream>
class Name{
    private:
    std::string firstName;
    std::string lastName;
    
    protected:
    void setFirstName(std::string fn);
    std::string getFirstName();
    void setLastName(std::string ln);
    std::string getLastName();

    public:
    void setName(std::string fn, std::string ln);
    Name getName();
    Name();
    Name(Name &other);
    Name(std::string fn, std::string ln);
    ~Name();
    friend std:: ostream& operator<< (std::ostream& out,Name &other);
    void display();

};