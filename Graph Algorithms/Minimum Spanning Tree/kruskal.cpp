#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
    int src;
    int dst;
    int w;
};

bool sort_edges(edge const& l, edge const& r){
    return l.w < r.w;
}

void make_set(int[], int);
int find_set(int[], int);
void union_op(int[], int, int, int);
void MST_kruskal(vector<int> [], edge[], int[], int, int);

int main() {

    int vertices;
    int edges;
    int src, dst;
    int weight;
    cout << "Enter number of vertices : ";
    cin >> vertices;

    vector<int> *adj;
    adj = new vector<int>[vertices];
    int set[vertices];

    cout << "Enter number of edges : ";
    cin >> edges;

    edge sorted_edges[edges];


    for(int i = 0; i < edges; i++){
        cout << "Enter src and dst nodes : ";
        cin >> src >> dst;
        cout << "Edge weight : ";
        cin >> weight;

        adj[src].push_back(dst);
        adj[dst].push_back(src);

        sorted_edges[i].src = src;
        sorted_edges[i].dst = dst;
        sorted_edges[i].w = weight;
    }

    cout << "Adjacency lists : " << endl;
    for(int i = 0; i < vertices; i++){
        cout << "Vertex " << i << " : ";
        for(vector<int>::iterator it = adj[i].begin() ; it != adj[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }

    make_set(set, vertices);
    sort(sorted_edges, sorted_edges + edges, &sort_edges);
    MST_kruskal(adj, sorted_edges, set, vertices, edges);

    return 0;
}


void MST_kruskal(vector<int> G[], edge w[], int set[], int total, int tedges){
    vector<int> A[total];
    int rep1;
    int rep2;

    for(int i = 0; i < tedges; i++){
        cout << w[i].w << " " << w[i].src << " " << w[i].dst << endl;
        rep1 = find_set(set, w[i].src);
        rep2 = find_set(set, w[i].dst);
        if(rep1 != rep2){
            A[w[i].src].push_back(w[i].dst);
            union_op(set, rep1, rep2, total);
        }
    }

    cout << "Adjacency lists for MST : " << endl;
    for(int i = 0; i < total; i++){
        cout << "Vertex " << i << " : ";
        for(vector<int>::iterator it = A[i].begin() ; it != A[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
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