---
Question Link: https://oj.uz/problem/view/IZhO14_bank
Problem Set:
  - IZho
Last edited time: 2024-04-12T22:24
Status: Solved with Help
tags:
  - Bitmask
  - Dynamic-Programming
---
```C++
1 5
8 
4 2 5 1 3
```

```C++
2 6
9 10
5 4 8 6 3 11
```

  

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
    int n, m;
    cin >> n >> m;
    vi people(n), notes(m);
    for(auto &i: people) cin >> i;
    for(auto &i: notes) cin >> i;

    vi dp(1 << m, -1), leftover(1 << m, -1);
    
    dp[0] = 0;
    leftover[0] = 0;

    for(int mask = 1; mask < (1 << m); mask++){
        for(int last = 0; last < m; last++){
            int prev = mask ^ (1 << last);

            if((mask & (1 << last)) == 0) continue;
            if(dp[prev] == -1) continue;

            int rem = leftover[prev] + notes[last];

            if(rem < people[dp[prev]]){
                dp[mask] = dp[prev];
                leftover[mask] = rem;
            }else if(rem == people[dp[prev]]){
                dp[mask] = dp[prev] +1;
                leftover[mask] = 0;
            }
        }

        if(dp[mask] == n){
            yes();
            return;
        }
    }

    no();
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```