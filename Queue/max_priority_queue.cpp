#include<iostream>
#define INF -9999
using namespace std;
int Parent(int);
int Left(int);
int Right(int);
void max_heapify(int[], int, int);
void build_max_heap(int[], int);

void print_queue(int[], int);
void max_heap_insert(int[], int, int*, int);
void heap_increase_key(int[], int, int);
int maximum(int[]);
int heap_extract_max(int[], int*);

int main() {
    int heap_size;
    cout << "Enter Max Heap size : ";
    cin >> heap_size;
    int arr[heap_size + 1];
    int current_size = 0;
    int i;
    
    max_heap_insert(arr, 10, &current_size, heap_size);
    print_queue(arr, current_size);
    max_heap_insert(arr, 30, &current_size, heap_size);
    max_heap_insert(arr, 20, &current_size, heap_size);
    print_queue(arr, current_size);
    max_heap_insert(arr, 5, &current_size, heap_size);
    max_heap_insert(arr, 1, &current_size, heap_size);
    cout << "Maximum priority element : " << maximum(arr) << endl;
    cout << "Extracting Maximum priority element : " << heap_extract_max(arr, &current_size) << endl;
    cout << current_size << endl;
    print_queue(arr, current_size);
    
    return 0;
}

void print_queue(int arr[], int size){
    for(int i = 1; i <= size; i++){
        cout << arr[i] << " ";;
    }
    cout << endl;
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

int maximum(int arr[]){
    return arr[1];
}

int heap_extract_max(int arr[], int *cur_size){
    if(*cur_size < 1){
        cout << "Heap Underflow" << endl;
    }
    else{
        int max = arr[1];
        arr[1] = arr[*cur_size];
        *cur_size = *cur_size - 1;
        max_heapify(arr, 1, *cur_size);
        return max;
    }
    return INF;
}

void max_heap_insert(int arr[], int key, int* cur_size, int size){
    if(*cur_size + 1 > size){
        cout << "Heap Overflow" << endl;
        return;
    }
    *cur_size = *cur_size + 1;
    arr[*cur_size] = INF;
    heap_increase_key(arr, *cur_size, key);
}

void heap_increase_key(int arr[], int i, int key){
    if(key < arr[i]){
        cout << "New key smaller than current value";
        return;
    }
    else{
        int temp;
        arr[i] = key;
        while(i > 1 && arr[Parent(i)] < arr[i]){
            temp = arr[i];
            arr[i] = arr[Parent(i)];
            arr[Parent(i)] = temp;

            i = Parent(i);
        }
    }
}

void build_max_heap(int arr[], int size){
    int i = size/ 2;
    while(i > 0){
        max_heapify(arr, i, size);
        i--;
    }
}

void max_heapify(int arr[], int i, int heap_size){
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
        max_heapify(arr, largest, heap_size);
    }
}