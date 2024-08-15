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

int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[] = {1, -1, -2, -2, -1, 1, 2, 2};

bool check(int x, int y, int r, int c){
    if(r<0 or r>=8 or c<0 or c>=8)
        return false;

    if(x==r and y==c)
        return false;

    for(int i=0; i<8; i++){
        int X = x+dx[i];
        int Y = y+dy[i];

        if(X==r and c==Y)
            return false;
    }
    return true;
}

int rec(int level){
    if(level==81){
        return 0;
    }

    int x = level/8;
    int y = level%8;

    int ans=0;

}

void solve(){

}

signed main(){
    fastio();
    solve();
    return 0;
}
