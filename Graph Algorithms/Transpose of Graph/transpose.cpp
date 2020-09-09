#include<iostream>
#include<vector>
using namespace std;

void transpose(vector<int>[], int, vector<int>*);

int main() {
    int num_vertex;
    int num_edges;
    int src, dst;

    cout << "Total Number of Vertices : ";
    cin >> num_vertex;
    cout << "total Number of edges : ";
    cin >> num_edges;

    vector<int> adj[num_vertex];
    vector<int> trans[num_vertex];

    for(int i = 0; i < num_edges; i++){
        cout << "Enter src and dst : ";
        cin >> src >> dst;

        adj[src].push_back(dst);
    }

    cout << "Adjecency List : " << endl;
    for(int i = 0; i < num_vertex; i++){
        cout << "vertex : " << i << " --> ";
        for(vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it){
            cout << *it << " ";
        } 
        cout << endl;
    }

    transpose(adj, num_vertex, trans);

    cout << "Transposed grapg : " << endl;
    for(int i = 0; i < num_vertex; i++){
        cout << "vertex : " << i << " --> ";
        for(vector<int>::iterator it = trans[i].begin(); it != trans[i].end(); ++it){
            cout << *it << " ";
        } 
        cout << endl;
    }

    return 0;
}

void transpose(vector<int> G[], int num_vertex, vector<int> *trans) {
    for(int i = 0; i < num_vertex; i++){
        for(vector<int>::iterator it = G[i].begin(); it != G[i].end(); ++it){
            trans[*it].push_back(i);
        }
    }    
}