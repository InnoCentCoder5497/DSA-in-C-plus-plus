#include<iostream>
#include<list>
using namespace std;

int main() {
    float arr[10] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int i;
    list<float> B[10];
    list<float>::iterator it;
    int n = 10;
    int index;
    cout << "Input List : " << endl;
    for(i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
    cout << endl;

    for(i = 0; i < n; i++){
        index = (int) n * arr[i];
        B[index].push_back(arr[i]);
    }

    for(i = 0; i < 10; i++){
        if(!B[i].empty()){
            B[i].sort();
        }
    }

    for(i = 0; i < n; i++){
        cout << "Bucket " << i << " : ";
        for(it = B[i].begin(); it != B[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }


    cout << "Sorted List : " << endl;

    for(i = 0; i < 10; i++){
        if(!B[i].empty()){
            for(it = B[i].begin(); it != B[i].end(); ++it){
                cout << *it << " ";
            }
        }
    }
    cout << endl;

    return 0;
}