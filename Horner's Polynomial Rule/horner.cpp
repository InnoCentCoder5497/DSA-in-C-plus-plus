#include<iostream>
using namespace std;

int horner(int[], int, int);

int main() {
    int deg;
    int x;
    int result;
    cout << "Enter degree of polynomial : ";
    cin >> deg;
    cout << "Enter value of 'x' : ";
    cin >> x;
    int cof[deg + 1];
    for(int i = 0; i < deg + 1; i++){
        cout << "Enter coefficient of x power " << i << " term : ";
        cin >> cof[i];
    }

    result = horner(cof, deg, x);

    cout << "The solutions is : " << result << endl;
    return 0;
}

int horner(int cof[], int deg, int x){
    int sum = 0;
    for(int i = deg; i >= 0; i--){
        if(i == deg){
            sum = cof[i];
        }
        else{
            sum = cof[i] + x * sum;
        }
    }

    return sum;
}