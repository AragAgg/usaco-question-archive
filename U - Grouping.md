---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_u
Problem Set:
  - AtCoder
Last edited time: 2023-11-29T14:41
Status: Skipped for now
tags:
  - Dynamic-Programming
What's up: Couldn’t understand the editorial. (Will retry after learning a bit of digit dp)
---
### Solution I Wrote [ofc wa]

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
ll fx2(int mask){
    if(mask == 0) return 0;

    int msb = -1, temp = mask;
    while(temp) temp >> 1, msb++;

    if(dp[mask] != -1) return dp[mask];

    dp[mask] = 0;

    for(int s = (mask -1)&mask; s; s = (s-1)&mask){
        dp[mask] = d
    }

}

void fx() {
    // Functionality for fx
    int n;
    cin >> n;

    vector<vector<int>> tab(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> tab[i][j];

    vector<ll> score((1 << n), 0);

    for(int s = 0; s < (1 << n); s++){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if((s & ( 1 << i)) and (s & ( 1 << j))) score[s] += tab[i][j];
        cout << score[s] << " ";
    }
    cout << endl;


    vector<ll>dp((1 << n), 0);
    for(int bit = 1; bit < n; bit++){
        int submask = (1 << bit) -1;

        for(int s = submask; s; s = (s-1)&submask){
            dp[(1 << (bit + 1)) -1] = max(dp[(1 << (bit + 1)) -1], score[s | (1 << bit)] + dp[submask ^ s]);
        }

        dp[(1 << (bit+1)) - 1] = max(dp[(1 << (bit+1)) - 1], dp[1 << (bit)]);

        dp[(1 << (bit+1)) - 1] = max(dp[(1 << (bit+1)) - 1], score[(1 << (bit + 1)) - 1]);

    }

    cout << (*max_element(all(dp))/2) << endl;
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