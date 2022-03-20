#include <iostream>
#include "Sort.h"

void useSortExample() {
    int v[] = {9, 8, 4, 2, 5, 18, 22, 0, 1};
    char s[] = "9,8,4,2,5,18,22,0,1";

    Sort v1(5, 5, 100);
    Sort v2(9, v);
    Sort v4(9, 9, 8, 4, 2, 5, 18, 22, 0, 1);
    Sort v5(s);

    v1.QuickSort(true);
    v2.InsertSort(true);
    v4.InsertSort(true);
    v5.BubbleSort(true);
    v1.Print();
    v2.Print();
    v4.Print();
    v5.Print();

    v1.InsertSort();
    v2.BubbleSort();
    v4.QuickSort();
    v5.InsertSort();
    v1.Print();
    v2.Print();
    v4.Print();
    v5.Print();

}

int main() {
    useSortExample();
    return 0;
}
