#include<iostream>
#include<cstdlib>
using namespace std;
void selection_sort(int[], int);

int main() {
    int arr[10];
    int i;
    for(i = 0; i < 10; i++){
        arr[i] = rand() % 10;
    }

    cout << "Input :" << endl;
    for(i = 0; i < 10; i++)
        cout << arr[i] << " ";

    cout << endl;

    selection_sort(arr, 10);

    cout << "Output : " << endl;
    for(i = 0; i < 10; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}

void selection_sort(int arr[], int size){
    int smallest, smallest_idx;
    int i, j, temp;

    for(i = 0; i < size - 1; i++){
        smallest = arr[i];
        smallest_idx = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < smallest){
                smallest_idx = j;
                smallest = arr[j];
            }
        }
        temp = arr[i];
        arr[i] = smallest;
        arr[smallest_idx] = temp; 
    }
}