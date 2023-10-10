---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=810
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Greedy
  - Observation
  - Sorting
---
### Solution (AC) [time complexity: O(NlogN)]

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



void fx(){
    long long l, n, f, b;
    cin >> l >> n >> f >> b;
    
    int farmerDist = 0;
    long long ans = 0;
    int bessieDist = 0;
    
    priority_queue<pii>pq;
    
    for(int i = 0; i < n; i++){
        pii t;
        cin >> t.s >> t.f;
        
        pq.push(t);
    }
    
    while(!pq.empty()){
        if(pq.top().s <= bessieDist){ pq.pop(); continue; }
        
        ans += ((pq.top().s - farmerDist)*f - (pq.top().s - bessieDist)*b)*pq.top().f;
        
        farmerDist = bessieDist = pq.top().s;
        
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("reststops"));

    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial [time complexity: O(N)]

> [!info] Solution - Rest Stops (USACO Silver 2018 Silver)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-810-rest-stops/solution](https://usaco.guide/problems/usaco-810-rest-stops/solution)