/*
Approach: Bipartiteness Check: Either you can go for checking if odd cycles are present or do a normal dfs
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph;
vector<int> visited;
vector<int> parent;
vector<int> mark;

void dfs(int node, int value, int &flag){
    visited[node]=1;
    mark[node]=value;

    for(auto nhbr : graph[node]){
        if(mark[nhbr]==value){
            flag=1;
            break;
        }
        if(!visited[nhbr]){
            dfs(nhbr, 1-value, flag);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    mark.assign(n+1, -1);
    visited.assign(n+1, 0);

    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int flag=0;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, 1, flag);
            if(flag)
                break;
        }
    }

    if(flag){
        cout<<"IMPOSSIBLE\n";
        return ;
    }

    for(int i=1; i<=n; i++)
        cout<<mark[i]+1<<" ";

    cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}