---
Question Link: https://oj.uz/problem/view/BOI12_mobile
Problem Set:
  - Baltic OI
Last edited time: 2024-03-22T09:58
Status: Nice Question
tags:
  - Binary-Search
  - Problem-Decomposition
What's up: Solved. Careful implementation required.
Key Takeaway: Although interval merging is easier (more intuitive) with a stack, we can do it even without it (possible in a simpler implementation), provided that the intervals are sorted.
---
### What I’ve thought of till now.

```Plain
I guess that the basic idea revolves around Binary Searching the minimim value alpha, such that every point x on the highway is less than or equal to max of alpha dist. away from the nearest tower.

One important observation involed is that the max value of coordinates are 1e9, which in no way is simulatable, so instead we simulate using the towers instead, which has a more resonable range of 1e6.

Given the location of a tower, and a certain value of alpha, we could quickly determine the range on the highway this tower covers using the Pythagorean theorem. After we find all such ranges (all 1e6) of them, we could sort them by their starting points, after which we could quickly find out if there exists a point on the highway which is not effectively covered by any tower.

The the value of alpha could be verified, using a monotonic function, which we could exploit to apply binary search.

Still the time constraints are a bit too tight to be sure for acceptance, therefore we would likely need to find some constant time speedup (possibly more than one).
```

  

  

  

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

\#define ld long double
vector<pair<ld, ld>> tab;
int n;
ld l;
ld eps = 0.000001;


bool check(ld alpha){
    ld curr = 0; 

    for(int i = 0; i < n; i++){
        auto [x, y] = tab[i];
        if(abs(y) > alpha) continue;
        ld delta = sqrt(alpha*alpha - y*y);
        if(x - delta <= curr) curr = max(curr, x + delta);
    }

    return (curr >= l);
}


void fx() {
    cin >> n >> l;

    for(int i = 0; i < n; i++){
        pair<ld, ld>curr;
        cin >> curr.f >> curr.s;
        tab.pb(curr);
    }

    ld lo = 0;
    ld hi = 1e10; 
    
    for(int iter = 0; iter < 45; iter++){
        ld mid = (lo + hi)/2;
        if(check(mid)) hi = mid;
        else lo = mid;
    }

    cout << fixed << setprecision(8) << lo << endl;

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