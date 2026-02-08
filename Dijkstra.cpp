#include <iostream>
#include <climits>
using namespace std;

class Graph {
    int n;
    int **adj;

public:
    Graph(int n1) {
        n = n1;
        adj = new int*[n];
        for (int i = 0; i < n; i++)
            adj[i] = new int[n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }
    void graphRead() {
        int u, v, w, f;
        do {
            cout << "Enter u v weight : ";
            cin >> u >> v >> w;
            adj[u][v] = w;
            adj[v][u] = w;
            cout << "More edge? (1=yes / 0=no): ";
            cin >> f;
        } while (f != 0);
    }
    void print() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
    void dijkstra(int source) {
        int *L = new int[n];
        int *S = new int[n];

        for (int i = 0; i < n; i++) {
            L[i] = INT_MAX;
            S[i] = 0;
        }

        L[source] = 0;

        for (int count = 0; count < n - 1; count++) {

            int min = INT_MAX, u = -1;
            for (int i = 0; i < n; i++) {
                if (S[i] == 0 && L[i] < min) {
                    min = L[i];
                    u = i;
                }
            }
            S[u] = 1;
            for (int v = 0; v < n; v++){
                if (S[v] == 0 && adj[u][v] != 0 && L[u] != INT_MAX && L[u] + adj[u][v] < L[v]){
                    L[v] = L[u] + adj[u][v];
                }
            }
        }
        cout << "\nShortest distance from source " << source << ":\n";
        for (int i = 0; i < n; i++)
            cout << "To " << i << " = " << L[i] << endl;
    }
};

int main() {
    int n;
    do {
        cout << "Enter number of vertices: ";
        cin >> n;
    } while (n <= 0);

    Graph g(n);
    g.graphRead();
    g.print();

    int src;
    cout << "\nEnter source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}
