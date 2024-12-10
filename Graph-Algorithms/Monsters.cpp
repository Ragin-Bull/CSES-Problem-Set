#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

vector<string> grid;
vector<vector<pair<int, int>>> parent;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool check(int x, int y, int n, int m){
    if(x<0 or y<0 or x>=n or y>=m or grid[x][y]=='#')
        return false;
    return true;
}

vector<vector<int>> bfs(pair<int, int> src, int n, int m){
    queue<pair<int, int>> q;
    q.push(src);
    vector<vector<int>> dist (n+1, vector<int> (m+1, 1e18));
    dist[src.first][src.second]=0;

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        int node_x = node.first;
        int node_y = node.second;

        for(int i=0; i<4; i++){
            int x = node_x+dx[i];
            int y = node_y+dy[i];

            if(check(x, y, n, m)){
                if(dist[x][y] > 1 + dist[node_x][node_y]){
                    dist[x][y] = 1 + dist[node_x][node_y];
                    parent[x][y] = node;
                    q.push({x, y});
                }
            }
        }
    }

    return dist;
}

vector<vector<int>> multisource_bfs(vector<pair<int, int>> &monsters, int n, int m){
    queue<pair<int, int>> q;
    vector<vector<int>> dist (n+1, vector<int> (m+1, 1e18));

    for(auto monster : monsters){
        q.push(monster);
        dist[monster.first][monster.second]=0;
    }

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        int node_x = node.first;
        int node_y = node.second;

        for(int i=0; i<4; i++){
            int x = node_x+dx[i];
            int y = node_y+dy[i];

            if(check(x, y, n, m)){
                if(dist[x][y] > 1 + dist[node_x][node_y]){
                    dist[x][y] = 1 + dist[node_x][node_y];
                    q.push({x, y});
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

    parent.assign(n+1, vector<pair<int, int>> (m+1, {-1, -1}));

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        grid.push_back(s);
    }

    // We find what the starting point and the co-ordinates of monsters are:
    vector<pair<int, int>> monster;
    pair<int, int> start;
    vector<pair<int, int>> boundaries;
    
    int already_on_the_boundary = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='A'){
                start={i, j};
            }
            else if(grid[i][j]=='M'){
                monster.push_back({i, j});
            }
        }
    }

    // Check if already on the boundary
    if(start.first == 0 or start.first == n-1 or start.second==0 or start.second==m-1){
        cout<<"YES\n";
        cout<<"0\n";
        return ;
    }

    // Find the extreme boundaries
    for(int j=0; j<m; j++){
        if(grid[0][j]=='.')
            boundaries.push_back({0, j});
        else if(grid[n-1][j]=='.')
            boundaries.push_back({n-1, j});
    }

    for(int i=0; i<n; i++){
        if(grid[i][0]=='.')
            boundaries.push_back({i, 0});
        else if(grid[i][m-1]=='.')
            boundaries.push_back({i, m-1});        
    }

    vector<vector<int>> dist_of_src = bfs(start, n, m);
    vector<vector<int>> dist_of_monsters = multisource_bfs(monster, n, m);

    int found=0;
    pair<int, int> exit;

    for(auto boundary : boundaries){
        int x = boundary.first;
        int y = boundary.second;

        // cout<<x<<" , "<<y<<"\n";
        // cout<<dist_of_src[x][y]<<" "<<dist_of_monsters[x][y]<<"\n";
        if(dist_of_src[x][y] < dist_of_monsters[x][y]){
            found++;
            exit = {x, y};
        }
    }


    if(found){
        cout<<"YES\n";
        cout<<dist_of_src[exit.first][exit.second]<<"\n";
        string path = find_trail(start, exit);
        cout<<path<<"\n";
    }
    else{
        cout<<"NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}