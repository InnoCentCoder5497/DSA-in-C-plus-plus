#include<iostream>
#include<vector>
#include<list>
#include<utility>
#define NIL -1
using namespace std;

void dfs(vector<int>[], char[], int[], int[], int[], int, list<pair<int, int>>*);
void dfs_visit(vector<int>[], char[], int[], int[], int[], int, int, list<pair<int, int>>*);
list<pair<int, int>> topological_sort(vector<int>[], int);
void transpose(vector<int>[], int, vector<int>*);


void dfs_t(vector<int>[], char[], int[], int[], int[], int, list<pair<int, int>>);
void dfs_visit_t(vector<int>[], char[], int[], int[], int[], int, int);
void print_forest(int[], int);
int linear_search(int[], int, int);

int time;

int main() {
    int num_vertex;
    int num_edges;
    int s;
    int src, dst;
    list<pair<int, int>> tporder;

    cout << "Total Number of Vertices : ";
    cin >> num_vertex;
    cout << "total Number of edges : ";
    cin >> num_edges;

    vector<int> adj[num_vertex];
    vector<int> trans[num_vertex];

    char color[num_vertex];
    int start[num_vertex];
    int final[num_vertex];
    int pred[num_vertex];

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
    
    transpose(adj, num_vertex, trans);

    dfs_t(trans, color, start, final, pred, num_vertex, tporder);

    cout << "Strongly Connected Components : " << endl;
    print_forest(pred, num_vertex);

    return 0;
}

void transpose(vector<int> G[], int num_vertex, vector<int> *trans) {
    for(int i = 0; i < num_vertex; i++){
        for(vector<int>::iterator it = G[i].begin(); it != G[i].end(); ++it){
            trans[*it].push_back(i);
        }
    }    
}


list<pair<int, int>> topological_sort(vector<int> G[], int num_vertex){
    char color[num_vertex];
    int start[num_vertex];
    int final[num_vertex];
    int pred[num_vertex];
    list<pair<int, int>> temp;

    dfs(G, color, start, final, pred, num_vertex, &temp);

    return temp;
}

void dfs(vector<int> G[], char color[], int start[], int final[], int pred[], int num_vertex, list<pair<int, int>> *t){
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


void dfs_visit(vector<int> G[], char color[], int start[], int final[], int pred[], int num_vertices, int u, list<pair<int, int>> *t){
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
    t->push_front(make_pair(u, time));
}

void dfs_t(vector<int> G[], char color[], int start[], int final[], int pred[], int num_vertex, list<pair<int, int>> order){
    for(int i = 0; i < num_vertex; i++){
        color[i] = 'W';
        pred[i] = NIL;
    }
    time = 0;
    for(list<pair<int, int>>::iterator it = order.begin(); it != order.end(); ++it){
        if(color[it->first] == 'W'){
            dfs_visit_t(G, color, start, final, pred, num_vertex, it->first);
        }
    }
}


void dfs_visit_t(vector<int> G[], char color[], int start[], int final[], int pred[], int num_vertices, int u){
    time ++;
    start[u] = time;
    color[u] = 'G';
    for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it){
        if(color[*it] == 'W'){
            pred[*it] = u;
            dfs_visit_t(G, color, start, final, pred, num_vertices, *it);
        }
    }
    color[u] = 'B';
    time++;
    final[u] = time;
}


void print_forest(int pred[], int num_vertex){
    int i;
    int x;
    for(i = 0; i < num_vertex; i++){
        if(pred[i] == -1){
            x = i;
            cout << x << " ";
            while(true){
                x = linear_search(pred, x, num_vertex);
                if(x == -2)
                    break;
                else{
                    cout << x << " ";
                }
            }
            cout << endl;
        }
    }
}

int linear_search(int arr[], int e, int numv){
    bool flag = false;
    int i;
    for(i = 0; i < numv; i++){
        if(arr[i] == e){
            flag = true;
            break;
        }
    }
    if(flag)
        return i;
    else
        return -2;
}