#include<iostream>
#include<ctime>
#define N_INF -9999
using namespace std;
int rod_cutting(int[], int);

int main() {
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30, 20, 24, 30,
                    24, 30, 20, 24, 30};
    time_t start;
    for(int i = 1; i <= 30; i++){
        time(&start);
        cout << "Best revenue which can be generated is : " << rod_cutting(price, i) << " For length " << i << endl;
        cout << "Time to compute : " << time(NULL) - start << " s" << endl;
    }
    return 0;
}

int rod_cutting(int p[], int n){
    int q = N_INF;
    if(n == 0){
        return 0;
    }
    for(int i = 1; i <= n; i++){
        q = max(q, p[i] + rod_cutting(p, n - i));
    }

    return q;
}