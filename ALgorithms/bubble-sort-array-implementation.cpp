#include<iostream>
using namespace std;

void bubble(int arr[], int size) {
    bool swapped = false;
    int j = size;
    while (j--) {
        swapped = false;
        for(int i = 0; i < j; i++){
            if(arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) return;
    }
}

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}