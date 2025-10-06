#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph;
vector<int> in_degree;

void kahn_algorithm(int n, int m){
    queue<int> q;
    vector<int> ordering;

    for(int i=1; i<=n; i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ordering.push_back(node);
        for(auto nhbr : graph[node]){
            in_degree[nhbr]--;
            if(in_degree[nhbr]==0)
                q.push(nhbr);
        }
    }

    if(ordering.size()==n){
        // reverse(ordering.begin(), ordering.end());
        for(auto node : ordering)
            cout<<node<<" ";
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    graph.resize(n+1);
    in_degree.assign(n+1, 0);

    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        in_degree[v]++;
        graph[u].push_back(v);
    }

    kahn_algorithm(n, m);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}