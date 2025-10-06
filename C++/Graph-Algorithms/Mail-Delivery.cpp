#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
 
vector<vector<pair<int, int>>> graph;
vector<int> degree;
vector<int> visited;
deque<int> path;
 
bool check_eulerian_circuit(int n){
    for(int i=1; i<=n; i++){
        if(degree[i]%2!=0)
            return false;
 
    }
    return true;
}
 
void dfs(int node){
    while(!graph[node].empty()){
        int next_node = graph[node].back().first;
        int id = graph[node].back().second;
        graph[node].pop_back();
 
        if(visited[id])
            continue;
 
        visited[id]=1;
        dfs(next_node); 
    }
 
    path.push_front(node);
}
 
bool find_eulerian_circuit(int n, int m){
    if(!check_eulerian_circuit(n)){
        return false;
    }
 
    dfs(1);
 
    if(path.size()==m+1)
        return true;
 
    return false;
}
 
 
void solve(){
    int n, m;
    cin>>n>>m;
 
    graph.resize(n+1);
    degree.assign(n+1, 0);
    visited.assign(m+1, 0);
 
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }
 
    // Need to first check for connectivity
 
    if(find_eulerian_circuit(n, m)){
        for(auto node : path)
            cout<<node<<" ";
 
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
 
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}