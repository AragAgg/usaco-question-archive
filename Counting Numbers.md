---
Question Link: https://cses.fi/problemset/result/7776525/#test15
Problem Set:
  - CSES
Last edited time: 2023-11-25T14:45
Status: Nice Question
tags:
  - Digit-DP
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
\#define int ll
// cin.tie(0)->sync_with_stdio(0);
ll dp[2][2][19][10] = {0};
string s;
int limit;

ll fx3(int digit, int prev, bool flag, bool allZeroes){
    
    if(digit == limit) return 1;
    if(dp[allZeroes][flag][digit][prev] != -1)return dp[allZeroes][flag][digit][prev];

    ll res = 0;
    for(int i = 0; i < 10; i++){
        if(flag and (i > ((int)(s[digit] - '0')))) break;

        if(i == prev and (!(prev == 0 and allZeroes))) continue;
        res += fx3(digit+1, i, (flag and i == (int)(s[digit] - '0')), (allZeroes and i == 0));
    }

    return dp[allZeroes][flag][digit][prev] = res;
}
ll fx2(ll a){
    if(a < 0) return 0;
    if(a == 0) return 1;
    for(int i = 0; i < 2; i++) for(int j = 0; j < 19; j++) for(int k = 0; k < 10; k++) dp[0][i][j][k] = -1, dp[1][i][j][k] = -1;

    s = to_string(a);
    limit = (s.size()) ;
    ll res = 0;
    for(int i = 0; i < (int)(s[0] - '0'); i++) res += fx3(1, i, false, (i == 0));
    
    res += fx3(1, (int)(s[0] - '0'), true, false);

    return res;
}

void fx() {
    // Functionality for fx
    ll a, b;
    cin >> a >> b;
    cout << (fx2(b) - fx2(--a)) << endl;
}

signed main() {
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