#include "Sort.h"
#include <cstring>
#include <cstdarg>
#include <iostream>

Sort::Sort(unsigned int size, int min, int max) { //1
    this->size = size;
    this->arr = new int[size];
    for(int i = 0; i < size; i++) {
        this->arr[i] = rand()%max+min;
    }
}

Sort::Sort(unsigned int size, ...) { //4
    this->size = size;
    this->arr = new int[size];
    va_list list;
    va_start(list, size);
    for(int i = 0; i < size; i++) {
        this->arr[i] = va_arg(list, int);
    }
    va_end(list);
}

Sort::Sort(const char *arrValues) { //5
    unsigned count = 1;
    for(int i = 0; i < strlen(arrValues); i++) {
        if(arrValues[i] == ',') {
            count++;
        }
    }
    this->size = count;
    this->arr = new int[count];

    char *valCopy = new char[(strlen(arrValues)+1) * sizeof(char)];
    strcpy(valCopy, arrValues);

    char *p = strtok(valCopy, ",");
    int i = 0;
    while(p) {
        int number = atoi(p);
        this->arr[i++] = number;
        p = strtok(nullptr, ",");
    }
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < size; i++) {
        int k = arr[i];
        int j = i-1;
        while (j >= 0 && (ascendent == true ? arr[j] > k : arr[j] < k)) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = k;
    }
}

int partition (int arr[], int left, int right, int ascendent) {
    int p = arr[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if ((ascendent == true ? arr[j] < p : arr[j] > p)) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[right]);
    return (i + 1);
}

void quickSort(int arr[], int left, int right, int ascendent) {
    if (left < right) {
        int p = partition(arr, left, right, ascendent);
        quickSort(arr, left, p - 1, ascendent);
        quickSort(arr, p + 1, right, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    quickSort(this->arr, 0, this->size-1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < this->size-1; i++)
        for (int j = 0; j < this->size-i-1; j++)
            if ((ascendent == true ? arr[j] > arr[j+1] : arr[j] < arr[j+1]))
                std::swap(arr[j], arr[j+1]);
}

void Sort::Print() {
    for(int i = 0; i < this->size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int Sort::GetElementsCount() {
    return this->size;
}

int Sort::GetElementFromIndex(int index) {
    return this->arr[index];
}




