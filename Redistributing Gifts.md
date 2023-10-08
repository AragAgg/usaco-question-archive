---
Question Link: http://usaco.org/index.php?page=viewproblem2&cpid=1206
Problem Set:
  - Silver
Last edited time: 2023-10-08T23:06
Status: Seen Editorial
tags:
  - Connected-Components
  - DFS
  - Floyd-Warshall's
  - Retry
Key Takeaway: Problem Modelling is probably the toughest thing about graph questions.
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
int n;

vb visited;

bool dfs(int x, int root){
    if(visited[x]) return false;
    
    visited[x] = true;
    
    for(auto &i: tab[x]){
        if(i == x) break;
        if(i == root or dfs(i, root)){
            return true;
        }
    }
    
    return false;
}

void fx() {
    // Functionality for fx
    cin >> n;
    tab.assign(n+1, {});
    
    for(int i = 1; i < n+1; i++){
        tab[i].assign(n, 0);
        for(int j = 0; j < n; j++) cin >> tab[i][j];
    }
    
    for(int i = 1; i < n+1; i++){
        visited.assign(n+1, false);
        int counter = 0;
        
        while(true){
            if((tab[i][counter] == i) or dfs(tab[i][counter], i)){
                cout << tab[i][counter] << endl;
                break;
            }
            
            counter++;
        }
    }
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

### Other Solution Ideas

1. Use Floyd Warshall’s to calculate reachability between all pair of nodes, then go thorough all nodes, and find the first node that’s reachable in the node’s preference list. O(N^3)
2. Use the concept of SCC to find cycle’s in CCs, and then go through the node’s preference list and find the first gift that’s in the node’s SCC.

  

### Official Analysis

> [!info] Contest Results  
> Let's start by constructing a  
> [http://www.usaco.org/current/data/sol_prob1_silver_feb22.html](http://www.usaco.org/current/data/sol_prob1_silver_feb22.html)  

### Editorial

> [!info] Solution - Redistributing Gifts (USACO Silver 2022 February)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-1206-redistributing-gifts/solution](https://usaco.guide/problems/usaco-1206-redistributing-gifts/solution)