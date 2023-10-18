---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=858
Problem Set:
  - CSES
  - Silver
Last edited time: 2023-10-18T19:10
Status: Solved
tags:
  - Binary-Search
  - Sorting
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

int n, m, c;
vi tab;

bool isVaible(int k){
    int iter = 0;
    
    int buses = m;
    
    while(iter != n and buses){
        // cout << " # " << iter << endl;
        int cows = c-1;
        
        int initCow = tab[iter++]; 
        
        while(iter != n and (tab[iter] - initCow <= k) and buses and cows){
            cows--;
            iter++;
        }
        
        buses--;
        
    }
    
    return (iter == n);
}

void fx(){
    cin >> n >> m >> c;
    tab.assign(n, 0);
    for(auto &i: tab) cin >> i;
    
    sort(all(tab));
    
    int low = 0;
    int high = 1e9+10;
    
    while(low < high){
        int mid = low + (high - low)/2;
        // cout << mid << endl;
        if(isVaible(mid)) high = mid; // <-possibly buggy...
        else low = mid+1;
    }
    
    cout << low << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("convention"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Solution - Convention (USACO Silver 2018 December)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-858-convention/solution](https://usaco.guide/problems/usaco-858-convention/solution)