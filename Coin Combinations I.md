---
Question Link: https://cses.fi/problemset/task/1635/
Problem Set:
  - CSES
Last edited time: 2023-11-18T02:57
Status: Solved
tags:
  - Dynamic-Programming
Key Takeaway: Try to avoid as many % operations as possible. If you have them in a loop, try to see if you maybe limit to number of times that gets executed.
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

vector<ll> coins;
vector<ll> dp;
ll mod = 1e9+7;

ll fx2(ll sum){
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(dp[sum] != -1) return dp[sum];
    ll res = 0;
    for(auto coin : coins) res = (res + fx2(sum - coin));
    res %= mod;
    return dp[sum] = res;
}
void fx() {
    // Functionality for fx
    ll n, x;
    cin >> n >> x;
    coins.assign(n, 0);
    for(auto &i: coins) cin >> i;
    dp.assign(1000001, -1);
    cout << fx2(x) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```