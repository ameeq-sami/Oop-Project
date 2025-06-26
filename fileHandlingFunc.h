#include<iostream>
#include"director.h"
#include"scifiMovie.h"
#include"animationMovie.h"



int fileSize(std::string fileName);
void directorFileAppend(std::string fileName, int directors_count);
void directorFileToArray(std::string fileName, Director* arr_ptr, int arr_size);
void directorArrayToFile(std::string fileName, Director* arr_ptr, int arr_size); // frnd function of director and also declared in director.h 
void directorArrayToFile(std::string fileName, Director director, std::string mode); // this also
void directorFileDisplay(std::string fileName);

void sicifiMovie_FileAppend(std::string fileName, int sicifiMovie_count, Director* directors, int director_arraySize);
void sicifiMovie_FileToArray(std::string fileName, SicifiMovie* s_movies, int arr_size); // copy file content into array
void sicifiMovie_ArrayToFile(std::string fileName, SicifiMovie *s_movies, int arr_size);
void sicifiMovie_FileDisplay(std::string fileName);
void removeObj_SicifiMovieType(SicifiMovie*& arr, int &size, std::string toRemove);

void animationMovie_FileAppend(std::string fileName, int sicifiMovie_count, Director* directors, int director_arraySize);
void animationMovie_FileToArray(std::string fileName, AnimationMovie* s_movies, int arr_size); // copy file content into array
void animationMovie_ArrayToFile(std::string fileName, AnimationMovie *a_movies, int arr_size);
void animationMovie_FileDisplay(std::string fileName);
void removeObj_AnimationMovieType(AnimationMovie*& arr, int &size, std::string toRemove);