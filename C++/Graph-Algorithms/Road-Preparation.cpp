#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
 
class DSU{
public:
    vector<int> parent, size;
    int components;
 
    DSU(int n){
        parent.resize(n+1);
        size.assign(n+1, 1);
        components = n;
 
        for(int i=1; i<=n; i++){
            parent[i]=i;
        }
    }
 
    int find_parent(int node){
        if(parent[node]==node)
            return node;
 
        return parent[node] = find_parent(parent[node]);
    }
 
    void unify(int u, int v){
        int par_u = find_parent(u);
        int par_v = find_parent(v);
 
        if(par_u == par_v)
            return ;
 
        if(size[par_u]>size[par_v])
            swap(par_u, par_v);
 
        parent[par_u]=par_v;
        size[par_v]+=size[par_u];
        components--;
    }
 
 
};
 
void solve(){
    int n, m;
    cin>>n>>m;
 
    vector<pair<int, pair<int, int>>> edge_list;
    DSU dsu(n);
 
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
 
        edge_list.push_back({wt, {u, v}});
    }
 
    sort(edge_list.begin(),edge_list.end());
 
    int min_cost=0;
 
    for(auto trip : edge_list){
        int weight = trip.first;
        int u = trip.second.first;
        int v = trip.second.second;
 
        if(dsu.find_parent(u)!=dsu.find_parent(v)){
            min_cost+=weight;
            dsu.unify(u, v);
        }
    }
 
    if(dsu.components!=1)
        cout<<"IMPOSSIBLE\n";
    else
        cout<<min_cost<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}