---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_j
Problem Set:
  - AtCoder
Last edited time: 2023-11-26T11:28
Status: "Very Interesting "
tags:
  - Dynamic-Programming
What's up: Can’t really understand properly how the expected value works.
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
float dp[301][301][301];
int n;

float fx2(vector<int>d){
    if(d[1] == 0 and d[2] == 0 and d[0] == 0) return 0;
    float res = 0;

    if(dp[d[0]][d[1]][d[2]] != -1.0) return dp[d[0]][d[1]][d[2]]; 
    dp[d[0]][d[1]][d[2]] = 0.0;

    if(d[0] >= 1) res += fx2({d[0] -1, d[1], d[2]}) * (d[0]);
    if(d[1] >= 1) res += fx2({d[0] + 1, d[1] -1, d[2]}) * (d[1]);
    if(d[2] >= 1) res += fx2({d[0], d[1]+1, d[2]-1}) * (d[2]);

    res += n;
    res /= (d[0] + d[1] + d[2]);
    return dp[d[0]][d[1]][d[2]]  = res;
}

void fx() {
    // Functionality for fx
    for(int i = 0; i <= 300; i++) for(int j = 0; j <= 300; j++) for(int k = 0; k <= 300; k++) dp[i][j][k] = -1.0;

    cin >> n;

    vector<int>d(3, 0);
    for(int i = 0; i < n; i++){

        int t;
        cin >> t;
        d[--t]++;
    }

    cout << setprecision(10) << fx2(d) << endl;
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