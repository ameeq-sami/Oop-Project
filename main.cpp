#include<iostream>
#include<fstream>
#include"scifiMovie.h"
#include"animationMovie.h"
#include"director.h"
#include"actionMovie.h"
#include"directorHelpingFuncs.h"
#include"standAloneFuncs.h"

using namespace std;

main()
{
    fstream directorFile;
    string d_File = "director.txt";
    int director_size = 5 ;
    Director* directors = new Director[director_size];
    directors[0] =  Director ("James", "Cameron", 25, "USA");
    directors[1] = Director ("Christopher", "Nolan", 22, "UK");
    directors[2] = Director ("Greta", "Gerwig", 10, "USA");
    directors[3] = Director ("Hayao", "Miyazaki", 40, "Japan");
    directors[4] = Director ("Zoya", "Akhtar", 15, "India");

    // directorFileAppend(d_File, 2);
    directorArrayToFile(d_File, directors, director_size);
    directorFileDisplay(d_File); 
    // directorFileToArray(d_File, directors, fileSize(d_File)/4);
    
  


   
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