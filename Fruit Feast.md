---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=574
Problem Set:
  - Gold
Last edited time: 2023-12-02T12:45
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
ll t, a, b;

int dp[2][5000001];

int fx2(int n, bool flag){
    if(n > t) return -1;
    if(dp[flag][n] != -1) return dp[flag][n];
    
    dp[flag][n] = max({n, fx2(n + a, flag), fx2(n + b, flag), ((!flag?fx2(n/2, !flag):-1))});
    return dp[flag][n];
}

void fx() {
    // Functionality for fx
    cin >> t >> a >> b;
    for(int i = 0; i < 2; i++) for(int j = 0; j < t+1; j++) dp[i][j] = -1; 

    cout << fx2(0, 0) << endl;

}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("feast"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```