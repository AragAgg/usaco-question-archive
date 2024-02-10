---
Question Link: https://cses.fi/problemset/task/1757
Problem Set:
  - CSES
Last edited time: 2024-02-10T08:49
Status: Solved with Help
tags:
  - Graph-Reversing-Technique
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

void fx() {
    int n, m, a, b;
    cin >> n >> m;
    vvi adj(n);
    vi indeg(n, 0);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        --a; --b;

        adj[b].pb(a);
        indeg[a]++;
    }

    priority_queue<int>pq;
    for(int i = 0;i < n; i++) if(indeg[i] == 0) pq.push(i);

    vi topSort;
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();

        topSort.pb(node);
        for(auto neigh: adj[node]) if(--indeg[neigh] == 0) pq.push(neigh);
    }

    reverse(all(topSort));

    for(auto &i: topSort) cout << (i+1) << " ";
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```