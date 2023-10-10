---
Question Link: https://codeforces.com/contest/1860/submission/219302077
Problem Set:
  - DIV2B
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Greedy
  - Math
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

void fx() {
    // Functionality for fx
    int m, k, a, b;
    cin >> m >> k >> a >> b;
    
    // int x = m - k*min(b, ((b > 0)?(m/k):(0)));
    
    // int y = x - min(a, x);
    
    // int ans1 = y/k;
    
    // int ans2 = y - ans1;
    
    int normalb = (b <= 0)?(0):min(b, m/k);
    
    int normala = min(a, m - k*normalb);
    
    int fancyb = (m - normalb*k - normala)/k;
    
    int fancya = (m - (normalb + fancyb)*k - normala);
    
    if(((fancya)%k + normala) >= k and fancya >= 2){
        int a = k - (fancya)%k;
        
        fancya -= fancya%k;
        fancyb++;
    }
    
    cout << (fancya + fancyb) << endl;
    
    // cout << (ans1 + ans2) << endl;
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

### Solution Explanation

Alright, let's break down and explain this solution step by step:

### Preprocessing and Macros

The given solution starts with a collection of `#include` directives, type definitions, and macros. These are mainly for the programmer's convenience and for debugging purposes.

### Main Functionality: fx()

1. The function starts by reading the inputs `m`, `k`, `a`, and `b`.
2. It then calculates the number of regular coins of type \(k\) (`normalb`) that should be used. We need to check if \(b \leq 0\) because if there are no regular coins of type \(k\), then \(normalb\) should be zero. Otherwise, it's the minimum between `b` and \(m/k\), ensuring we don't use more coins than needed or available.
3. Next, it calculates the number of regular coins of type \(1\) (`normala`) that should be used. This is the minimum of `a` and the remaining amount after deducting the value provided by `normalb` coins of type \(k\).
4. Now, the solution calculates the number of fancy coins of type \(k\) (`fancyb`) and type \(1\) (`fancya`) needed after using the regular coins. The idea here is to first utilize as many of the larger denomination coins as possible (fancy coins of type \(k\)), and then fill up the remaining amount with the smaller denomination coins (fancy coins of type \(1\)).
5. The block of code under the `if` condition checks whether it's more optimal to use another fancy coin of type \(k\) instead of multiple fancy coins of type \(1\). If so, the necessary adjustments are made to `fancya` and `fancyb`.
6. Finally, the function outputs the total number of fancy coins used, which is the sum of `fancya` and `fancyb`.

### Main()

This is the driver function that reads the number of test cases and then processes each test case using the `fx()` function.

### Editorial

TBA