#include<iostream>
using namespace std;

class Graph{
    int n;
    int **adj;

public:
    Graph(int n1){
        n = n1;
        adj = new int*[n];
        for(int i=0;i<n;i++)
            adj[i] = new int[n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j] = 0;
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

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(int w[], int u[], int v[], int n, int i){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < n && w[l] > w[largest])
            largest = l;
        if(r < n && w[r] > w[largest])
            largest = r;

        if(largest != i){
            swap(w[i], w[largest]);
            swap(u[i], u[largest]);
            swap(v[i], v[largest]);
            heapify(w, u, v, n, largest);
        }
    }

    void heapSort(int w[], int u[], int v[], int m){
        for(int i=m/2-1;i>=0;i--)
            heapify(w, u, v, m, i);

        for(int i=m-1;i>=0;i--){
            swap(w[0], w[i]);
            swap(u[0], u[i]);
            swap(v[0], v[i]);
            heapify(w, u, v, i, 0);
        }
    }

    int find(int parent[], int i){
        while(parent[i] != i){
            i = parent[i];
		}
        return i;
    }

    void merge(int parent[], int x, int y){
        parent[y] = x;
    }
    void Kruskal(){
        int u[100], v[100], w[100];
        int m = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(adj[i][j] != 0){
                    u[m] = i;
                    v[m] = j;
                    w[m] = adj[i][j];
                    m++;
                }
            }
        }
        heapSort(w, u, v, m);

        int parent[n];
        for(int i=0;i<n;i++)
            parent[i] = i;

        int count = 0;
        int cost = 0;

        cout<<"\nEdges in Minimum Spanning Tree:\n";

        for(int i=0;i<m && count < n-1;i++){
            int x = find(parent, u[i]);
            int y = find(parent, v[i]);

            if(x != y){
                cout<<u[i]<<" - "<<v[i]<<" : "<<w[i]<<"\n";
                merge(parent, x, y);
                cost += w[i];
                count++;
            }
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

    g.Kruskal();
    g.print();

    return 0;
}
