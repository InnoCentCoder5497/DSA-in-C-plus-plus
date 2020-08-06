#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void insertion_sort(int[], int);
void insertion_sort_decreasing(int[], int);

int main() {
    time_t start_time;
    int sizes[5] = {10, 100, 1000, 10000, 50000};
    
    for(int size : sizes){
        int arr[size];
        for(int i = 0; i < size; i++)
            arr[i] = rand();

        time(&start_time);
        insertion_sort(arr, size);
        cout << "Processing time for " << size << " elements : " << time(NULL) - start_time << " seconds" << endl;
    }

    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }

    cout << endl;

    insertion_sort_decreasing(arr, 10);

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    
    
/*
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
*/
    return 0;
}

void insertion_sort(int arr[], int size){
    int temp, i;
    for(int j = 1; j < size; j++){
        i = j - 1;
        temp = arr[j];
        while(i >= 0 && arr[i] > temp){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i + 1] = temp;
    }
}

void insertion_sort_decreasing(int arr[], int size){
    int temp, i;
    for(int j = 1; j < size; j++){
        i = j - 1;
        temp = arr[j];
        while(i >= 0 && arr[i] < temp){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i + 1] = temp;
    }
}