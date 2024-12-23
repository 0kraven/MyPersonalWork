#include<iostream>
using namespace std;

void insertion(int arr[] = {0}, int size = 10) {
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while(j-- && arr[j] > key)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    insertion(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << " ";
    }
}
