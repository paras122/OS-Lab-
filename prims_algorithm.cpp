#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 10;
const int INF = 1e9; // Infinity

int graph[MAXN][MAXN];
bool visited[MAXN];

int prim(int start, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    int mst_weight = 0;
    int count=0;
    int min = INF;
    int temp= start;
    visited[start]=true;
   bool flag=false;

    while(count<=n-1){
        flag=false;
        for (int j = 1; j <= n; j++){
            if(!visited[j]){
                if(graph[start][j]<min||graph[j][start]<min){
                    min=graph[start][j];
                    temp=j;
                    flag= true;
                }

            }
        }
        if(flag)
        mst_weight+= min;
        cout<<mst_weight;
        visited[temp] = true;
        start = temp;
        count++;
    }

    return mst_weight;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter edge " << i + 1 << " (u v w): ";
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    int start_vertex;
    cout << "Enter starting vertex: ";
    cin >> start_vertex;

    int mst_weight = prim(start_vertex, n);
    cout << "Total MST Weight: " << mst_weight << endl;

    return 0;
}
