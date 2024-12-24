#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph;
vector<int> in, out;
deque<int> path;

bool check_eulerian_circuit(int n){
    int start_nodes=0, end_nodes=0;

    for(int i=1; i<=n; i++){
        if(out[i]-in[i]>1 or in[i]-out[i]>1)
            return false;

        else if(out[i]-in[i]==1)
            start_nodes++;

        else if(in[i]-out[i]==1)
            end_nodes++;
    }

    return (start_nodes==0 and end_nodes==0) or (start_nodes==1 and end_nodes==1);
}

void dfs(int node){
    while(out[node]>0){
        int next_node = graph[node][out[node]-1];
        out[node]--;
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
    in.assign(n+1, 0);
    out.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        in[v]++;
        out[u]++;
    }

    // find_eulerian_circuit(n,  m);

    if(find_eulerian_circuit(n,  m)){
        if(path.back()!=n){
            cout<<"IMPOSSIBLE\n";
            return ;
        }
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