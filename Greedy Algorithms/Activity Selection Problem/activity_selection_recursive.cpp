#include<iostream>
using namespace std;

void greedy_activity_selection_recursive(int[], int[], int, int);

int main() {
    int start[12] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finish[12] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    greedy_activity_selection_recursive(start, finish, 0, 11);

    return 0;
}

void greedy_activity_selection_recursive(int s[], int f[], int k, int n){
    int m = k + 1;
    while(m <= n && s[m] < f[k]){
        m = m + 1;
    }
    if(m <= n){
        cout << "A" << m << " " << s[m] << "-->" << f[m] << endl;
        greedy_activity_selection_recursive(s, f, m, n);
    }
}