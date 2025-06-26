#include<iostream>
#include<fstream>
#include"scifiMovie.h"
#include"director.h"
#include"fileHandlingFunc.h"

using namespace std;

main()
{
    fstream directorFile;
    fstream sicifiMovie_File;
    fstream animationMovie_File;
    string d_File = "director.txt";
    string s_File = "sicifiMovie.txt";
    string a_File = "animationMovie.txt";
    int director_size = 5 ;
    int sicifiMovie_size = 5;
    int animationSize_size = 5;
    Director* directors = new Director[director_size];

    directors[0] =  Director ("James", "Cameron", 25, "USA");
    directors[1] = Director ("Christopher", "Nolan", 22, "UK");
    directors[2] = Director ("Greta", "Gerwig", 10, "USA");
    directors[3] = Director ("Hayao", "Miyazaki", 40, "Japan");
    directors[4] = Director ("Zoya", "Akhtar", 15, "India");
    
    SicifiMovie* movies = new SicifiMovie[sicifiMovie_size];
    movies[0] = SicifiMovie("James", "Cameron", 25, "USA", 162, "Dec", 18, "Avatar", 9, 13, 2, 0);
    movies[1] = SicifiMovie("Christopher", "Nolan", 22, "UK", 169, "Nov", 7, "Interstellar", 8, 13, 1, 0);
    movies[2] = SicifiMovie("Greta", "Gerwig", 10, "USA", 130, "Jul", 21, "Barbie Galaxy", 7, 7, 3, 1);
    movies[3] = SicifiMovie("Hayao", "Miyazaki", 40, "Japan", 120, "Aug", 15, "Spirited Cosmos", 9, 5, 2, 1);
    movies[4] = SicifiMovie("Zoya", "Akhtar", 15, "India", 140, "Oct", 10, "Future Tides", 8, 18, 1, 0);

    AnimationMovie* animMovies = new AnimationMovie[5];

    animMovies[0] = AnimationMovie("James", "Cameron", 25, "USA", 15, "June", 2020, "Toy Universe", 9, 2, 5, false);
    animMovies[1] = AnimationMovie("Christopher", "Nolan", 22, "UK", 10, "July", 2019, "Castle in the Stars", 8, 3, 18, true);
    animMovies[2] = AnimationMovie("Greta", "Gerwig", 10, "USA", 25, "December", 2021, "Frozen Planet", 7, 1, 7, false);
    animMovies[3] = AnimationMovie("Hayao", "Miyazaki", 40, "Japan", 5, "March", 2018, "Inside Reality", 8, 2, 18, true);
    animMovies[4] = AnimationMovie("Zoya", "Akhtar", 15, "India", 20, "October", 2022, "Animated Dreams", 6, 3, 7, true);


    // directorFileDisplay(d_File); 
    // sicifiMovie_FileAppend(s_File, 1, directors, director_size );
    // sicifiMovie_ArrayToFile(s_File, movies, sicifiMovie_size);
    // sicifiMovie_FileToArray(s_File, movies, fileSize(s_File)/12);
// for (int i = 0; i < sicifiMovie_size; i++)
// {
//     cout<<movies[i]<<endl;
// }

    // sicifiMovie_FileDisplay(s_File);
    // directorFileAppend(d_File, 2);
    // directorArrayToFile(d_File, directors, director_size);
    // directorFileToArray(d_File, directors, fileSize(d_File)/4);
    // animationMovie_FileAppend(a_File, animationSize_size, directors, director_size);
    animationMovie_ArrayToFile(a_File, animMovies, animationSize_size);
    animationMovie_FileToArray(a_File, animMovies, 1);
    // removeObj_AnimationMovieType(animMovies, animationSize_size, "Toy Universe");
    animationMovie_ArrayToFile(a_File, animMovies, animationSize_size);
    animationMovie_FileDisplay(a_File);

    // cout<<animMovies[0];
    // cout<<animMovies[1];
    // cout<<animMovies[2];
    // cout<<animMovies[3];
    // cout<<animMovies[4];


}