#include<iostream>
#include<cstdlib>
#include<ctime>
#define INF 99999
using namespace std;

void merge(int[], int, int, int);
void mergesort(int[], int, int);

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
        mergesort(arr, 0, size);
        cout << "Processed " << size << " elements in " << time(NULL) - start << " s" << endl;

    }

    return 0;
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