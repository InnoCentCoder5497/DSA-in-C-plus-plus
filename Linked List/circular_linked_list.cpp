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

        void insert_front(int value){
            var = new node;
            var->value = value;
            var->prev = sentinal;
            if(sentinal->next == sentinal){
                sentinal->next = var;
                sentinal->prev = var;
                var->next = sentinal;
            }
            else{
                trav = sentinal->next;
                sentinal->next = var;
                var->next = trav;
                trav->prev = var;
            }
        }

        void delete_front(){
            if(sentinal->next == sentinal){
                cout << "Liist is empty" << endl;
                return;
            }
            else{
                if(sentinal->next->next == sentinal){
                    trav = sentinal->next;
                    sentinal->next = sentinal;
                    sentinal->prev = sentinal;
                    delete trav;
                }
                else{
                    temp = sentinal->next;
                    trav = temp->next;
                    sentinal->next = trav;
                    trav->prev = sentinal;
                    delete temp;
                }
            }
        }

        void delete_back(){
            if(sentinal->next == sentinal){
                cout << "List is empty" << endl;
                return;
            }
            else{
                if(sentinal->next->next == sentinal){
                    trav = sentinal->next;
                    cout << "Item removed : " << trav->value << endl;
                    sentinal->next = sentinal;
                    sentinal->prev = sentinal;
                    delete trav;
                }
                else{
                    temp = sentinal->prev;
                    trav = temp->prev;
                    trav->next = sentinal;
                    sentinal->prev = trav;
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
    list.delete_back();
    list.delete_back();
    list.insert_back(20);
    list.insert_back(30);
    list.insert_front(99);
    cout << endl << "Forward : " << endl;
    list.print_forward();
    cout << endl << "Backward : " << endl;
    list.print_backward();
    list.delete_front();
    list.insert_back(40);
    cout << endl << "Forward : " << endl;
    list.print_forward();
    cout << endl << "Backward : " << endl;
    list.print_backward();
    list.delete_back();
    cout << endl << "Forward : " << endl;
    list.print_forward();
    cout << endl << "Backward : " << endl;
    list.print_backward();

    return 0;
}