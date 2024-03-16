---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=861
Problem Set:
  - Gold
Last edited time: 2024-03-16T23:47
Status: Seen Editorial
tags:
  - Dijkstra's-Algo
  - Implementation
  - Trick
What's up: "Very nice question. "
Key Takeaway: "Adding a Dummy node is a powerful technique. "
---
### Solution (WA) [Complicated it a bit too much]

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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pll>>adj(n); // <lo, len>
    vi sigma(n, 0);
    priority_queue<tuple<ll, int, int>>pq; // <len, node, status?>
    vll dist[2]; //dist[0][node] -> dist without and official dining stop
    vi stopSpot(n, -1);

    for(int i = 0; i < n; i++) dist[0].pb(INF), dist[1].pb(INF);

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        adj[--a].pb({--b, c});
        adj[b].pb({a, c});
    }

    for(int i = 0; i < k; i++){
        int stop, sig; //sig is tastiness value
        cin >> stop >> sig;
        
        sigma[--stop] = sig;
    }

    dist[0][n-1] = 0;
    pq.p({0, n-1, 0});

    if(sigma[n-1]) dist[1][n-1] = 0;

    while(!pq.empty()){
        //status is def zero
        auto [len, node, status] = pq.top();
        pq.pop();

        len *= -1;

        if(len > dist[0][node]) continue;

        for(auto [_neigh, _len]: adj[node]){
            if(dist[0][_neigh] > dist[0][node] + _len){
                dist[0][_neigh] = dist[0][node] + _len;
                pq.p({-dist[0][_neigh], _neigh, status});
            }
        }
    }

    for(int i = 0; i < n; i++) if(sigma[i]) pq.p({dist[0][i], i, i}), stopSpot[i] = i;

    while(!pq.empty()){
        //spot contains stoping spot
        auto [len, node, spot] = pq.top();
        pq.pop();

        len *= -1;

        if(stopSpot[node] != -1 and (sigma[spot] - (len - dist[0][node]) < sigma[stopSpot[node]] - (dist[1][node] - dist[0][node]))) continue;

        stopSpot[node] = spot;
        dist[1][node] = len;

        for(auto [_neigh, _len]: adj[node]){
            if(sigma[spot] - (len + _len) - dist[0][_neigh] >= 0){
                pq.push({-(len + _len), _neigh, spot});
            }
        }
    }

    for(int i = 0; i < n; i++) cout << (dist[1][i] != INF) << " ";
    cout << endl;
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
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<pll>>adj(n+1);
    vi sigma(n+1, 0);
    vll dist(n+1, INF);
    priority_queue<pair<ll, int>>pq;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        adj[--a].pb({--b, c});
        adj[b].pb({a, c});
    }

    for(int i = 0; i < k; i++){
        int spot, tastiness;
        cin >> spot >> tastiness;
        sigma[--spot] = tastiness;
    }

    dist[n-1] = 0;
    pq.p({0, n-1});

    while(!pq.empty()){
        auto [len, node] = pq.top();
        pq.pop();
        
        len *= -1;

        if(dist[node] < len) continue;

        for(auto [_neigh, _len]: adj[node]){
            if(dist[_neigh] > len + _len){
                dist[_neigh] = len + _len;
                pq.p({-(dist[_neigh]), _neigh});
            }
        }
    }

    for(int i = 0; i < n; i++) if(sigma[i]) adj[n].pb({i, dist[i] - sigma[i]});

    vll dist2(n+1, INF);
    dist2[n] = 0;
    pq.p({0, n});

    while(!pq.empty()){
        auto [len, node] = pq.top();
        pq.pop();

        len *= -1;

        if(dist2[node] < len) continue;

        for(auto [_neigh, _len]: adj[node]){
            if(dist2[_neigh] > len + _len){
                dist2[_neigh] = len + _len;
                pq.p({-(dist2[_neigh]), _neigh});
            }
        }
    }

    for(int i = 0; i < n-1; i++) cout << (dist2[i] <= dist[i]) << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("dining"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```