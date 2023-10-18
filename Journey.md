---
Question Link: https://codeforces.com/contest/839/problem/C
Problem Set:
  - "*1500"
  - Code Forces
  - DIV2C
Last edited time: 2023-10-18T13:44
Status: Nice Question
tags:
  - DFS
  - Dynamic-Programming
  - Probability-&-Expected-Value
  - Tree
What's up: Had to take a hint.
Key Takeaway: Pay attention to the question wording if the authors use works like with equal probability and probability depending on the height of the node. It’s usually a sign that the authors expect some use of probability.
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

vvi tab;

double dfs(int x, int prev, int height){
    bool flag = true;
    
    
    double curr = 0;
    int branches = 0;
    
    for(auto neigh: tab[x]){
        if(neigh == prev) continue;
        
        curr += dfs(neigh, x, height +1);
        flag = false;
        branches++;
    }
    
    if(flag) return 0;
    else return (curr/branches + 1);
}

void fx() {
    int n;
    cin >> n;
    
    tab.assign(n, {});
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        
        tab[--a].pb(--b);
        tab[b].pb(a);
    }
    
    cout << setprecision(10) << fixed << (dfs(0, -1, 0)) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Codeforces Round #428 editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/53815](https://codeforces.com/blog/entry/53815)  

> [!info] Solution - Journey (CF)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cf-journey/solution](https://usaco.guide/problems/cf-journey/solution)