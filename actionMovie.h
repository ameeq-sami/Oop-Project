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
    ActionMovie(std::string fn, std::string ln, int ye, std::string nation, int da, std::string m, int y, std::string t, int r, std::string vl, int nf, bool s);
    ActionMovie(ActionMovie& other);
    ~ActionMovie();

    int calculateScore() override;
    int countExplosions();
    void  assessCensorship();
    void stuntCoordinatorReport();
    void display() override;
    
    friend std::ostream& operator<< (std::ostream& out, ActionMovie& am);
    friend void actionMovie_ArrayToFile(std::string fileName, ActionMovie *a_movies, int arr_size);
    
};