#include<iostream>
using namespace std;

int quick(int arr[], int low, int high) { 
    int i = low-1;
    int pivot = arr[high];
    for(int j = low; j < high; ++j) {
        if(arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}
void quicksearch(int arr[],int low,int high) {
    if (low < high) {
        int pi = quick(arr, low, high);
        quicksearch(arr, low, pi-1);
        quicksearch(arr, pi+1, high);
    }    
}

