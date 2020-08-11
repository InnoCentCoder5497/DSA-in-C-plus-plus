#include<iostream>
using namespace std;
int modified_merge_sort(int[], int, int);
int modified_merge(int[], int, int, int);

int main() {
    int arr[5] = {2, 3, 8, 6, 1};
    int x;

    x = modified_merge_sort(arr, 0, 4);

    cout << x;
    return 0;
}

int modified_merge_sort(int arr[], int p, int r) {
    int q;
    int left;
    int right;
    int inv;
    if(p < r){
        q = (p + r) / 2;
        left = modified_merge_sort(arr, p, q);
        right = modified_merge_sort(arr, q+1, r);
        inv = modified_merge(arr, p, q, r) + left + right;
        return inv;
    }
    return 0;
}

int modified_merge(int arr[], int p, int q, int r){
    int inv = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    int i, j, k;

    for(i = 1; i < n1 + 1; i++)
        L[i] = arr[p + i - 1];

    for(j = 1; j < n2 + 1; j++)
        R[j] = arr[q + j];

    i = 1; 
    j = 1;
    k = p;

    while(i != n1 + 1 && j != n2 + 1){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            inv += j;
            cout << "Inv : (" << L[i] << " , " << R[j] << ")" << endl;
            j++;
        }
        k++;
    }

    if(i == n1 + 1){
        for(int m = j; m < n2 + 1; m++){
            arr[k] = R[m];
            k++;
        }
    }

    if(j == n2 + 1){
        for(int m = i; m < n1 + 1; m++){
            arr[k] = L[m];
            inv = inv + n2 + 1;
            cout << "Inv : (" << L[m] << " , " << R[j - 1] << ")" << endl;
            k++;
        }
    }
    return inv;
}