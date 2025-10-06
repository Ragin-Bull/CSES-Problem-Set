#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define mod_ 998244353
#define inf 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define pi 3.141592653589793238462
#define cntSetBits __builtin_popcountll
#define szz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long
#define double long double

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > ordered_set; // find_by_order, order_of_key

vector<string> board;
vector<pair<int, int>> positions;

bool check(int row, int col){
    if(row<0 or col<0 or row>=8 or col>=8)
        return false;

    if(board[row][col]=='*')
        return false;

    int m = szz(positions);
    for(int i=0; i<m; i++){
        int rr = positions[i].ff;
        int cc = positions[i].ss;

        if(rr==row)
            return false;
        
        if(cc==col)
            return false;

        if(abs(rr-row)==abs(cc-col))
            return false;
    }

    return true;
}

// Level is the rows
int rec(int level, int queens_left){
    if(queens_left<0)
        return 0;
    
    if(level==8){
        // for(int i=0; i<szz(positions); i++){
        //     cout<<positions[i].ff<<" : "<<positions[i].ss<<"\n";
        // }
        if(queens_left==0)
            return 1;
        return 0;
    }

    int ans=0;

    for(int col=0; col<8; col++){
        if(check(level, col)){
            // You can place it there
            positions.pb({level, col});
            ans+=rec(level+1, queens_left-1);

            positions.ppb();
            // ans+=rec(level+1, queens_left);
        }
    }
    
    return ans;
}

void solve(){
    for(int i=0; i<8; i++){
        string s;
        cin>>s;
        board.pb(s);
    }

    int ans = rec(0, 8);
    cout<<ans<<"\n";
}

signed main(){
    fastio();
    solve();
    return 0;
}