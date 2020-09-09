#include<iostream>
#include<vector>
#include<list>
#define NIL -1
using namespace std;

void dfs(vector<int>[], char[], int[], int[], int[], int, list<int>*);
void dfs_visit(vector<int>[], char[], int[], int[], int[], int, int, list<int>*);
list<int> topological_sort(vector<int>[], int);

int time;

int main() {
    int num_vertex;
    int num_edges;
    int s;
    int src, dst;
    list<int> tporder;

    cout << "Total Number of Vertices : ";
    cin >> num_vertex;
    cout << "total Number of edges : ";
    cin >> num_edges;

    vector<int> adj[num_vertex];

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

    tporder = topological_sort(adj, num_vertex);

    cout << "Topological order : " << endl;
    for(list<int>::iterator it = tporder.begin(); it != tporder.end(); ++it){
        cout << *it << " ";
    }
    
    return 0;
}


list<int> topological_sort(vector<int> G[], int num_vertex){
    char color[num_vertex];
    int start[num_vertex];
    int final[num_vertex];
    int pred[num_vertex];
    list<int> temp;

    dfs(G, color, start, final, pred, num_vertex, &temp);

    return temp;
}

void dfs(vector<int> G[], char color[], int start[], int final[], int pred[], int num_vertex, list<int> *t){
    for(int i = 0; i < num_vertex; i++){
        color[i] = 'W';
        pred[i] = NIL;
    }
    time = 0;
    for(int i = 0; i < num_vertex; i++){
        if(color[i] == 'W'){
            dfs_visit(G, color, start, final, pred, num_vertex, i, t);
        }
    }
}


void dfs_visit(vector<int> G[], char color[], int start[], int final[], int pred[], int num_vertices, int u, list<int> *t){
    time ++;
    start[u] = time;
    color[u] = 'G';
    for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it){
        if(color[*it] == 'W'){
            pred[*it] = u;
            dfs_visit(G, color, start, final, pred, num_vertices, *it, t);
        }
    }
    color[u] = 'B';
    time++;
    final[u] = time;
    t->push_front(u);
}
