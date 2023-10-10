---
Question Link: https://codeforces.com/contest/1859/problem/C
Problem Set:
  - DIV2C
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Greedy
What's up: "Proof by AC: Found a patter on small values of n, used it to form a solution."
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

void fx(){
    
    int n; cin >> n;
    vi tab(n);
    
    for(int i = 1; i <= n; i++) tab[i-1] = i;
    
    
    int ans = INT_MIN;
    
    for(int i = 0; i < tab.size(); i++){
        reverse(tab.begin()+i, tab.end());
        
        int cost = 0;
        int m = INT_MIN;
        
        for(int i = 0; i < tab.size(); i++){ cost += tab[i]*(i+1); m = max(m, tab[i]*(i+1));}
        
        cost -= m;
        
        ans = max(ans, cost);
        
        reverse(tab.begin()+i, tab.end());
    }
    
    cout << ans << endl;
    

    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

  

`Solved by seriouslyFlawed, Proved by AC.`