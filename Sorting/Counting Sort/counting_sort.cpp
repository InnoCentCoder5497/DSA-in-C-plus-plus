#include<iostream>
using namespace std;
void counting_sort(int[], int[], int, int);


int main() {
    int arr[10] = {2, 5, 3, 0, 8, 3, 9, 3, 1, 4};
    int max_element = 10;
    int size = 10;
    int B[size];

    cout << "input Array : " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    counting_sort(arr, B, max_element, size);

    cout << "Sorted Array : " << endl;
    for(int i = 0; i < size; i++){
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}

void counting_sort(int arr[], int B[], int k, int size){
    int C[k + 1];
    int i;
    for(i = 0; i < k + 1; i++){
        C[i] = 0;
    }

    // Count of element i
    for(i = 0; i < size; i++){
        C[arr[i]] = C[arr[i]] + 1;
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

    for(i = size; i >= 0; i--){
        B[C[arr[i]] - 1] = arr[i];
        C[arr[i]] = C[arr[i]] - 1;
    }
}