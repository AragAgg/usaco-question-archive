---
Question Link: https://www.spoj.com/problems/PR003004/
Problem Set:
  - SPOJ
Last edited time: 2023-12-21T14:55
Status: Solved
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

// cin.tie(0)->sync_with_stdio(0);
string s;
unsigned ll dp[20][2][200];

unsigned ll fx2(int digit, bool tight, int pre){
    if(s == "-1" or digit == s.size()) return pre;

    if(dp[digit][tight][pre] != -1) return dp[digit][tight][pre];
    else dp[digit][tight][pre] = 0;

    for(int d = 0; d <= (tight?(s[digit]-'0'):9); d++) 
        dp[digit][tight][pre] += fx2(digit+1, (tight and d == (s[digit] -'0')), pre + d);

    return dp[digit][tight][pre];
}


void fx() {
    // Functionality for fx
    ll x, y;
    cin >> x >> y;

    s = to_string(--x);
    memset(dp, -1, sizeof(dp));
    ll X = fx2(0, 1, 0);

    s = to_string(y);
    memset(dp, -1, sizeof(dp));
    cout << (fx2(0, 1, 0) - X) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    //fx();
    
    return 0;
}
```