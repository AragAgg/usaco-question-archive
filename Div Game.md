---
Question Link: https://atcoder.jp/contests/abc169/tasks/abc169_d
Problem Set:
  - AtCoder
Last edited time: 2023-10-27T21:53
Status: Solved
tags:
  - Math
  - Prime-Factorisation
Key Takeaway: Instead of writing a single use root_finding method, simply write a general purpose function to implement the quadratic formula (it’s four line code).
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
    
    ll n;
    cin >> n;
    
    vi factors;
    
    for(ll i = 2; i*i <= n; i++){
        if(n%i != 0) continue;
        
        factors.pb(0);
        while(n%i == 0) factors.back()++, n /= i;
        
    }
    
    if(n > 1) factors.pb(1);
    
    ll ans = 0;
    
    for(auto expo: factors) {
        ll curr = sqrt(2*expo);
        if((curr*(curr+1))/2 <= expo) ans += curr;
        else ans += curr -1;
    }
    
    cout << ans << endl;
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

### Editorial

> [!info] Solution - Div Game (AtCoder Beginner Contest)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/ac-div-game/solution](https://usaco.guide/problems/ac-div-game/solution)