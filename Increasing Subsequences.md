---
Question Link: https://codeforces.com/contest/1922/problem/E
Problem Set:
  - Code Forces
Last edited time: 2024-01-20T13:33
Status: Seen Editorial
tags:
  - Bitmask
  - Constructive
  - Greedy
What's up: Had the wrong idea. Easiest DIV2E
---
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

void fx2(ll n, vi &ans){
    if(n == 2) ans.pb(0);
    else if(n & 1) fx2(n-1, ans), ans.pb(*min_element(all(ans)) - 1);
    else fx2(n/2, ans), ans.pb(*max_element(all(ans)) + 1);
}

void fx() {
    // Functionality for fx
    ll n;
    cin >> n;

    vi ans;
    fx2(n, ans);
    cout << ans.size() << endl;
    for(auto &i: ans) cout << i << " ";
}


int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
     int t; cin >> t;
     while(t--) fx();
    
    // Single test case
   
    
    return 0;
}
```