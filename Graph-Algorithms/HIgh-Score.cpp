#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

struct triplet{
    int first, second, third;
};

vector<vector<pair<int, int>>> graph;
vector<triplet> edges;
vector<int> dist;
vector<int> parent;

void bellman_ford(int src, int n, int m, int &negative_cycle){
    dist[src]=0;

    for(int i=0; i<n-1; i++){
        for(auto edge : edges){
            int st = edge.first;
            int en = edge.second;
            int wt = edge.third;

            if(dist[en] > dist[st] + wt){
                dist[en] = dist[st] + wt;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        for(auto edge : edges){
            int st = edge.first;
            int en = edge.second;
            int wt = edge.third;

            if(dist[en] > dist[st] + wt){
                negative_cycle++;
                return ;
            }
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;

    dist.assign(n+1, 1e18);
    map<pair<int, int>, int> mp;

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        if(mp.find({u, v})!=mp.end()){
            wt = min(mp[{u,v}], wt);
        }
        edges.push_back({u, v, -wt});
        mp[{u, v}]=wt;
    }

    int src=1;
    int negative_cycle=0;

    if(n==1){
        cout<<mp[{1, 1}]<<"\n";
        return;
    }

    bellman_ford(src, n, m, negative_cycle);

    if(negative_cycle and mp.find({1, n})==mp.end())
        cout<<-1<<"\n";
    else{
        cout<<-dist[n]<<"\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}