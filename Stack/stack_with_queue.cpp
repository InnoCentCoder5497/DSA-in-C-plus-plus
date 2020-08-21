#include<iostream>
#include<queue>

using namespace std;

class Stack {
    queue<int> q1, q2;
    
    public:
        void push(int value){
            q1.push(value);
        }

        void pop(){
            int s = q1.size();
            int i;
            int temp;
            for(i = 0 ; i < s - 1; i++){
                temp = q1.front();
                q1.pop();
                q2.push(temp);
            }
            cout << "Element Popped : " << q1.front() << endl;
            q1.pop();

            while(!q2.empty()){
                temp = q2.front();
                q2.pop();
                q1.push(temp);
            }
        }

        queue<int> get_queue(){
            return q1;
        }

};

void print_stack(queue<int> q){
    cout << "Stack content" << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    Stack s;
    queue<int> q;

    s.push(10);
    q = s.get_queue();
    print_stack(q);

    s.push(20);
    q = s.get_queue();
    print_stack(q);

    s.pop();
    q = s.get_queue();
    print_stack(q);

    s.push(30);
    q = s.get_queue();
    print_stack(q);

    return 0;
}