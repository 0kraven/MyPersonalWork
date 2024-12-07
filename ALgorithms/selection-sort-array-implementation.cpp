#include<iostream>
using namespace std;    

void insertion_sort(int arr[], int size) {
    int key, j;
    for(int i = 0; i < size-1; i++) {
        int key = i;
        for(j = i+1; j < size; j ++) {
            if(arr[key] > arr[j]) key = j;
        }
        if (key != i) {
            int temp = arr[key];
            arr[key] = arr[i];
            arr[i] = temp;
        }
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