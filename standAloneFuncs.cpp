#include"standAloneFuncs.h"
#include<fstream>
#include<string>
#include"scifiMovie.h"

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

void removeObj_SicifiMovieType(SicifiMovie**& arr, int &size, std::string toRemove)
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
    }
    
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;

    SicifiMovie** tempArr = new SicifiMovie*[size];

    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;


}
// void removeObj_DirectorType(Movie**& arr, int &size, std::string toRemove)
// {
//     int index = -1; 
//     for (int i = 0; i < size; i++)
//     {
//         if (searchByTitle(toRemove, arr[i]))
//         {
//             index = i;
//             break;
//         }
//     }
//     if (index == -1)
//     {
//         std::cout<<"Movie Not Found Recheck your Input\n";
//     }
    
//     for (int i = index; i < size - 1; i++)
//     {
//         arr[i] = arr[i+1];
//     }
//     size--;

//     Movie** tempArr = new Movie*[size];

//     for (int i = 0; i < size; i++)
//     {
//         tempArr[i] = arr[i];
//     }

//     delete[] arr;
//     arr = tempArr;


// }
