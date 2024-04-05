---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=719
Problem Set:
  - Gold
Last edited time: 2024-04-05T21:20
Status: Nice Question
tags:
  - PBDS
What's up: cool. bad implementation, but who gives a fuck when its’ AC
---
use a pbds to store the entry point of each segment, and whenever you encounter an end point of a segment, add the number of segments which were added after the addition of the current segment’s starting point to res and remove the starting point of the current segment from our structure.

  

### Solution (AC)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>
\#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    int res = 0;

    n *= 2;

    Tree<int>t;
    unordered_map<int, int> entry;

    int timer = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(entry.count(x)){
            res += t.size() - t.order_of_key(entry[x]) -1;
            t.erase(entry[x]);

        }else{
            entry[x] = timer++;
            t.insert(entry[x]);
        }
    }

    cout << res << endl;


}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
     iofile(string("circlecross"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}


```