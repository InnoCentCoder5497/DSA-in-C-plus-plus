#include<iostream>
#include<ctime>
#define N_INF -9999
using namespace std;
int memoized_cut_rod(int[], int);
int memoized_cut_rod_aux(int[], int, int[]);


int main() {
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30,
                    24, 30, 20, 24, 30};
    time_t start;
    for(int i = 1; i <= 30; i++){
        time(&start);
        cout << "Best revenue which can be generated is : " << memoized_cut_rod(price, i) << " For length " << i << endl;
        cout << "Time to compute : " << time(NULL) - start << " s" << endl;
    }

    return 0;
}

int memoized_cut_rod(int p[], int n){
    int r[n + 1];
    for(int i = 0; i <= n; i++){
        r[i] = N_INF;
    }
    return memoized_cut_rod_aux(p, n, r);
}


int memoized_cut_rod_aux(int p[], int n, int r[]){
    int q;
    if(r[n] >= 0){
        return r[n];
    }
    if(n == 0){
        q = 0;
    }
    else{
        q = N_INF;
        for(int i = 1; i <= n; i++){
            q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
        }
    }
    r[n] = q;
    return q;
}