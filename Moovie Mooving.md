---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=515
Problem Set:
  - Gold
Last edited time: 2023-12-14T12:17
Status: Solved
tags:
  - Dynamic-Programming
What's up: O(2^N* NlogC) solution passes…. ~\_( ‘ ‘ )_/~
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
typedef vector<ll> vi;
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
    ll n, l, c;
    cin >> n >> l;

    vi duration(n);
    vvi tab(n);
    for(int i = 0; i < n;  i++){
        cin >> duration[i] >> c;
        tab[i].assign(c, 0);

        for(int j = 0; j < c; j++) cin >> tab[i][j];
    }
    
    vector<ll>dp(1 << n, 0);

    int res = INT_MAX;    

    for(int mask = 0; mask < (1 << n); mask++){
        if(dp[mask] == l) res = min(res, __builtin_popcount(mask));

        for(int bit = 0; bit < n; bit++){
            if(mask & ( 1 << bit )) continue;

            auto iter = lower_bound(all(tab[bit]), dp[mask]);
            if(iter != tab[bit].end() and *iter == dp[mask]) dp[mask | ( 1 << bit )] = max(dp[mask | ( 1<<bit)], min(dp[mask] + duration[bit], l));

            if(iter != tab[bit].begin()) dp[mask | ( 1 << bit )] = max(dp[mask | ( 1 << bit)], min(duration[bit] + *prev(iter), l));
            
        }
    }

    if(res == INT_MAX) cout << "-1" << endl;
    else cout << res << endl;


}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("movie"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```