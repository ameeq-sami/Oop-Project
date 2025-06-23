#include "sta.h"
#include "director.h"

int fileSize(std::string fileName){
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Error: Could not open file." << std::endl;
        return -1 ;
    }
    std::string line;
    int lineCount = 0;
    while (getline(file, line))
    {
        lineCount++;
    }
    return lineCount;
}

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
    file.open(fileName, std::ios::in);
    for (int  i = 0; i < arr_size; i++)
    {
        file<<directors[i].get();
        
    }
    
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
                std::cout<<"Director First Name: ";    
            }
            else if (i == 1)
            {
                std::cout<<"Director Second Name: ";
            }
            else if (i == 2)
            {
                std::cout<<"Director Year of Exprience: ";
            }
            else
            std::cout<<"Director Nationality: ";
            std::cout<<str<<std::endl;
            i++;
            if (i == 4) i = 0;            
        }   
        file.close();
}
