---
Question Link: https://codeforces.com/contest/1520/problem/F1
Problem Set:
  - "*1600"
  - Code Forces
  - DIV3F
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Binary-Search
  - Interactive
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

int N, T, K;

bool isViable(ll mid){
    cout << "? 1 " << (mid+1) << endl;
    cout.flush();
    
    int f;
    cin >> f;
    
    if(f == -1) exit(0);
    
    return (mid + 1 -f >= K);
}

void fx() {
    // Functionality for fx
    cin >> N >> T >> K;
    
    int lo = 0;
    int hi = N;
    
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        
        if(isViable(mid)) hi = mid;
        else lo = mid +1;
    }
    
    cout << "! " << (lo+1) << endl;
    cout.flush();
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