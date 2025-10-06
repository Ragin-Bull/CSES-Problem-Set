#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

struct edge{
    int first, second, weight;
};

vector<vector<pair<int, int>>> graph;
vector<vector<pair<int, int>>> graph_reversed;
vector<int> visited;
vector<edge> edge_list;

vector<int> dijsktra(int src, int n, int m, vector<vector<pair<int, int>>> &g){
    vector<int> dist(n+1, 1e18);
    dist[src]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        auto info = pq.top();
        int node = info.second;

        pq.pop();

        if(visited[node])
            continue;

        visited[node]=1;

        for(auto value : g[node]){
            int nhbr = value.first;
            int wt = value.second;

            if(dist[nhbr] > dist[node] + wt){
                dist[nhbr] = dist[node] + wt;
                pq.push({dist[nhbr], nhbr});
            }
            
        }
    }

    return dist;
}

void solve(){
    int n, m;
    cin>>n>>m;
    graph.resize(n+1);
    graph_reversed.resize(n+1);
    visited.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v, wt});
        graph_reversed[v].push_back({u, wt});
        edge_list.push_back({u, v, wt});
    }

    int minCost = 1e18;
    auto dist = dijsktra(1, n, m, graph);
    visited.assign(n+1, 0);
    auto dist_reversed = dijsktra(n, n, m, graph_reversed);

    for(auto edge : edge_list){
        int u = edge.first;
        int v = edge.second;
        int wt = edge.weight;

        minCost = min(minCost, dist[u] + (wt/2) + dist_reversed[v]);
    }

    cout<<minCost<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}