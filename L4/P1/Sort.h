#include <ostream>

class Sort
{
    // add data members
    unsigned size;
    int* arr;
public:
    Sort(unsigned size, int min, int max); //1
    Sort(unsigned size, int *arr) : size(size), arr(arr){} //2
//    Sort(unsigned size, int arr[]); //3
    Sort(unsigned size, ...); //4
    Sort(const char* arrValues); //5
    // add constuctors
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};