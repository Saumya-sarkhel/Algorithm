#include <iostream>
using namespace std;

#define INF 99999

class Graph {
    int n;
    int **adj;

public:
    Graph(int n1) {
        n = n1;
        adj = new int*[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    adj[i][j] = 0;
                else
                    adj[i][j] = INF;
            }
        }
    }

    void graphRead() {
        char u_char, v_char;
        int w, f;
        do {
            cout << "Enter u v weight (e.g., A B 5): ";
            cin >> u_char >> v_char >> w;

            int u = u_char - 'A';  // Convert A→0, B→1, etc.
            int v = v_char - 'A';

            adj[u][v] = w;
            adj[v][u] = w;   // Comment the line For Directed Graph

            cout << "Add more edge? (1=yes / 0=no): ";
            cin >> f;
        } while (f != 0);
    }

    void printMatrix() {
        cout << "\nAdjacency / Distance Matrix:\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (adj[i][j] == INF)
                    cout << "INF ";
                else
                    cout << adj[i][j] << "   ";
            }
            cout << endl;
        }
    }

    void floydWarshall() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (adj[j][i] != INF && adj[i][k] != INF && adj[j][i] + adj[i][k] < adj[j][k]) {
                        adj[j][k] = adj[j][i] + adj[i][k];
                    }
                }
            }
        }
    }
};

int main() {
    int n;
    do {
        cout << "Enter number of vertices (max 26): ";
        cin >> n;
    } while (n <= 0 || n > 26);

    Graph g(n);
    g.graphRead();

    cout << "\nBefore Floyd Warshall:\n";
    g.printMatrix();

    g.floydWarshall();

    cout << "\nAfter Floyd Warshall (All Pair Shortest Path):\n";
    g.printMatrix();

    return 0;
}
