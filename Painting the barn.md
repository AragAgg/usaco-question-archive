---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=919
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - 2D-Prefix-Sum
---
### Solution

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

void fx() {
    // Functionality for fx
    int n, k; cin >> n >> k;
    
    vvi tab(1002, vi(1002, 0));
    
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        x1++; y1++; x2; y2;
        
        tab[x1][y1]++;
        tab[x2+1][y2+1]++;
        tab[x1][y2+1]--;
        tab[x2+1][y1]--;
        
        
    }
    
    int ans = 0;
    
    for(int x = 1; x < 1002; x++){
        for(int y = 1; y < 1002; y++){
            tab[x][y] += (tab[x][y-1] + tab[x-1][y] - tab[x-1][y-1]);
            
            if(tab[x][y] == k) ans++;
        }
        
    }
    
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("paintbarn"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```