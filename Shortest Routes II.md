---
Question Link: https://cses.fi/problemset/task/1672
Problem Set:
  - CSES
Last edited time: 2024-03-16T11:14
Status: Solved
tags:
  - Floyd-Warshall's
---
### Solution (AC)

```C++
//\#pragma GCC optimize("03,unroll-loops")
 
\#include <bits/stdc++.h>
 
using namespace std;
 
// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
//\#define int ll
\#define endl "\n"
\#define sz(x) (int)x.size()
 
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
 
const ll inf = 1e18;
 
void fx() {
    int n, m, q;
    cin >> n >> m >> q;
 
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
 
    for(int i = 0; i < n; i++) dist[i][i] = 0;
 
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
 
        --a; --b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
 
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
 
    while(q--){
        int a, b;
        cin >> a >> b;
        --a; --b;
 
        cout << ((dist[a][b] == inf)?-1:dist[a][b]) << endl;
    }
}
 
signed main() {
 
    //cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```