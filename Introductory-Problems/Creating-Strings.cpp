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

int n;
set<string> final;
string ans;
string s;

void rec(int level, unordered_map<char, int>&mp){
    // Base Case
    if(level==n){
        if(szz(ans)==n){
            final.insert(ans);
        }
        return ;
    }

    for(int i=0; i<n; i++){
        if(mp[s[i]]){
            mp[s[i]]--;
            ans.pb(s[i]);
            rec(level+1, mp);
            mp[s[i]]++;
            ans.pop_back();
            // rec(level+1, mp);
        }
    }
}


void solve(){
    cin>>s;
    n=szz(s);
    unordered_map<char, int> mp;

    for(auto ch : s)
        mp[ch]++;

    if(szz(mp)==1){
        cout<<1<<"\n";
        cout<<s<<"\n";
        return ;
    }
    rec(0, mp);

    int m = szz(final);
    cout<<m<<"\n";

    for(auto ss : final)
        cout<<ss<<"\n";

}

signed main(){
    fastio();
    solve();
    return 0;
}
