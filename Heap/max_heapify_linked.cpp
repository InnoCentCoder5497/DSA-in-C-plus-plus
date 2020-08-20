#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    int level = 0;
};

void add_node_value(node*, int);
void bfs(node*);

int main() {
    node *head, *trav, *var;
    head = NULL;

    int arr[10] = {16, 4, 10, 14, 7, 9, 3, 2, 4, 1};

    for(int i = 0; i < 10; i++){
        if(head == NULL){
            var = new node;
            add_node_value(var, arr[i]);
            head = var;
        }
        else {
            trav = head;
            var = new node;
            while(true){
                if(trav->left == NULL){
                    add_node_value(var, arr[i]);
                    trav->left = var;
                    cout << "Added to left of : " << trav->value << endl;
                    break;
                }
                else if(trav->right == NULL){
                    add_node_value(var, arr[i]);
                    trav->right = var;
                    cout << "Added to Right of : " << trav->value << endl;
                    break;
                }
                else{
                    trav = trav->left;
                }
            }
        }
    }

    cout << "Printing tree" << endl;
    bfs(head);

    return 0;
}

void bfs(node *head){
    queue<node> q;
    node temp;
    int i = 0;
    int prev = 0;

    q.push(*head);
    head->level = i;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(prev < temp.level){
            cout << endl;
            prev += 1;
        }
        cout << "Level : " << temp.level << " value : " << temp.value << endl;
        if(temp.left != NULL){
            temp.left->level = temp.level + 1;
            q.push(*temp.left);
        }
        if(temp.right != NULL){
            temp.right->level = temp.level + 1;
            q.push(*temp.right);
        }
    }
}


void add_node_value(node* var, int value){
    var->value = value;
    var->left = NULL;
    var->right = NULL;
}