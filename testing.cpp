#include<iostream>
using namespace std;
#include"movie.h"
#include"scifiMovie.h"
#include"fileHandlingFunc.h"
int main() {
    int size = 5;

    // Create sample Director objects
    // Director d1("James", "Cameron", 25, "USA");
    // Director d2("Christopher", "Nolan", 22, "UK");
    // Director d3("Greta", "Gerwig", 10, "USA");
    // Director d4("Hayao", "Miyazaki", 40, "Japan");
    // Director d5("Zoya", "Akhtar", 15, "India");

    Director* directors = new Director[director_size];
    directors[0] =  Director ("James", "Cameron", 25, "USA");
    directors[1] = Director ("Christopher", "Nolan", 22, "UK");
    directors[2] = Director ("Greta", "Gerwig", 10, "USA");
    directors[3] = Director ("Hayao", "Miyazaki", 40, "Japan");
    directors[4] = Director ("Zoya", "Akhtar", 15, "India");

    SicifiMovie* movies = new SicifiMovie[size];
    movies[0] = SicifiMovie(d1, 162, "Dec", 18, "Avatar", 9, 13, 2, 0);
    movies[1] = SicifiMovie(d2, 169, "Nov", 7, "Interstellar", 8, 13, 1, 0);
    movies[2] = SicifiMovie(d3, 130, "Jul", 21, "Barbie Galaxy", 7, 7, 3, 1);
    movies[3] = SicifiMovie(d4, 120, "Aug", 15, "Spirited Cosmos", 9, 5, 2, 1);
    movies[4] = SicifiMovie(d5, 140, "Oct", 10, "Future Tides", 8, 18, 1, 0);


    // Create dynamic array of SciFiMovie objects using constructor
    // Display movie details
    // for (int i = 0; i < size; i++) {
    //     cout<<"----------"<<endl;
    //     movies[i]->display();
    //     cout<<"----------"<<endl;
    // }

//     string s = "Avatar";
//     removeObj_SicifiMovieType(movies, size, s);
//     cout<<"----------"<<endl;

//     cout<<"After Remove:"<<endl;
// for (int i = 0; i < size; i++) {
//         movies[i].display();
//         cout<<"----------"<<endl;
//     }

//     // Free memory
//     delete[] movies;

//     return 0;
}
// main(){

//      Director d1("James", "Cameron", 25, "USA");
//     Movie* ptr = new SicifiMovie (d1, 162, "Dec", 18, "Avatar", 9, 13, 2, 0);
//     *ptr->display();
// }
