---
Question Link: https://saco-evaluator.org.za/cms/sapo2015z/tasks/jazz/description
Problem Set:
  - South African Programming Olympiad
Last edited time: 2023-12-19T16:02
Status: Seen Editorial
tags:
  - Dynamic-Programming
  - Range
What's up: Nice introductory question
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
    string s;
    cin >> s;
    int n = s.size();

    vvi dp(n+1, vi(n+1, 0));
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n - j; i++){
            // the base case
            dp[i][i+j] = dp[i+1][i+j] + 1;

            for(int k = i+1; k <= i + j; k++){
                if(s[i] != s[k]) continue;
                dp[i][i+j] = min(dp[i][i+j], dp[i+1][k-1] + dp[k+1][i+j]);
            }
        }
    }

    cout << dp[0][n-1] << endl;
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