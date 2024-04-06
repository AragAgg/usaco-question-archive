---
Question Link: https://cses.fi/problemset/task/1137
Problem Set:
  - CSES
Last edited time: 2024-04-06T09:20
Status: Solved
tags:
  - Euler-Tour
What's up: Introductory Problem. Tree Flattening.
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
\#define int ll
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

struct fenwickTree{
    vi e;
    int n;

    fenwickTree(int _n) : n(_n+1), e(_n+1, 0) {}

    void update(int ind, int delta){
        ind++;
        while(ind < n){
            e[ind] += delta;
            ind += ind & -ind;
        }
    }

    int query(int ind){
        ind++;
        int sum = 0;

        while(ind > 0){
            sum += e[ind];
            ind -= ind & -ind;
        }

        return sum;
    }
};

int dfs(int node, int parent, vvi &adj, vi &discovery, vi &nodesUnder, vi &tab, int &timer, fenwickTree &t){
    t.update(timer, tab[node]);
    discovery[node] = timer++;

    for(auto neigh: adj[node]){
        if(neigh == parent) continue;
        nodesUnder[node] += dfs(neigh, node, adj, discovery, nodesUnder, tab, timer, t);
    }

    return (nodesUnder[node] + 1);
}


void fx() {
    int n, q;
    cin >> n >> q;

    vvi adj(n);
    vi tab(n), discovery(n, 0), nodesUnder(n, 0);
    fenwickTree t(n);

    for(auto &i: tab) cin >> i;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int timer = 0;

    dfs(0, -1, adj, discovery, nodesUnder, tab, timer, t);


    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int node, changeTo;
            cin >> node >> changeTo;

            --node;
            int delta = changeTo - tab[node];
            tab[node] += delta;

            t.update(discovery[node], delta);

        }else{
            int node;
            cin >> node;
            --node;

            cout << (t.query(discovery[node] + nodesUnder[node]) - t.query(discovery[node]-1)) << endl;
        }
    }
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