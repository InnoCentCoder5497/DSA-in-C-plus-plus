#include<iostream>
using namespace std;
void print_inversions(int[], int);

int main() {
    int arr[5] = {2, 3, 8, 6, 1};
    int i;

    cout << "Input Array : " << endl;
    for(i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << endl;

    print_inversions(arr, 5);

    return 0;
}

void print_inversions(int arr[], int size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                cout << "Inversion : (" << arr[i] << " , " << arr[j] << ")" << endl;
            }
        }
    }
}