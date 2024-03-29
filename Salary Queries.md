---
Question Link: https://cses.fi/problemset/task/1144
Problem Set:
  - CSES
Last edited time: 2024-03-29T12:13
Status: Nice Question
tags:
  - PBDS
---
### Solution (AC)

```C++
\#pragma GCC optimize("O3,unroll-loops")
\#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

Tree<pii>people;

void fx() {
    int n, q;
    cin >> n >> q;
    vi tab(n);
    for(int i = 0; i < n; i++) cin >> tab[i], people.insert({tab[i], i});

    int idx, val, a, b;
    char operation;

    while(q--){
        cin >> operation;

        if(operation == '!'){
            //set
            cin >> idx >> val;
            idx--;
            people.erase({tab[idx], idx});
            tab[idx] = val;
            people.insert({tab[idx], idx});

        }else{
            cin >> a >> b;
            int alpha = people.order_of_key({a, INT_MIN});
            int beta = n - people.order_of_key({b, INT_MAX});
            int res = n - alpha - beta;
            res = max(res, 0);
            cout << res << endl;
        }
    }

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