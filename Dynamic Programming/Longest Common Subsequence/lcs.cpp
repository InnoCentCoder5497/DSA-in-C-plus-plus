#include<iostream>
using namespace std;

void lcs_length(int**, char**, char[], char[], int, int);
void print_lcs(char**, char[], int, int);

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
    char X[7] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char Y[6] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int m = 7;
    int n = 6;
    int **c;
    char **b;

    c = initialize_array<int>(m + 1, n + 1, 0);
    b = initialize_array<char>(m + 1, n + 1, 'x');

    lcs_length(c, b, X, Y, m, n);

    cout << "Count Matrix : " << endl;
    print(c, m + 1, n + 1);
    cout << "Direction Matrix : " << endl;
    print(b, m + 1, n + 1);
    cout << "LCS is : ";
    print_lcs(b, X, m, n);

    return 0;
}

void print_lcs(char **b, char X[], int i, int j){
    if(i == 0 || j == 0){
        return;
    }
    else{
        if(b[i][j] == '\\'){
            print_lcs(b, X, i - 1, j - 1);
            cout << X[i - 1] << " ";
        }
        else if(b[i][j] == '|'){
            print_lcs(b, X, i - 1, j);
        }
        else{
            print_lcs(b, X, i, j - 1);
        }
    }
}

void lcs_length(int **c, char **b, char X[], char Y[], int m, int n){
    int i;
    int j;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(X[i - 1] == Y[j - 1]){
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            }
            else if(c[i - 1][j] >= c[i][j - 1]){
                c[i][j] = c[i - 1][j];
                b[i][j] = '|';
            }
            else{
                c[i][j] = c[i][j - 1];
                b[i][j] = '-';
            }
        }
    }
}