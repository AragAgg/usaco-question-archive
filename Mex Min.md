---
Question Link: https://atcoder.jp/contests/abc194/tasks/abc194_e
Problem Set:
  - AtCoder
Last edited time: 2024-03-24T17:03
Status: Nice Question
tags:
  - Implementation
  - Two-Pointer
Key Takeaway: Nice question. Got struck for a while.
---
### Solution (AC)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define p push
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
//\#define int ll
\#define endl "\n"
\#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

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


void fx() {
    int n, m;
    cin >> n >> m;

    vi tab(n);
    unordered_map<int, int>s;

    for(int i = 0; i < m; i++){
        cin >> tab[i];
        s[tab[i]]++;
    }

    int mex = m;
    for(int i = 0; i < m; i++){
        if(s.count(i) == 0){ mex = i; break; }
    }

    for(int i = m; i < n; i++){
        cin >> tab[i];
        s[tab[i]]++;
        if(--s[tab[i-m]] == 0) mex = min(mex, tab[i-m]), s.erase(tab[i-m]);
    }

    cout << mex << endl;

}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
	
```