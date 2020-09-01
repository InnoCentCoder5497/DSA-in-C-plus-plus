#include<iostream>
#define N_INF -9999
using namespace std;
void extended_bottom_up_cut_rod(int[], int, int[], int[]);
void print_cut_rod_solution(int[], int);


int main() {
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int i = 7;

    print_cut_rod_solution(price, i);
    
    return 0;
}

void print_cut_rod_solution(int p[], int n){
    int r[n+1], s[n+1];
    extended_bottom_up_cut_rod(p, n, r, s);
    cout << "Total revenue : " << r[n] << endl;
    while(n > 0){
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << endl;
}

void extended_bottom_up_cut_rod(int p[], int n, int r[], int s[]){
    int q;
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        q = N_INF;
        for(int i = 1; i <= j; i++){
            if(q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}