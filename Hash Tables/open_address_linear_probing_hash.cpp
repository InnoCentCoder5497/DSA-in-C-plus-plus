#include<iostream>
#define M 5
#define NIL -9999
using namespace std;

int auxillary_hash_function(int value){
    return value % M;
}

int linear_probing(int value, int i){
    return (auxillary_hash_function(value) + i) % M;
}

void menu() {
    cout << "1. Insert" << endl << 
            "2. Delete" << endl <<
            "3. Search" << endl <<
            "4. Print" << endl <<
            "0. Exit" << endl;
}

void print_table(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 5;
    int table[size];
    int i;
    bool flag = true;
    bool done = false;
    int choice;
    int value;
    int slot;

    for(i = 0; i < size; i++){
        table[i] = NIL;
    }

    while(flag){
        menu();
        done = false;
        cout << "Choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value : ";
                cin >> value;
                i = 0;
                while(i != size){
                    slot = linear_probing(value, i);
                    if(table[slot] == NIL){
                        table[slot] = value;
                        done = true;
                        break;
                    }
                    else{
                        i++;
                    }
                }
                if(done){
                    cout << "Inserted value : " << value << " at slot : " << slot << endl;
                }
                else{
                    cout << "table full" << endl;
                }
                break;
            case 2:
                cout << "Enter item to delete : ";
                cin >> value;
                i = 0;
                while(i != size){
                    slot = linear_probing(value, i);
                    if(table[slot] == value){
                        table[slot] = NIL;
                        done = true;
                        break;
                    }
                    else if(table[slot] == NIL){
                        break;
                    }
                    else{
                        i++;
                    }
                }
                if(done){
                    cout << "Deleted value : " << value << " from slot : " << slot << endl;
                }
                else{
                    cout << "Element Not found" << endl;
                }
                break;
            case 3:
                cout << "Enter item to search : ";
                cin >> value;
                while(i != size){
                    slot = linear_probing(value, i);
                    if(table[slot] == value){
                        done = true;
                        break;
                    }
                    else if(table[slot] == NIL){
                        break;
                    }
                    else{
                        i++;
                    }
                }
                if(done){
                    cout << "Value : " << value << " found at slot : " << slot << endl;
                }
                else{
                    cout << "Element Not found" << endl;
                }
                break;
            case 4:
                print_table(table, size);
                break;
            case 0:
                flag = false;
                break;
            default:
                cout << "Invalid Entry" << endl; 
        }
    }


    return 0;
}