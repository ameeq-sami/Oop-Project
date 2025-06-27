#include "fileHandlingFunc.h"
#include<fstream>
#include <string>
#include "director.h"


int fileSize(std::string fileName){
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Error: Could not open file." << std::endl;
        return -1 ;
    }
    std::string line;
    int lineCount = 0;
    while (getline(file, line))
    {
        lineCount++;
    }
    return lineCount;
}

//for directors
void directorFileAppend(std::string fileName) //take data from user and append into file
{

    std::fstream directorFile;
    directorFile.open(fileName, std::ios::app);
    if (!directorFile.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
        std::string str;    
        std::cout<<"Director First Name: ";
        std::cin>>str;
        directorFile<<str<<std::endl;

        std::cout<<"Director Second Name: ";
        std::cin>>str;
        directorFile<<str<<std::endl;
    
        std::cout<<"Director Nationality: ";
        std::cin>>str;
        directorFile<<str<<std::endl;

        std::cout<<"Director Year of Exprience: ";
        std::cin>>str;
        directorFile<<str<<std::endl;

    directorFile.close();

}

void directorFileToArray(std::string fileName, Director* &directors, int arr_size) // copy file content into array
{
        delete directors;
        directors = new Director[arr_size];  

    std::fstream directorFile;
    std::string fname, lname, natioanlity;
    int yearOfExprience;
    directorFile.open(fileName, std::ios::in);
    if (!directorFile.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    for(int i = 0; i < arr_size ; i++){
        directorFile>>fname;        
        directorFile>>lname;
        directorFile>>natioanlity;
        directorFile>>yearOfExprience;
        directors[i] = Director(fname, lname, yearOfExprience, natioanlity);
}
    directorFile.close();
}

void directorArrayToFile(std::string fileName, Director *directors, int arr_size)   //for overwrite obj array in file
{
    std::fstream file;
    file.open(fileName, std::ios::out);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    for (int  i = 0; i < arr_size; i++)
    {
        file<<directors[i].name.getFirstName()<<std::endl;
        file<<directors[i].name.getLastName()<<std::endl;
        file<<directors[i].getNationality()<<std::endl;
        file<<directors[i].getYearOfExperience()<<std::endl;
        
    }
    file.close();

}

void directorArrayToFile(std::string fileName, Director directors, std::string mode) // for append or overwrite obj in file
{
    if(mode == "out"){
    std::fstream file;
    file.open(fileName, std::ios::out);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
        file<<directors.name.getFirstName()<<std::endl;
        file<<directors.name.getLastName()<<std::endl;
        file<<directors.getNationality()<<std::endl;
        file<<directors.getYearOfExperience()<<std::endl;
        
    file.close();
    }
    else if (mode == "app")
    {
        std::fstream file;
        file.open(fileName, std::ios::app);
        if (!file.is_open()) {
        std::cout << "Error: Could not open file." << std::endl;
        return ;
    }
        file<<directors.name.getFirstName()<<std::endl;
        file<<directors.name.getLastName()<<std::endl;
        file<<directors.getNationality()<<std::endl;
        file<<directors.getYearOfExperience()<<std::endl;
        
        file.close();

    }
    

}

void directorFileDisplay(std::string fileName) //display content of file on complier screen
{
    std::cout<<"Display..."<<std::endl;
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    std::string temp;
    int i = 0;
    int counter = 1; // to display movie number
    while(getline(file,temp)){
            if (i == 0)
            {
                std::cout<<"------ Director no."<<counter<<" ------\n ";    
                std::cout<<"First Name: "<<temp<<std::endl;  
                counter++;
            }
            else if (i == 1)
            {
            
                std::cout<<"Second Name: "<<temp<<std::endl;
                
            }
            else if (i == 2)
            {
            
                std::cout<<"Nationality: "<<temp<<std::endl;
                
            }
            else{
                std::cout<<"Year of Exprience: "<<temp<<std::endl;
            }
            i++;
            if (i == 4) i = 0;            
        }   
        file.close();
}


void sicifiMovie_FileAppend(std::string fileName, Director* directors, int director_arraySize)
{
    std::fstream file;
    file.open(fileName, std::ios::app);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
        std::string str;
        int temp;
        int index;    
        std::cout<<"Chose Director from above list";
        std::cin>>index;
        while (!(index >= 1 && index <= director_arraySize))
        {
            std::cout<<"Enter Valid index\n";
            std::cin>>index;
        }
        index = index - 1;
        directorArrayToFile(fileName, directors[index], "app");
        
        std::cout<<"Enter Title of Movie: ";
        std::cin.ignore();
        std::getline(std::cin, str);
        file<<str<<std::endl;
        

        std::cout<<"Enter Release day";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Release month ";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Release year ";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Tech Level (it should be between 1 to 3): ";
        std::cin>>temp;
        while (!(temp >= 1 && temp <= 3))
        {
            std::cout<<"Enter valid Tech Level (it should be between 1 to 3): ";
            std::cin>>temp;
        }
        file<<temp<<std::endl;
        
        std::cout<<"Enter Rating of Moive (it should be between 1 to 5): ";
        std::cin>>temp;
        while (!(temp >= 0 && temp <=5))
        {
            std::cout<<"Enter Valid Rating of Moive (it should be between 1 to 5): ";
            std::cin>>temp;
        }
        file<<temp<<std::endl;
        
        std::cout<<"Does it contains aliens press 1 for true and 0 for false: ";
        std::cin>>temp;
        file<<temp<<std::endl;

        std::cout<<"Is set in some future year press 1 for true and 0 for false: ";
        std::cin>>temp;
        file<<temp<<std::endl;

        file.close();

}

void sicifiMovie_FileToArray(std::string fileName, SicifiMovie* &s_movies, int arr_size) // copy file content into array
{
        delete s_movies;
        s_movies = new SicifiMovie[arr_size];  

    std::fstream file;
    std::string fname, lname, natioanlity, title, month;
    int yearOfExprience, day, year, teklevl, rating;
    bool a, fy;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    for(int i = 0; i < arr_size ; i++){
        
        file>>fname;        
        file>>lname;
        file>>natioanlity;
        file>>yearOfExprience;
        std::getline(file >> std::ws, title);
        file>>day;
        std::getline(file >> std::ws, month);
        file>>year;
        file>>teklevl;
        file>>rating;
        file>>a;
        file>>fy;
        s_movies[i] = SicifiMovie(fname, lname, yearOfExprience, natioanlity, day, month, year, title, rating, teklevl, a, fy);
        // std::cout<<s_movies[i]<<std::endl;
        
}
    file.close();
}

void sicifiMovie_ArrayToFile(std::string fileName, SicifiMovie *s_movies, int arr_size)   
{
    
    std::fstream file;
    file.open(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file." << std::endl;
        return ;
    }
        std::ofstream file_d(fileName, std::ios::trunc);// to delete all content of file

        for (int i = 0; i < arr_size; i++)
        {        
        directorArrayToFile(fileName, s_movies[i].getDirector(), "app");
        file<<s_movies[i].getTitle()<<std::endl;
        file<<s_movies[i].releaseDate.getDay()<<std::endl;
        file<<s_movies[i].releaseDate.getMonth()<<std::endl;
        file<<s_movies[i].releaseDate.getYear()<<std::endl;
        file<<s_movies[i].getTechLevel()<<std::endl;
        file<<s_movies[i].getRating()<<std::endl;
        file<<s_movies[i].getAlien()<<std::endl;
        file<<s_movies[i].getFutureYear()<<std::endl;
        }
    file.close();

}

void sicifiMovie_FileDisplay(std::string fileName) //display content of file on complier screen
{
    std::cout<<"Display..."<<std::endl;
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    std::string temp;
    int i = 0;
    int counter = 1; // to display movie number
    while(getline(file,temp)){
            if (i == 0)
            {
                std::cout<<"-------- Movie no."<<counter<<" --------\n";
                std::cout<<"     --- Director Info ---\n ";
                std::cout<<"First Name: "<<temp<<std::endl;  
                counter++;
            }
            else if (i == 1)
            {
                
                std::cout<<"Second Name: "<<temp<<std::endl;
                
            }
            else if (i == 2)
            {
                
                std::cout<<"Nationality: "<<temp<<std::endl;
                
            }
            else if (i == 3){
                std::cout<<"Year of Exprience: "<<temp<<std::endl;
                std::cout<<std::endl;
                std::cout<<"     --- Movie Info ---\n ";
            }
            
            else if (i == 4){
                std::cout<<"Movie Title: "<<temp<<std::endl;
            }
            else if (i == 5){
                std::cout<<"Date: "<<temp;
            }
            else if (i == 6){
                std::cout<<" / "<<temp;
            }
            else if (i == 7){
                std::cout<<" / "<<temp<<std::endl;
            }
            else if (i == 8){
                std::cout<<"Tech Level: "<<temp<<std::endl;
            }
            else if (i == 9){
                std::cout<<"Rating: "<<temp<<std::endl;
            }
            else if (i == 10){
                std::cout<<"Alien status: "<<temp<<std::endl;
            }
            else{
                std::cout<<"Future Year status: "<<temp<<std::endl;
                std::cout<<"----------------------------\n";
            }
            
            i++;

            if (i == 12) i = 0;            
        }   
        file.close();
}

void removeObj_SicifiMovieType(SicifiMovie*& arr, int &size, std::string toRemove)
{
    int index = -1; 
    for (int i = 0; i < size; i++)
    {
        if (searchByTitle(toRemove, arr[i]))
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        std::cout<<"Movie Not Found Recheck your Input\n";
        return;
    }
    
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;

    SicifiMovie* tempArr = new SicifiMovie[size];

    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;


}


void animationMovie_FileAppend(std::string fileName, Director *directors, int director_arraySize)
{
    std::fstream file;
    file.open(fileName, std::ios::app);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
        std::string str;
        int temp;
        int index;    
        std::cout<<"Chose Director from above list";
        std::cin>>index;
        while (!(index >= 1 && index <= director_arraySize))
        {
            std::cout<<"Enter Valid index\n";
            std::cin>>index;
        }
        index = index - 1;
        directorArrayToFile(fileName, directors[index], "app");
        
        std::cout<<"Enter Title of Movie: ";
        std::cin.ignore();
        getline(std::cin, str);
        file<<str<<std::endl;
        

        std::cout<<"Enter Release day";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Release month ";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Release year ";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Animation Style (it should be between 1 to 3): ";
        std::cin>>temp;
        while (!(temp >= 1 && temp <= 3))
        {
            std::cout<<"Enter valid Animation Style (it should be between 1 to 3): ";
            std::cin>>temp;
        }
        file<<temp<<std::endl;
        
        std::cout<<"Enter Rating of Moive (it should be between 1 to 5): ";
        std::cin>>temp;
        while (!(temp >= 0 || temp <=5))
        {
            std::cout<<"Enter Valid Rating of Moive (it should be between 1 to 5): ";
            std::cin>>temp;
        }
        file<<temp<<std::endl;
        

        std::cout<<"Enter Age Group of Moive (it should be 5 , 7 or 18): ";
        std::cin>>temp;
        while (!(temp == 5 || temp == 7 || temp == 18))
        {
            std::cout<<"Enter Valid Age Group of Moive (it should be 5 , 7 or 18): ";
            std::cin>>temp;
        }
        file<<temp<<std::endl;

        std::cout<<"If it is Musical press 1 for true and 0 for false: ";
        std::cin>>temp;
        file<<temp<<std::endl;
}

void animationMovie_FileToArray(std::string fileName, AnimationMovie* &a_movies, int arr_size)
{
    
        delete a_movies;
        a_movies = new AnimationMovie[arr_size];  

    std::fstream file;
    std::string fname, lname, natioanlity, title, month;
    int yearOfExprience, day, year, ageGrp, rating, animationStyle;
    bool musical;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    for(int i = 0; i < arr_size ; i++){
        file>>fname;        
        file>>lname;
        file>>natioanlity;
        file>>yearOfExprience;
        // file.ignore();
        std::getline(file >> std::ws, title);
        // file.ignore();
        file>>day;
        std::getline(file >> std::ws, month);
        file>>year;
        file>>animationStyle;
        file>>rating;
        file>>ageGrp;
        file>>musical;
        a_movies[i] = AnimationMovie(fname, lname, yearOfExprience, natioanlity, day, month, year, title, rating, animationStyle, ageGrp, musical );
}
    file.close();
}

void animationMovie_ArrayToFile(std::string fileName, AnimationMovie *a_movies, int arr_size)
{
    std::fstream file;
    file.open(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file." << std::endl;
        return ;
    }
        std::ofstream file_d(fileName, std::ios::trunc);// to delete all content of file

        for (int i = 0; i < arr_size; i++)
        {        
        directorArrayToFile(fileName, a_movies[i].getDirector(), "app");
        file<<a_movies[i].getTitle()<<std::endl;
        file<<a_movies[i].releaseDate.getDay()<<std::endl;
        file<<a_movies[i].releaseDate.getMonth()<<std::endl;
        file<<a_movies[i].releaseDate.getYear()<<std::endl;
        file<<a_movies[i].getAnimationStyle()<<std::endl;
        file<<a_movies[i].getRating()<<std::endl;
        file<<a_movies[i].getAgeGroup()<<std::endl;
        file<<a_movies[i].getMusical()<<std::endl;
        }
    file.close();

}

void animationMovie_FileDisplay(std::string fileName)
{
    std::cout<<"Display..."<<std::endl;
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    std::string temp;
    int i = 0;
    int counter = 1; // to display movie number
    while(getline(file,temp)){
            if (i == 0)
            {
                std::cout<<"-------- Movie no."<<counter<<" --------\n";
                std::cout<<"     --- Director Info ---\n ";
                std::cout<<"First Name: "<<temp<<std::endl;  
                counter++;
            }
            else if (i == 1)
            {
                
                std::cout<<"Second Name: "<<temp<<std::endl;
                
            }
            else if (i == 2)
            {
                
                std::cout<<"Nationality: "<<temp<<std::endl;
                
            }
            else if (i == 3){
                std::cout<<"Year of Exprience: "<<temp<<std::endl;
                std::cout<<std::endl;
                std::cout<<"     --- Movie Info ---\n ";
            }
            
            else if (i == 4){
                std::cout<<"Movie Title: "<<temp<<std::endl;
            }
            else if (i == 5){
                std::cout<<"Date: "<<temp;
            }
            else if (i == 6){
                std::cout<<" / "<<temp;
            }
            else if (i == 7){
                std::cout<<" / "<<temp<<std::endl;
            }
            else if (i == 8){
                std::cout<<"Animation Style: "<<temp<<std::endl;
            }
            else if (i == 9){
                std::cout<<"Rating: "<<temp<<std::endl;
            }
            else if (i == 10){
                std::cout<<"Age Group: "<<temp<<std::endl;
            }
            else{
                std::cout<<"Musical status: "<<temp<<std::endl;
                std::cout<<"----------------------------\n";
            }
            
            i++;

            if (i == 12) i = 0;            
        }   
        file.close();
}

void removeObj_AnimationMovieType(AnimationMovie *&arr, int &size, std::string toRemove)
{
    int index = -1; 
    for (int i = 0; i < size; i++)
    {
        if (searchByTitle(toRemove, arr[i]))
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        std::cout<<"Movie Not Found Recheck your Input\n";
        return;
    }
    
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;

    AnimationMovie* tempArr = new AnimationMovie[size];

    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;


}


void actionMovie_FileAppend(std::string fileName, Director *directors, int director_arraySize)
{
    std::fstream file;
    file.open(fileName, std::ios::app);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
        std::string str;
        int temp;
        int index;    
        std::cout<<"Chose Director from above list";
        std::cin>>index;
        while (!(index >= 1 && index <= director_arraySize))
        {
            std::cout<<"Enter Valid index\n";
            std::cin>>index;
        }
        index = index - 1;
        directorArrayToFile(fileName, directors[index], "app");
        
        std::cout<<"Enter Title of Movie: ";
        std::cin.ignore();
        getline(std::cin, str);
        file<<str<<std::endl;
        

        std::cout<<"Enter Release day";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Release month ";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Release year ";
        std::cin>>str;
        file<<str<<std::endl;

        std::cout<<"Enter Voilence Level (it should be D, M or U ): ";
        std::cin>>str;
        while (!( str == "D" || str == "M" || str == "U" ))
        {
            std::cout<<"Enter valid Voilence Level (it should be D, M or U ): ";
            std::cin>>str;
        }
        file<<str<<std::endl;
        
        std::cout<<"Enter Rating of Moive (it should be between 1 to 5): ";
        std::cin>>temp;
        while (!(temp >= 0 || temp <=5))
        {
            std::cout<<"Enter Valid Rating of Moive (it should be between 1 to 5): ";
            std::cin>>temp;
        }
        file<<temp<<std::endl;
        

        std::cout<<"Enter Number no of Fight Scenes: ";
        std::cin>>temp;
        file<<temp<<std::endl;

        std::cout<<"If it is has stunts press 1 for true and 0 for false: ";
        std::cin>>temp;
        file<<temp<<std::endl;
}

void actionMovie_FileToArray(std::string fileName, ActionMovie* &a_movies, int arr_size)
{
      delete a_movies;
        a_movies = new ActionMovie[arr_size];  

    std::fstream file;
    std::string fname, lname, natioanlity, title, month, vl;
    int yearOfExprience, day, year,  rating, nf;
    bool musical, stunts;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    for(int i = 0; i < arr_size ; i++){
        file>>fname;        
        file>>lname;
        file>>natioanlity;
        file>>yearOfExprience;
        std::getline(file >> std::ws, title);
        file>>day;
        std::getline(file >> std::ws, month);
        file>>year;
        file>>vl;
        file>>rating;
        file>>nf;
        file>>stunts;
        a_movies[i] = ActionMovie(fname, lname, yearOfExprience, natioanlity, day, month, year, title, rating, vl, nf, stunts );
}
    file.close();
}

void actionMovie_ArrayToFile(std::string fileName, ActionMovie *a_movies, int arr_size)
{
    std::fstream file;
    file.open(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file." << std::endl;
        return ;
    }
        std::ofstream file_d(fileName, std::ios::trunc);// to delete all content of file

        for (int i = 0; i < arr_size; i++)
        {        
        directorArrayToFile(fileName, a_movies[i].getDirector(), "app");
        file<<a_movies[i].getTitle()<<std::endl;
        file<<a_movies[i].releaseDate.getDay()<<std::endl;
        file<<a_movies[i].releaseDate.getMonth()<<std::endl;
        file<<a_movies[i].releaseDate.getYear()<<std::endl;
        file<<a_movies[i].getViolenceLevel()<<std::endl;
        file<<a_movies[i].getRating()<<std::endl;
        file<<a_movies[i].getNoOfFightScenes()<<std::endl;
        file<<a_movies[i].getStunts()<<std::endl;
        }
    file.close();

}

void actionMovie_FileDisplay(std::string fileName)
{
    std::cout<<"Display..."<<std::endl;
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
    std::cout << "Error: Could not open file." << std::endl;
    return ;
    }
    std::string temp;
    int i = 0;
    int counter = 1; // to display movie number
    while(getline(file,temp)){
            if (i == 0)
            {
                std::cout<<"-------- Movie no."<<counter<<" --------\n";
                std::cout<<"     --- Director Info ---\n ";
                std::cout<<"First Name: "<<temp<<std::endl;  
                counter++;
            }
            else if (i == 1)
            {
                
                std::cout<<"Second Name: "<<temp<<std::endl;
                
            }
            else if (i == 2)
            {
                
                std::cout<<"Nationality: "<<temp<<std::endl;
                
            }
            else if (i == 3){
                std::cout<<"Year of Exprience: "<<temp<<std::endl;
                std::cout<<std::endl;
                std::cout<<"     --- Movie Info ---\n ";
            }
            
            else if (i == 4){
                std::cout<<"Movie Title: "<<temp<<std::endl;
            }
            else if (i == 5){
                std::cout<<"Date: "<<temp;
            }
            else if (i == 6){
                std::cout<<" / "<<temp;
            }
            else if (i == 7){
                std::cout<<" / "<<temp<<std::endl;
            }
            else if (i == 8){
                std::cout<<"Violence Level: "<<temp<<std::endl;
            }
            else if (i == 9){
                std::cout<<"Rating: "<<temp<<std::endl;
            }
            else if (i == 10){
                std::cout<<"No of Fights: "<<temp<<std::endl;
            }
            else{
                std::cout<<"Stunts status: "<<temp<<std::endl;
                std::cout<<"----------------------------\n";
            }
            
            i++;

            if (i == 12) i = 0;            
        }   
        file.close();
}

void removeObj_actionMovieType(ActionMovie *&arr, int &size, std::string toRemove)
{
    int index = -1; 
    for (int i = 0; i < size; i++)
    {
        if (searchByTitle(toRemove, arr[i]))
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        std::cout<<"Movie Not Found Recheck your Input\n";
        return;
    }
    
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;

    ActionMovie* tempArr = new ActionMovie[size];

    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;


}
