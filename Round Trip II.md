---
Question Link: https://cses.fi/problemset/task/1678
Problem Set:
  - CSES
Last edited time: 2024-01-03T20:17
Status: Nice Question
tags:
  - Cycle
  - Implementation
  - Topological-Sort
Key Takeaway: If the no of element in the array containing the topological ordering of a graph (found using the khan’s algo) is no equal to the number of nodes in the graph, then the graph must have a cycle.
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
vvi adj;
vi vis;
vi res;

const int instack = 1;
const int unvisited = 0;
const int visited = 2;
bool cycle = false;
int last;

bool dfs(int node){
    if(vis[node] == instack){ res.pb(node); last = node; cycle = true; return true;} 
    vis[node] = instack;
    
    for(auto &neigh: adj[node]){
        if(vis[neigh] != visited and dfs(neigh)){
            if(cycle) res.pb(node);
            if(node == last) cycle = false;
            return true;
        }
    }

    vis[node] = visited;
    return false;
}

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;
    adj.assign(n, {});

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[--a].pb(--b);
    }

    vis.assign(n, unvisited);

    for(int i = 0; i < n; i++){
        if(vis[i] == unvisited){
            if(dfs(i)) break;
        }
    }

    if(res.size() == 0) cout << "IMPOSSIBLE" << endl;
    else{
        reverse(all(res));
        cout << res.size() << endl;
        for(auto &i: res) cout << (1+i) << " ";
        cout << endl;
    }
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