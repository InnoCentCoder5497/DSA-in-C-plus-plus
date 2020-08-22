#include<iostream>
using namespace std;

struct node {
    node* prev;
    int value;
    node* next;
};

class DoublyLinkedList {
    node *head, *trav, *var, *temp;

    public:
        DoublyLinkedList(){
            head = NULL;
        }

        void insert_front(int value){
            var = new node;
            var->value = value;
            var->prev = NULL;
            if(head == NULL){
                var->next = NULL;
                head = var;
            }
            else{
                head->prev = var;
                var->next = head;
                head = var;
            }
        }

        void delete_front(){
            if(head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else{
                temp = head->next;
                temp->prev = NULL;
                cout << "Item removed : " << head->value << endl;
                delete head;
                head = temp;
            }
        }

        void insert_back(int value){
            var = new node;
            var->value = value;

            if(head == NULL){
                var->prev = NULL;
                var->next = NULL;
                head = var;
            }
            else{
                trav = head;
                while(!(trav->next == NULL)){
                    trav = trav->next;
                }
                trav->next = var;
                var->prev = trav;
                var->next = NULL;
            }
        }

        void delete_back(){
            if(head == NULL){
                cout << "List is Empty" << endl;
                return;
            }
            else{
                trav = head;
                while(trav->next != NULL){
                    trav = trav->next;
                }
                cout << "Item removed : " << trav->value << endl;
                if(trav->prev == NULL){
                    delete trav;
                    head = NULL;
                }
                else{
                    temp = trav->prev;
                    temp->next = NULL;
                    delete trav;
                }
            }
        }

        void print_list(){
            if(head == NULL){
                cout << "List empty" << endl;
                return;
            }
            else{
                trav = head;
                cout << "Forward print" << endl;
                while(true){
                    cout << trav->value << " ";
                    if(trav->next == NULL){
                        break;
                    }
                    else{
                        trav = trav->next;
                    }
                }
                cout << endl << "Backward print" << endl;
                while(true){
                    cout << trav->value << " ";
                    if(trav->prev == NULL){
                        break;
                    }
                    else{
                        trav = trav->prev;
                    }
                }
                cout << endl;
            }
        }

};

int main() {
    DoublyLinkedList list;

    list.insert_back(10);
    list.delete_back();
    list.print_list();

    list.insert_front(10);
    list.insert_front(99);
    list.print_list();

    list.insert_back(20);
    list.insert_back(30);

    list.delete_front();
    list.print_list();

    list.insert_back(40);
    list.delete_back();
    list.insert_back(50);
    list.print_list();

    return 0;
}