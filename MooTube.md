---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=788
Problem Set:
  - Silver
Last edited time: 2023-10-18T12:22
Status: Solved
tags:
  - Connected-Components
  - Tree
Key Takeaway: When exploring a tree, it might be helpful to pass a prev variable to make sure we don’t traverse backwards, instead of using the normal method of visited array.
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

int n, q;
vector<vii>tab;

int dfs(int v, int r, int prev){
    
    int ans = 1;
    for(auto edge: tab[v]){
        if(edge.s >= r and prev != edge.f) ans += dfs(edge.f, r, v);
    }
    
    return ans;
}

void fx() {
    cin >> n >> q;
    
    tab.assign(n, {});
    
    for(int i = 0; i < n -1 ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        tab[--a].pb({--b, c});
        tab[b].pb({a, c});
    }
    
    while(q--){
        int v, r;
        cin >> r >> v;
        v--;
        cout << (dfs(v, r, -1)-1) << endl;
    }
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("mootube"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Solution - Mootube (USACO Silver 2018 January)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-788-mootube/solution](https://usaco.guide/problems/usaco-788-mootube/solution)