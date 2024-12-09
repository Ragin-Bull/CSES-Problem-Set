/*
Approach: We need to count the number of connected components in the graph
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<vector<int>> visited;
vector<string> grid;

bool check(int x, int y, int n, int m){
    if(x<0 or y<0 or x>=n or y>=m or grid[x][y]=='#')
        return false;
    return true;
}

void dfs(int node_x, int node_y, int n, int m){
    visited[node_x][node_y]=1;

    for(int i=0; i<4; i++){
        int x = node_x+dx[i];
        int y = node_y+dy[i];

        if(check(x, y, n, m)){
            if(!visited[x][y])
                dfs(x, y, n, m);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    visited.assign(n+1, vector<int>(m+1, 0));
    
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        grid.push_back(s);
    }

    int connected_components=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                if(grid[i][j]!='#'){
                    dfs(i, j, n, m);
                    connected_components++;
                }
            }
        }
    }

    cout<<connected_components<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}