/*
Approach: We need to find the shortest distance between the start and the end points using bfs and print the path taken
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<vector<int>> visited;
vector<vector<pair<int, int>>> parent;
vector<string> grid;

bool check(int x, int y, int n, int m){
    if(x<0 or y<0 or x>=n or y>=m or grid[x][y]=='#')
        return false;
    return true;
}

vector<vector<int>> bfs(pair<int, int> start, pair<int, int> end, int n, int m){
    queue<pair<int, int>> q;
    vector<vector<int>> dist (n+1, vector<int> (m+1, 1e18));
    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int x = node.first + dx[i];
            int y = node.second + dy[i];

            if(check(x, y, n, m)){
                if(dist[x][y]>dist[node.first][node.second]+1){
                    dist[x][y]=dist[node.first][node.second]+1;
                    q.push({x, y});
                    parent[x][y] = node;
                }
            }
        }
    }

    return dist;
}

string find_trail(pair<int, int> start, pair<int, int> end){
    pair<int, int> node = end;
    vector<pair<int, int>> trail;
    string path;

    while(node!=start){
        trail.push_back(node);
        node=parent[node.first][node.second];
    }

    trail.push_back(start);
    reverse(trail.begin(), trail.end());

    int sz = trail.size();

    for(int i=1; i<sz; i++){
        int next_x = trail[i].first;
        int next_y = trail[i].second;
        int curr_x = trail[i-1].first;
        int curr_y = trail[i-1].second;

        if(curr_x==next_x){
            if(next_y==curr_y+1)
                path.push_back('R');
            else if(next_y==curr_y-1)
                path.push_back('L');
        }
        else if(curr_y==next_y){
            if(next_x==curr_x+1)
                path.push_back('D');
            else if(next_x==curr_x-1)
                path.push_back('U');
        }
    }

    return path;
}

void solve(){
    int n, m;
    cin>>n>>m;
    visited.assign(n+1, vector<int>(m+1, 0));
    parent.assign(n+1, vector<pair<int, int>> (m+1, {-1, -1}));
    
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        grid.push_back(s);
    }

    pair<int, int> start, end;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='A')
                start={i, j};

            if(grid[i][j]=='B')
                end={i, j};
        }
    }

    vector<vector<int>> dist = bfs(start, end, n, m);
    if(dist[end.first][end.second]==1e18){
        cout<<"NO\n";
        return ;
    }

    cout<<"YES\n";
    string path = find_trail(start, end);
    cout<<path.size()<<"\n"<<path<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}