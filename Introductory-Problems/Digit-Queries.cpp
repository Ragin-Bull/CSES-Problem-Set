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

long long power(long long a, long long b){
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int digits=1;
        int base=9;

        while(k-digits*base>0){
            k-=digits*base;
            base*=10;
            digits++;
        }

        int index = k%digits;

        int number = power(10, (digits-1)) + (k-1)/digits;

        if(index!=0) // Assuming back indexing acc to remainders
            number = number/power(10, digits-index);

        int result = number%10;
        cout<<result<<"\n";
    }
}

signed main(){
    fastio();
    solve();
    return 0;
}