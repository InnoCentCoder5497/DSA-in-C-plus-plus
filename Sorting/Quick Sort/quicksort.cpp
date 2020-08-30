#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
int sizes[5] = {10, 100, 1000, 10000, 100000};
    int i;
    time_t start;

    for(int size : sizes){
        int arr[size];

        for(i = 0; i < size; i++){
            arr[i] = rand() % 100;
        }

        time(&start);
        quicksort(arr, 0, size - 1);
        cout << "Processed " << size << " elements in " << time(NULL) - start << " s" << endl;
    }
    return 0;
}

int partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p - 1;
    int j;
    int temp;
    for(j = p; j <= r - 1; j++){
        if(arr[j] <= x){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void quicksort(int arr[], int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);   
    }
}