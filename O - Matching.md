---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_o
Problem Set:
  - AtCoder
Last edited time: 2023-12-13T15:05
Status: Nice Question
tags:
  - Bitmask
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
int n;
bool tab[22][22];
vector<vector<ll>>dp(21, vector<ll>(3000000, -1));
const ll mod = 1e9+7;

ll fx2(int bitmask, int bit){
    //cout << "bitmask: " << bitmask << ", bit: " << bit << endl;
    if(bit == n) return (bitmask == 0);

    if(dp[bit][bitmask] != -1) return dp[bit][bitmask];
    dp[bit][bitmask] = 0;

    ll res = 0;
    for(int i = 0; i < n; i++){
        if(!tab[bit][i] or !(bitmask & (1 << i))) continue;

        res += fx2(bitmask ^ (1 << i), bit+1);
    }
    res %= mod;
    return dp[bit][bitmask] = res;
}
void fx() {
    // Functionality for fx
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> tab[i][j];
    int mask = 0;
    for(int i = 0; i < n; i++) mask |= (1 << i);
    cout << fx2(mask, 0) << endl;
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

### Bullshit solution (WA on final case with pragma)

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
// cin.tie(0)->sync_with_stdio(0);

void fx() {
    // Functionality for fx
    int n;
    cin >> n;

    vector<vi>compatible(n);
    vector<vector<ll>>dp(1 << n, vector<ll>(n, 0)); 
    
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        bool isConnected;
        cin >> isConnected; 
        if(isConnected) compatible[j].pb(i);
    }
    
    for(auto man: compatible[0]) dp[1 << man][0] = 1;


    for(int i = 1; i < n; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            if(__builtin_popcount(mask) < i+1) continue;
            for(auto man: compatible[i]){
                if((mask & ( 1 << man)) == 0) continue;

                dp[mask][i] += dp[mask ^ (1 << man)][i-1];
            }

            dp[mask][i] %= mod;
        }
    }

    cout << dp[(1 << n) -1][n-1] << endl;


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

  

### Best Solution (193 ms, form: Editorial)

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

const ll mod = 1e9+7;
void fx() {
    // Functionality for fx
    int n;
    cin >> n;

    vector<vi>compat(n, vi(n, false));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> compat[i][j];

    vector<ll>dp(1 << n, 0);

    // finalise the base case
    dp[0] = 1;
    
    for(int mask = 0; mask < (1 << n); mask++){
        if(dp[mask] == 0) continue;
        int men = __builtin_popcount(mask);
        for(int w = 0; w < n; w++){
            if(!((mask & ( 1 << w)) || !compat[men][w])) dp[mask | ( 1 << w)] = (dp[mask | (1 << w)] + dp[mask]) %mod;
        }
    }

    cout << dp[(1 << n) -1] << endl;
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