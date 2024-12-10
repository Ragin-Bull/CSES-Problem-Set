#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

void floyd_warshall(vector<vector<int>> &dist, int n){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve(){
    int n, m, q;
    cin>>n>>m>>q;

    vector<vector<int>> graph (n+1, vector<int> (n+1, 1e18));

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        graph[u][v]=min({wt, graph[u][v], graph[v][u]});
        graph[v][u]=graph[u][v];
    }

    for(int i=1; i<=n; i++){
        graph[i][i]=0;
    }

    floyd_warshall(graph, n);

    while(q--){
        int a, b;
        cin>>a>>b;
        if(graph[a][b]==1e18)
            cout<<(-1)<<"\n";
        else
            cout<<graph[a][b]<<"\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}