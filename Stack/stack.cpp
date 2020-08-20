#include<iostream>
using namespace std;

class Stack {
    
    int top;
    int size;
    int *arr;

    public:
        Stack(int s){
            top = -1;
            size = s;
            arr = new int [size];
            if(arr == nullptr){
                cout << "Not init" << endl;
            }
        }

        void print_values(){
            cout << "Top : " << top << endl <<
                    "Size value : " << size << endl;
            cout << "Array" << endl;
            for(int i = 0; i <= top; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        bool isempty(){
            if(top == -1){
                return true;
            }
            return false;
        }

        bool isfull(){
            if(top + 1 == size){
                return true;
            }
            return false;
        }

        void push(int value){
            if(isfull()){
                cout << "Overflow" << endl;
            }
            else{
                top++;
                arr[top] = value;
            }
        }

        void pop(){
            if(isempty()){
                cout << "Underflow" << endl;
            }
            else{
                top--;
            }
        }

        int gettop(){
            if(isempty()){
                cout << "Stack empty" << endl;
                return -1;
            }
            return arr[top];
        }

};

void menu() {
    cout << "1. Push to value" << endl <<
            "2. Pop value" << endl <<
            "3. Get top value" << endl <<
            "4. Print all values" << endl <<
            "0. Quit" << endl;
}

int main() {
    int choice;
    int value;
    int flag = true;

    Stack s(5);

    while(flag){
        menu();
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> value;
            s.push(value);
            break;
        
        case 2:
            s.pop();
            break;

        case 3:
            cout << "Top value : " << s.gettop() << endl;
            break;

        case 4:
            s.print_values();
            break;


        case 0:
            flag = false;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}