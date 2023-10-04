---
Question Link: https://codeforces.com/contest/847/problem/B
Problem Set:
  - "*1600"
  - Code Forces
Last edited time: 2023-10-04T20:38
Status: Seen Editorial
tags:
  - Binary-Search
  - Implementation
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

void fx() {
    // Functionality for fx
    int N;
    cin >> N;
    
    vvi tab;
    
    while(N--){
        int curr; 
        cin >> curr;
        
        int lo = 0;
        int hi = tab.size();
        
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(tab[mid].back() < curr) hi = mid;
            else lo = mid +1;
        }
        
        if(lo == tab.size()) tab.pb({curr});
        else tab[lo].pb(curr);
    }
    
    for(auto i: tab){
        for(auto item: i) cout << item << " ";
        cout << endl;
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