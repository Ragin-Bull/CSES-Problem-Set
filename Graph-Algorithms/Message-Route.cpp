/*
Approach: Apply BFS and save the path from start node to the end node
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph;
vector<int> dist;
vector<int> parent;

void bfs(int src, int n){
    queue<int> q;
    dist.assign(n+1, 1e18);
    dist[src]=0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto nhbr : graph[node]){
            if(dist[nhbr] > dist[node] + 1){
                dist[nhbr] = dist[node] + 1;
                parent[nhbr]=node;
                q.push(nhbr);
            }
        }
    }

    if(dist[n]==1e18){
        cout<<"IMPOSSIBLE\n";
        return ;
    }

    cout<<dist[n]+1<<"\n";
    int st = 1, en =n;
    int node = en;
    vector<int> trail;

    while(node!=st){
        trail.push_back(node);
        node=parent[node];
    }

    trail.push_back(st);
    reverse(trail.begin(), trail.end());

    for(auto network : trail)
        cout<<network<<" ";

    cout<<"\n";
    
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    parent.assign(n+1, -1);
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1, n);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}