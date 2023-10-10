---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=416
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - 2D-Prefix-Sum
Key Takeaway: If the solution construct is within a narrow band of the required time limit, search for some sort of constant time optimization, try to memoize helper function calls.An over-optimized solution is every bit bad as an under-optimised one.
---
### Solution

```JavaScript
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

vvi pre;
int n;

int fx2(int i, int j, int k){
    int res;
    int ul = min(n-1, j+k);
    
    if(j-k-1 < 0) res = pre[i][ul];
    else res = pre[i][ul] - pre[i][j-k-1];
    
    return res;
}

void fx() {
    // Functionality for fx
    int K; cin >> n >> K;
    vvi tab(n, vi(n));
    pre.assign(n, vi(n));
    int res = INT_MIN;
    
    for(int i = 0; i < n; i++){
        int offset = 0;
        
        for(int j= 0; j < n; j++){
            cin >> tab[i][j];
            offset += tab[i][j];
            pre[i][j] = offset;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            int x = i;
            int ans = 0;
            int k = K;
            
            while(x >= 0 and k >= 0) ans += fx2(x--, j, k--);
            
            x = i+1;
            k = K-1;
            
            while(x < n and k >= 0) ans +=fx2(x++, j, k--);
            
            res = max(res, ans);
        }
    }
    
    
    cout << res << endl;
    
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("lazy"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Alternate Solution (I don’t understand it)

### 45-Degree Rotation:

The 45-degree rotation is a clever trick used in this problem to simplify the area Bessie can move in. Let's delve into why it works:

- **Original Problem**:
    
    In the original problem, Bessie can move a maximum of `K` steps in any direction, including diagonally. This means that if you were to plot her possible movement on the grid, it would form a diamond shape.
    
- **After 45-Degree Rotation**:
    
    When you rotate the grid by 45 degrees, the diamond shape becomes a square. This is because the diagonals of the original grid (which formed the boundaries of the diamond) become the horizontal and vertical lines of the rotated grid.
    
- **Simplification**:
    
    Working with a square is much simpler than working with a diamond. In the rotated grid, to find out how much grass Bessie can eat starting from a particular cell, you just need to compute the sum of the elements in a square subgrid. This can be done efficiently using a prefix sum array.
    

  

### Editorial (Based on Matrix Rotation)

[http://www.usaco.org/current/data/sol_lazy_silver.html](http://www.usaco.org/current/data/sol_lazy_silver.html)