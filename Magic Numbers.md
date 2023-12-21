---
Question Link: https://codeforces.com/contest/628/problem/D
Problem Set:
  - "*2200"
  - Code Forces
Last edited time: 2023-12-21T16:45
Status: Nice Question
tags:
  - Digit-DP
  - Dynamic-Programming
---
### Solution (AC) [can completely remove M[][] ]

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
ll dp[2001][2001][2][2];
//dp[digit][rem][tight][tight_low] 
ll M[10][2001];
string a, b;
int m, k, n;
const ll mod = 1e9+7;

ll fx2(int digit, int rem, bool tight, bool tightLow){
    //base case
    if(digit == n) return (rem == 0);

    //for simplicity's sake
    auto &ref = dp[digit][rem][tight][tightLow];
    int least = a[digit] - '0';
    int most = b[digit] - '0';

    //memo
    if(ref != -1) return ref;
    else ref = 0;

    //only if the current digit is even placed (&1 because 0-indexed)
    if(digit & 1){
        if((tight and k > most) or (tightLow and k < least)) return ref = 0;
        return ref = fx2(digit+1, (rem*10 + k)%m, (tight and k == most), (tightLow and k == least));
    }

    //try all digits for curr place
    for(int d = 0; d < 10; d++){
        if(d == k or (tight and d > most) or (tightLow and d < least)) continue;
        ref += fx2(digit+1, (rem*10 + d)%m, (tight and d == most), (tightLow and d == least));
    }

    ref %= mod;
    return ref;
}

void fx() {
    // Functionality for fx
    cin >> m >> k;
    memset(dp, -1, sizeof dp);
    for(int d = 0; d < 10; d++){
        M[d][0] = d%m;
        for(int mul = 1; mul < 2001; mul++){
            M[d][mul] = (M[d][mul-1] * 10)%m;
        }
    }
    
    cin >> a >> b;
    n = a.size();
    cout << fx2(0, 0, 1, 1) << endl; 
    
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

### Solution (AC) [slower]

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
ll dp[2001][2001][2][2];
//dp[digit][rem][tight][tight_low] 
ll M[10][2001];
string a, b;
int m, k, n;
const ll mod = 1e9+7;

ll fx2(int digit, int rem, bool tight, bool tightLow){
    //base case
    if(digit == n) return (rem == 0);

    //for simplicity's sake
    auto &ref = dp[digit][rem][tight][tightLow];
    int least = a[digit] - '0';
    int most = b[digit] - '0';

    //memo
    if(ref != -1) return ref;
    else ref = 0;

    //only if the current digit is even placed (&1 because 0-indexed)
    if(digit & 1){
        if((tight and k > most) or (tightLow and k < least)) return ref = 0;
        return ref = fx2(digit+1, (rem + M[k][n - digit - 1])%m, (tight and k == most), (tightLow and k == least));
    }

    //try all digits for curr place
    for(int d = 0; d < 10; d++){
        if(d == k or (tight and d > most) or (tightLow and d < least)) continue;
        ref += fx2(digit+1, (rem + M[d][n - digit -1])%m, (tight and d == most), (tightLow and d == least));
    }

    ref %= mod;
    return ref;
}

void fx() {
    // Functionality for fx
    cin >> m >> k;
    memset(dp, -1, sizeof dp);
    for(int d = 0; d < 10; d++){
        M[d][0] = d%m;
        for(int mul = 1; mul < 2001; mul++){
            M[d][mul] = (M[d][mul-1] * 10)%m;
        }
    }
    
    cin >> a >> b;
    n = a.size();
    cout << fx2(0, 0, 1, 1) << endl; 
    
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