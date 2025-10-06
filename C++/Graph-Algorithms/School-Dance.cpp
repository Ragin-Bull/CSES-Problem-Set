#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<int>> graph, capacity;
vector<pair<int, int>> edge_list;
 
int get_path_bottleneck(int n, int source, int sink, vector<int> &parent){
    parent.assign(n+2, -1);
    parent[source]=-2;
    queue<pair<int, int>> q;
    q.push({source, 1e18});

    while(!q.empty()){
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(auto nhbr : graph[node]){
            if(parent[nhbr]==-1 and capacity[node][nhbr]){
                parent[nhbr]=node;
                int bottleneck = min(flow, capacity[node][nhbr]);

                if(nhbr == sink)
                    return bottleneck;
                
                q.push({nhbr, bottleneck});
            }
        }
    }

    return -1;
}

void edmunds_karp(int n, int m, int source, int sink){
    vector<int> parent(n+2, -1);
    int max_flow=0;

    while(true){
        int bottle_neck = get_path_bottleneck(n, source, sink, parent);
        if(bottle_neck==-1)
            break;
        
        max_flow+=bottle_neck;
        int node = sink;

        while(node!=source){
            int par = parent[node];
            capacity[par][node] -= bottle_neck;
            capacity[node][par] += bottle_neck;
            node = par;
        }
    }
}

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}