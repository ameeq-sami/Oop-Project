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
    SicifiMovie(std::string fn, std::string ln, int ye, std::string nation, int da, std::string m, int y, std::string t ,int r, int tl, bool a, bool fy);
    SicifiMovie(SicifiMovie& other);
    ~SicifiMovie();

    int calculateScore() override;
    void display() override;
    void showTechAnalysis();
    void simulateFutureScenario();
    void toggleAlienInvasion();
    friend std::ostream& operator<<(std::ostream& out,SicifiMovie& sm);
    friend void sicifiMovie_ArrayToFile(std::string fileName, SicifiMovie *s_movies, int arr_size);



};
