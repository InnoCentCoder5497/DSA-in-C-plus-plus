#include<iostream>
using namespace std;
int hashfunc(int);

struct node {
    int value;
    node* next;
};

class List {

    node *head, *trav, *var, *prev;

    public:
        List(){
            head = NULL;
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
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

        int search(int value){
            int i = 0;
            bool flag = false;
            if(isEmpty()){
                return -1;
            }
            else{
                trav = head;
                while(trav != NULL){
                    if(trav->value != value){
                        trav = trav->next;
                        i++;
                    }
                    else{
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    return i;
                else
                    return -1;
            }
        }

        void delete_entry(int value){
            if(isEmpty()){
                cout << "No entries in slot" << endl;
                return;
            }
            else{
                trav = head;
                prev = trav;
                while(trav->next != NULL && trav->value != value){
                    prev = trav;
                    trav = trav->next;
                }
                if(trav == NULL){
                    cout << "Item not in table" << endl;
                }
                else if(trav == prev){
                    delete trav;
                    head = NULL;
                }
                else{
                    prev->next = trav->next;
                    delete trav;
                }
            }
        }

        void print_list(){
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

int hash_func(int value){
    int m = 12;
    return value % m;
}

void print_table(List l[]){
    int i;
    for(i = 0; i < 12; i++){
        cout << "Slot " << i << " ";
        if(l[i].isEmpty()){
            cout << "empty" << endl;
        }
        else{
            l[i].print_list();
        }
    }
}

void menu() {
    cout << "1. Insert" << endl << 
            "2. Delete" << endl <<
            "3. Search" << endl <<
            "4. Print" << endl <<
            "0. Exit" << endl;
}

int main() {
    List list[12];
    bool flag = true;
    int choice;
    int value;
    int slot;
    int i;

    while(flag){
        menu();
        cout << "Choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value : ";
                cin >> value;
                slot = hash_func(value);
                list[slot].insert_front(value);
                break;
            case 2:
                cout << "Enter item to delete : ";
                cin >> value;
                slot = hash_func(value);
                list[slot].delete_entry(value);
                break;
            case 3:
                cout << "Enter item to search : ";
                cin >> value;
                slot = hash_func(value);
                i = list[slot].search(value);
                if(i == -1){
                    cout << "Item not in table" << endl;
                }
                else{
                    cout << "Item found in slot : " << slot << " at position : " << i + 1 << endl;
                }
                break;
            case 4:
                print_table(list);
                break;
            case 0:
                flag = false;
                break;
            default:
                cout << "Invalid Entry" << endl; 
        }
    }
    return 0;
}