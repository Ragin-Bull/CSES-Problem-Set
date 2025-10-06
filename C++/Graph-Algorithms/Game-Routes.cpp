/*
Approach: Since we are given a directed acyclic graph, so we can use the method of dynamic programming for solving this. 
Main requirement for solving dp problems is an ordering: we shall consider the topological ordering in this case
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
const int mod = 1e9+7;

vector<vector<int>> graph;
vector<vector<int>> reverse_graph;
vector<int> visited;
vector<int> in_degree;
vector<int> dp;

void kahn(int src, int dest, int n){
    queue<int> q;
    vector<int> ordering;

    for(int i=1; i<=n; i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }

    dp[1]=1;

    while(!q.empty()){
        int node = q.front();
        ordering.push_back(node);
        q.pop();

        for(auto nhbr : graph[node]){
            in_degree[nhbr]--;
            if(in_degree[nhbr]==0){
                q.push(nhbr);
            }
        }
    }

    for(auto node : ordering){
        for(auto nhbr : reverse_graph[node]){
            dp[node] = (dp[node] + dp[nhbr])%mod;
        }
    }

    cout<<dp[n]<<"\n";

}

void solve(){
    int n, m;
    cin>>n>>m;
    
    graph.resize(n+1);
    reverse_graph.resize(n+1);

    visited.assign(n+1, 0);
    dp.assign(n+1, 0);
    in_degree.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
        in_degree[v]++;
    }

    kahn(1, n, n);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}