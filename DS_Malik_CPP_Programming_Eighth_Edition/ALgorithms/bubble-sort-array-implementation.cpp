#include<iostream>
using namespace std;

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int j = sizeof(arr)/sizeof(arr[0]);
    while(j--) {
        for(int i = 0; i < j; i++) {
            if(arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    for(int i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) {
        cout << arr[i] << " ";
    }
}