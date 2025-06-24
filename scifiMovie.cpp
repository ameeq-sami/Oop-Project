#include"scifiMovie.h"

void SicifiMovie::setTechLevel(int tl)
{
    techLevel = tl;
}

int SicifiMovie::getTechLevel()
{
    return techLevel;
}

void SicifiMovie::setAlien(bool a)
{
    alien = a;
}

bool SicifiMovie::getAlien()
{
    return  alien;
}

void SicifiMovie::setFutureYear(bool fy)
{
    futureYear = fy;
}

bool SicifiMovie::getFutureYear()
{
    return futureYear;
}

void SicifiMovie::setGenre()
{
    genre = "SiciFI";
}

SicifiMovie::SicifiMovie():Movie()
{
    setTechLevel(-1);
    setAlien(0);
    setFutureYear(0);
}

SicifiMovie::SicifiMovie(Director &di, int da, std::string m, int y, std::string t, int r, int tl, bool a, bool fy):Movie(di, da, m, y, t, r)
{
    setTechLevel(tl);
    setAlien(a);
    setFutureYear(fy);
}

SicifiMovie::SicifiMovie(SicifiMovie &other):Movie(other)
{
    setTechLevel(other.getTechLevel());
    setFutureYear(other.getFutureYear());
    setAlien(other.getAlien());

}

SicifiMovie::~SicifiMovie()
{
}

int SicifiMovie::calculateScore(int noOfDays)
{
    return (Movie::getRating()*noOfDays*getTechLevel())%10;
}

void SicifiMovie::display()
{
    std::cout<<"Title: "<<getTitle()<<"     Rating: "<<getRating()<<std::endl;
    std::cout<<"Director Detail: "<<std::endl;
    std::cout<<*this;
}

void SicifiMovie::showTechAnalysis()
{
    if (calculateScore(4) > 7)
    {
        std::cout<<"Awesome "<<std::endl;
    }
    else std::cout<<"Not so Awesome"<<std::endl;
    
}

void SicifiMovie::simulateFutureScenario()
{
    if (calculateScore(4) > 7 && getAlien() == 1 && getFutureYear() == 1)
    {
        std::cout<<"Future is bright"<<std::endl;
    }
    else std::cout<<"Future is not so bright"<<std::endl;
    
}

void SicifiMovie::toggleAlienInvasion()
{
    setAlien(!getAlien());
}

std::ostream &operator<<(std::ostream &out, SicifiMovie &sm)
{ 
    out<<sm.getDirector()<<"Tech Level: "<< sm.getTechLevel()<<"      Alien Status: "<<sm.getAlien() <<"      Future Year Status: "<<sm.getFutureYear()<<std::endl;
    return out; 
}
