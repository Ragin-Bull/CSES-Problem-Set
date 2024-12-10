/*
Approach: Apply DFS and find the backedge and print the path
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph;
vector<int> visited;
vector<int> parent;
vector<int> path;

void dfs(int node, int par, int &flag){
    visited[node]=1;
    parent[node]=par;

    for(auto nhbr : graph[node]){
        if(visited[nhbr]==0){
            dfs(nhbr, node, flag);
        }

        else if(visited[nhbr]==1){
            int start = nhbr;
            int end = node;

            int current_node = end;

            while(current_node!=start){
                path.push_back(current_node);
                current_node=parent[current_node];
            }
            
            path.push_back(start);
            path.push_back(end);

            reverse(path.begin(), path.end());

            flag=1;
        }

        if(flag)
            return ;
    }

    visited[node]=2;
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    parent.assign(n+1, -1);
    visited.assign(n+1, 0);
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    int is_cycle = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, -1, is_cycle);
            if(is_cycle)
                break;
        }
        if(is_cycle)
            break;
    }

    if(is_cycle){
        cout<<path.size()<<"\n";
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