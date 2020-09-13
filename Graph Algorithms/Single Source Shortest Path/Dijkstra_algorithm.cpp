#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#define NIL -1
#define INF 999
using namespace std;

struct vertex {
    int name;
    int d;
    int pred;
};

struct Comparator {
    int operator() (const vertex* v1, const vertex* v2){
        return v1->d > v2->d;
    }
};

ostream &operator<<(ostream &output, const vertex* v) { 
    output << "Vertex : " << v->name << " Distance from source : " << v->d << " Predecessor : " << v->pred << endl;
    return output; 
}

void initialize_single_source(vertex*[], int, int);
void relax(vertex*, vertex*, int);
void dijkstra(vector<pair<int, int>>[], int, int);

int main() {
    int num_vertex;
    int num_edges;
    int s;
    int src, dst;
    int weight;
    int u, v;

    cout << "Total Number of Vertices : ";
    cin >> num_vertex;
    cout << "total Number of edges : ";
    cin >> num_edges;

    vector<pair<int, int>> adj[num_vertex];

    for(int i = 0; i < num_edges; i++){
        cout << "Enter src, dst and weight : ";
        cin >> src >> dst >> weight;

        adj[src].push_back(make_pair(dst, weight));
    }

    cout << "Enter source Vertex : ";
    cin >> s;

    cout << "Adjecency List : " << endl;
    for(int i = 0; i < num_vertex; i++){
        cout << "vertex : " << i << " --> ";
        for(vector<pair<int, int>>::iterator it = adj[i].begin(); it != adj[i].end(); ++it){
            cout << "(" << it->first << " " << it->second << ") ";
        } 
        cout << endl;
    }

    dijkstra(adj, num_vertex, s);

    return 0;
}

void dijkstra(vector<pair<int, int>> G[], int num_vertices, int source) {
    vertex *V[num_vertices];
    vertex *temp;
    int u, v, w;
    initialize_single_source(V, num_vertices, source);
    priority_queue<vertex*, vector<vertex*>, Comparator> pq;
    for(int i = 0; i < num_vertices; i++){
        pq.push(V[i]);
    }

    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        u = temp->name;
        for(vector<pair<int, int>>::iterator it = G[u].begin(); it != G[u].end(); ++it){
            v = it->first;
            w = it->second;
            relax(V[u], V[v], w);
        }
    }  

    for(int i = 0; i < num_vertices; i++){
        cout << V[i] << endl;
    } 
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