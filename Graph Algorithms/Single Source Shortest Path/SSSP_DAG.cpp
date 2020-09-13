#include<iostream>
#include<vector>
#include<list>
#include<utility>
#define NIL -1
#define INF 999
using namespace std;

struct vertex {
    int name;
    int d;
    int pred;
};

ostream &operator<<(ostream &output, const vertex* v) { 
    output << "Vertex : " << v->name << " Distance from source : " << v->d << " Predecessor : " << v->pred << endl;
    return output; 
}

void dfs(vector<pair<int, int>>[], char[], int[], int[], int[], int, list<int>*);
void dfs_visit(vector<pair<int, int>>[], char[], int[], int[], int[], int, int, list<int>*);
list<int> topological_sort(vector<pair<int, int>>[], int);

void initialize_single_source(vertex*[], int, int);
void relax(vertex*, vertex*, int);

int time;

int main() {
    int num_vertex;
    int num_edges;
    int s;
    int src, dst;
    int weight;
    int u, v;
    list<int> tporder;

    cout << "Total Number of Vertices : ";
    cin >> num_vertex;
    cout << "total Number of edges : ";
    cin >> num_edges;

    vector<pair<int, int>> adj[num_vertex];
    vertex *V[num_vertex];

    for(int i = 0; i < num_edges; i++){
        cout << "Enter src, dst and weight : ";
        cin >> src >> dst >> weight;

        adj[src].push_back(make_pair(dst, weight));
    }

    cout << "Adjecency List : " << endl;
    for(int i = 0; i < num_vertex; i++){
        cout << "vertex : " << i << " --> ";
        for(vector<pair<int, int>>::iterator it = adj[i].begin(); it != adj[i].end(); ++it){
            cout << "(" << it->first << " " << it->second << ")";
        } 
        cout << endl;
    }

    tporder = topological_sort(adj, num_vertex);

    cout << "Topological order : " << endl;
    for(list<int>::iterator it = tporder.begin(); it != tporder.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    initialize_single_source(V, num_vertex, 0);

    for(list<int>::iterator it = tporder.begin(); it != tporder.end(); ++it){
        u = *it;
        for(vector<pair<int, int>>::iterator vt = adj[u].begin(); vt != adj[u].end(); ++vt){
            v = vt->first;
            weight = vt->second;
            relax(V[u], V[v], weight);
        }
    }
    
    for(int i = 0; i < num_vertex; i++){
        cout << V[i] << " ";
    }
    return 0;
}


list<int> topological_sort(vector<pair<int, int>> G[], int num_vertex){
    char color[num_vertex];
    int start[num_vertex];
    int final[num_vertex];
    int pred[num_vertex];
    list<int> temp;

    dfs(G, color, start, final, pred, num_vertex, &temp);

    return temp;
}

void dfs(vector<pair<int, int>> G[], char color[], int start[], int final[], int pred[], int num_vertex, list<int> *t){
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


void dfs_visit(vector<pair<int, int>> G[], char color[], int start[], int final[], int pred[], int num_vertices, int u, list<int> *t){
    time ++;
    start[u] = time;
    color[u] = 'G';
    for(vector<pair<int, int>>::iterator it = G[u].begin(); it != G[u].end(); ++it){
        if(color[it->first] == 'W'){
            pred[it->first] = u;
            dfs_visit(G, color, start, final, pred, num_vertices, it->first, t);
        }
    }
    color[u] = 'B';
    time++;
    final[u] = time;
    t->push_front(u);
}

void initialize_single_source(vertex* V[], int num_vertices, int source) {
    vertex *t;
    for(int i = 0; i < num_vertices; i++){
        t = new vertex;
        V[i] = t;
        V[i]->name = i;
        V[i]->d = INF;
        V[i]->pred = NIL;
    }
    V[source]->d = 0;
}

void relax(vertex *u, vertex *v, int w) {
    if(v->d > u->d + w){
        v->d = u->d + w;
        v->pred = u->name;
    }
}