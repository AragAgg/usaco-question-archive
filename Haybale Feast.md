---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=767
Problem Set:
  - Gold
Last edited time: 2024-03-24T16:04
Status: Solved
tags:
  - Two-Pointer
---
### Solution (AC)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define p push
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
//\#define int ll
\#define endl "\n"
\#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

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


void fx() {
    // Functionality for fx
    ll n, k;
    cin >> n >> k;
    
    priority_queue<pll>pq;
    vii tab(n);
    
    ll rSum = 0;
    int lo = 0;

    ll res = INT_MAX;
    
    for(int i = 0; i < n; i++){
        cin >> tab[i].s >> tab[i].f;
        pq.p({tab[i].f, i});

        rSum += tab[i].s;

        while(!pq.empty() and pq.top().s < lo) pq.pop();
        if(rSum >= k) res = min(res, pq.top().f);

        while(rSum > k) rSum -= tab[lo++].s;
    }

    while(!pq.empty() and pq.top().s < lo) pq.pop();
    if(rSum >= k) res = min(res, pq.top().f);

    cout << res<< endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("hayfeast"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```