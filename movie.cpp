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

int Movie::getMovieYear()
{

    return releaseDate.getYear();
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

Movie::Movie(std::string fn, std::string ln, int ye, std::string nation, int da, std::string m, int y, std::string t, int r):director(fn, ln, ye, nation), releaseDate(da, m, y)
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

int Movie::calculateScore() 
{
    return (getRating()*releaseDate.getDay())%10;
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

bool searchByYear(int yr, Movie toSearch)
{
    if (toSearch.getMovieYear() == yr)
    return true;
    
    return false;
}

bool searchByTitle(std::string t, Movie toSearch)
{
    
    if (toSearch.getTitle() == t)
    {
        return true;
    }
    
    return false;
}

bool searchByRating(int r, Movie toSearch)
{
    if (toSearch.getRating() == r)
    {
        return true;
    }
    
    return false;
}

bool searchByTitleAndRating(std::string t, int r, Movie toSearch)
{
    if (toSearch.getRating() == r && toSearch.getTitle() == t )
    {
        return true;
    }
    
    return false;
}

bool searchByDrector(std::string fn, std::string ln, Movie toSearch)
{
    std::string f,l;
    toSearch.director.getDirectorName(f,l);
    if (fn == f && ln == l) return true;
    return false;
}


Director& Movie::getDirector()
{
    return director;
}
