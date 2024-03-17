---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=899
Problem Set:
  - Gold
Last edited time: 2024-03-17T13:14
Status: Nice Question
tags:
  - Dijkstra's-Algo
  - Implementation
Key Takeaway: Nice trick to maintain the lexicographically smallest path string.Simplify implementation an at all costs, and keep your code editable.
---
### Idea

1. Dijkstra’s with path extraction
2. backtracking from each node to calculate total contribution to total travel time of each node
3. choose the node with the highest contribution time.

### Solution (AC)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define p push
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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

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
    // Functionality for fx
    int n, m, t;
    cin >> n >> m >> t;

    vi cows(n, 0);
    vector<vector<pll>>adj(n);
    vll dist(n, INF);
    priority_queue<tuple<ll, int, int>>pq; // <-len, node, suggestedParent>
    vll p(n, INF);
    vll c(n, 0);

    for(auto &i: cows) cin >> i;

    while(m--){
        int x, y, cost;
        cin >> x >> y >> cost;
        --x; --y;

        adj[x].pb({y, cost});
        adj[y].pb({x, cost});
    }

    dist[0] = 0;
    pq.p({0, 0, -1});
    p[0] = -1;

    while(!pq.empty()){
        auto [len, node, suggestedParent] = pq.top();
        pq.pop();

        len *= -1;

        if(len > dist[node] or suggestedParent != p[node]) continue;

        for(auto [_neigh, _cost] : adj[node]){
            if(dist[_neigh] > len + _cost or (dist[_neigh] == len + _cost and p[_neigh] > node)){
                dist[_neigh] = len + _cost;
                p[_neigh] = node;
                pq.p({-dist[_neigh], _neigh, node});
            }
        }
    }


    for(int i = 0; i < n; i++){
        int curr = i;

        while(curr != -1){
            c[curr] += cows[i];
            curr = p[curr];
        }
    }

    ll best = 0;

    for(int i = 1; i < n; i++) best = max(best, c[i]*(dist[i] - t));

    cout << best << endl;

}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("shortcut"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

  

Note that the solution works even without `or suggestedParent != p[node]` check, but it is possible to find an case where this will time out.

  

- Img
    
    ![[Image.jpeg]]