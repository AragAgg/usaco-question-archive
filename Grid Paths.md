---
Question Link: https://cses.fi/problemset/task/1638/
Problem Set:
  - CSES
Last edited time: 2023-11-18T04:37
Status: Solved
tags:
  - Dynamic-Programming
Key Takeaway: Let’s not get lost in the sea of debate over which DP method is the best (top-down or bottom-up), we will bend and use whatever is at our disposal to solve the given quesition.
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

    vvi dp(n, vi(n, 0));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++) if(s[j] == '*') dp[i][j] = -1;
    }
    if(dp[0][0] == -1 or dp[n-1][n-1] == -1){
        cout << 0 << endl;
        return;
    }
    int mod = 1e9+7;
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] == -1) continue;

            if(i < n-1 and dp[i+1][j] != -1) dp[i+1][j] = ( dp[i+1][j] + dp[i][j] )%mod;
            if(j < n-1 and dp[i][j+1] != -1) dp[i][j+1] = ( dp[i][j+1] + dp[i][j] )%mod;
        }
    }
    cout << dp[n-1][n-1] << endl;
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