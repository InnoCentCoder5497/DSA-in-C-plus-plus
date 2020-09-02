#include<iostream>
#define INF 99999
using namespace std;

const int l = 7;
const int n = l - 1;
int s[n][l];
void matrix_chain_order(int[], int);

void print_optimal_parens(int i, int j) {
    if(i == j){
        cout << "A" << i << ".";
    }
    else{
        cout << "(";
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j] + 1, j);
        cout << ")";
    }

}

int main() {
    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int length = 7;

    matrix_chain_order(p, length);

    return 0;
}

void matrix_chain_order(int p[], int length) {
    int n = length - 1;
    int m[length][length];

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    int l, i, j, k, q;
    for(l = 2; l <= n; l++){
        for(i = 1; i <= n - l + 1; i++){
            j = i + l - 1;
            m[i][j] = INF;
            for(k = i; k <= j - 1; k++){
                q = m[i][k] + m[k+1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "matrix M : " << endl;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "matrix S : " << endl;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Optimal parenthesization is : ";
    print_optimal_parens(1, 6);

}
