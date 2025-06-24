#pragma once
#include<iostream>
#include"movie.h"
#include <string>
#include"scifiMovie.h"

int fileSize(std::string fileName);
// void removeObj_MovieType(Movie**& arr, int& size, std::string toRemove);
void removeObj_SicifiMovieType(SicifiMovie**& arr, int &size, std::string toRemove);