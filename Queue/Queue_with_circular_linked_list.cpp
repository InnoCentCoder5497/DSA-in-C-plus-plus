#include<iostream>
#define INF 9999
using namespace std;

struct node {
    node* prev;
    int value;
    node* next;
};

class CircularLinkedList {
    node *sentinal, *trav, *var, *temp;

    public:
        CircularLinkedList(){
            sentinal = new node;
            sentinal->next = sentinal;
            sentinal->prev = sentinal;
            sentinal->value = INF;
        }

        void insert_back(int value){
            var = new node;
            var->value = value;
            var->next = sentinal;
            if(sentinal->next == sentinal){
                sentinal->next = var;
                sentinal->prev = var;
                var->prev = sentinal;
            }
            else{
                trav = sentinal->prev;
                sentinal->prev = var;
                trav->next = var;
                var->prev = trav;
            }
        }

        void delete_front(){
            if(sentinal->next == sentinal){
                cout << "Liist is empty" << endl;
                return;
            }
            else{
                if(sentinal->next->next == sentinal){
                    temp = sentinal->next;
                    sentinal->next = sentinal;
                    sentinal->prev = sentinal;
                    cout << "Item removed : " << temp->value << endl;
                    delete temp;
                }
                else{
                    temp = sentinal->next;
                    trav = temp->next;
                    sentinal->next = trav;
                    trav->prev = sentinal;
                    cout << "Item removed : " << temp->value << endl;
                    delete temp;
                }
            }
        }

        void print_forward(){
            if(sentinal->next == sentinal){
                cout << "List is empty" << endl;
                return;
            }
            else{
                trav = sentinal->next;
                while(trav != sentinal){
                    cout << trav->value << " ";
                    trav = trav->next;
                }
                cout << endl;
            }
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

    CircularLinkedList q;

    while(flag){
        menu();
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> value;
            q.insert_back(value);
            break;
        
        case 2:
            q.delete_front();
            break;

        case 3:
            q.print_forward();
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