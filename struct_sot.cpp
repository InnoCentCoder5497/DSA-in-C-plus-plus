#include<iostream>
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

int main() {
    int s, d, w;
    edge e[3];
    for(int i = 0; i < 3; i++){
        cin >> s >> d >> w;
        e[i].src = s;
        e[i].dst = d;
        e[i].w = w;
    }

    sort(e, e + 3, &sort_edges);

    for(int i = 0; i < 3; i++){
        cout << e[i].src << " " << e[i].dst << " " << e[i].w << endl;
    }

    return 0;
}