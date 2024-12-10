#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<pair<int, int>>> graph;
vector<int> visited;

void dijsktra(int src, int n){
    vector<int> dist(n+1, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src]=0;

    while(!pq.empty()){
        int node = pq.top().second;

        pq.pop();

        if(visited[node])
            continue;

        visited[node]=1;

        for(auto p : graph[node]){
            int nhbr = p.first;
            int wt = p.second;

            if(dist[nhbr] > dist[node] + wt){
                dist[nhbr] = dist[node] + wt;
                pq.push({dist[nhbr], nhbr});
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout<<dist[i]<<" ";

    cout<<"\n";
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    visited.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }

    dijsktra(1, n);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}