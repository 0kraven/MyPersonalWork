#include<iostream>
using namespace std;

void insertion_sort(int arr[], int size) {
    for(int i = 1; i < size; i++) { 
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }    
}

int main(){
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}