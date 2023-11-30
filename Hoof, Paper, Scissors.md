---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=691
Problem Set:
  - Silver
Last edited time: 2023-11-30T12:41
Status: Solved
tags:
  - Game
  - Prefix-Sums
Key Takeaway: Instead of Storing suffix sum in a different structure, try counting the number of occurrences of different states and then subtract the current prefix sum from it to get the suffix sum till the current time.
---
### Solution

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
    int n; cin >> n;
    
    vi f(3, 0);
    vi p(3, 0);
    
    vi tab;
    
    while(n--){
        char c;
        cin >> c;
        
        if(c == 'H'){ tab.pb(0); f[0]++;}
        else if(c == 'P'){ tab.pb(1); f[1]++; }
        else{ tab.pb(2); f[2]++;}
    
    }
    
    int ans = 0;
    
    for(auto &r: tab){
        p[r]++;
        f[r]--;
        
        ans = max(ans, (*max_element(p.begin(), p.end()) + *max_element(f.begin(), f.end())));
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("hps"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

[https://usaco.guide/problems/usaco-691-hoof-paper-scissors/solution](https://usaco.guide/problems/usaco-691-hoof-paper-scissors/solution)