#include<iostream>
#include<list>
using namespace std;

template <typename T>
void print(T** arr, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
T** initialize_array(int row, int col, T defualt){
    T **arr;

    arr = new T*[row];
    for(int i = 0; i < row; i++){
        arr[i] = new T[col];
        for(int j = 0; j < col; j++){
            arr[i][j] = defualt;
        }
    }
    return arr;
}

int main() {
    int src, dst;
    int edges;
    int vertices;
    bool weighted = false;
    bool undirected = true;
    char choice;
    int weight;

    cout << "Enter number of vertices : ";
    cin >> vertices;
    int** matrix = initialize_array<int>(vertices, vertices, 0);
    
    cout << "Enter number of edges : ";
    cin >> edges;
    
    cout << "Is graph weighted? (Y/N) : ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
        weighted = true;

    cout << "Is graph Directed? (Y/N) : ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
        undirected = false;

    for(int i = 0; i < edges; i++){
        cout << "Enter src and dst nodes : ";
        cin >> src >> dst;

        if(weighted){
            cout << "Enter weight : ";
            cin >> weight;
        }
        src--;
        dst--;

        if(undirected && weighted){
            matrix[src][dst] = weight;
            matrix[dst][src] = weight;
        }
        else if(!undirected && weighted){
            matrix[src][dst] = weight;
        }
        else if(undirected && !weighted){
            matrix[src][dst] = 1;
            matrix[dst][src] = 1;
        }
        else{
            matrix[src][dst] = 1;
        }
    }

    cout << "Adjecency Matrix : " << endl;
    print<int>(matrix, vertices, vertices);
    return 0;
}