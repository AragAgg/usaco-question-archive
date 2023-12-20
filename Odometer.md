---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=435
Problem Set:
  - Silver
Last edited time: 2023-12-20T16:23
Status: Skipped for now
tags:
  - Digit-DP
  - Dynamic-Programming
  - Implementation
What's up: Reallly Reallly shitty question. Skipping.
---
### Solution (ofc wrong)

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

ll fx2(string s){
    int n = s.size();
    ll dp[n][10][n+1][2];
    //dp[j][i][tight?] represent the n(nos) such there's exactly i j's and weather or not the curr state is tight.

    for(int i=0; i<n; i++) for(int j=0; j<10; j++) for(int k=0; k<n+1; k++) dp[i][j][k][0] = 0, dp[i][j][k][1] = 0;
    for(int d = 0; d < 10; d++){
        if(('0' + d) == s[0]) dp[0][1][d][1]++;
        else if(('0' + d) > s[0]) break;
        else dp[0][1][d][0]++;
    }

    for(int digit = 0; digit < n-1; digit++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j <= n; j++){
                dp[digit+1][j][i][0] += 9 * dp[digit][j][i][0];
                dp[digit+1][j+1][i][0] += dp[digit][j][i][0];

                if((int)(s[digit]) > i) dp[digit+1][j+1][i][0] += dp[digit][j][i][1];
                dp[digit+1][j][i][1] += dp[digit][j][i][1];
                if((int)(s[digit]) == i) dp[digit+1][j+1][i][1] += dp[digit][j][i][1];
            }
        }
    }

    ll res = 0;
    for(int digit = 0; digit < 10; digit++){
        for(int t = (n+1)/2; t <= n; t++){
            res += dp[n-1][digit][t][0] + dp[n-1][digit][t][1];
        }
    }

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < 10; j++) cout << dp[n-1][i][j][0] << " ";
        cout << endl;
    }
    cout << res << endl;
    return res; 

}

void fx() {
    string a, b;
    cin >> a >> b;


    cout << (fx2(b) - fx2(a)) << endl;
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

  

==See official contest result for more idea :)==