#include<iostream>
using namespace std;
int Parent(int);
int Left(int);
int Right(int);
void max_heapify(int[], int, int, int);

int main() {
    int arr[10] = {16, 4, 10, 14, 7, 9, 3, 2, 4, 1};
    int heap_size = 10;
    int total_size = 10;

    for(int i = 0; i < heap_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    max_heapify(arr, 1, heap_size, total_size);
    
    for(int i = 0; i < heap_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

int Parent(int i){
    return i / 2;
}

int Left(int i){
    return 2 * i;
}

int Right(int i){
    return 2 * i + 1;
}

void max_heapify(int arr[], int i, int heap_size, int size){
    int l = Left(i);
    int r = Right(i);
    int temp;
    int largest;

    if(l <= heap_size && arr[l] > arr[i]){
        largest = l;
    }
    else{
        largest = i;
    }

    if(r <= heap_size && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, largest, heap_size, size);
    }
}