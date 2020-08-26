#include<iostream>
#include<queue>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    int level = 0;
};

class BinaryTree{
    node *root, *trav, *var, *prev;

    public:
        BinaryTree(){
            root = NULL;
        }

        void insert(int value){
            var = new node;
            var->value = value;
            var->left = NULL;
            var->right = NULL;
            if(root == NULL){
                root = var;
            }
            else{
                trav = root;
                while(trav != NULL){
                    prev = trav;
                    if(value <= trav->value){
                        trav = trav->left;
                    }
                    else{
                        trav = trav->right;
                    }
                }
                if(value <= prev->value){
                    prev->left = var;
                }
                else{
                    prev->right = var;
                }
            }
        }

        int minimum(){
            if(root == NULL){
                return -1;
            }
            else{
                trav = root;
                while(trav->left != NULL){
                    trav = trav->left;
                }
                return trav->value;
            }
        }

        int maximum(){
            if(root == NULL){
                return -1;
            }
            else{
                trav = root;
                while(trav->right != NULL){
                    trav = trav->right;
                }
                return trav->value;
            }
        }

        node *tree_search(int key){
            trav = root;
            while(trav != NULL && trav->value != key){
                if(key < trav->value){
                    trav = trav->left;
                }
                else{
                    trav = trav->right;
                }
            }
            return trav;
        }

        void bfs(){
            queue<node> q;
            node temp;
            int i = 0;
            int prev = 0;

            q.push(*root);
            root->level = i;

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

        node *get_root(){
            return root;
        }

};

void inorder_traversal(node* root){
    if(root != NULL){
        inorder_traversal(root->left);
        cout << root->value << " ";
        inorder_traversal(root->right);
    }
}

void preorder_traversal(node* root){
    if(root != NULL){
        cout << root->value << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(node* root){
    if(root != NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->value << " ";
    }
}



int main() {

    BinaryTree tree;
    int value;
    node *val;

    value = tree.maximum();
    if(value != -1)
        cout << "Maximum value : " << value << endl;
    else
        cout << "Tree empty" << endl;

    tree.insert(10);
    tree.insert(5);
    tree.insert(12);
    tree.insert(3);
    tree.insert(7);
    tree.insert(13);

    value = tree.maximum();
    if(value != -1)
        cout << "Maximum value : " << value << endl;
    else
        cout << "Tree empty" << endl;

    value = tree.minimum();
    if(value != -1)
        cout << "Miniimum value : " << value << endl;
    else
        cout << "Tree empty" << endl;

    tree.bfs();

    val = tree.tree_search(100);
    if(val == NULL){
        cout << "Not found" << endl;
    }
    else{
        cout << "Key found" << endl;
    }

    val = tree.tree_search(12);
    if(val == NULL){
        cout << "Not found" << endl;
    }
    else{
        cout << "Key found" << endl;
    }

    node *head;
    head = tree.get_root();
    inorder_traversal(head);
    cout << endl;
    preorder_traversal(head);
    cout << endl;
    postorder_traversal(head);

    return 0;
}