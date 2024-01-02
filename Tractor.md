---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=245
Problem Set:
  - Silver
Last edited time: 2024-01-02T13:57
Status: Nice Question
tags:
  - DSU
  - Implementation
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

int res = INT_MAX;
int n;

struct DSU{
    vi e;
    void init(int N){e = vi(N, -1);}
    int get(int x){return (e[x] < 0) ? x: e[x] = get(e[x]);}
    void unite(int x, int y, int c){
        int a = get(x); int b = get(y);
        if(a == b) return;
        if(e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        if(-e[a] >= (n*n + 1)/2) res = min(res, c);
    }

};

void fx() {
    // Functionality for fx
    cin >> n;
    map<pii, int>c;

    vvi tab(n, vi(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tab[i][j];
            c[{i, j}];
        }
    }

    int cnt = 0;
    for(auto &i: c) i.s = cnt++;
    
    vector<pair<int, pii>> edges;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int d = 0; d < 4; d++){
                int x = i + dx[d], y = j + dy[d];
                if(x >= 0 and x < n and y >= 0 and y < n) edges.pb({abs(tab[i][j] - tab[x][y]), {c[{i,j}], c[{x, y}]}});
            }
        }
    }

    sort(all(edges));

    DSU tree;
    tree.init(c.size());
    for(auto &edge: edges){
        tree.unite(edge.s.f, edge.s.s, edge.f);
    }

    cout << res << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("tractor"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```