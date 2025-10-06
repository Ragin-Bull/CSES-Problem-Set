/*
Approach: 
For minimum distance: plain old dijkstra
For number of minimum routes if dist is equal then add the node route to the nhbr route else just equalise the nhbr and node routes
For maximum edges and minimum edges with min distance just increment by one everytime you see a new node and in case of equality just take the max or min
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

const int mod =1e9+7;

vector<vector<pair<int, int>>> graph;
vector<int> visited;

void dijsktra(int n, int m){
    vector<int> dist (n+1, 1e18);
    vector<int> routes (n+1, 0);
    vector<int> count_min(n+1, 0);
    vector<int> count_max(n+1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    routes[1]=1;
    dist[1]=0;
    pq.push({0, 1});

    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();

        if(visited[node])
            continue;

        visited[node]=1;

        for(auto pack : graph[node]){
            int nhbr = pack.first;
            int wt = pack.second;
            if(dist[nhbr] > dist[node]+wt){
                dist[nhbr] = dist[node]+wt;
                pq.push({dist[nhbr], nhbr});
                routes[nhbr] = routes[node];
			    count_min[nhbr] = count_min[node] + 1;
				count_max[nhbr] = count_max[node] + 1;
            }

            else if(dist[nhbr] == dist[node]+wt){
                routes[nhbr] = (routes[nhbr] + routes[node])%mod;
                count_min[nhbr] = min(count_min[nhbr], count_min[node] + 1);
				count_max[nhbr] = max(count_max[nhbr], count_max[node] + 1);
            }
        }
    }

    cout<<dist[n]<<" "<<routes[n]<<" "<<count_min[n]<<" "<<count_max[n]<<"\n";
}

void solve(){
    int n, m;
    cin>>n>>m;

    graph.resize(n+1);
    visited.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }

    dijsktra(n, m);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}