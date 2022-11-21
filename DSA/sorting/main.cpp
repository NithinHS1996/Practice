/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
void selectionSorting(vector<int> array)
{
    int lowest = 0xFFFF;
    int lowIndex = 0;
    for(int i = 0; i < array.size() ; i++)
    {
        for(int j = i; j < array.size() ; j++)
        {
            if(array[j] < lowest){
                lowest = array[j];
                lowIndex = j;
            }
        }
        if(lowIndex){
            array[lowIndex] = array[i];
            array[i] = lowest;
        }
        lowIndex = 0;
        lowest = 0xFFFF;
    }
    cout << array[0]  << array[1]  << array[2]  << array[3]  << array[4] ;
}

bool bubbleSorting(vector<int> &array)
{   
    int temp;
    for(int i = array.size(); i != 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if((j+1) < i and (array[j] > array[j+1]))
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    return true;
}

void insertionSorting(vector<int> &array)
{
    int temp = 0;
    for(int i = 0; i < array.size() ; i++)
    {
        if((i+1) < array.size() and (array[i] > array[i+1])){
            for(int j = i+1; j !=0 ; j--){
                if(array[j] < array[j-1]){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                }
                
            }
        }
        
    }
}

void mergeSorting(vector<int> &array)
{
    
}

int main()
{
    int lowest = 0xFFFF;
    int lowIndex = 0;
    vector<int> array = {3,4,1,2,5};
 
    insertionSorting(array);
cout << array[0]  << array[1]  << array[2]  << array[3]  << array[4] ;
    return 0;
}

