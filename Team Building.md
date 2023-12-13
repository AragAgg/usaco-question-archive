---
Question Link: https://codeforces.com/contest/1316/problem/E
Problem Set:
  - "*2300"
  - Code Forces
Last edited time: 2023-12-13T22:48
Status: Nice Question
tags:
  - Bitmask
  - Dynamic-Programming
Key Takeaway: Check for invalid DP states.
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


const ll mod = 1e9+7;

void fx() {
    // Functionality for fx
    int n, k, p;
    cin >> n >> p >> k;

    vii tab(n, {0, 0});
    for(int i = 0; i < n; i++){
        cin >> tab[i].f;
        tab[i].s = i;
    }

    sort(tab.rbegin(), tab.rend());
    vector<ll>dp(1 << p, 0);

    vvi score(n, vi(p, 0));
    for(int i = 0; i < n; i++) for(int j= 0; j < p; j++) cin >> score[i][j];
   
    for(int x = 0; x < n; x++){
        const auto &person = tab[x];
        for(int mask = (1 << p); mask >= 0; mask--){
            int test = x - __builtin_popcount(mask);
            if(test < k && test >= 0) dp[mask] += person.f;
            for(int pos = 0; pos < p; pos++){
                if(mask & ( 1 << pos)) dp[mask] = max(dp[mask], score[person.s][pos] + dp[mask ^ (1 << pos)]);
            }
        }

    }
    
    cout << dp[(1 << p) - 1] << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    cin.tie(0)->sync_with_stdio(0);
    
    // Single test case
    fx();
    
    return 0;
}
```