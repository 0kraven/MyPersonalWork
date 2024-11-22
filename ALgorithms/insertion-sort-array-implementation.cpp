#include<iostream>
using namespace std;    

void insertion_sort(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    const int size = 10;
    int arr[] = {10, 12, 8, 6, 3, 2, 1, 0, 13, 14};
    
    insertion_sort(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}