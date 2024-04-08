---
Question Link: https://atcoder.jp/contests/abc202/tasks/abc202_e
Problem Set:
  - AtCoder
Last edited time: 2024-04-08T13:08
Status: Solved
tags:
  - Euler-Tour
  - Small-to-Large-Merging
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

int n;
vi res;
vvi neighs, queries;
vii param;

unordered_map<int, int>euler_tour(int node, int parent, int depth){
    unordered_map<int, int>subTree;
    subTree[depth]++;
    for(auto neigh: neighs[node]){
        if(neigh == parent) continue;
        auto childTree = euler_tour(neigh, node, depth+1);
        if(childTree.size() > subTree.size()) swap(childTree, subTree);

        for(auto &[d, c] : childTree) subTree[d] += c;
    }

    for(auto q: queries[node]){
        res[q] = subTree[param[q].s];
    }

    return subTree;
}

void fx() {
    cin >> n;
    
    neighs.assign(n, {});
    queries.assign(n, {});

    for(int child = 1; child < n; child++){
        int parent;
        cin >> parent;
        parent--;

        neighs[child].pb(parent);
        neighs[parent].pb(child);
    }

    int q;
    cin >> q;

    param.assign(q, {});

    for(int i = 0; i < q; i++){
        int root, depth;
        cin >> root >> depth;
        root--;

        queries[root].pb(i);
        param[i] = {root, depth};
    }

    res.assign(q, 0);

    euler_tour(0, -1, 0);

    for(auto &item: res) cout << item << endl;
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