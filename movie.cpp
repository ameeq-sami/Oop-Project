#include "movie.h"

void Movie::setTitle(std::string t)
{
    title = t;
}

std::string Movie::getTitle()
{
    return title;
}

void Movie::setRating(int r)
{
    rating = r;
}

int Movie::getRating()
{
    return rating;
}

void Movie::setGenre()
{
    genre = "Generic";
}

std::string Movie::getGenre()
{
    return genre;
}

Movie::Movie() : director(), releaseDate()
{
    setTitle("EMPTY");
    setRating(-1);
}

Movie::Movie(Director &di, int da, std::string m, int y, std::string t, int r): director(di), releaseDate(da, m , y) 
{
    setTitle(t);
    setRating(r);
}

Movie::Movie(Movie &other):director(other.director), releaseDate(other.releaseDate)
{
    setTitle(other.getTitle());
    setRating(other.getRating());
}

Movie::~Movie()
{
}

int Movie::calculateScore(int noOfDays) 
{
    return (getRating()*noOfDays)%10;
}

void Movie::display() 
{
    std::cout<<*this;
}

std::ostream &operator<<(std::ostream &out, Movie &m)
{
    out<<"Director: "<<m.director<<"Title: "<<m.getTitle()<<"     Rating: "<<m.getRating()<<std::endl<<"Release Date: "<<m.releaseDate<<std::endl;
    return out;
}


bool searchByTitle(std::string t, Movie* toSearch)
{
    if (toSearch->getTitle() == t)
    {
        return true;
    }
    
    return false;
}

bool searchByRating(int r, Movie* toSearch)
{
    if (toSearch->getRating() == r)
    {
        return true;
    }
    
    return false;
}

bool searchByTitleAndRating(std::string t, int r, Movie* toSearch)
{
    if (toSearch->getRating() == r && toSearch->getTitle() == t )
    {
        return true;
    }
    
    return false;
}

Director& Movie::getDirector()
{
    return director;
}
