---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=925
Problem Set:
  - Platinum
Last edited time: 2023-12-05T14:22
Status: Skipped for now
tags:
  - Dynamic-Programming
What's up: Will retry later.
---
### Solution [realised that it won’t work]

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
int n, m, x, y;
vb visited;
vector<vi>c;
vvi farms;
vvi adj;
ll res = 0;
const ll mod = 1e9+7;

void visit(int node, int farm){
    if(visited[node]) return;

    visited[node] = true;
    farms[farm].pb(node);

    for(auto &neigh: adj[node]) visit(neigh, farm);
}

void dfs(int node, int parent, const ll& multiplier, ll dist){
   ll t = 0;

   for(auto &neigh: adj[node]){
       if(neigh == parent) continue;

       t += multiplier * (dist + c[node][neigh]) %mod;

       dfs(neigh, node, multiplier, (dist + c[node][neigh]) %mod);
    }

    res = (res + t) %mod;

}


void fx() {
    // Functionality for fx
    cin >> n >> m >> x >> y;
    c.assign(n+1, vi(n+1, -1));
    visited.assign(n+1, 0);
    adj.assign(n+1, {});
    
    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;

        c[a][b] = d, c[b][a] = d;
        adj[a].pb(b);
        adj[b].pb(a);

    }
    
    int farm = 1;
    farms.pb({});

    for(int i = 1; i < n+1; i++){
        if(!visited[i]) farms.pb({}), visit(i, farm++);
    }

    vector<ll>pre(farm+1, 1), suf(farm+1, 1);

    for(int i = 1; i < farm+1; i++) pre[i] = (pre[i-1] * ((farms[i].size()) * (farms[i].size() - 1) %mod)) %mod;
    for(int i = farm; i >= 1; i--) suf[i] = (suf[i+1] * ((farms[i].size()) * (farms[i].size() - 1) %mod)) %mod;

    for(int i = 1; i < farm+1; i++){
        for(auto node : farms[i]) dfs(node, -1, (pre[i-1] * suf[i+1])%mod, 0);
    }
    
    cout << res << endl;
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

### Solution [also doesn’t work]

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
int n, m, x, y;
vb visited;
vector<vi>c;
vvi farms;
vvi adj;
ll res = 0;
const ll mod = 1e9+7;

void visit(int node, int farm){
    if(visited[node]) return;

    visited[node] = true;
    farms[farm].pb(node);

    for(auto &neigh: adj[node]) visit(neigh, farm);
}

vector<ll>dp1(1001*1001, 0);
void dfs(int node, int parent, vector<ll>&dp2, ll dist){
   ll t = 0;

   for(auto &neigh: adj[node]){
       if(neigh == parent) continue;
       dp2[dist]++;
       dfs(neigh, node, dp2, (dist + c[node][neigh]) %mod);
    }

}


void fx() {
    // Functionality for fx
    cin >> n >> m >> x >> y;
    c.assign(n+1, vi(n+1, -1));
    visited.assign(n+1, 0);
    adj.assign(n+1, {});
    
    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;

        c[a][b] = d, c[b][a] = d;
        adj[a].pb(b);
        adj[b].pb(a);

    }
    
    int farm = 1;
    farms.pb({});

    for(int i = 1; i < n+1; i++){
        if(!visited[i]) farms.pb({}), visit(i, farm++);
    }
    
    dp1[0] = 1;

    for(auto f: farms){

        vector<ll>dp2(1001*1001, 0);
        for(auto node: f){
            dfs2(node, -1, 0, dp2);
        }

        for(int i = 0; i < dp2.size(); i++){
            for(int j = 0; j < dp1.size();
        }
    }

    
    cout << res << endl;
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