#include<iostream>
using namespace std;

int main() {
    int arr[10] = {9, 4, 3, 1, 0, 7, 6, 8, 2, 5};
    int key, found = 0, i;

    cout << "Enter key to be searched : ";
    cin >> key;

    // Linear Search
    for(i = 0; i < 10; i++){
        if(arr[i] == key){
            found = 1;
            break;
        }
    }

    if(found == 1){
        cout << "Key found at index : " << i + 1;
    }
    else {
        cout << "Key not Found!";
    }

    return 0;
}