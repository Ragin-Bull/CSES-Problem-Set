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
    string s;
    cin>>s;
    map<char, int> mp;
    int n = s.length();

    for(auto ch : s){
        mp[ch]++;
    }

    if(n&1){
        char odd_ch;
        int odd_freq=0;
        int flag=0;
        int another_flag=0;

        for(auto p : mp){
            if(p.ss&1){
                if(flag){
                    another_flag=1;
                    break;
                }
                else{
                    odd_freq=p.ss;
                    odd_ch=p.ff;
                    flag++;
                }
            }
        }

        if(another_flag or flag==0){
            cout<<"NO SOLUTION\n";
            return ;
        }

        string ans;
        for(auto p : mp){
            if(p.ss%2==0){
                char ch = p.ff;
                int freq = p.ss/2;
                while(freq--)
                    ans.pb(ch);
            }
        }

        int m = ans.length();
        for(int i=0; i<m; i++)
            cout<<ans[i];

        for(int i=0; i<odd_freq; i++)
            cout<<odd_ch;

        for(int i=m-1; i>=0; i--)
            cout<<ans[i];

        cout<<"\n";

    }
    else{
        int flag=0;
        for(auto &p : mp){
            if(p.ss&1){
                flag++;
                break;
            }
        }

        if(flag){
            cout<<"NO SOLUTION\n";
            return ;
        }

        string ans;
        for(auto p : mp){
            char ch = p.ff;
            int freq = p.ss/2;
            while(freq--){
                ans.pb(ch);
            }
        }
        int m=szz(ans);
        for(int i=0; i<m; i++)
            cout<<ans[i];

        for(int i=m-1; i>=0; i--)
            cout<<ans[i];

        cout<<"\n";
    }
}

signed main(){
    fastio();
    solve();
    return 0;
}
