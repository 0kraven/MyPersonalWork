#include<iostream>
using namespace std;

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while(left < right) {
        int mid = (right + left) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {9,8,7,6,5,17,4,3,2,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Element found at index: " <<binary_search(arr,size, 17) << endl;
}