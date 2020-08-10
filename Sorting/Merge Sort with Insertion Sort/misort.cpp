#include<iostream>
#include<cstdlib>
#include<ctime>
#define INF 9999
using namespace std;

void insertion_k_sort(int[], int, int, int);
void merge(int[], int, int, int);
void merge_insertion_sort(int[], int, int, int);
void mergesort(int[], int, int);
void insertion_sort(int[], int);

int main() {
    int size = 100000;
    int k = 20;
    int i;
    time_t start;
    for(int j = 0; j < 3; j++){
        int arr[size];
        for(i = 0; i < size; i++){
            arr[i] = rand() % 10;
        }

        if(j == 0){
            time(&start);
            insertion_sort(arr, size);
            cout << "Sorting " << size << " elements with Insertion sort : " << time(NULL) - start << " seconds" << endl;
        }
        else if(j == 1){
            time(&start);
            mergesort(arr, 0, size - 1);
            cout << "Sorting " << size << " elements with Merge sort : " << time(NULL) - start << " seconds" << endl;
        }
        else{
            time(&start);
            merge_insertion_sort(arr, 0, size - 1, k);
            cout << "Sorting " << size << " elements with Merge and Insertion sort Combined : " << time(NULL) - start << " seconds" << endl;
        }
    }
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

void insertion_k_sort(int arr[], int size, int start, int end){
    int temp, i;
    for(int j = start; j <= end; j++){
        i = j - 1;
        temp = arr[j];
        while(i >= 0 && arr[i] > temp){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i + 1] = temp;
    }
}

void merge_insertion_sort(int arr[], int p, int r, int k){
    int q;
    if(p < r){
        q = (p + r) / 2;
        merge_insertion_sort(arr, p, q, k);
        merge_insertion_sort(arr, q + 1, r, k);
        if((r - p) <= k)
            insertion_k_sort(arr, r - p, p, r);
        else
            merge(arr, p, q, r);
    }
}

void mergesort(int arr[], int p, int r){
    int q;
    if(p < r){
        q = (p + r) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
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