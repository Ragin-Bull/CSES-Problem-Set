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

int bin_mul(int a, int b){
    int ans = 0;
    while(b){
        if(b&1){
            ans=(ans+a)%mod;
        }
        a=(a+a)%mod;
        b/=2;
    }
    return ans;
}

int binary_exp(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}

int mod_inverse(int a){
    return binary_exp(a, mod-2)%mod;
}

vector<int> factorial(){
    int N = 2e5+5;
    vector<int> fact(N);
    fact[0]=0;
    fact[1]=1;
    for(int i=2; i<N; i++)
        fact[i]=bin_mul(i, fact[i-1])%mod;
    return fact;
}

int nCr(int n, int r, vector<int> &fact){
    if(n<r)
        return 0LL;

    if(n==r or r==0)
        return 1LL;


    int a = fact[n];
    int b = mod_inverse((fact[n-r]*fact[r])%mod)%mod;
    int c = (a*b)%mod;

    return c;
}

void solve(){
    int n;
    cin>>n;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    cout<<szz(mp)<<"\n";
}

signed main(){
    fastio();
    solve();
    return 0;
}
