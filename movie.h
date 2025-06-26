#pragma once
#include<iostream>
#include"name.h"
#include"date.h"
#include"director.h"


class Movie{
    private:
    std::string title;
    int rating;
    
    protected: 
    Director director;
    Date releaseDate;
    std::string genre;
    void setTitle(std::string t);
    std::string getTitle();
    void setRating(int r);
    int getRating();
    virtual void setGenre() ;
    std::string getGenre();
    
    public: 

    Movie();
    Movie(Director& di ,int da, std::string m, int y ,std::string t ,int r );
    Movie(std::string fn, std::string ln, int ye, std::string nation, int da, std::string m, int y ,std::string t ,int r );
    Movie(Movie& other);
    ~Movie();
    
    Director& getDirector();
    friend std::ostream& operator<< (std::ostream& out , Movie& m);
    virtual int calculateScore(int noOfDays);
    virtual void display();
    
    friend bool searchByTitle(std::string t, Movie toSearch);
    friend bool searchByRating(int r, Movie* toSearch);
    friend bool searchByTitleAndRating(std::string t, int r, Movie* toSearch);

    
};