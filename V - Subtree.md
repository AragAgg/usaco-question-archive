---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_v
Problem Set:
  - AtCoder
Last edited time: 2023-11-29T19:49
Status: Skipped for now
tags:
  - Dynamic-Programming
  - Tree
What's up: Can’t implement
---
### Basic idea

  

The main idea here is to first arbitrary root the tree at `root` and then define g(node) as the number of ways to paint the subtree rooted at `node` such that `node` is `BLACK`.

  

We could do this quickly with a `DFS` by defining `g(leaf` = 1 and then g(node) = product of all g values of all its children +1.

  

Now we have found out the value of the ans for root. Now we could use DP on trees to find our ans, using the re-rooting method.

  

basically ans for node:

```Plain
ans = g(node) * (g(parent) / g(node) +1)  + 1
```

  

and we could avoid doing division under modulo by sloring the intermedite (prefix and suffix) values when calculating g(node).

  

  

  

  

```C++
5 1000
1 2
1 3
2 4
2 5
```

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

ll n, m;
const ll mod = 1e9+7;

vector<int>parent;
vector<vector<int>>tree;
vector<ll>g;
vector<vector<pair<int, int>>> t;

vector<ll>dp;

void dfs2(int node){
    cout<<"called dfsssss(" << node << ")\n";
    dp[node] = g[node];
    for(int i = 0; i < tree[node].size(); i++){
        ll tNode = g[node], tNext = g[tree[node][i]];
        g[node] = (t[node][i].f * t[node][i].s) %mod;
        cout << "# " << t[node][i].f << " #" << t[node][i].s << endl;
        g[tree[node][i]] = (g[tree[node][i]] * (g[node] +1)) %mod;
        
        dfs2(tree[node][i]);
        g[node] = tNode;
        g[tree[node][i]] = tNext;
    }
}

ll dfs(int node){
    cout << "called dfs(" << node << ")\n";
    if(tree[node].size() == 0) return g[node] = 1;
    if(g[node] != -1) return g[node];
    vector<ll> suf(tree[node].size(), 0);
    ll p = 1;

    for(int i = 0; i < tree[node].size(); i++){
        t[node][i].f = p;
        suf[i] = dfs(tree[node][i]) + 1;
        p = p * suf[i] %mod;
    }

    g[node] = p;
    p = 1;
    for(int i = tree[node].size() - 1; i >= 0; i--){
        t[node][i].s = p;
        p = p * suf[i] %mod;
    }
    
    return p;
}
void fx() {
    // Functionality for fx
    cin >> n >> m;
    parent.assign(n, -1);
    tree.assign(n, {});
    g.assign(n, -1);
    dp.assign(n, 0);
    for(int i = 0; i < n -1; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        
        tree[a].pb(b);
        parent[b] = a;
    }
    
    for(int i = 0; i < n; i++){
        t.pb({});
        for(int j = 0; j < tree[i].size(); j++) t[i].pb({0, 0});
    }
    
    for(int i = 0; i < n; i++) if(g[i] == -1) dfs(i);
    
    dfs2(0);
    
    for(int i = 0; i < n; i++) cout << dp[i] << " ";
    cout << endl;

    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```