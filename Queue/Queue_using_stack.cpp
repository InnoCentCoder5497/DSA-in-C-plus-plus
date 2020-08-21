#include<iostream>
#include "my_stack.h"

using namespace std;
class QueueWithStacks{

    int size;
    Stack *s1, *s2;

    public:
        QueueWithStacks(int s){
            s1 = new Stack(s);
            s2 = new Stack(s);
            size = s;
        }

        void enqueue(int value){
            s1->push(value);
        }

        int dequeue(){
            int temp;
            int x;
            while(!s1->isempty()){
                temp = s1->gettop();
                s1->pop();
                s2->push(temp);
            }
            x = s2->gettop();
            s2->pop();
            while(!s2->isempty()){
                temp = s2->gettop();
                s2->pop();
                s1->push(temp);
            }
            return x;
        }

        void print_stack(){
            s1->print_values();
        }

};

int main() {
    QueueWithStacks q(5);

    q.enqueue(10);
    q.print_stack();
    q.enqueue(20);

    q.print_stack();
    q.enqueue(30);
    q.print_stack();
    cout << "Item removed : " << q.dequeue() << endl;
    q.print_stack();

    return 0;
}