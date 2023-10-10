---
Question Link: https://codeforces.com/problemset/problem/1000/C
Problem Set:
  - "*1700"
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Coordinate-Compression
  - Implementation
  - Sorting
  - Structure
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

\#define ll long long

void fx() {
    // Functionality for fx
    int n;
    cin >> n;
    
    map<ll, ll>offsets;
    
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        
        b++;
        
        offsets[a]++;
        offsets[b]--;
    }
    
    map<ll, ll>anss;
    
    ll prev = -10;
    ll currOffset = 0;
    for(auto &curr : offsets){
        anss[currOffset] += (curr.f - prev);
        
        prev = curr.f;
        
        currOffset += curr.s;
    }
    
    for(int i = 1; i <= n; i++){
        cout << anss[i] << " ";
    }
    
    cout << endl;
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

### Editorial (CodeForces)

> [!info] Разбор Educational Codeforces Round 46 - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/60288](https://codeforces.com/blog/entry/60288)  

### Editorial (USACO)

> [!info] Solution - Covered Points Count (CF)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cf-covered-points-count/solution](https://usaco.guide/problems/cf-covered-points-count/solution)