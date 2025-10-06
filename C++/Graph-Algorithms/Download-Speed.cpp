/*
So we are given a complete graph with edge weights, we need to apply dp with bitmasking 
to find the shortest path we can have such that we visit every node exactly once
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph, capacity;

// This returns the bottleneck value
int bfs(int n, int source, int sink, vector<int> &parent){
    parent.assign(n+1, -1);
    parent[source]=-2;
    queue<pair<int, int>> q;
    q.push({source, 1e18});

    while(!q.empty()){
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(auto nhbr : graph[node]){
            if(parent[nhbr]==-1 and capacity[node][nhbr]){
                parent[nhbr]=node;
                int new_flow = min(flow, capacity[node][nhbr]);

                if(nhbr == sink)
                    return new_flow;

                q.push({nhbr, new_flow});
            }
        }
    }

    return -1;
}

int maxflow(int n, int source, int sink) {
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow;

    while(1) {
        new_flow = bfs(n, source, sink, parent);
        if(new_flow==-1)
            break;
        flow += new_flow;
        int node = sink;
        while (node != source) {
            int prev = parent[node];
            capacity[prev][node] -= new_flow;
            capacity[node][prev] += new_flow; //Node to previous that means the back edge
            node = prev;
        }
    }

    return flow;
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    capacity.assign(n+1, vector<int> (n+1, 0));

    for(int i=0; i<m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v]+=c;
        // capacity[v][u]+=c;
    }

    // Let the source be 1 and the sink be n
    int ans = maxflow(n, 1, n);
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}