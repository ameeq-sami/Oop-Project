#include "actionMovie.h"

void ActionMovie::setViolenceLevel(std::string vl)
{
    violenceLevel = vl;
}

std::string ActionMovie::getViolenceLevel()
{
    return violenceLevel;
}

void ActionMovie::setNoOfFightScenes(int ns)
{
    noOfFightScenes = ns;
}

int ActionMovie::getNoOfFightScenes()
{
    return noOfFightScenes;
}

void ActionMovie::setStunts(bool s)
{
    stunts = s;
}

bool ActionMovie::getStunts()
{
    return stunts;
}

void ActionMovie::setGenre()
{
    genre = "Action";
}

ActionMovie::ActionMovie():Movie()
{
    setViolenceLevel("E");
    setNoOfFightScenes(0);
    setStunts(0);
}

ActionMovie::ActionMovie(Director &di, int da, std::string m, int y, std::string t, int r, std::string vl, int nf, bool s): Movie(di, da, m, y, t, r)
{
    setViolenceLevel(vl);
    setNoOfFightScenes(nf);
    setStunts(s);
}

ActionMovie::ActionMovie(ActionMovie &other):Movie(other) 
{
    setViolenceLevel(other.getViolenceLevel());
    setNoOfFightScenes(other.getNoOfFightScenes());
    setStunts(other.getStunts());
}

ActionMovie::~ActionMovie()
{
}

int ActionMovie::calculateScore(int n)
{
    int nf; 
    if (getNoOfFightScenes() > 7 )
    {
        nf = 2;
    }
    else nf = getNoOfFightScenes();
    
    return (((getRating()*n*nf)/countExplosions())%10);
}

int ActionMovie::countExplosions()
{
    int nf;
    if (getNoOfFightScenes() > 5)
    {
        return 8;
    }
        return 2;
}

void ActionMovie::assessCensorship()
{
    if (getViolenceLevel() == "D")
    {
        std::cout<<"Domestic Violence"<<std::endl;
    }
    else if (getViolenceLevel() == "M")
    {
        std::cout<<"Mafia"<<std::endl;
    }
    else
    std::cout<<"Ultra Cool"<<std::endl;    
}

void ActionMovie::stuntCoordinatorReport()
{
    if (getStunts() == 1 && (getNoOfFightScenes() > 5 && getNoOfFightScenes() < 10))
    {
        std::cout<<"Very Cool"<<std::endl;
    }
    else    std::cout<<"Might be boring"<<std::endl;
}

void ActionMovie::display()
{
    std::cout<<*this;
}

std::ostream &operator<<(std::ostream &out, ActionMovie &am)
{
    out << am.getDirector()<<"Violence Level: "<<am.getViolenceLevel() <<"      No of Fight scenes: " <<am.getNoOfFightScenes()<< "     Has Stunts: "<<am.getStunts()<<std::endl;
}
