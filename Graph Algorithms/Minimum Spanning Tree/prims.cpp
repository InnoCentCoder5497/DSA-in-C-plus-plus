#include<iostream>
#include<vector>
#include<queue>
#define NIL -1
using namespace std;

void prims(vector<pair<int, int>> [], int, int);

struct vertex {
    int name;
    int key;
    int pred;
};

struct Comparator {
    int operator() (const vertex* v1, const vertex* v2){
        return v1->key > v2->key;
    }
};

int main() {
    int vertices;
    int edges;
    int src, dst;
    int weight;
    cout << "Enter number of vertices : ";
    cin >> vertices;

    vector<pair<int, int>> *adj;
    adj = new vector<pair<int, int>>[vertices];

    cout << "Enter number of edges : ";
    cin >> edges;

    for(int i = 0; i < edges; i++){
        cout << "Enter src and dst nodes : ";
        cin >> src >> dst;
        cout << "Edge weight : ";
        cin >> weight;

        adj[src].push_back(make_pair(dst, weight));
        adj[dst].push_back(make_pair(src, weight));
    }

    cout << "Adjacency lists : " << endl;
    for(int i = 0; i < vertices; i++){
        cout << "Vertex " << i << " : ";
        for(vector<pair<int, int>>::iterator it = adj[i].begin() ; it != adj[i].end(); ++it){
            cout << "(" << it->first << " , " << it->second <<  ") ";
        }
        cout << endl;
    }

    prims(adj, 3, vertices);

    return 0;
}

void prims(vector<pair<int, int>> G[], int r, int num_vertices) {
    priority_queue<vertex*, vector<vertex*>, Comparator> pq;
    vertex *vertices[num_vertices];
    int inqueue[num_vertices];
    vertex *temp;
    vector<int> adj[num_vertices];
    int INF = 999;
    int v;
    int w;
    for(int i = 0; i < num_vertices; i++) {
        inqueue[i] = 1;
        temp = new vertex;
        temp->name = i;    
        temp->key = INF - i;
        if(i == r)
            temp->key = 0;
        temp->pred = NIL;
        vertices[i] = temp;
        pq.push(temp);
    }


    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        cout << pq.top()->key;
        inqueue[temp->name] = 0;
        for(vector<pair<int, int>>::iterator it = G[temp->name].begin(); it != G[temp->name].end(); ++it){
            v = it->first;
            w = it->second;
            if(inqueue[v] == 1 && w < vertices[v]->key){
                vertices[v]->pred = temp->name;
                vertices[v]->key = w;
            }
        }
        make_heap(const_cast<vertex**>(&pq.top()), const_cast<vertex**>(&pq.top()) + pq.size(), Comparator());
    }

    for(int i = 0; i < num_vertices; i++){
        cout << "Vertex : " << i << " Predecessor : " << vertices[i]->pred << " Weight : " << vertices[i]->key << endl;
    }
}
