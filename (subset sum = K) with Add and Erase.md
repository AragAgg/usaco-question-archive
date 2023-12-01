---
Question Link: https://atcoder.jp/contests/abc321/tasks/abc321_f
Problem Set:
  - AtCoder
  - Review
Last edited time: 2023-12-01T14:27
Status: Nice Question
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

void fx() {
    int q, K;
    cin >> q >> K;

    vector<ll>dp(5001, 0);
    dp[0] = 1;

    const ll mod = 998244353;

    for(int i = 0; i < q; i++){
        char c;
        int n;
        cin >> c >> n;

        if(c == '+'){
            for(int j = K; j >= n; j--) dp[j] = (dp[j] + dp[j - n]) %mod;
        }else{
            for(int j = n; j <= K; j++) dp[j] = ((dp[j] - dp[j-n]) %mod + mod ) %mod;
        }

        cout << dp[K] << endl;
    }
    // Functionality for fx
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