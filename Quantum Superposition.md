---
Question Link: https://open.kattis.com/problems/quantumsuperposition
Problem Set:
  - Kattis
Last edited time: 2024-01-04T01:36
Status: Nice Question
tags:
  - Dynamic-Programming
  - Implementation
  - Topological-Sort
What's up: Toxic Implementation.
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
\#define endl "\n"

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Debugging macros
\#define debug(x) cerr << \#x << " = " << (x) << '\n'
\#define debug_vector(v) _debug_vector(\#v, v)
template<typename T>
void _debug_vector(const string& name, const vector<T>& a) {
    cerr << name << " = [ ";
    for(const auto &x : a) cerr << x << ' ';
    cerr << "]\n";
}

// I/O redirection for local testing
\#define iofile(io) \
        freopen((io + ".in").c_str(), "r", stdin); \
        freopen((io + ".out").c_str(), "w", stdout);

// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

// cin.tie(0)->sync_with_stdio(0);
int n1, n2, m1, m2;
vvi adj1, adj2;


void dfs(int node, vvi adj, vi &visited, vi &res){
    visited[node] = true;
    for(auto &neigh: adj[node]) if(!visited[neigh]) dfs(neigh, adj, visited, res);
    res.pb(node);
}

void fx() {
    // Functionality for fx
    cin >> n1 >> n2 >> m1 >> m2;
    adj1.assign(n1, {});
    adj2.assign(n2, {});

    for(int i = 0; i < m1; i++){
        int a, b;
        cin >> a >> b;
        adj1[--a].pb(--b);
    }
    
    for(int i = 0; i < m2; i++){
        int a, b;
        cin >> a >> b;
        adj2[--a].pb(--b);
    }

    vector<vb>dp1(n1, vb(2001, 0)), dp2(n2, vb(2001, 0));
    dp1[0][0] = dp2[0][0] = 1;

    vi topSort;
    vi visited(n1, false);
    for(int i = 0; i < n1; i++) if(!visited[i]) dfs(i, adj1, visited, topSort);
    reverse(all(topSort));

    for(int i = 0; i < n1; i++){
        int node = topSort[i];
        for(auto neigh: adj1[node]){
            for(int j = 0; j < 2000; j++) if(dp1[node][j] and !dp1[neigh][j+1]) dp1[neigh][j+1] = true;
        }
    }

    topSort.clear();
    visited.clear();

    visited.assign(n2, false);
    for(int i = 0; i < n2; i++) if(!visited[i]) dfs(i, adj2, visited, topSort);
    reverse(all(topSort));

    for(int i = 0; i < n2; i++){
        int node = topSort[i];
        for(auto neigh: adj2[node]){
            for(int j = 0; j < 2000; j++) if(dp2[node][j] and !dp2[neigh][j+1]) dp2[neigh][1+j] = true;
        }
    }

    int q;
    cin >> q;

    while(q--){
        int sum;
        cin >> sum;
        bool flag = false;
        for(int i = 0; i <= sum; i++) if(dp1[n1-1][i] and dp2[n2-1][sum - i]){ flag = true; break; } 

        if(flag) yes();
        else no();
    }
    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```