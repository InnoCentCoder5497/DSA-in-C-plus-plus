#include<iostream>
using namespace std;

template <typename T>
void print(T** arr, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
T** initialize_array(int row, int col, T defualt){
    T **arr;

    arr = new T*[row];
    for(int i = 0; i < row; i++){
        arr[i] = new T[col];
        for(int j = 0; j < col; j++){
            arr[i][j] = defualt;
        }
    }
    return arr;
}


int main() {
    char **arr;
    int **a;

    arr = initialize_array<char>(2, 2, 'a');
    a = initialize_array<int>(3, 3, 1);
    print(arr, 2, 2);
    print(a, 3, 3);

    return 0;
}
