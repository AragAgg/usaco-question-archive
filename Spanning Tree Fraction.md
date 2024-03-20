---
Question Link: https://www.hackerrank.com/contests/w31/challenges/spanning-tree-fraction/problem
Problem Set:
  - HackerRank
Last edited time: 2024-03-20T13:28
Status: Seen Editorial
tags:
  - "!!COMEBACK"
  - Binary-Search
  - Implementation
  - Kruskal's-MST
What's up: Requires careful observations.
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

struct DSU{
    vi e;
    int comps;
    DSU(int n){
        e.assign(n, -1);
        comps = n;
    }

    int get(int node){ return (e[node]<0)?node:(e[node] = get(e[node])); }
    void merge(int a, int b){
        int x = get(a), y = get(b);
        if(x==y)return;
        comps--;
        if(e[x]>e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
};

void reduce(ll a, ll b){

    for(int i = 2; i <= min(a, b); i++){
        if(a%i == 0 and b%i == 0){
            a /= i;
            b /= i;

            reduce(a, b);
            return;
        }
    }

    cout << a << "/"<< b<< endl;
}

vector<pair<float, int>>edges;
vi A, B, C, D;

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;

    A.assign(m, 0), B.assign(m, 0), C.assign(m, 0), D.assign(m, 0);

    for(int i = 0; i < m; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    double lo = 0, hi = 1e9;

    for(int iter = 0; iter < 100; iter++){
        DSU sys(n);
        edges.clear();

        double mid = (lo + hi)/2;

        for(int i = 0; i < m; i++) edges.pb({D[i]*mid - C[i], i});

        sort(all(edges));

        ll ptr = 0;
        ll resN = 0, resD = 0;

        while(ptr < edges.size() and sys.comps > 1){
            auto [len, ind] = edges[ptr];
            if(sys.get(A[ind]) != sys.get(B[ind])){
                sys.merge(A[ind], B[ind]);
                resN += C[ind];
                resD += D[ind];
            }

            ptr++;
        }

        if(resN - resD * mid >= 0) lo = mid;
        else hi = mid;
    }

    double optimal = lo;

    //repeated code
    DSU sys(n);
    edges.clear();

    for(int i = 0; i < m; i++) edges.pb({D[i]*optimal - C[i], i});

    sort(all(edges));

    ll ptr = 0;
    ll resN = 0, resD = 0;

    while(ptr < edges.size() and sys.comps > 1){
        auto [len, ind] = edges[ptr];
        if(sys.get(A[ind]) != sys.get(B[ind])){
            sys.merge(A[ind], B[ind]);
            resN += C[ind];
            resD += D[ind];
        }

        ptr++;
    }

    reduce(resN, resD);

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