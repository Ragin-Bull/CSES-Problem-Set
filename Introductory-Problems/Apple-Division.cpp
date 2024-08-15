#include <algorithm>
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

int total_sum=0;
int min_diff=1e18;
int n;
vector<int> arr;

void rec(int level, int sum_taken){
    if(level==n){
        int rem_sum=total_sum-sum_taken;
        min_diff=min(min_diff, abs(rem_sum-sum_taken));
        return ;
    }

    // Don't take arr[level]
    rec(level+1, sum_taken);

    // Take arr[level]
    rec(level+1, sum_taken+arr[level]);
}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.pb(x);
        total_sum+=x;
    }

    rec(0, 0);

    cout<<min_diff<<"\n";
}

signed main(){
    fastio();
    solve();
    return 0;
}
