#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

struct edge{
    int first, second, weight;
};

vector<edge> edges;
vector<int> parent;

void bellman_ford(int src, int n, int m){
    vector<int> dist(n+1, 1e18);
    dist[src]=0;
    int last_node_relaxed=-1;

    for(int i=0; i<n; i++){
        last_node_relaxed = -1;
        for(auto edge : edges){
            if(dist[edge.second] > dist[edge.first] + edge.weight){
                dist[edge.second] = dist[edge.first] + edge.weight;
                last_node_relaxed = edge.second;
                parent[edge.second] = edge.first; 
            }
        }
    }

    if(last_node_relaxed==-1){
        cout<<"NO\n";
    }
    else{
        vector<int> cycle;
        for(int i=0; i<n; i++){
            last_node_relaxed=parent[last_node_relaxed];
        }

        int node = last_node_relaxed;
        while(!(cycle.size() > 1 and node == last_node_relaxed)){
            cycle.push_back(node);
            node = parent[node];
        }

        reverse(cycle.begin(), cycle.end());

        cout<<"YES\n";
        for(auto node : cycle){
            cout<<node<<" ";
        }
        
        if(cycle[0]!=cycle[1])
            cout<<cycle[0]<<" ";

        cout<<"\n";
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    parent.assign(n+1, -1);

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back({u, v, wt});
    }

    bellman_ford(1, n, m);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}