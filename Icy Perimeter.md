---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=895
Problem Set:
  - Silver
Last edited time: 2023-10-14T11:23
Status: Solved
tags:
  - Flood-Fill
Key Takeaway: When implementing floodfill, try to initialise all state variables in global
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

vector<string>tab;
vvi visited;
int n;

void dfs(int i, int j, pii &res){
    if(i < 0 or i >= n or j < 0 or j >= n){
        res.s++;
        return;
    }else if(tab[i][j] == '.'){
        res.s++;
        return;
    }else if(visited[i][j]) return;
    
    res.f++;
    visited[i][j] = true;
    
    dfs(i+1, j, res);
    dfs(i-1, j, res);
    dfs(i, j+1, res);
    dfs(i, j-1, res);
}

void fx() {
    cin >> n;
    
    visited.assign(n, vi(n, 0));
    tab.assign(n, "");
    for(auto &i: tab) cin >> i;
    
    pii ans = {INT_MIN, INT_MIN};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) continue;
            
            pii curr = {0, 0};
            
            dfs(i, j, curr);
            
            if(curr.f > ans.f) ans = curr;
            else if(curr.f == ans.f and curr.s < ans.s) ans = curr;
            
        }
    }
    
    cout << ans.f << " " << ans.s;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("perimeter"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```