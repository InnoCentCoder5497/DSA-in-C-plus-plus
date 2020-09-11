#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main() {
    map<int, pair<int, int>> c;

    c[10] = make_pair(1, 0);
    c[1] = make_pair(2, 0);
    c[20] = make_pair(3, 0);
    c[7] = make_pair(4, 0);
    int a, b, d;
    cin >> a >> b >> d;
    c[d] = make_pair(a, b);

    for(map<int, pair<int, int>>::iterator it = c.begin(); it != c.end(); ++it){
        cout << it->first << " (" << it->second.first << "," <<  it->second.second << ")" << endl;
    }

    return 0;
}