---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=668
Problem Set:
  - Silver
Last edited time: 2023-12-31T02:46
Status: Solved
tags:
  - Connected-Components
  - DFS
Key Takeaway: Keep thing as simple as possible
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

int n;

struct cow{
    int x, y, p;
};

vector<cow>cows;
vvi tab;
double eps = 1e-9;

vb visited;

int dfs(int x){
    if(visited[x]) return 0;
    visited[x] = true;
    
    int ans = 1;
    for(auto &i: tab[x]){
        ans += dfs(i);
    }
    
    return ans;
}

void fx() {
    // Functionality for fx
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cow c;
        cin >> c.x >> c.y >> c.p;
        cows.pb(c);
    }
    
    tab.assign(n, {});
    
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            
            double dist = sqrt(pow(cows[i].x - cows[j].x, 2) + pow(cows[i].y - cows[j].y, 2));
            
            if(dist - eps < cows[i].p) tab[i].pb(j);
            if(dist - eps < cows[j].p) tab[j].pb(i);
        }
    }
    
    int ans = 1;
    
    for(int i = 0; i < n; i++){
        visited.assign(n, false);
        ans = max(ans, dfs(i));
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("moocast"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```