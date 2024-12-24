#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph, capacity;
vector<pair<int, int>> edge_list;
vector<int> visited;

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

void dfs(int node){
    visited[node]=1;
    for(auto nhbr : graph[node]){
        if(!visited[nhbr] and capacity[node][nhbr])
            dfs(nhbr);
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    graph.resize(n+1);
    capacity.assign(n+1, vector<int> (n+1, 0));
    visited.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);

        capacity[u][v]++;
        capacity[v][u]++;

        edge_list.push_back({u, v});
    }

    int ans = maxflow(n, 1, n);
    dfs(1);
    vector<pair<int, int>> removed;

    for(auto edge : edge_list){
        int u = edge.first;
        int v = edge.second;

        if((visited[u] and !visited[v]) or (!visited[u] and visited[v]))
            removed.push_back({u, v});
    }

    cout<<ans<<"\n";

    for(auto edge : removed){
        cout<<edge.first<<" "<<edge.second<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}