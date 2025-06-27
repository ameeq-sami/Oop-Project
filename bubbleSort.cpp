#include "bubbleSort.h"
using namespace std;

// void bubbleSort(Movie *arry, int size)
// {
//     int arr[size];
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = i;
//     }
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size - 1; j++)
//         {
//             if (arry[j].getMovieYear() > arry[j+1].getMovieYear())
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
            
//         }
        
//     }
    
// }

#include "bubbleSort.h"
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Movie *arry, int size, int* indexArray)
{

    for (int i = 0; i < size; i++)
    {
        indexArray[i] = i;
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arry[indexArray[j]].getMovieYear() < arry[indexArray[j + 1]].getMovieYear())
            {
                swap(indexArray[j], indexArray[j + 1]);
            }
        }
    }
    
}
