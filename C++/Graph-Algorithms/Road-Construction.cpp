#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

class DSU{
public:
    vector<int> parent, size;
    int components;
    int max_component;

    DSU(int n){
        parent.resize(n+1);
        size.assign(n+1, 1);
        components = n;

        for(int i=1; i<=n; i++)
            parent[i]=i;

        max_component=1;
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
        max_component = max({max_component, size[par_v], size[par_u]});
    }


};

void solve(){
    int n, m;
    cin>>n>>m;

    DSU dsu(n);
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        if(dsu.find_parent(u)!=dsu.find_parent(v)){
            dsu.unify(u, v);
        }
        cout<<dsu.components<<" "<<dsu.max_component<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}