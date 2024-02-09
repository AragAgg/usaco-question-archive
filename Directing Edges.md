---
Question Link: https://codeforces.com/contest/1385/problem/E
Problem Set:
  - Code Forces
Last edited time: 2024-02-09T07:16
Status: Solved
tags:
  - Topological-Sort
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
int n, m;   
vi topSort, visited;
vvi edges;
vvi adj;

bool fx2(int i){
    visited[i] = -1;
    for(auto &neigh: adj[i]) {
        if(visited[neigh] == -1) return false;
        else if(!visited[neigh] and !fx2(neigh)) return false;
    }

    topSort.pb(i);
    visited[i] = 1;
    return true;
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    topSort.clear(), visited.clear();
    adj.assign(n, {});
    edges.assign(n, {});

    int dir, x, y;

    for(int i = 0; i < m; i++){
        cin >> dir >> x >> y;
        --x; --y;
        if(dir) adj[x].pb(y);
        else edges[x].pb(y), edges[y].pb(x);
    }

    visited.assign(n, false);
    
    for(int i = 0; i < n; i++){
        if(!visited[i] and !fx2(i)){
            no();
            return;
        }
    }

    reverse(all(topSort));

    vi rank(n);
    int r = 0;
    for(auto &i: topSort) rank[i] = r++;

    for(int c = 0; c < n; c++){
        int i = topSort[c];

        for(auto j : edges[i]){
            if(rank[i] < rank[j]) adj[i].pb(j);
        }
    }

    int sum = 0;
    for(auto &neigh: adj) sum += neigh.size();

    if(sum != m) no();
    else{
        yes();
        for(int i = 0; i < n; i++){
            for(auto &neigh: adj[i]) cout << (i+1) << " " << (neigh+1) << endl;
        }
    }

}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t; while(t--) fx();
    
    // Single test case
    //fx();
    
    return 0;
}
```