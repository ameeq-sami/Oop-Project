#pragma once
#include"movie.h"
class SicifiMovie:public Movie
{
    private:
    int techLevel;
    bool alien;
    bool futureYear;

    protected: 
    void setTechLevel(int tl);
    int getTechLevel();
    void setAlien(bool a);
    bool getAlien();
    void setFutureYear(bool fy);
    bool getFutureYear();
    void setGenre() override;
    
    public:
    SicifiMovie();
    SicifiMovie(Director& di, int da, std::string m, int y, std::string t ,int r, int tl, bool a, bool fy);
    SicifiMovie(SicifiMovie& other);
    ~SicifiMovie();

    int calculateScore(int noOfDays) override;
    friend std::ostream& operator<<(std::ostream& out,SicifiMovie& sm);
    void display() override;
    void showTechAnalysis();
    void simulateFutureScenario();
    void toggleAlienInvasion();



};
