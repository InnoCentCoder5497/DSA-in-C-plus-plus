#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void make_set(int[], int);
int find_set(int[], int);
void union_op(int[], int, int, int);

int main() {
    int vertices;
    int edges;
    int src, dst;
    cout << "Enter number of vertices : ";
    cin >> vertices;
    int rep1, rep2;

    vector<int> *adj;
    adj = new vector<int>[vertices];
    int set[vertices];

    cout << "Enter number of edges : ";
    cin >> edges;

    for(int i = 0; i < edges; i++){
        cout << "Enter src and dst nodes : ";
        cin >> src >> dst;

        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }

    cout << "Adjacency lists : " << endl;
    for(int i = 0; i < vertices; i++){
        cout << "Vertex " << i << " : ";
        for(vector<int>::iterator it = adj[i].begin() ; it != adj[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << "Before Disjoint set creation : " << endl;
    make_set(set, vertices);

    for(int i = 0; i < vertices; i++){
        cout << set[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < vertices; i++){
        for(vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it){
            rep1 = find_set(set, i);
            rep2 = find_set(set, *it);
            if(rep1 != rep2){
                union_op(set, rep1, rep2, vertices);
            }
        }

    }
    
    cout << "After Disjoint set creation : " << endl;
    for(int i = 0; i < vertices; i++){
        cout << set[i] << " ";
    }
    return 0;
}

void union_op(int arr[], int u, int v, int total) {
    int mini = u;
    if(v < u){
        mini = v;
    }

    for(int i = 0; i < total; i++){
        if(arr[i] == u || arr[i] == v){
            arr[i] = mini;
        }
    }
}

int find_set(int arr[], int v){
    return arr[v];
}

void make_set(int arr[], int total) {
    for(int i = 0; i < total; i++){
        arr[i] = i;
    }
}