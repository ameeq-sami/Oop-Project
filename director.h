#pragma once
#include"name.h"


class Director{
    private:
    Name name;
    int yearOfExperience;
    std::string nationality;
    
    protected: 
    void setYearOfExperience(int ye);
    int getYearOfExperience();
    void setNationality(std::string na);
    std::string getNationality();

    public:
    void getDirectorName(std::string &fn, std::string &ln);  
    Director();
    Director(std::string fn, std::string ln, int ye, std::string na );
    Director(Director &other);
    ~Director();

    void setDirector(std::string fn, std::string ln, int ye, std::string na);
    virtual Director getDirector();
    
    friend void directorArrayToFile(std::string fileName, Director *directors, int arr_size);
    friend void directorArrayToFile(std::string fileName, Director director, std::string mode);
    friend std::ostream& operator<< (std::ostream& out , Director& d);
    void display();
    
};