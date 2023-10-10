---
Question Link: https://codeforces.com/problemset/problem/1176/E
Problem Set:
  - "*1700"
  - Code Forces
  - DIV3E
Last edited time: 2023-10-10T20:20
Status: Solved
tags:
  - Bipartite
  - DFS
  - Tree
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
vi color;
int red;
int blue;


void dfs(int x, bool col){
    (col?red:blue)++;
    
    color[x] = col;
    
    for(auto &i: tab[x]){
        if(color[i] != -1) continue;
        
        dfs(i, !col);
    }
}

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;
    
    tab.assign(n+1, {});
    color.assign(n+1, -1);
    red = 0;
    blue = 0;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        tab[a].pb(b);
        tab[b].pb(a);
    }
    
    dfs(1, 1);
    
    if(red < blue){
        cout << red << endl;
        
        for(int i = 1; i < n+1; i++){
            if(color[i] == 1) cout << i << " ";
        }
        
    }else{
        cout << blue << endl;
        
        for(int i = 1; i < n+1; i++){
            if(color[i] == 0) cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

### Editorial

> [!info] Codeforces Round #565 (Div. 3) Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/67598](https://codeforces.com/blog/entry/67598)