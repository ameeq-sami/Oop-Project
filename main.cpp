#include <iostream>
#include "scifiMovie.h"
#include "director.h"
#include "animationMovie.h"
#include "actionMovie.h"
#include "fileHandlingFunc.h"
#include"bubbleSort.h"

using namespace std;

main()
{
    string d_File = "director.txt";
    string s_File = "sicifiMovie.txt";
    string a_File = "animationMovie.txt";
    string ac_File = "actionMovie.txt";
    int director_size = fileSize(d_File) / 4;
    int sicifiMovie_size = fileSize(s_File) / 12;
    int animationMovie_size = fileSize(a_File) / 12;
    int actionMovie_size = fileSize(ac_File) / 12;

    Director *directors = new Director[director_size];
    // directors[0] = Director("James", "Cameron", 25, "USA");
    // directors[1] = Director("Christopher", "Nolan", 22, "UK");
    // directors[2] = Director("Greta", "Gerwig", 10, "USA");
    // directors[3] = Director("Hayao", "Miyazaki", 40, "Japan");
    // directors[4] = Director("Zoya", "Akhtar", 15, "India");

    SicifiMovie *movies = new SicifiMovie[sicifiMovie_size];
    // movies[0] = SicifiMovie("James", "Cameron", 25, "USA", 162, "Dec", 2020, "Avatar", 9, 13, 2, 0);
    // movies[1] = SicifiMovie("Christopher", "Nolan", 22, "UK", 169, "Nov", 2019, "Interstellar", 8, 13, 1, 0);
    // movies[2] = SicifiMovie("Greta", "Gerwig", 10, "USA", 130, "Jul", 2021, "Barbie Galaxy", 7, 7, 3, 1);
    // movies[3] = SicifiMovie("Hayao", "Miyazaki", 40, "Japan", 120, "Aug", 2018, "Spirited Cosmos", 9, 5, 2, 1);
    // movies[4] = SicifiMovie("Zoya", "Akhtar", 15, "India", 140, "Oct", 2022, "Future Tides", 8, 18, 1, 0);

    AnimationMovie *animMovies = new AnimationMovie[animationMovie_size];
    // animMovies[0] = AnimationMovie("James", "Cameron", 25, "USA", 15, "June", 2020, "Toy Universe", 9, 2, 5, false);
    // animMovies[1] = AnimationMovie("Christopher", "Nolan", 22, "UK", 10, "July", 2019, "Castle in the Stars", 8, 3, 18, true);
    // animMovies[2] = AnimationMovie("Greta", "Gerwig", 10, "USA", 25, "December", 2021, "Frozen Planet", 7, 1, 7, false);
    // animMovies[3] = AnimationMovie("Hayao", "Miyazaki", 40, "Japan", 5, "March", 2018, "Inside Reality", 8, 2, 18, true);
    // animMovies[4] = AnimationMovie("Zoya", "Akhtar", 15, "India", 20, "October", 2022, "Animated Dreams", 6, 3, 7, true);

    ActionMovie *actionMovies = new ActionMovie[actionMovie_size];
    // actionMovies[0] = ActionMovie("James", "Cameron", 25, "USA", 15, "June", 2020, "Wick Reloaded", 9, "M", 10, true);
    // actionMovies[1] = ActionMovie("Christopher", "Nolan", 22, "UK", 10, "July", 2019, "Mission Thunder", 8, "U", 6, true);
    // actionMovies[2] = ActionMovie("Greta", "Gerwig", 10, "USA", 25, "December", 2021, "Resistance Rise", 7, "D", 8, false);
    // actionMovies[3] = ActionMovie("Hayao", "Miyazaki", 40, "Japan", 5, "March", 2018, "Fast Reboot", 9, "U", 12, true);
    // actionMovies[4] = ActionMovie("Zoya", "Akhtar", 15, "India", 20, "October", 2022, "The Shadow Code", 8, "M", 4, false);

    // sicifiMovie_ArrayToFile(s_File,movies, 5);
    // animationMovie_ArrayToFile(a_File, animMovies,5);
    // actionMovie_ArrayToFile(ac_File, actionMovies,5);
    // directorArrayToFile(d_File, directors, 5);

    sicifiMovie_FileToArray(s_File, movies, sicifiMovie_size);
    animationMovie_FileToArray(a_File, animMovies, animationMovie_size);
    actionMovie_FileToArray(ac_File, actionMovies, actionMovie_size);
    directorFileToArray(d_File, directors, director_size);

    int main_choice = -1;
    int sub_choice = -1;
    char sub_sub_choice;
    cout << "Press 1 to Add new movie\nPress 2 to Display\nPress 3 for Search Menu\nPress 4 to Remove Movie\nPres 5 for bubble sort"<<endl;
    cin >> main_choice;
    if (main_choice == 1)
    {
        cout << "\tPress 1 for SICIFI MOVIE\n\tPress 2 for ANIMATION MOVIE\n\tPress 3 for ACTION MOVIE" << endl
             << "\t";
        cin >> sub_choice;
        int temp;
        cout << "How much movies you want to enter: ";
        cin >> temp;
        cout << endl;
        directorFileDisplay(d_File);
        cout << endl;
        while (!(sub_choice >= 1 && sub_choice <= 3))
        {
            cout << "Enter Valid Choice" << endl;
            cin >> sub_choice;
        }
        if (sub_choice == 1)
        {
            for (int i = 0; i < temp; i++)
            {
                sicifiMovie_FileAppend(s_File, directors, director_size);
                sicifiMovie_FileToArray(s_File, movies, sicifiMovie_size);
            }
        }
        else if (sub_choice == 2)
        {
            for (int i = 0; i < temp; i++)
            {
                animationMovie_FileAppend(a_File, directors, director_size);
                animationMovie_FileToArray(a_File, animMovies, animationMovie_size);
            }
        }
        else if (sub_choice == 3)
        {
            for (int i = 0; i < temp; i++)
            {

                actionMovie_FileAppend(ac_File, directors, director_size);
                actionMovie_FileToArray(ac_File, actionMovies, actionMovie_size);
            }
        }
    }
    else if (main_choice == 2)
    {
        cout << "Press a to display all movies\n";
        cout << "Press b to display scifi movies\n";
        cout << "Press c to display animation movies\n";
        cout << "Press d to display action movies\n";
        cout << "Press e to display directors\n";
        cout << "Press f to display movies by specific director\n";
        cout << "Enter your choice: ";
        cin >> sub_sub_choice;

        if (sub_sub_choice == 'a')
        {
            cout << "Displaying all movies...\n";
            cout << "--- Sicifi Movives ---\n";
            sicifiMovie_FileDisplay(s_File);
            cout << endl;
            cout << "--- Animation Movives ---\n";
            animationMovie_FileDisplay(a_File);
            cout << endl;
            cout << "--- Action Movives ---\n";
            actionMovie_FileDisplay(ac_File);
            cout << endl;
        }
        else if (sub_sub_choice == 'b')
        {
            cout << "Displaying Sci-Fi movies...\n";
            cout << "--- Sicifi Movives ---\n";
            sicifiMovie_FileDisplay(s_File);
            cout << endl;
        }
        else if (sub_sub_choice == 'c')
        {
            cout << "Displaying Animation movies...\n";
            cout << "--- Animation Movives ---\n";
            animationMovie_FileDisplay(a_File);
            cout << endl;
        }
        else if (sub_sub_choice == 'd')
        {
            cout << "Displaying Action movies...\n";
            cout << "--- Action Movives ---\n";
            actionMovie_FileDisplay(ac_File);
            cout << endl;
        }
        else if (sub_sub_choice == 'e')
        {
            cout << "Displaying all directors...\n";
            directorFileDisplay(d_File);
            cout << endl;
        }
        else if (sub_sub_choice == 'f')
        {
            string directorFName;
            string directorLName;
            cout << "Enter director's first name: ";
            cin.ignore();
            cin >> directorFName;
            cout << "Enter director's Last name: ";
            cin.ignore();
            cin >> directorLName;
            cout << "Displaying movies by " << directorFName << " " << directorLName << "...\n"
                 << endl;
            for (int i = 0; i < sicifiMovie_size; i++)
            {
                if (searchByDrector(directorFName, directorLName, movies[i]))
                {
                    cout << movies[i] << endl;
                }
            }
            for (int i = 0; i < animationMovie_size; i++)
            {
                if (searchByDrector(directorFName, directorLName, animMovies[i]))
                {
                    cout << animMovies[i] << endl;
                }
            }
            for (int i = 0; i < actionMovie_size; i++)
            {
                if (searchByDrector(directorFName, directorLName, actionMovies[i]))
                {
                    cout << actionMovies[i] << endl;
                }
            }
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
    else if (main_choice == 3)
    {
        cout << "\n--- Search Menu ---\n";
        cout << "Press a to search and display a movie (all movies) by year\n";
        cout << "Press b to search and display a movie (all movies) by title\n";
        cout << "Press c to search and display a movie (all movies) by rating\n";
        cout << "Press d to search and display a movie (all movies) by title and ranking\n";
        cout << "Press e to search and display a movie (all movies) by Score\n";
        cout << "Enter your choice: ";
        cin >> sub_sub_choice;
        if (sub_sub_choice == 'a')
        {
            int temp;
            cout << "Enter Year: .\n";
            cin >> temp;
            for (int i = 0; i < sicifiMovie_size; i++)
            {
                if (searchByYear(temp, movies[i]))
                {
                    cout << movies[i] << endl;
                }
            }
            for (int i = 0; i < animationMovie_size; i++)
            {
                if (searchByYear(temp, animMovies[i]))
                {
                    cout << animMovies[i] << endl;
                }
            }
            for (int i = 0; i < actionMovie_size; i++)
            {
                if (searchByYear(temp, actionMovies[i]))
                {
                    cout << actionMovies[i] << endl;
                }
            }
            
        }
        else if (sub_sub_choice == 'b')
        {
            string temp;
            cout << "Enter Title.\n";
            cin.ignore();
            getline(cin, temp);
            for (int i = 0; i < sicifiMovie_size; i++)
            {
                if (searchByTitle(temp, movies[i]))
                {
                    cout << movies[i] << endl;
                }
            }
            for (int i = 0; i < animationMovie_size; i++)
            {
                if (searchByTitle(temp, animMovies[i]))
                {
                    cout << animMovies[i] << endl;
                }
            }
            for (int i = 0; i < actionMovie_size; i++)
            {
                if (searchByTitle(temp, actionMovies[i]))
                {
                    cout << actionMovies[i] << endl;
                }
            }
        }
        else if (sub_sub_choice == 'c')
        {
            int temp;
            cout << "Enter Rating.\n";
            cin >> temp;
            for (int i = 0; i < sicifiMovie_size; i++)
            {
                if (searchByRating(temp, movies[i]))
                {
                    cout << movies[i] << endl;
                }
            }
            for (int i = 0; i < animationMovie_size; i++)
            {
                if (searchByRating(temp, animMovies[i]))
                {
                    cout << animMovies[i] << endl;
                }
            }
            for (int i = 0; i < actionMovie_size; i++)
            {
                if (searchByRating(temp, actionMovies[i]))
                {
                    cout << actionMovies[i] << endl;
                }
            }
        }
        else if (sub_sub_choice == 'd')
        {
            string tempS;
            int tempI;
            cout << "Enter title.\n";
            cin.ignore();
            getline(cin,tempS);
            cout << "Enter Ranking.\n";
            cin>>tempI;
            for (int i = 0; i < sicifiMovie_size; i++)
            {
                if (searchByTitleAndRating(tempS,tempI, movies[i]))
                {
                    cout << movies[i] << endl;
                }
            }
            for (int i = 0; i < animationMovie_size; i++)
            {
                if (searchByTitleAndRating(tempS,tempI, animMovies[i]))
                {
                    cout << animMovies[i] << endl;
                }
            }
            for (int i = 0; i < actionMovie_size; i++)
            {
                if (searchByTitleAndRating(tempS,tempI, actionMovies[i]))
                {
                    cout << actionMovies[i] << endl;
                }
            }
        }
        else if (sub_sub_choice == 'e')
        {
            int temp;
            cout << "Enter score.\n";
            cin >> temp;
            for (int i = 0; i < sicifiMovie_size; i++)
            {
                if (movies[i].calculateScore() >= temp)
                {
                    cout << movies[i] << endl;
                }
            }
            for (int i = 0; i < animationMovie_size; i++)
            {
                if (animMovies[i].calculateScore() >= temp)
                {
                    cout << animMovies[i] << endl;
                }
            }
            for (int i = 0; i < actionMovie_size; i++)
            {
                if (actionMovies[i].calculateScore() >= temp)
                {
                    cout << actionMovies[i] << endl;
                }
            }
        }
        
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    else if (main_choice == 4)
    {
        sicifiMovie_FileToArray(s_File, movies, sicifiMovie_size);
        animationMovie_FileToArray(a_File, animMovies, animationMovie_size);
        actionMovie_FileToArray(ac_File, actionMovies, actionMovie_size);
        directorFileToArray(d_File, directors, director_size);

        string temp;
        cout<<"Enter Titile to Remove: ";
        cin.ignore();
        getline(cin,temp);
        removeObj_SicifiMovieType(movies, sicifiMovie_size, temp);
        removeObj_AnimationMovieType(animMovies, actionMovie_size, temp);
        removeObj_actionMovieType(actionMovies, animationMovie_size, temp);
        
        sicifiMovie_ArrayToFile(s_File, movies, sicifiMovie_size);
        animationMovie_ArrayToFile(a_File, animMovies, animationMovie_size);
        actionMovie_ArrayToFile(ac_File, actionMovies, actionMovie_size);
        sicifiMovie_FileDisplay(s_File);
        animationMovie_FileDisplay(a_File);
        actionMovie_FileDisplay(ac_File);
        
    }
    else if (main_choice == 5)
    {
        int indexArray[sicifiMovie_size];
        bubbleSort(movies, sicifiMovie_size, indexArray);
        cout << "Movies sorted by year:\n";
    for (int i = 0; i < sicifiMovie_size ; i++)
    {
        cout <<movies[indexArray[i]]<<endl;
            
    }
        
       
        
        
        

    }
    

    delete movies;
    delete animMovies;
    delete actionMovies;
    delete directors;
}