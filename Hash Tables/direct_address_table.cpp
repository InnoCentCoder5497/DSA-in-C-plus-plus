#include<iostream>
#define NIL -99999
using namespace std;

struct entry{
    int key;
    int value;
};

class DATable{
    entry *table;
    int size;

    public:
        DATable(int size){
            table = new entry[size + 1];
            this->size = size + 1;
        }

        void insert(int key, int value){
            table[key].key = key;
            table[key].value = value;
        }

        void delete_key(int key){
            table[key].key = NIL;
            table[key].value = NIL;
        }

        int search(int key){
            if(table[key].key == key){
                return table[key].value;    
            }
            else{
                return -1;
            }
        }

        void print_table(){
            cout << "Current table state" << endl;
            for(int i = 0; i < this->size; i++){
                if(table[i].key == NIL){
                    cout << "E";
                }
                else if(table[i].key == i){
                    cout << table[i].value;
                }
                else{
                    cout << "E";
                }
                cout << endl;
            }
        }

};

int main() {
    DATable t(10);
    t.insert(2, 99);
    t.insert(3, 80);
    t.insert(5, 66);
    t.insert(8, 100);
    t.print_table();
    t.delete_key(3);
    t.print_table();
    cout << t.search(2) << endl;
    cout << t.search(4) << endl;

    return 0;
}