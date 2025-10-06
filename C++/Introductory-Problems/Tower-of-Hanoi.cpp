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

int n;
set<string> final;
string ans;
string s;

void rec(int disk, int source, int helper, int destination){
    if(disk==1){
        cout<<source<<" "<<destination<<"\n";
        return ;
    }
    rec(disk-1, source, destination, helper);
    cout<<source<<" "<<destination<<"\n";
    rec(disk-1, helper, source, destination);
}


void solve(){
    int n;
    cin>>n;
    cout<<((1<<n)-1)<<"\n";
    rec(n, 1, 2, 3);
}

signed main(){
    fastio();
    solve();
    return 0;
}
