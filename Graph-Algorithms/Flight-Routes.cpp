/*
Approach: (Reference: Wikipedia)
q = empty min heap
count = 0-filled array
push (0, s) on q
while count[t] < k:
    (l, u) = pop q
    if count[u] == k:
        continue
    count[u] += 1
    if u == t:
        found a path of length l
    for each outgoing edge (u, v, w) from u:
        push (l + w, v) on q
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<vector<pair<int, int>>> graph;

void eppstein(int n, int m, int k){
    vector<int> count(n+1, 0), final_paths, dist(n+1, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[1]=0;
    pq.push({0,1});

    while(count[n]<k and !pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        if(count[node]==k)
            continue;

        count[node]++;

        if(node == n)
            final_paths.push_back(cost); // Found a node with length l 

        for(auto nhbr_info : graph[node]){
            int nhbr = nhbr_info.first;
            int wt = nhbr_info.second;

            pq.push({wt+cost, nhbr});
        }

    }

    sort(final_paths.begin(), final_paths.end());

    for(int i=0; i<k; i++)
        cout<<final_paths[i]<<" ";

    cout<<"\n";
    
}

void solve(){
    int n, m, k;
    cin>>n>>m>>k;

    graph.resize(n+1);

    for(int i=0; i<m ;i++){
        int u, v, w;
        cin>>u>>v>>w;

        graph[u].push_back({v, w});
    }

    eppstein(n, m, k);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
