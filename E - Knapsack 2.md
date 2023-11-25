---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_e
Problem Set:
  - AtCoder
Last edited time: 2023-11-25T19:41
Status: Nice Question
tags:
  - Dynamic-Programming
What's up: The end part of the solution is a bit dumb, as i try to maximise index of dp array where the value is suitable, whereas i just could have found the last index which is suitable.
Key Takeaway: "Dynamic Programming is magic. "
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
    ll n, w;
    cin >> n >> w;

    vector<ll>dp(1e5+1, LLONG_MAX);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        ll weight, value;
        cin >> weight >> value;

        for(int j = 1e5; j >= 0; j--) if(j + value <= 1e5 and dp[j] < LLONG_MAX) dp[j + value] = min(dp[j + value], dp[j] + weight);
    }

    ll res = 0;

    for(ll i = 0; i <= 1e5; i++) if(dp[i] <= w) res = max(res, i);

    cout << res << endl;
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