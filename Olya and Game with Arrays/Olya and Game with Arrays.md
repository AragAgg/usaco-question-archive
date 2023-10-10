---
Question Link: https://codeforces.com/contest/1859/problem/B
Problem Set:
  - DIV2B
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Constructive
  - Greedy
  - Math
  - Sorting
---
### Solution (AC)

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

void fx() {
    int n; cin >> n;
    
    vvi tab(n);
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        
        while(m--){
            int t; cin >> t;
            
            tab[i].pb(t);
        }
        
        sort(all(tab[i]));
    }
    
    int worst = tab[0][1];;
    int wi = 0;
    
    for(int i = 0; i < n; i++){
        if(tab[i][1] < worst){
            worst = tab[i][1];
            
            wi = i;
        }
    }
    // debug(wi);
    for(int i = 0; i < n; i++){
        debug_vector(tab[i]);
        if(i == wi) continue;
        
        tab[wi].pb(tab[i][0]);
    
    }
    
    sort(all(tab[wi]));
    
    
    
    
    long long ans = 0;
    
    for(int i = 0; i < n; i++){
        if(i == wi) ans += tab[i][0];
        else ans += tab[i][1];
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

### ChatGPT Explanation of Solution (possibly buggy)

![[Screenshot_2023-08-13_at_1.11.52_PM.png]]

### Editorial

![[Screenshot_2023-08-13_at_1.12.31_PM.png]]