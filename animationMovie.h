#pragma oncce
#include"movie.h"
class AnimationMovie : public Movie
{
    private:
    int animationStyle;
    int ageGroup;
    bool musical;

    
    protected:
    void setAnimationStyle(int as);
    int getAnimationStyle();
    void setAgeGroup(int ag);
    int getAgeGroup();
    void setMusical(bool m);
    bool getMusical();
    void setGenre() override;

    public:
    AnimationMovie();
    AnimationMovie(Director& di, int da, std::string m, int y, std::string t, int r, int am, int ag, bool mu);
    AnimationMovie(std::string fn, std::string ln, int ye, std::string nation, int da, std::string m, int y, std::string t, int r, int am, int ag, bool mu);
    AnimationMovie(AnimationMovie &other);
    ~AnimationMovie();

    void display() override;
    int calculateScore(int noOfDays) override;
    void suggestMerchandise();
    bool isFamilyFriendly();
    void changeAnimationStyle(int as);
    
    friend void animationMovie_ArrayToFile(std::string fileName, AnimationMovie *a_movies, int arr_size);
    friend std::ostream& operator<< (std::ostream& out, AnimationMovie& am);




};