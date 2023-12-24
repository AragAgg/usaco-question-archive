---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=491
Problem Set:
  - Silver
Last edited time: 2023-12-24T14:47
Status: Nice Question
tags:
  - BFS
Key Takeaway: Try using Reverse BFS
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
void bfs(int start, int c, vi &cost){
    vi visited(cost.size(), 0);
    queue<int>q;
    q.push(start);
    cost[start] = 0;
    visited[start] = 1;

    while(!q.empty()){
        auto curr = q.front(); q.pop();

        for(auto neigh: adj[curr]){
            if(visited[neigh]) continue;
            visited[neigh] = 1;
            cost[neigh] = cost[curr] + c;
            q.push(neigh);
        }
    }
}

void fx() {
    // Functionality for fx
    int b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;

    adj.assign(n, {});
    vi bessie(n, 0), elsie(n, 0), piggy(n, 0);

    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        adj[--n1].pb(--n2);
        adj[n2].pb(n1);
    }

    bfs(0, b, bessie);
    bfs(1, e, elsie);
    bfs(n-1, p, piggy);

    int res = bessie[n-1] + elsie[n-1];
    for(int i = 0; i < n; i++) res = min(res, bessie[i] + elsie[i] + piggy[i]);
    cout << res << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("piggyback"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```