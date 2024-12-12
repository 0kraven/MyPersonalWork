#include<iostream>
using namespace std;

void radix_helper(int arr[], int size, int exp) {
    int count[10] = {0}, output[size] = {0};

    for(int i = 0; i < size; i++)
        count[(arr[i]/exp)%10]++;
    
    for(int i = 1; i < 10; i++) 
        count[i] += count[i-1];

    for(int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for(int i = 0; i < size; i++) {
        arr[i] = output[i];  // Copy the output array to input array
    }

}

void radix(int arr[], int size) {

    int max = arr[0];

    for(int i=0; i < size; i++)
        if(arr[i] > max) 
            max = arr[i];
    
    for(int exp = 1; max / exp > 0; exp *= 10) {
        radix_helper(arr, size, exp);
    }
}


int main() {
    int arr[] = {10, 23, 34, 45464564 ,4456456,456,4645,646,4, 64,5645,645, 456, 5678, 2114754};
    radix(arr, sizeof(arr)/sizeof(arr[0]));

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        cout << arr[i] << " ";

    return 0;
}