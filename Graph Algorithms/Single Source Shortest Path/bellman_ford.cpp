#include<iostream>
using namespace std;
#define INF 9999
#define NIL -1

struct vertex {
    int name;
    int d;
    int pred;
};

struct edge {
    int src;
    int dst;
    int weight;
};

ostream &operator<<(ostream &output, const vertex* v) { 
    output << "Vertex : " << v->name << " Distance from source : " << v->d << " Predecessor : " << v->pred << endl;
    return output; 
}

ostream &operator<<(ostream &output, const edge& e) { 
    output << "(" << e.src << "," << e.dst << "," << e.weight << ")";
    return output; 
}

void initialize_single_source(vertex*[], int, int);
void relax(vertex*, vertex*, int);

int main() {
    int num_vertices;
    int source = 0;
    int num_edges;
    int src, dst, w;
    int u, v;
    bool flag = true;

    cout << "Enter number of vertices : ";
    cin >> num_vertices;

    cout << "Enter number of edges : ";
    cin >> num_edges;

    vertex *V[num_vertices];
    edge E[num_edges];

    for(int i = 0; i < num_edges; i++){
        cout << "Enter src, dst and weight : ";
        cin >> src >> dst >> w;
        E[i].src = src;
        E[i].dst = dst;
        E[i].weight = w;
    }

    // Bellman Ford
    initialize_single_source(V, num_vertices, source);
    for(int i = 0; i < num_vertices - 1; i++){
        for(int j = 0; j < num_edges; j++){
            u = E[j].src;
            v = E[j].dst;
            w = E[j].weight;
            relax(V[u], V[v], w);
        }
    }

    for(int j = 0; j < num_edges; j++){
        u = E[j].src;
        v = E[j].dst;
        w = E[j].weight;
        if(V[v]->d > V[u]->d + w){
            flag = false;
            break;
        }    
    }

    if(flag){
        cout << "No negative Weight cycle Exist" << endl;
        cout << "Vertices with predecessor are : " << endl;
        for(int i = 0; i < num_vertices; i++){
            cout << V[i] << " ";
        }
    }
    else{
        cout << "Negative Weight cycle exist hence no shortest path exist" << endl;
    }

    return 0;
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