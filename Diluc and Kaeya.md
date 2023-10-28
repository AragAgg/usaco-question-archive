---
Question Link: https://codeforces.com/problemset/problem/1536/C
Problem Set:
  - "*1500"
  - Code Forces
  - DIV2C
Last edited time: 2023-10-28T10:57
Status: Solved
tags:
  - Implementation
  - Math
Key Takeaway: "a/b + c/d = (a+b)/(c+d), given that (c+d) is not equal to 0.In future you could write a full fledged simplification function (that takes care of zero values): See bottom of page!"
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
\#define endl "\n"

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

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

// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

// cin.tie(0)->sync_with_stdio(0);

void fx() {
    // Functionality for fx
    int n; cin >> n;
    
    string s;
    cin >> s;
    
    map<ll, int>m;
    double a = 0, b = 0;
    
    for(auto ch: s){
        if(ch == 'D') a++;
        b++;
        
        cout << (++m[(a/b)*1e14]) << " ";
    }
    
    cout << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

### Editorial

> [!info] Codeforces Round #724 — Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/91520](https://codeforces.com/blog/entry/91520)  

### Simplification Function

```C++
pair<int, int> getRatio(int a, int b) {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}
```