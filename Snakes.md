---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=945
Problem Set:
  - Gold
Last edited time: 2023-12-01T00:33
Status: Nice Question
tags:
  - Dynamic-Programming
  - Implementation
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
    int n, k;
    cin >> n >> k;

    vi tab(n, 0);
    for(auto &i: tab) cin >> i;

    vector<vector<pii>>dp(n, vector<pii>(k+1, {INT_MAX, 0}));

    dp[0][0] = {0, tab[0]};
    int total = tab[0];
    int maxElement = tab[0];

    for(int i = 1; i < n; i++){
        maxElement = max(maxElement, tab[i]);
        total += tab[i];
        dp[i][0] = {maxElement*(i+1) - total, maxElement};
        int sum = 0;
        int m = INT_MIN;
        for(int j = i-1; j >= 0; j--){
            sum += tab[j+1];
            m = max(m, tab[j+1]);
            for(int x = 0; x <= k; x++){
                if(dp[j][x].f == INT_MAX) continue;

                if(dp[j][x].s >= m and dp[i][x].f > dp[j][x].f + dp[j][x].s * (i-j) - sum){
                    dp[i][x].f = dp[j][x].f + dp[j][x].s * (i-j) - sum;
                    dp[i][x].s = dp[j][x].s;
                }

                if(x != k and dp[i][x+1].f > dp[j][x].f + m * (i-j) - sum){
                    dp[i][x+1].f = dp[j][x].f + m * (i-j) - sum;
                    dp[i][x+1].s = m;
                }
            
            }
        }
    }

    int res = INT_MAX;
    for(auto i: dp[n-1]) res = min(res, i.f);
    cout << res << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("snakes"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```