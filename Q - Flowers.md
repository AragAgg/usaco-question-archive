---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_q
Problem Set:
  - AtCoder
Last edited time: 2024-04-17T02:29
Status: "Very Interesting "
tags:
  - Dynamic-Programming
What's up: Solved. Make sure to check the editorial.
Key Takeaway: If the time complexity of O(NlogN) is allowed without it being too tight, you could use better data structures in order to ease implementation.
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
    int n;
    cin >> n;
    vi h(n, 0), b(n, 0);
    for(auto &i: h) cin >> i;
    for(auto &i: b) cin >> i;

    map<int, ll>dp;
    dp[0] = 0;
    dp[h[0]] = b[0];

    for(int i = 1; i < n; i++){
        auto itr = (dp.insert({h[i], 0})).f;
        if((*itr).s < (*prev(itr)).s + b[i]) (*itr).s = (*prev(itr)).s + b[i];
        auto n = next(itr);
        while(n != dp.end() and (*n).s < (*itr).s) n = dp.erase(n);
    }
    cout << dp.rbegin()->s << endl;
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

  

  

Another solution idea: use the height of the flower as the index of the array to update the segment tree, and then query for each flower (0 - > height of flower) and add the beauty value of the current flower to the best yet until height of flower), ans is max of all those values.