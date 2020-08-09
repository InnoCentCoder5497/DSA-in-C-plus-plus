#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void bubblesort(int arr[], int size);

int main() {
    int sizes[5] = {10, 100, 1000, 10000, 100000};
    int i;
    time_t start;

    for(int size: sizes){
        int arr[size];
        for(i = 0; i < size; i++){
            arr[i] = rand() % 100;
        }

        time(&start);
        bubblesort(arr, size);
        cout << "Sorted " << size << " elements in time : " << time(NULL) - start << " seconds" << endl;
    }
    return 0;
}

void bubblesort(int arr[], int size){
    int i, j;
    int temp;
    for(i = 0; i < size; i++){
        for(j = size - 1; j >= i + 1; j--){
            if(arr[j] < arr[j-1]){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}