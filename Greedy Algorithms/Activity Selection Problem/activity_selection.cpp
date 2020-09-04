#include<iostream>
using namespace std;

void greedy_activity_selection_and_print(int[], int[], int);

int main() {
    int start[11] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finish[11] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    greedy_activity_selection_and_print(start, finish, 11);

    return 0;
}

void greedy_activity_selection_and_print(int s[], int f[], int n) {
    cout << "A1 " << s[0] << "-->" << f[0] << endl;
    int k = 0;
    int m;
    for(m = 1; m < n; m++){
        if(s[m] >= f[k]){
            cout << "A" << m + 1 << " " << s[m] << "-->" << f[m] << endl;
            k = m;
        }
    }
}