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

int expo(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans%mod;
}

int getDivisors(int x){
    int count=0;
    for(int i=1; i*i<=x; i++){
        if(i*i==x)
            count++;
        else if(x%i==0){
            count+=2;
        }
    }
    return count;
}

void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    while(n--){
        int x;
        cin>>x;
        if(mp.find(x)!=mp.end())
            cout<<mp[x]<<"\n";
        else{
            mp[x]=getDivisors(x);
            cout<<mp[x]<<"\n";
        }
    }
}

signed main(){
    fastio();
    solve();
    return 0;
}