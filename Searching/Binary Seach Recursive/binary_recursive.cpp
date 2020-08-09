#include<iostream>
#include<cstdlib>
#define INF 9999
using namespace std;

void merge_sort(int[], int, int, int);
void merge(int[], int, int, int);
int binary_search(int[], int, int, int);

int main() {
    int arr[10];
    int key;
    int i;

    for(i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }

    cout << "Sorting array using merge sort" << endl;
    merge_sort(arr, 0, 9, 10);
    cout << "Sorting complete" << endl;

    cout << "Enter the key to search in Random array : ";
    cin >> key;

    i = binary_search(arr, key, 0, 9);

    if(i != -1)
        cout << "Key found at index : " << i << endl;
    else
        cout << "key not found!" << endl;


    return 0;
}

int binary_search(int arr[],int key, int start, int end){
    int mid;
    
    if(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == key){
            return mid + 1;
        }
        else if(arr[mid] < key){
            binary_search(arr, key, mid + 1, end);
        }
        else{
            binary_search(arr, key, start, mid - 1);
        }
    }
    else{
        return -1;
    }
}

void merge_sort(int num[], int p, int r, int size){
    int q;
    if(p < r){
        q = (p + r) / 2;
        merge_sort(num, p, q, size);
        merge_sort(num, q+1, r, size);
        merge(num, p, q, r);
        for(int i = 0; i < size; i++)
            cout << num[i] << "\t";
        cout << endl;
    }
}

void merge(int num[], int p, int q, int r){
    const int n1 = q - p + 1;
    const int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];
    int i, j, k;

    for(i = 1; i <= n1; i++)
        L[i - 1] = num[p + i - 1];

    for(j = 1; j <= n2; j++)
        R[j- 1] = num[q + j];

    L[n1] = INF;
    R[n2] = INF;

    i = 0;
    j = 0;

    for(k = p; k <= r; k++){
        if(L[i] <= R[j]){
            num[k] = L[i];
            i++;
        }
        else{
            num[k] = R[j];
            j++;
        }
    }
}