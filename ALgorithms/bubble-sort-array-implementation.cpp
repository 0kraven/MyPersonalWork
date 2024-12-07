#include<iostream>
using namespace std;

void bubble_sort(int arr[], int size) {
    int j = size;
    bool swapped;
    while(j--) {
        swapped = false;
        for(int i = 0; i < j; i++) {
            if(arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main() {
    int arr[] = {9,8,7,6,5,56,3,2,3,5,4,9,5,4,57,9,0,7,8,34,3,2,1,0};
    bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    
}
// Adding the swapped flag improves the best-case time complexity of Bubble Sort to O(n). This is beneficial when the array is already sorted or nearly sorted.
// The outer loop still iterates up to size - 1 times in the worst case, maintaining the overall worst-case time complexity of O(n²).