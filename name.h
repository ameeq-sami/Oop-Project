#pragma once
#include<iostream>
class Name{
    private:
    std::string firstName;
    std::string lastName;
    
    protected:
    void setFirstName(std::string fn);
    void setLastName(std::string ln);
    
    public:
    
    void getName(std::string &fn, std::string &ln);
    std::string getFirstName();
    std::string getLastName();
    
    void setName(std::string fn, std::string ln);
    Name getName();
    Name();
    Name(Name &other);
    Name(std::string fn, std::string ln);
    ~Name();
    friend std:: ostream& operator<< (std::ostream& out,Name &other);
    void display();

};