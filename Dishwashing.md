---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=922
Problem Set:
  - Gold
Last edited time: 2024-03-22T12:21
Status: Solved
tags:
  - Implementation
  - Stack
  - Structure
Key Takeaway: Deque could be used as both a stack and a queue and as a vector. It’s really powerful.
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
    int n;
    cin >> n;

    vi tab(n);
    for(auto &i: tab) cin >> i;

    int lo = -1, hi = n;

    while(lo < hi-1){
        int mid = (lo + hi)/2;
        deque<int>unwashed;
        deque<vi>soapy;

        for(int i = 0; i <= mid; i++) unwashed.pb(tab[i]);

        sort(all(unwashed));

        for(int i = 0; i <= mid; i++){
            int plate = tab[i];

            int l = -1, r = soapy.size();

            while(l < r-1){
                int m = (l + r)/2;
                if(soapy[m].back() > plate) r = m;
                else l = m;
            }

            if(r == soapy.size()) soapy.pb({plate});
            else soapy[r].pb(plate);

            while(!soapy.empty() and soapy.front().back() == unwashed.front()){
                soapy.front().ppb();
                unwashed.pop_front();

                if(soapy.front().empty()) soapy.pop_front();
            }
        }

        if(soapy.empty()) lo = mid;
        else hi = mid;
    }

    cout << (lo + 1) << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
     iofile(string("dishes"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```