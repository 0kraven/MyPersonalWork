#include<iostream>
using namespace std;

void selection_sort(int *arr, int size) {

    for(int i = 0; i < size- 1; i++) {
        int  key = i;
        for(int j = i+1;j < size; j++) {
            key = (arr[key] > arr[j]) ? j : key;
        }
        int temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
    }
    
}
int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    const int size = 10;
    selection_sort(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}