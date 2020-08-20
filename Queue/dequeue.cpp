#include<iostream>
using namespace std;

class DeQueue {
    int head;
    int tail;
    int size;
    int *arr;

    public:
        DeQueue(int s){
            head = 0;
            tail = 0;
            size = s;
            arr = new int[s];
            for(int i = 0; i < s; i++)
                arr[i] = -999;
        }

        void print_values(){
            cout << "Head : " << head << endl <<
                    "Tail : " << tail << endl <<
                    "Size value : " << size << endl;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        bool isempty() {
            if(head == tail){
                return true;
            }
            return false;
        }

        void enqueue_front(int value) {
            if(head == 0 && tail == size - 1){
                cout << "Overflow" << endl;
                return;
            }
            if(head == 0){
                head  = size - 1;
            }
            else{
                head--;
            }
            arr[head] = value;
        }

        int dequeue_back(){
            if(isempty()){
                cout << "Underflow" << endl;
                return -1; 
            }
            if(tail == 0){
                tail = size - 1;
            }
            else{
                tail--;
            }
            int x = arr[tail];
            arr[tail] = -999;
            return x;
        }

        void enqueue_back(int value){
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

        int dequeue_front(){
            if(head == tail){
                cout << "Underflow" << endl;
                return -1; 
            }
            int x = arr[head];
            arr[head] = -999;
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
    cout << "1. Enqueue Back" << endl <<
            "2. Dequeue Front" << endl <<
            "3. Enqueue Front" << endl <<
            "4. Dequeue Back" << endl <<
            "5. Print all values" << endl <<
            "0. Quit" << endl;
}

int main() {
    int choice;
    int value;
    int flag = true;

    DeQueue q(5);

    while(flag){
        menu();
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> value;
            q.enqueue_back(value);
            break;
        
        case 2:
            cout << "Element removed : " << q.dequeue_front() << endl;
            break;

        case 3:
            cout << "Enter value : ";
            cin >> value;
            q.enqueue_front(value);
            break;
        
        case 4:
            cout << "Element removed : " << q.dequeue_back() << endl;
            break;

        case 5:
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