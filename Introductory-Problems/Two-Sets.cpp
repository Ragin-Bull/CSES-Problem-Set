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

void solve(){
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;
    if(sum&1)
        cout<<"NO\n";
    else{
        set<int> s1, s2;
        if(n&1){
            for(int i=1; i<=n; i++){
                if(i&1)
                    s1.insert(i);
                else
                    s2.insert(i);
            }

            int m = (n+1)/4;

            if(s1.find(m)==s1.end()){
                int a = 1;
                int b = *s1.rbegin();
                int c = (a+b) - ((n+1)/4);
                s1.erase(1);
                s1.erase(b);
                if(s2.find(c)==s2.end()){
                    cout<<"NO\n";
                    return ;
                }
                s2.erase(c);
                s1.insert(c);
                s2.insert(a);
                s2.insert(b);
            }
            else{
                s1.erase(m);
                s2.insert(m);
            }

            cout<<"YES\n";
            cout<<szz(s1)<<"\n";
            for(auto num : s1)
                cout<<num<<" ";
            cout<<"\n";

            cout<<szz(s2)<<"\n";
            for(auto num : s2)
                cout<<num<<" ";
            cout<<"\n";
        }
        else{
            for(int i=1; i<=n; i++){
                if(i&1)
                    s1.insert(i);
                else
                    s2.insert(i);
            }

            int m = n/4;
            if(s2.find(m)==s2.end()){
                int diff=(n+1)/4;
                int a=1;
                int b=diff+a;
                s1.erase(a);
                s2.insert(a);
                if(s2.find(b)==s2.end()){
                    cout<<"NO\n";
                    return ;
                }
                s2.erase(b);
                s1.insert(b);
            }
            else{
                s2.erase(m);
                s1.insert(m);
            }

            cout<<"YES\n";
            cout<<szz(s1)<<"\n";
            for(auto num : s1)
                cout<<num<<" ";
            cout<<"\n";

            cout<<szz(s2)<<"\n";
            for(auto num : s2)
                cout<<num<<" ";
            cout<<"\n";

        }
    }
}

signed main(){
    fastio();
    solve();
    return 0;
}
