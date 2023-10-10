---
Question Link: https://codeforces.com/contest/1867/problem/A
Problem Set:
  - DIV2A
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Constructive
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
    int n;
    cin >> n;
    
    vii tab(n);
    for(int i = 0; i < n; i++){
        pii x;
        cin >> x.f;
        x.s = i;
        
        tab[i] = x;
    }
    
    sort(all(tab));
    reverse(all(tab));
    
    vi ans(n);
    
    int counter = 1;
    
    
    for(auto &i: tab){
        ans[i.s] = counter++;
    }
    
    for(auto &i: ans) cout << i << " ";
    cout<< endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("convention2"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

  

Idea: Pair the largest number with the smallest available number between `1 & n`.