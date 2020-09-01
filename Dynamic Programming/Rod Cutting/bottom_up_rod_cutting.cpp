#include<iostream>
#include<ctime>
#define N_INF -9999
using namespace std;
int bottom_up_cut_rod(int[], int);


int main() {
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30,
                    24, 30, 20, 24, 30};
    time_t start;
    for(int i = 1; i <= 30; i++){
        time(&start);
        cout << "Best revenue which can be generated is : " << bottom_up_cut_rod(price, i) << " For length " << i << endl;
        cout << "Time to compute : " << time(NULL) - start << " s" << endl;
    }

    return 0;
}

int bottom_up_cut_rod(int p[], int n){
    int r[n + 1];
    int q;
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        q = N_INF;
        for(int i = 1; i <= j; i++){
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];
}