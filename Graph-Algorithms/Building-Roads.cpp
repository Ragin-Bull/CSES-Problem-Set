/*
Approach: We need to find the number of connected components 
and then for each connected component id we store the first visited node and then we print them for all component ids
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph;
vector<int> visited;

void dfs(int node){
    visited[node]=1;

    for(auto nhbr : graph[node]){
        if(!visited[nhbr]){
            dfs(nhbr);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    visited.assign(n+1, 0);
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    map<int, int> component_to_node;
    int components=1;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            component_to_node[components]=i;
            components++;
        }
    }
    int num = components-2;

    cout<<components-2<<"\n";

    for(int i=2; i<=num+1; i++){
        cout<<component_to_node[i]<<" "<<component_to_node[i-1]<<"\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}