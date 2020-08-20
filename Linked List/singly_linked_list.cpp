#include<iostream>
using namespace std;

struct node {
    int value;
    node* next;
};

class SinglyList {

    node *head, *trav, *var, *prev;

    public:
        SinglyList(){
            head = NULL;
        }

        void insert_front(int value){
            var = new node;
            var->value = value;
            
            if(head == NULL){
                head = var;
                var->next = NULL;
            }
            else {
                var->next = head;
                head = var;
            }
        }

        void insert_end(int value){
            var = new node;
            var->value = value;
            var->next = NULL;

            if(head == NULL){
                head = var;
            }
            else {
                trav = head;
                while(trav->next != NULL){
                    trav = trav->next;
                }
                trav->next = var;
            }

        }

        void delete_end(){
            if(head == NULL){
                cout << "List is empty" << endl;
            }
            else{
                trav = head;
                prev = trav;
                while(trav->next != NULL){
                    prev = trav;
                    trav = trav->next;
                }
                prev->next = NULL;
                delete trav;
            }
        }

        void delete_front(){
            if(head == NULL){
                cout << "List Empty" << endl;
            }
            else{
                trav = head;
                head = trav->next;
                delete trav;
            }
        }

        void print_list(){
            cout << "List values" << endl;
            if(head == NULL){
                cout << "Empty list" << endl;
            }
            else{
                trav = head;
                while(trav != NULL){
                    cout << trav->value << " ";
                    trav = trav->next;
                }
                cout << endl;
            }
        }

};

int main() {
    SinglyList list;

    list.print_list();
    list.insert_end(10);

    list.print_list();
    list.insert_end(20);

    list.print_list();
    list.insert_end(30);

    list.print_list();
    list.delete_end();

    list.print_list();
    list.delete_front();
    list.print_list();
    return 0;
}