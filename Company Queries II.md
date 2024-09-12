---
Question Link: https://cses.fi/problemset/task/1688
Problem Set:
  - CSES
Last edited time: 2024-09-12T19:56
Status: Nice Question
tags:
  - DSU
  - Euler-Tour
  - Implementation
  - LCA
What's up: "Nice question. Small-to-large merging was causing trouble, so removed it. "
Key Takeaway: Try to not use small-to-large merging when doing euler-tour unless you’re completely sure that it would work.
---
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

vvi adj;
vi res;
unordered_map<int, vii> queries;

struct DSU{
    vi e;
    int comps;
    DSU(int n) : e(n, -1), comps(n) {}
    int get(int node){ return ((e[node] < 0)?node:(e[node] = get(e[node]))); }
    void merge(int a, int b){
        int x = get(a), y = get(b);
        if(x == y) return;
        // don't do small-to-large merging
        e[x] += e[y];
        e[y] = x;
    }
};


void euler_tour(int node, int parent, vvi &adj, DSU &st, vi &visited){
    visited[node] = true;
    for(auto &neigh: adj[node]) if(neigh != parent) euler_tour(neigh, node, adj, st, visited);
    
    if(queries.count(node)) for(auto &[b, q] : queries[node]) if(visited[b] and res[q] == -1) res[q] = st.get(b);
    if(parent != -1) st.merge(parent, node); // <- small to large merging will cause trouble
}

void fx() {
    int n, q;
    cin >> n >> q;

    adj.assign(n, {}), res.assign(q, -1);
    vi visited(n, false);

    for(int i = 1; i < n; i++){
        int t;
        cin >> t;
        --t;

        adj[t].pb(i);
        adj[i].pb(t);
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;

        queries[a].pb({b, i});
        queries[b].pb({a, i});
    }

    DSU st(n);

    euler_tour(0, -1, adj, st, visited);

    for(auto ans: res) cout << (1+ans) << endl;
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