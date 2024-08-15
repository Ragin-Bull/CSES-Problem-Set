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

vector<string> generate_sol(int level){
    if(level==1){
        return {"0", "1"};
    }

    vector<string> previous_ans = generate_sol(level-1);
    vector<string> reversed_previous_ans = previous_ans;
    reverse(all(reversed_previous_ans));

    vector<string> ans;
    int flag=0;
    for(auto ss : previous_ans){
        ss.pb('0');
        ans.pb(ss);
    }

    for(auto ss : reversed_previous_ans){
        ss.pb('1');
        ans.pb(ss);
    }

    return ans;
}

void solve(){
    cin>>n;
    vector<string> ans = generate_sol(n);

    for(auto s : ans)
        cout<<s<<"\n";
}

signed main(){
    fastio();
    solve();
    return 0;
}
