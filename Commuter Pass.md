---
Question Link: https://oj.uz/problem/view/JOI18_commuter_pass
Problem Set:
  - Japanese Olympiad in Informatics
Last edited time: 2024-03-18T12:32
Status: Nice Question
tags:
  - Dijkstra's-Algo
  - Implementation
---
  

### Cases

```C++
6 6 
1 6
1 4
1 2 1
2 3 1
3 5 1
2 4 3
4 5 2
5 6 1
```

```C++
6 5
1 2
3 6
1 2 1000000000
2 3 1000000000 
3 4 1000000000 
4 5 1000000000 
5 6 1000000000
```

```C++
8 8  
5 7 
6 8 
1 2 2 
2 3 3 
3 4 4 
1 4 1 
1 5 5 
2 6 6 
3 7 7
4 8 8
```

```C++
5 5
1 5
2 3
1 2 1
2 3 10
2 4 10
3 5 10
4 5 10
```

```C++
10 15 
6 8
7 9
2 7 12 
8 10 17 
1 3 1
3 8 14 
5 7 15 
2 3 7
1 10 14 
3 6 12 
1 5 10 
8 9 1 
2 9 7 
1 4 1 
1 8 1 
2 4 7
5 6 16
```

  

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
int n, m, home, school, bookstore, cafe;

void dij(int src, vector<vii>&adj, vll &dist){
    dist[src] = 0;
    priority_queue<pll>pq;
    pq.p({0, src});

    while(!pq.empty()){
        auto [len, node] = pq.top();
        pq.pop();

        len *= -1;

        if(dist[node] < len) continue;

        for(auto [_neigh, _cost]: adj[node]){
            if(dist[_neigh] > _cost + len){
                dist[_neigh] = _cost + len;
                pq.p({-dist[_neigh], _neigh});
            }
        }
    }
}

vector<pll>memo;

pll dfs(int node, ll delta, vll &dist, vll &distB, vll &distC, vector<vector<pii>>&adj){
    if(memo[node].f != -1 and memo[node].s != -1) return memo[node];
    ll distToB = distB[node];
    ll distToC = distC[node];

    if(node == home) return {distToB, distToC};

    for(auto [_neigh, _cost] : adj[node]){
        if(dist[_neigh] == delta - _cost){
            auto [_distToB, _distToC] = dfs(_neigh, delta - _cost, dist, distB, distC, adj);
            _distToB = min(_distToB, distB[node]);
            _distToC = min(_distToC, distC[node]);

            if(_distToB + _distToC < distToB + distToC) distToB = _distToB, distToC = _distToC;
        }
    }

    return memo[node] = {distToB, distToC};
}

void fx() {
    // Functionality for fx
    cin >> n >> m >> home >> school >> bookstore >> cafe;

    home--;
    school--;
    bookstore--;
    cafe--;

    vector<vii>adj(n);
    memo.assign(n, {-1, -1});
    while(m--){
        int src, dest, cost;
        cin >> src >> dest >> cost;
        src--;
        dest--;

        adj[src].pb({dest, cost});
        adj[dest].pb({src, cost});
    }

    vll dist(n, INF), distB(n, INF), distC(n, INF);

    dij(home, adj, dist);
    dij(bookstore, adj, distB);
    dij(cafe, adj, distC);

    auto [distToB, distToC] = dfs(school, dist[school], dist, distB, distC, adj);

    cout << min(distToB + distToC, distB[cafe]) << endl;

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