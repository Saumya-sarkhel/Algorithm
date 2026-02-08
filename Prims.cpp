#include<iostream>
using namespace std;

class Graph{
    int n;
    int **adj;

public:
    Graph(int n1){
        n = n1;
        adj = new int*[n];
        for(int i=0;i<n;i++){
            adj[i] = new int[n];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j] = 0;
            }
        }
    }

    void graphRead(){
        int u,v,w,f;
        do{
            cout<<"Enter edge (u v weight): ";
            cin>>u>>v>>w;
            adj[u][v] = w;
            adj[v][u] = w;
            cout<<"Add more edges? (1=y / 0=n): ";
            cin>>f;
        }while(f!=0);
    }

    void Prim(){
        int key[n];
        int parent[n];
        int inMST[n];

        for(int i=0;i<n;i++){
            key[i] = 9999;
            parent[i] = -1;
            inMST[i] = 0;
        }


        key[0] = 0;

        for(int count=0; count<n-1; count++){
            int min = 9999, u = -1;

            for(int v=0; v<n; v++){
                if(inMST[v]==0 && key[v] < min){
                    min = key[v];
                    u = v;
                }
            }

            inMST[u] = 1;

            for(int v=0; v<n; v++){
                if(adj[u][v] != 0 && inMST[v]==0 && adj[u][v] < key[v]){
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        int cost = 0;
        cout<<"\nEdges in Minimum Spanning Tree:\n";
        for(int i=1;i<n;i++){
            cout<<parent[i]<<" - "<<i<<" : "<<adj[i][parent[i]]<<"\n";
            cost += adj[i][parent[i]];
        }
        cout<<"Total cost of MST = "<<cost<<"\n";
    }

    void print(){
        cout<<"\nAdjacency Matrix:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<adj[i][j]<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;

    Graph g(n);
    g.graphRead();
    g.print();

    g.Prim();
    g.print();

    return 0;
}
