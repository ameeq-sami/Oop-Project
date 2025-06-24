#include "directorHelpingFuncs.h"
#include<fstream>
#include <string>


void directorFileAppend(std::string fileName, int directors_count)
{
    std::fstream directorFile;
    directorFile.open("director.txt", std::ios::app);
    if (!directorFile.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    for (int i = 0; i < directors_count; i++)
    {
        std::string str;    
        std::cout<<"Director First Name: ";
        std::cin>>str;
        directorFile<<str<<std::endl;

        std::cout<<"Director Second Name: ";
        std::cin>>str;
        directorFile<<str<<std::endl;
    
        std::cout<<"Director Nationality: ";
        std::cin>>str;
        directorFile<<str<<std::endl;

        std::cout<<"Director Year of Exprience: ";
        std::cin>>str;
        directorFile<<str<<std::endl;
    }

    directorFile.close();

}

void directorFileToArray(std::string fileName, Director *directors, int arr_size)
{
    std::fstream directorFile;
    std::string fname, lname, natioanlity;
    int yearOfExprience;
    directorFile.open(fileName, std::ios::in);
    if (!directorFile.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    for(int i = 0; i < arr_size ; i++){
        directorFile>>fname;        
        directorFile>>lname;
        directorFile>>natioanlity;
        directorFile>>yearOfExprience;
        directors[i] = Director(fname, lname, yearOfExprience, natioanlity);
}
    directorFile.close();
}

void directorArrayToFile(std::string fileName, Director *directors, int arr_size)
{
    std::fstream file;
    file.open(fileName, std::ios::out);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    file.clear();
    for (int  i = 0; i < arr_size; i++)
    {
        file<<directors[i].name.getFirstName()<<std::endl;
        file<<directors[i].name.getLastName()<<std::endl;
        file<<directors[i].getNationality()<<std::endl;
        file<<directors[i].getYearOfExperience()<<std::endl;
        
    }
    file.close();

}

void directorFileDisplay(std::string fileName)
{
    std::cout<<"Display..."<<std::endl;
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    std::string str;
    int i = 0;
    while(getline(file,str)){
        
            if (i == 0)
            {
                std::cout<<"------Director------\n ";    
                std::cout<<"First Name: ";    
            }
            else if (i == 1)
            {
                std::cout<<"Second Name: ";
            }
            else if (i == 2)
            {
                std::cout<<"Year of Exprience: ";
            }
            else
            std::cout<<"Nationality: ";
            std::cout<<str<<std::endl;
            i++;
            if (i == 4) i = 0;            
        }   
        file.close();
}
