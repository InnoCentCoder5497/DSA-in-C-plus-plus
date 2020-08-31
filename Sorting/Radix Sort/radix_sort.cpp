#include<iostream>
using namespace std;
void counting_sort(int[], int[], int, int, int[], int[]);
void radix_sort(int[], int, int, int);
void copy_array(int[], int[], int);

int main() {
    int arr[7] = {329, 457, 657, 839, 436, 720, 355};
    int max_element = 9;
    int size = 7;

    cout << "input Array : " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    radix_sort(arr, 3, max_element, size);

    cout << "Sorted Array : " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void copy_array(int a[], int b[], int s){
    for(int i = 0; i < s; i++){
        a[i] = b[i];
    }
}

void radix_sort(int arr[], int d, int k, int size){
    int temp[size];
    copy_array(temp, arr, size);
    int B[size];
    int digits[size];
    
    for(int i = 0; i < d; i++){
        for(int j = 0; j < size; j++){
            digits[j] = temp[j] % 10;
        }
        cout << "At " << i + 1 << " digit ";
        counting_sort(digits, B, k, size, arr, temp);
        copy_array(arr, B, size);
    }
    
}

void counting_sort(int digits[], int B[], int k, int size, int arr[], int temp[]){
    int C[k + 1];
    int i;
    int t[size];
    for(i = 0; i < k + 1; i++){
        C[i] = 0;
    }

    // Count of element i
    for(i = 0; i < size; i++){
        C[digits[i]] = C[digits[i]] + 1;
    }
    
    cout << "Count of each Element : " << endl;
    for(i = 0; i < k + 1; i++){
        cout << C[i] << " ";
    }
    cout << endl;

    // Count of elements less than or equal to i
    for(i = 1; i < k + 1; i++){
        C[i] = C[i] + C[i - 1];
    }
    copy_array(t, temp, size);

    for(i = size - 1; i >= 0; i--){
        B[C[digits[i]] - 1] = arr[i];
        temp[C[digits[i]] - 1] = t[i] / 10;
        C[digits[i]] = C[digits[i]] - 1;
    }
}