#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct vertex {
    int number;
    int key;
    int pred;
};

struct Comparator {
    int operator() (const vertex* v1, const vertex* v2){
        return v1->key > v2->key;
    }
};

int main(){
    priority_queue<vertex*, vector<vertex*>, Comparator> pq;
    int v = 2;
    vertex *temp;
    vertex *vertices[v];

    for(int i = 0; i < 3; i++){
        temp = new vertex;
        temp->number = i;
        temp->key = i + 1;
        temp->pred = i - 1;

        vertices[i] = temp;
        pq.push(temp);

/*
        vertices[i].number = i;
        vertices[i].key = i + 1;
        vertices[i].pred = i - 1;
*/
    }

/*
    pq.push(vertices[0]);
    pq.push(vertices[1]);
    pq.push(vertices[2]);
*/

    vertices[1]->key = 4;
    while(!pq.empty()){
        temp = pq.top();
        cout << temp->number << " " << temp->key << " " << temp->pred << endl;
        pq.pop();
    }

    return 0;
}