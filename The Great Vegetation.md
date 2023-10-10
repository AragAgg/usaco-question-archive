---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=916
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Graph-Partition
---
### Solution

```Markup
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

vi color;
vvi tab;

void fx2(int root){
    vb p(4, 1);
    
    for(auto &neigh : tab[root]){
        if(color[neigh] == -1) continue;
        
        p[color[neigh]] = false;
    }
    
    int cc = 0;
    while(!p[cc]) cc++;
    
    color[root] = cc;
}

void fx(){
    int n, m;
    cin >> n >> m;
    
    color.assign(n, -1);
    tab.assign(n, {});
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        tab[a-1].pb(b-1);
        tab[b-1].pb(a-1);
    }
    
    for(int i = 0; i < n; i++) fx2(i);
    
    for(auto c: color) cout << c +1;
    
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("revegetate"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```