---
Question Link: https://cses.fi/problemset/task/1139
Problem Set:
  - CSES
Last edited time: 2024-04-07T18:41
Status: Solved
tags:
  - Euler-Tour
  - Small-to-Large-Merging
  - Structure
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

int n;
vi tab;
vvi adj;
vi ans;

set<int> euler_tour(int node, int parent, vi &tour){
    set<int>res;
    res.insert(tab[node]);

    for(auto &neigh: adj[node]){
        if(neigh == parent) continue;
        auto r = euler_tour(neigh, node, tour);
        if(r.size() > res.size()) swap(r, res);
        for(auto &i: r) res.insert(i);
    }

    ans[node] = res.size();
    return res;
}

void fx() {
    cin >> n;
    tab.assign(n, 0);
    adj.assign(n, {});
    for(auto &i: tab) cin >> i;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi tour;
    ans.assign(n, 0);

    euler_tour(0, -1, tour);
    for(auto i: ans) cout << i << " ";
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