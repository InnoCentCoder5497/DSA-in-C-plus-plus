#include<iostream>
#define INF 9999
using namespace std;

struct node {
    node* prev;
    int value;
    node* next;
};

class CircularLinkedList {
    node *sentinal, *trav, *var;

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

        void delete_back(){
            // TODO
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
            }
        }

        void print_backward(){
            if(sentinal->prev == sentinal){
                cout << "List is empty" << endl;
                return;
            }
            else{
                trav = sentinal->prev;
                while(trav != sentinal){
                    cout << trav->value << " ";
                    trav = trav->prev;
                }
            }
        }
};

int main() {
    CircularLinkedList list;

    list.insert_back(10);
    list.insert_back(20);
    list.print_forward();
    cout << endl;
    list.print_backward();

    return 0;
}