#include<iostream>
#include<list>
#define INF 999
using namespace std;

template <typename T>
void print(T** arr, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << arr[i][j] << "\t";
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
            if(i == j)
                arr[i][j] = 0;
        }
    }
    return arr;
}

template <typename T>
void copy_matrix(T** dst, T** src, int row, int col) {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            dst[i][j] = src[i][j];
        }
    }
}

int** floyd_warshall(int**, int**, int);

int main() {
    int src, dst;
    int edges;
    int vertices;
    int weight;

    cout << "Enter number of vertices : ";
    cin >> vertices;
    int** matrix = initialize_array<int>(vertices, vertices, INF);
    int** pred = initialize_array<int>(vertices, vertices, INF);
    int** final_matrix;
    
    cout << "Enter number of edges : ";
    cin >> edges;
    
    for(int i = 0; i < edges; i++){
        cout << "Enter src and dst nodes : ";
        cin >> src >> dst;

        cout << "Enter weight : ";
        cin >> weight;
            
        matrix[src][dst] = weight;
        pred[src][dst] = src;
    }

    cout << "Adjecency Matrix : " << endl;

    final_matrix = floyd_warshall(matrix, pred, vertices);
    cout << "Final Weight matrix : " << endl;
    print<int>(final_matrix, vertices, vertices);
    cout << "Final Predecessor matrix : " << endl;
    print<int>(pred, vertices, vertices);
    return 0;
}

int** floyd_warshall(int **W, int **p, int num_vertex){
    int **D_k = initialize_array<int>(num_vertex, num_vertex, INF);
    int **D_k_1 = initialize_array<int>(num_vertex, num_vertex, INF);
    int **p_k_1 = initialize_array<int>(num_vertex, num_vertex, INF);
    int temp;

    copy_matrix<int>(D_k_1, W, num_vertex, num_vertex);
    copy_matrix<int>(p_k_1, p, num_vertex, num_vertex);

    for(int k = 0; k < num_vertex; k++){
        for(int i = 0; i < num_vertex; i++){
            for(int j = 0; j < num_vertex; j++){
                if(D_k_1[i][j] <= D_k_1[i][k] + D_k_1[k][j]){
                    D_k[i][j] = D_k_1[i][j];
                    p[i][j] = p_k_1[i][j];
                }
                else{
                    D_k[i][j] = D_k_1[i][k] + D_k_1[k][j];
                    p[i][j] = p_k_1[k][j];
                }
            }
        }
        copy_matrix<int>(D_k_1, D_k, num_vertex, num_vertex);
        copy_matrix<int>(p_k_1, p, num_vertex, num_vertex);
    }

    return D_k;
}