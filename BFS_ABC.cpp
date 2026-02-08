#include <iostream>
using namespace std;

class graph{
    int n;
    int **adj;

public:
    graph(int n1){
        n = n1;
        adj = new int *[n];
        for (int i = 0; i < n; i++){
            adj[i] = new int[n];
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                adj[i][j] = 0;
            }
        }
    }

    void grapread(){
        char u_char, v_char;
        int f;
        do{
            cout << "Enter the vertex pair within their edges: ";
            cin >> u_char >> v_char;

            int u = u_char - 'A';
            int v = v_char - 'A';

            adj[u][v] = 1;
            adj[v][u] = 1;      // Comment the line For Directed Graph

            cout << "do you want to add more edge (1=y/0=n): ";
            cin >> f;
        } while (f != 0);
    }

    void bfs(char start_char){
        int s = start_char - 'A';

        int *d = new int[n];
        int *par = new int[n];
        int *Q = new int[n];

        int front = -1;
        int rear = -1;
        int count = 0;

        for (int i = 0; i < n; i++){
            d[i] = -1;
            par[i] = -1;
        }

        d[s] = 0;
        Q[++rear] = s;

        while (front != rear){
            int u = Q[++front];
            count++;
            for (int v = 0; v < n; v++){
                if (adj[u][v] == 1 && d[v] < 0){
                    d[v] = d[u] + 1;
                    par[v] = u;
                    Q[++rear] = v;
                }
            }
        }

        if (count == n){
            cout << "Graph is connected" << endl;
        }
        else{
            cout << "Graph is not connected" << endl;
        }

        for (int i = 0; i < n; i++){
            cout << "path to " << char('A' + i) << ": ";
            if (d[i] < 0){
                cout << "Not reachable";
            }
            else{
                int k = i;
                while (k != -1){
                    cout << char('A' + k) << " ";
                    k = par[k];
                }
                cout << "(distance: " << d[i] << ")";
            }
            cout << endl;
        }

        delete[] d;
        delete[] par;
        delete[] Q;
    }

    void print(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    int n;
    do{
        cout << "Enter no of vertices: ";
        cin >> n;
    } while (n <= 0);

    graph g(n);
    g.grapread();
    cout << "Adjacency matrix is: " << endl;
    g.print();

    char s;
    cout << "Enter the source: ";
    cin >> s;
    g.bfs(s);
    return 0;
}
