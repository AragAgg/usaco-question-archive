---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=594
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Binary-Search
  - Greedy
  - Simulation
  - Sorting
What's up: Binary search the value of R. [firstTrue() on a monotonic function]
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

int k;
set<int>locs;

bool isViable(int r){
    auto iter = locs.begin();
    int rem = k;
    
    while(iter != locs.end() and rem){
        rem--;
        iter = locs.upper_bound(*iter + 2*r);
    }
    
    return (iter == locs.end());
}

void fx(){
    int n;
    cin >> n >> k;
    
    while(n--){
        int t;
        cin >> t;
        locs.insert(t);
    }
    
    int lo = 0, hi = 2e9;
    
    while(lo < hi){
        int mid = (lo) + (hi - lo)/2;
        
        if(isViable(mid)) hi = mid;
        else lo = mid +1;
    }
    
    cout << lo << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("angry"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```