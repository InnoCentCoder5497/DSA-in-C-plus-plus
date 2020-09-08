#include<iostream>
#include<vector>
#include<queue>
#define NIL -1
#define INF 9999
using namespace std;

void bfs(vector<int>[], char[], int[], int[], int, int);
void print_path(vector<int>[], int, int, int[]);

int main() {
    int num_vertex;
    int num_edges;
    int s;
    int src, dst;

    cout << "Total Number of Vertices : ";
    cin >> num_vertex;
    cout << "total Number of edges : ";
    cin >> num_edges;

    char color[num_vertex];
    int dist[num_vertex];
    int pred[num_vertex];

    vector<int> adj[num_vertex];

    for(int i = 0; i < num_edges; i++){
        cout << "Enter src and dst : ";
        cin >> src >> dst;

        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }

    for(int i = 0; i < num_vertex; i++){
        cout << "vertex : " << i << " --> ";
        for(vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it){
            cout << *it << " ";
        } 
        cout << endl;
    }

    cout << "Enter src vertex : ";
    cin >> src;

    bfs(adj, color, dist, pred, num_vertex, src);

    for(int i = 0; i < num_vertex; i++){
        cout << i << " ";
    }
    cout << endl;
    
    for(int i = 0; i < num_vertex; i++){
        cout << color[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < num_vertex; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < num_vertex; i++){
        cout << pred[i] << " ";
    }
    cout << endl;

    cout << "Enter vertex to which path is to be printed : ";
    cin >> dst;

    print_path(adj, src, dst, pred);

    return 0;
}

void print_path(vector<int> G[], int src, int dst, int pred[]){
    if(dst == src){
        cout << src << " ";
    }
    else if(pred[dst] == NIL){
        cout << "No path exist from " << src << " to " << dst << endl;
    }
    else{
        print_path(G, src, pred[dst], pred);
        cout << dst << " ";
    }
}


void bfs(vector<int> G[], char color[], int dist[], int pred[], int num_vertex, int src){
    int i;
    int u;
    queue<int> Q;

    for(i = 0; i < num_vertex; i++){
        if(i != src){
            color[i] = 'W';
            dist[i] = INF;
            pred[i] = NIL;
        }
    }

    color[src] = 'G';
    dist[src] = 0;
    pred[src] = NIL;

    Q.push(src);

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it){
            if(color[*it] == 'W'){
                color[*it] = 'G';
                dist[*it] = dist[u] + 1;
                pred[*it] = u;
                Q.push(*it);
            }
        }
        color[u] = 'B';
    }

}