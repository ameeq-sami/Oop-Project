#pragma once
#include"movie.h"

class ActionMovie: public Movie{
    private:
    std::string violenceLevel;
    int noOfFightScenes;
    bool stunts;
    
    protected:
    void setViolenceLevel(std::string vl);
    std::string getViolenceLevel();
    void setNoOfFightScenes(int ns);
    int getNoOfFightScenes();
    void setStunts(bool s);
    bool getStunts();
    void setGenre() override;

    public: 
    ActionMovie();
    ActionMovie(Director& di, int da, std::string m, int y, std::string t, int r, std::string vl, int nf, bool s);
    ActionMovie(ActionMovie& other);
    ~ActionMovie();

    int calculateScore(int n) override;
    int countExplosions();
    void  assessCensorship();
    void stuntCoordinatorReport();
    friend std::ostream& operator<< (std::ostream& out, ActionMovie& am);
    void display() override;
    
};