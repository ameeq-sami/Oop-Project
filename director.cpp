#include "director.h"

void Director::setYearOfExperience(int ye)
{
    yearOfExperience = ye;
}

int Director::getYearOfExperience()
{
    return yearOfExperience;
}

void Director::setNationality(std::string na)
{
    nationality = na;
}

std::string Director::getNationality()
{
    return nationality;
}

void Director::getDirectorName(std::string &fn, std::string &ln)
{
    name.getName(fn, ln);
}

Director::Director() : name()
{
    setYearOfExperience(-1);
    setNationality("NULL");
}

Director::Director(std::string fn, std::string ln, int ye, std::string na):name(fn, ln)
{
    setYearOfExperience(ye);
    setNationality(na);
}

Director::Director(Director &other):name(other.name)
{
    setYearOfExperience(other.getYearOfExperience());
    setNationality(other.getNationality());
}

Director::~Director()
{
}

void Director::setDirector(std::string fn, std::string ln, int ye, std::string na)
{
    name.setName(fn,ln);
    setYearOfExperience(ye);
    setNationality(na);
}

Director Director::getDirector()
{
    return *this;
}

std::ostream &operator<<(std::ostream &out, Director &d)
{
    out<<d.name << "Years Of Experience: "<<d.getYearOfExperience()<< "     Nationality: "<<d.getNationality()<<std::endl;
    return out;
}

void Director::display()
{
    std::cout<<*this;
}