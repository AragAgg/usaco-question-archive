---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_a
Problem Set:
  - AtCoder
Last edited time: 2023-11-17T18:03
Status: Solved
tags:
  - Dynamic-Programming
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
vi tab;
vector<ll>dp;
\#define INF 10000000000

ll fx2(int i){
    if(!i) return 0;
    if(i < 0) return INF;
    else if(dp[i] != INF) return dp[i];

    dp[i] = (i-1 >= 0)?(fx2(i-1) + abs(tab[i-1] - tab[i])):INF;
    dp[i] = min(dp[i], (i-2 >= 0)?(fx2(i-2) + abs(tab[i-2] - tab[i])):INF);

    return dp[i];
}

void fx() {
    // Functionality for fx
    ll n;
    cin >> n;
    tab.assign(n, 0);
    for(auto &i: tab) cin >> i;

    dp.assign(n, INF);

    cout << fx2(n-1) << endl;
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