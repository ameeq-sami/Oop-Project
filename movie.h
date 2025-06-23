#pragma once
#include<iostream>
#include"name.h"
#include"date.h"
#include"director.h"


class Movie{
    private:
    Director director;
    std::string title;
    Date releaseDate;
    int rating;
    
    protected: 
    std::string genre;
    void setTitle(std::string t);
    std::string getTitle();
    void setRating(int r);
    int getRating();
    virtual void setGenre() ;
    std::string getGenre();
    
    public: 

    Movie();
    Movie(Director& di // director
        ,int da, std::string m, int y //Date
        ,std::string t //title 
        ,int r //rating
         );
    Movie(Movie& other);
    ~Movie();

    Director& getDirector();
    friend std::ostream& operator<< (std::ostream& out , Movie& m);
    virtual int calculateScore(int noOfDays);
    virtual void display();
    
    friend bool searchByTitle(std::string t, Movie &toSearch);
    friend bool searchByRating(int r, Movie &toSearch);
    friend bool searchByTitleAndRating(std::string t, int r, Movie &toSearch);

    
};