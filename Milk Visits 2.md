---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=970
Problem Set:
  - Gold
Last edited time: 2024-04-08T16:18
Status: Nice Question
tags:
  - Euler-Tour
  - Implementation
  - LCA
  - Trick
---
perform an euler tour, and store the index of each appearance of T[i] in a sorted way in a vvi, and for each query, check if vvi.lowerbound of A[i] is. ≤ B[i], [actual implementation is a bit diff]

  

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

vi flavor, tour, lcaFirst, first, param[3];

vii lcs;
vvi adj;

vector<vector<tuple<int, int, int>>>track;
vector<array<int, 3>>query;

/*

   param[0] -> start
   param[1] -> end
   param[2] -> LCA

   query[0] -> start
   query[1] -> end
   query[2] -> flavor

*/

void euler_tour(int node, int parent, int depth){
    tour.pb(node);
    first[node] = tour.size() -1;

    lcs.pb({depth, node});
    lcaFirst[node] = lcs.size() -1;

    for(auto neigh: adj[node]){
        if(neigh == parent) continue;
        euler_tour(neigh, node, depth+1);
        lcs.pb({depth, node});
    }

    tour.pb(-1 -node);
}

struct RMQ{
    int lvl(int x){ return 31-__builtin_clz(x); }
    vii v;
    vvi jmp;
    int cmp(int a, int b){ return ((v[a].f == v[b].f)?min(a, b):((v[a].f < v[b].f)?a:b)); }
    RMQ(vii &_v){
        v = _v;
        jmp.pb(vi(v.size(), 0));
        iota(all(jmp[0]), 0);

        for(int j = 1; (1 << j) <= v.size(); j++){
            jmp.pb(vi(v.size() - (1 << j) +1, 0));
            for(int i = 0; i < jmp[j].size(); i++) jmp[j][i] = cmp(jmp[j-1][i], jmp[j-1][i + (1 << (j-1))]);
        }
    }
    int LCA(int starta, int startb){
        if(starta > startb) swap(starta, startb);
        int d = lvl(startb-starta+1);
        return v[cmp(jmp[d][starta], jmp[d][startb - (1 << d) +1])].s;
    }
};


void fx() {
    int n, m;
    cin >> n >> m;

    flavor.assign(n, 0);
    adj.assign(n, {});
    first.assign(n, -1);
    lcaFirst.assign(n, -1);
    track.assign(n, {});
    
    for(auto &i: flavor) cin >> i;

    for(int i = 0 ; i < 3; i++) param[i] = vi(m, -1);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    euler_tour(0, -1, 0);

    //for LCA
    RMQ t(lcs);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        query.pb({a, b, c});
        
        if(first[a] > first[b]) swap(a, b);
        track[a].pb({c, i, 0});
        track[b].pb({c, i, 1});
        track[t.LCA(lcaFirst[a], lcaFirst[b])].pb({c, i, 2});
    }

    //perform a linear sweep and figure our param[0, 1, 2]
    map<int, int>s;
    for(int i = 0; i < tour.size(); i++){
        if(tour[i] >= 0){
            s[flavor[tour[i]]]++;
            for(auto [c, q, t]: track[tour[i]]){
                param[t][q] = s[c];
            }
        }else{
            int node = -1 * (tour[i] + 1);
            s[flavor[node]]--;
        }
    }
    
    //ans queries
    for(int i = 0; i < m; i++){
        cout << ((flavor[t.LCA(lcaFirst[query[i][0]], lcaFirst[query[i][1]])] == query[i][2]) or (param[0][i] - param[2][i]) or (param[1][i] - param[2][i]));
    }

    cout << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("milkvisits"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```