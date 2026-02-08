#include<iostream>
using namespace std;

class Graph{
    int n;
    int **adj;

public:
        Graph(int n1){
            n=n1;
            adj=new int *[n];
            for(int i=0; i<n; i++){
                adj[i] = new int[n];
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    adj[i][j] = 0;
                }
            }
        }

        void grepRead(){
            int u,v,f;
            do{
                cout<<"Enter the vertex pair within their edges:";
                cin>>u>>v;
                adj[u][v]=1;
                adj[v][u]=1;    // Comment the line For Directed Graph
                cout<<"Do you want to add more edge(1=y/0=n)";
                cin>>f;
            }while(f!=0);
        }

        void DFS(int s){
            int *d = new int[n];
            int *par = new int[n];
            int *stack = new int[n];

            for(int i=0;i<n;i++){
                d[i] = -1;
                par[i] = -1;
            }
            int top = -1;
            d[s] = 0;
            par[s] = -1;
            top = top + 1;
            stack[top] = s;
            int count = 0;
            cout << "\nDFS Order: ";
            while(top >= 0){
                int u = stack[top];
                top = top-1;
                cout << u << " ";
                count = count+1;
                for(int v=0; v<n; v++){
                    if(adj[u][v] == 1 && d[v] == -1){
                        d[v] = d[u] + 1;
                        par[v] = u;
                        top = top+1;
                        stack[top] = v;
                    }
                }
            }
            cout << "\nGraph is: ";
            if(count == n){
                cout << "Connected\n";
            }
            else{
                cout << "Disconnected\n";
            }
            cout << "\nPath for each vertex:\n";
            for(int i=0;i<n;i++){
                cout << "Path to " << i << ": ";
                int k = i;
                cout << k << " ";
                while(par[k] != -1){
                    k = par[k];
                    cout << k << " ";
                }
                cout << "\n";
            }
            delete[] d;
            delete[] par;
            delete[] stack;
        }

        void print(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<adj[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
};

int main(){
    int n;
    do{
        cout<<"Enter no of vertices:";
        cin>>n;
    }while(n<=0);

    Graph g(n);
    g.grepRead();

    cout<<"\nAdjacency Matrix:\n";
    g.print();

    int s;
    cout<<"\nEnter starting node for DFS: ";
    cin>>s;
    g.DFS(s);
    return 0;
}
