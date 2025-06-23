#include "name.h"

void Name::setFirstName(std::string fn)
{
    firstName = fn;
}

std::string Name::getFirstName()
{
    return firstName;
}

void Name::setLastName(std::string ln)
{
    lastName = ln;
}

std::string Name::getLastName()
{
    return lastName;
}

void Name::setName(std::string fn, std::string ln)
{
    setFirstName(fn);
    setLastName(ln);
}

Name Name::getName()
{
    Name n(getFirstName(), getLastName());
    return n;
}

Name::Name()
{
    setFirstName("EMPTY");
    setLastName("EMPTY");
}

Name::Name(Name &other)
{
    setFirstName(other.getFirstName());
    setLastName(other.getLastName());
}

Name::Name(std::string fn, std::string ln)
{
    setFirstName(fn);
    setLastName(ln);
}

Name::~Name()
{
}

void Name::display()
{
    std::cout<<*this;
}

std::ostream &operator<<(std::ostream &out, Name &other)
{
    out<<"FIRST NAME: "<<other.getFirstName()<<"     LAST NAME: "<<other.getLastName()<<std::endl;
    return out;
}
