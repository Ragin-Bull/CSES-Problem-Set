#include <iostream>
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

int paths=0, steps=0;
int is_visited[7][7];
string s;
int n;

void rec(int row, int col){
    if(is_visited[row][col])
        return;

    // Hitting the upper and lower walls: Pruning Case
    if((col>=1 and col<=5 and !is_visited[row][col-1] and !is_visited[row][col+1]) and ((row==0 and is_visited[row+1][col]) or (row==6 and is_visited[row-1][col])))
        return ;

    // Hitting the left and right walls: Pruning Case
    if((row>=1 and row<=5 and !is_visited[row-1][col] and !is_visited[row+1][col]) and ((col==0 and is_visited[row][col+1]) or (col==6 and is_visited[row][col-1])))
        return ;

    // Hitting the already visited path on the left or right side: Pruning Case
    if(row>=1 and row<=5 and col>=1 and col<=5 and is_visited[row+1][col] and is_visited[row-1][col] and !is_visited[row][col-1] and !is_visited[row][col+1])
        return ;

    // Htting the already visited path on the top or bottom side: Pruning Case
    if(row>=1 and row<=5 and col>=1 and col<=5 and is_visited[row][col+1] and is_visited[row][col-1] and !is_visited[row-1][col] and !is_visited[row+1][col])
        return ;

    // Base Case in case we hit the last cell
    if(row==6 and col==0){
        if(steps==48)
            paths++;
        return ;
    }

    is_visited[row][col]=1;

    if(s[steps]=='?'){
        if(row-1>=0 and !is_visited[row-1][col]){
            steps++;
            rec(row-1, col);
            steps--;
        }

        if(row+1<=6 and !is_visited[row+1][col]){
            steps++;
            rec(row+1, col);
            steps--;
        }

        if(col+1<=6 and !is_visited[row][col+1]){
            steps++;
            rec(row, col+1);
            steps--;
        }

        if(col-1>=0 and !is_visited[row][col-1]){
            steps++;
            rec(row, col-1);
            steps--;
        }

        is_visited[row][col]=0;
        return ;
    }


    // Move Up
    if(s[steps]=='U' and row-1>=0 and !is_visited[row-1][col]){
        steps++;
        rec(row-1, col);
        steps--;
    }

    // Move Down
    if(s[steps]=='D' and row+1<=6 and !is_visited[row+1][col]){
        steps++;
        rec(row+1, col);
        steps--;
    }

    // Move Left
    if(s[steps]=='L' and col-1>=0 and !is_visited[row][col-1]){
        steps++;
        rec(row, col-1);
        steps--;
    }

    // Move Right
    if(s[steps]=='R' and col+1<=6 and !is_visited[row][col+1]){
        steps++;
        rec(row, col+1);
        steps--;
    }

    is_visited[row][col]=0;
    return ;
}

void solve(){
    cin>>s;
    n = s.length();
    rec(0, 0);
    cout<<paths<<"\n";
}

signed main(){
    fastio();
    solve();
    return 0;
}
