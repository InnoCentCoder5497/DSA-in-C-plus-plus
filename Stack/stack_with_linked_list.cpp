#include<iostream>
using namespace std;

struct node {
    int value;
    node* next;
};

class SinglyListStack {

    node *head, *trav, *var, *prev;

    public:
        SinglyListStack(){
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

        void delete_front(){
            if(head == NULL){
                cout << "List Empty" << endl;
            }
            else{
                trav = head;
                head = trav->next;
                cout << "Item removed : " << trav->value << endl;
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

void menu() {
    cout << "1. Push to value" << endl <<
            "2. Pop value" << endl <<
            "3. Print all values" << endl <<
            "0. Quit" << endl;
}

int main() {
    SinglyListStack list;
    int choice;
    int value;
    int flag = true;

    while(flag){
        menu();
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> value;
            list.insert_front(value);
            break;
        
        case 2:
            list.delete_front();
            break;

        case 3:
            list.print_list();
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