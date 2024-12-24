/*
Approach: WE weill cheking if all the components belong to a single component
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph;
vector<vector<int>> reversed_graph;
vector<int> visited;

void dfs(int node, stack<int> &st){
    visited[node]=1;

    for(auto nhbr : graph[node]){
        if(!visited[nhbr])
            dfs(nhbr, st);
    }

    st.push(node);
}

void dfs_for_scc(int node, int count, vector<vector<int>> &g){
    visited[node]=count;

    for(auto nhbr : g[node]){
        if(!visited[nhbr])
            dfs_for_scc(nhbr, count, g);
    }
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    reversed_graph.resize(n+1);
    visited.assign(n+1, 0);
    stack<int> st;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        reversed_graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, st);
        }
    }

    visited.assign(n+1, 0);
    
    int count=1;
    int start=st.top();
    int en=st.top();

    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(!visited[top]){
            dfs_for_scc(top, count, reversed_graph);
            en = top;
            count++;
        }
    }

    cout<<count-1<<"\n";
    for(int i=1; i<=n; i++)
        cout<<visited[i]<<" ";
    cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}