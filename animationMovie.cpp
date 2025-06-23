#include "animationMovie.h"

void AnimationMovie::setAnimationStyle(int as)
{
    animationStyle = as;
}

int AnimationMovie::getAnimationStyle()
{
    return animationStyle;
}

void AnimationMovie::setAgeGroup(int ag)
{
    ageGroup = ag;
}

int AnimationMovie::getAgeGroup()
{
    return ageGroup;
}

void AnimationMovie::setMusical(bool m)
{
    musical = m;
}

bool AnimationMovie::getMusical()
{
    return musical;
}

void AnimationMovie::setGenre()
{
    genre = "Animation";
}


AnimationMovie::AnimationMovie():Movie()
{
    setAnimationStyle(0);
    setAgeGroup(0);
    setMusical(0);
    setGenre();
}

AnimationMovie::AnimationMovie(Director &di, int da, std::string m, int y, std::string t, int r, int am, int ag, bool mu):Movie(di, da, m, y, t, r)
{
    setAnimationStyle(am);
    setAgeGroup(ag);
    setMusical(mu);
    setGenre();
}

AnimationMovie::AnimationMovie(AnimationMovie &other):Movie(other)
{
    setAnimationStyle(other.getAnimationStyle());
    setAgeGroup(other.getAgeGroup());
    setMusical(other.getMusical());
    setGenre(); 
}

AnimationMovie::~AnimationMovie()
{
}

void AnimationMovie::display()
{
    std::cout<<*this;
}

int AnimationMovie::calculateScore(int noOfDays)
{
    return (getRating()*noOfDays*(getAgeGroup()/getAnimationStyle())%10);
}

void AnimationMovie::suggestMerchandise()
{
    if (getAnimationStyle() == 2 || getAnimationStyle() == 3 )
    {
        std::cout<<" COOL "<<std::endl;
    }
    else std::cout<<" NOT COOL "<<std::endl;
    
}

bool AnimationMovie::isFamilyFriendly()
{
    if ((getAgeGroup() == 18 && getMusical() == 1 ) || ( (getAgeGroup() == 5 || getAgeGroup() == 7 ) && getMusical() == 0 ) || getAnimationStyle() == 3 )
    {
        return true;
    }
        return false;
}

void AnimationMovie::changeAnimationStyle(int as)
{
    setAnimationStyle(as);
}

std::ostream &operator<<(std::ostream &out, AnimationMovie &am)
{
    out<<am.getDirector()<<"Animation Style: "<< am.getAnimationStyle()<<"      Age Group: "<<am.getAgeGroup() <<"      Musical: "<<am.getMusical()<<std::endl;
    return out; 
}

