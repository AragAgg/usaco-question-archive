---
Question Link: https://csacademy.com/contest/archive/task/mountain-time
Problem Set:
  - CSA
Last edited time: 2024-01-03T00:55
Status: Implementation
tags:
  - DSU
  - Observation
What's up: Got Frustrated after 4-5 hours… can’t make the code work.
---
### Solution (not AC)

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

int n, m;
vvi tab;
vii h;
vi cost;

struct DSU{
    vi e;
    void init(int N){ e = vi(N, -1); }
    int get(int x){ return (e[x] < 0) ? x : e[x] = get(e[x]); }
    void unite(int a, int b){
        int x = get(a), y = get(b);
        if(x == y) return;
        if(tab[h[x].f][h[x].s] < tab[h[y].f][h[y].s]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        cost[y] = tab[h[y].f][h[y].s] - min(tab[h[a].f][h[a].s], tab[h[b].f][h[b].s]);
    }
};

vector<vector<bool>> visited;
unordered_set<int>connected;

int dfs(int node){
    if(visited[h[node].f][h[node].s]) return INT_MAX;
    int res = cost[node];
    visited[h[node].f][h[node].s] = true;
    connected.insert(node);
    for(int i = 0; i < 4; i++){
        int x = h[node].f + dx[i], y = h[node].s + dy[i];
        if(x >= 0 and x < n and y >= 0 and y < m and cost[x * m + y] > 0 and !visited[x][y]) res = min(res, dfs(x * m + y));
    }
    return res;
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    tab.assign(n, vi(m, 0));
    
    int cnt = 0;
    vii nodes;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++, cnt++){
            cin >> tab[i][j];
            h.pb({i, j});
            nodes.pb({-tab[i][j], cnt});
        }
    }

    sort(all(nodes));

    cost.assign(cnt+1, INT_MAX);
    DSU grid;
    grid.init(cnt+1);

    for(auto node: nodes){
        cost[node.s] = min(-node.f, cost[node.s]);
        for(int d = 0; d < 4; d++){
            int x = h[node.s].f + dx[d], y = h[node.s].s + dy[d];
            if(x >= 0 and x < n and y >= 0 and y < m and -node.f < tab[x][y]) grid.unite(node.s, (x * m + y));
            if(x >= 0 and x < n and y >= 0 and y < m and -node.f == tab[x][y]) cost[x * m + y] = min(cost[x * m + y], cost[node.s]), cost[node.s] = min(cost[node.s], cost[x * m + y]);
        }
    }

    visited.assign(n, vb(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] and cost[i * m + j]){
                int c = dfs(i * m + j);
                for(auto &node: connected) cost[node] = c;
                connected.clear();
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << cost[i * m + j] << " ";
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