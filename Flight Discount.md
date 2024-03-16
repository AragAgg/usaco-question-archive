---
Question Link: https://cses.fi/problemset/task/1195
Problem Set:
  - CSES
Last edited time: 2024-03-16T11:13
Status: Solved
tags:
  - Dijkstra's-Algo
  - Implementation
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
 
const ll INF = 1e15;
 
void fx() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<ll, ll>>>adj(n);
 
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[--a].pb({c, --b});
    }
 
    priority_queue<pair<ll, pair<ll, ll>>>pq;
    pq.push({0, {0, 0}});
    
    vector<vector<ll>>dist(2, vector<ll>(n));
 
    for(int i = 0; i < n; i++) dist[0][i] = dist[1][i] = INF;
 
    dist[0][0] = 0;
 
    while(!pq.empty()){
        int node = pq.top().s.f;
        int status = pq.top().s.s;
        ll len = -pq.top().f;
 
        pq.pop();
 
        if(dist[status][node] < len) continue;
 
        for(auto &neigh: adj[node]){
            if(!status and dist[1][neigh.s] > dist[0][node] + neigh.f/2){
                dist[1][neigh.s] = dist[0][node] + neigh.f/2; 
                pq.push({-dist[1][neigh.s], {neigh.s, 1}});
            }
 
            if(dist[status][neigh.s] > dist[status][node] + neigh.f){
                dist[status][neigh.s] = dist[status][node] + neigh.f;
                pq.push({-dist[status][neigh.s], {neigh.s, status}});
            }
        }
    }
 
 
    cout << dist[1][n-1] << endl;
 
 
    
}
 
signed main() {
 
    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```