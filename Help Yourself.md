---
Question Link: http://usaco.org/index.php?page=viewproblem2&cpid=1018
Problem Set:
  - Gold
  - Review
Last edited time: 2023-11-14T13:37
Status: Seen Editorial
tags:
  - Math
What's up: "Very interesting question. Must retry. "
Key Takeaway: When you notice something weird about a question constraint, ask yourself why that constraint is there. Its now a coincidence, its an hint towards the intended solution.
---
### Solution

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

vector<ll>twoPow(1e5+100, 1);

void fx() {
    // Functionality for fx
    ll n;
    ll mod = 1e9+7;
    cin >> n;
    for(int i = 1; i < 1e5+100; i++) twoPow[i] = 2 * twoPow[i-1] % mod;
    vii segments(n);
    for(auto &i: segments) cin >> i.s >> i.f;
    sort(all(segments));
    for(auto &i: segments) swap(i.f, i.s);
    vector<ll> preEnd(2*n+1, 0);
    for(auto &seg: segments) preEnd[seg.s]++;
    for(int i = 1; i < 2*n+1; i++) preEnd[i] += preEnd[i-1];
    vector<ll>dp(n, 0);
    for(int i = 0; i < n; i++){
        ll btw = preEnd[segments[i].s - 1] - preEnd[segments[i].f -1];
        dp[i] = (btw == i)?0:dp[i - btw - 1];
        dp[i] += twoPow[preEnd[segments[i].f]] - 1 + twoPow[btw];
        dp[i] %= mod;
    }
    ll res = 0;
    for(auto i: dp) res += i, res %= mod;
    cout << res<< endl;
}

int main() {
    // Uncomment the following lines for file I/O
    //iofile(string("help"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution (AC) [from the editorial]

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
    ll mod = 1e9+7;
    ll n;
    cin >> n;

    vi s(2*n, 0);
    for(int i = 0; i < n; i++){
        pii t;
        cin >> t.f >> t.s;

        s[t.f-1]++;
        s[t.s-1]--;
    }
    
    vector<ll> twoPow(n+1, 1);
    for(int i = 1; i <= n; i++) twoPow[i] = 2*twoPow[i-1] %mod;

    ll res = 0;
    ll curr = 0;

    for(auto i: s){
        curr += i;

        if(i == 1) res = (res + twoPow[n - curr]) % mod;
    }
    cout << res << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("help"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Solution - Help Yourself (USACO Gold 2020 February)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-1018-help-yourself/solution](https://usaco.guide/problems/usaco-1018-help-yourself/solution)