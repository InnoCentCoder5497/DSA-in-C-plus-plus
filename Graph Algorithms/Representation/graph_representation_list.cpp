#include<iostream>
#include<vector>
using namespace std;

int main() {
    int vertices;
    int edges;
    int src, dst;
    cout << "Enter number of vertices : ";
    cin >> vertices;
    vector<int> *adj;
    adj = new vector<int>[vertices];

    cout << "Enter number of edges : ";
    cin >> edges;

    for(int i = 0; i < edges; i++){
        cout << "Enter src and dst nodes : ";
        cin >> src >> dst;

        adj[src - 1].push_back(dst);
        adj[dst - 1].push_back(src);
    }

    cout << "Adjacency lists : " << endl;
    for(int i = 0; i < vertices; i++){
        cout << "Vertex " << i + 1 << " : ";
        for(vector<int>::iterator it = adj[i].begin() ; it != adj[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}