#include<iostream>
#include<fstream>
#include"scifiMovie.h"
#include"animationMovie.h"
#include"director.h"
#include"actionMovie.h"
#include"sta.h"
using namespace std;

main()
{
    fstream directorFile;
    string d_File = "director.txt";
    int director_size;
    Director* directors = new Director[director_size];
    // directorFileAppend(d_File, 2);
    directorFileDisplay(d_File); 
    directorFileToArray(d_File,directors, fileSize(d_File)/4);
    directors[1].display();
    // SicifiMovie m1(director, 23, "jan", 25, "hi u", 5, 3, 1, 1);
    // AnimationMovie am(director, 23, "jan", 25, "hi u", 5, 2, 5, 1);
    // ActionMovie ac(director, 23, "jan", 25, "hi u", 5, 1, 7, 0);
    // cout<<m1;
    // cout<<am;
    // cout<<ac;


   
    // int mainChoice;
    // char subChoice;
    // cout<<"Press 1 to new Movies";
    // cin>>mainChoice;
    // if (mainChoice == 1)
    // {
    //     cout<<"Press S to add Sicifi Movie\nPress A to add Animation Movie\nPress X to add Action Movie";
    //     cin>>subChoice;
    //     if (subChoice == "S")
    //     {
    //         cout<<
    //     }
        
        
    // }
    

}