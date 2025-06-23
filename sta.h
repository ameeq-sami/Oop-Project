#include<iostream>
#include<fstream>
#include"director.h"
int fileSize(std::string fileName);
void directorFileAppend(std::string fileName, int directors_count);
void directorFileToArray(std::string fileName, Director* arr_ptr, int arr_size);
void directorArrayToFile(std::string fileName, Director* arr_ptr, int arr_size);
void directorFileDisplay(std::string fileName);