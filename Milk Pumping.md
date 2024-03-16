---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=969
Problem Set:
  - Gold
Last edited time: 2024-03-16T11:11
Status: Solved
tags:
  - Dijkstra's-Algo
  - Dynamic-Programming
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


const ll INF = 1e9;

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, pii>>>adj(n);
    vii dist(n, {0, INF});
    priority_queue<pair<double, tuple<int, int, int>>>pq;

    while(m--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        adj[--a].pb({--b, {c, d}});
        adj[b].pb({a, {c, d}});
    }

    dist[0] = {INF, 0};
    pq.push({0, {0, INF, 0}});

    while(!pq.empty()){

        double invFlow = -pq.top().f;
        auto [node, flow, cost] = pq.top().s;
        
        pq.pop();

        if((double)dist[node].s/dist[node].f < invFlow) continue;

        for(auto [_neigh, metrics]: adj[node]){
            auto [_cost, _flow] = metrics;
            double take = ((double)(cost + _cost))/(min(flow, _flow));

            if(take < (double)dist[_neigh].s/dist[_neigh].f){
                dist[_neigh].s = cost + _cost;
                dist[_neigh].f = min(flow, _flow);

                pq.push({-take, {_neigh, dist[_neigh].f, dist[_neigh].s}});
            }
        }
    }

    cout << floor(((double)dist[n-1].f*1e6)/dist[n-1].s) << endl;

}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
     iofile(string("pump"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```