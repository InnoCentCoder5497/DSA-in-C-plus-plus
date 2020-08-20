#include<iostream>
using namespace std;

class Queue {
    int head;
    int tail;
    int size;
    int *arr;

    public:
        Queue(int s){
            head = 0;
            tail = 0;
            size = s;
            arr = new int[s];
        }

        void print_values(){
            cout << "Head : " << head << endl <<
                    "Tail : " << tail << endl <<
                    "Size value : " << size << endl;
        }

        bool isempty() {
            if(head == tail){
                return true;
            }
            return false;
        }

        void enqueue(int value){
            if(tail + 1 == head){
                cout << "Overflow" << endl;
                return;
            }
            arr[tail] = value;
            if(tail == size - 1){
                tail = 0;
            }
            else
                tail++;
        }

        int dequeue(){
            if(head == tail){
                cout << "Underflow" << endl;
                return -1; 
            }
            int x = arr[head];
            if(head == size - 1){
                head = 0;
            }
            else{
                head++;
            }
            return x;
        }
};

void menu() {
    cout << "1. Enqueue" << endl <<
            "2. Dequeue" << endl <<
            "3. Print all values" << endl <<
            "0. Quit" << endl;
}

int main() {
    int choice;
    int value;
    int flag = true;

    Queue q(5);

    while(flag){
        menu();
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> value;
            q.enqueue(value);
            break;
        
        case 2:
            cout << "Element removed : " << q.dequeue() << endl;
            break;

        case 3:
            q.print_values();
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