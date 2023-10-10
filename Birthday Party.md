---
Question Link: https://open.kattis.com/problems/birthday
Problem Set:
  - Kattis
  - Medium
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Connected-Components
  - DFS
Key Takeaway: Just write the simplest possible code that would still get accepted.
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long

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

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

vvi tab;
vb visited;

void dfs(int x, int a, int b){
    if(visited[x]) return;
    visited[x] = true;
    
    for(auto neigh: tab[x]){
        if((x == a and neigh == b) or (x == b and neigh == a)) continue;
        
        dfs(neigh, a, b);
    }
}

bool fx(int n, int c) {
    // Functionality for fx
    
    tab.clear();
    tab.assign(n, {});
    visited.clear();
    
    vii connections;
    
    for(int i = 0; i < c; i++){
        int a, b;
        cin >> a >> b;
        
        tab[a].pb(b);
        tab[b].pb(a);
        
        connections.pb({a, b});
    }
    
    for(int i = 0; i < c; i++){
        visited.assign(n, false);
        dfs(0, connections[i].f, connections[i].s);
        
        for(auto i: visited) if(!i) return true;
    }
    
    
    return false;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    // fx();
    
    int p, c;
    
    while(true){
        cin >> p >> c;
        
        if(p == 0 and c == 0) return 0;
        
        cout << (fx(p, c)?"Yes":"No") << endl;
    }
    
    return 0;
}
```

### Editorial

> [!info] Solution - Birthday Party (VT HSPC 2014)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/kattis-birthday-party/solution](https://usaco.guide/problems/kattis-birthday-party/solution)