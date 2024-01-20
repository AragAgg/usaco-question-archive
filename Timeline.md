---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1017
Problem Set:
  - Gold
Last edited time: 2024-01-20T16:22
Status: Solved
tags:
  - Topological-Sort
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

vector<vii> adj;
vi on, visited;
vi topSort;

void dfs(int node){
    visited[node] = true;
    for(auto [neigh, _]: adj[node]) if(!visited[neigh]) dfs(neigh);
    topSort.pb(node);
}

void fx() {
    // Functionality for fx
    int n, m, c;
    cin >> n >> m >> c;
    on.assign(n, 0);
    adj.assign(n, {});
    visited.assign(n, 0);

    for(auto &i: on) cin >> i;

    for(int i = 0; i < c; i++){
        int a, b, x;
        cin >> a >> b >> x;
        adj[--a].pb({--b, x});
    }

    for(int i = 0; i < n; i++) if(!visited[i]) dfs(i);

    reverse(all(topSort));

    for(int i = 0; i < n; i++){
        int node = topSort[i];
        for(auto neigh: adj[node]) on[neigh.f] = max(on[neigh.f], on[node] + neigh.s);
    }

    for(auto &i: on) cout << i << "\n";
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("timeline"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```