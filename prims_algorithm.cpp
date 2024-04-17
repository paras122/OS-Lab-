#include <bits/stdc++.h>

const int MAXN = 10;
int parent[MAXN], rank_arr[MAXN];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank_arr[x] < rank_arr[y]){
        int tmp=x;
        x=y;
        y=tmp;
    };
    
    parent[y] = x;
    if (rank_arr[x] == rank_arr[y]){
        rank_arr[x]++   
    };
}
int main() {
    int n, m;
    std::cout<<"Enter no. of vertices ";
    std::cin >>n;
    std::cout<<"Enter no. of edges ";
    std::cin>>m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_arr[i] = 1;
    }
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        std::cin >> u >> v >> w;
        union_sets(u, v);
    }
    int mst_weight = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            mst_weight += w;
            std::cout << "Edge: " << i << " - " << parent[i] << " Weight: " << w << std::endl;
        }
    }
    std::cout << "Total MST Weight: " << mst_weight << std::endl;
    return 0;
}
