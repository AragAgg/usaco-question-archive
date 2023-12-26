---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=671
Problem Set:
  - Gold
Last edited time: 2023-12-26T19:40
Status: Nice Question
tags:
  - BFS
  - Implementation
What's up: Saw the editorial.
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

// cin.tie(0)->sync_with_stdio(0);

void fx() {
    // Functionality for fx
    int n;
    pii start, end;
    
    cin >> n;
    cin >> start.f >> start.s;
    
    vii tab(n+1);
    vi dist(n+1, INT_MAX);
    unordered_map<int, vi> m[2];


    for(int i = 0; i < n+1; i++){
        cin >> tab[i].f >>  tab[i].s;

        m[0][tab[i].f].pb(i);
        m[1][tab[i].s].pb(i);
        if(i == 0) end = {tab[i].f, tab[i].s};
    }
    
    queue<pii>q;
    
    for(auto &p: m[0][start.f]) dist[p] = 0, q.push({p, 1});
    for(auto &p: m[1][start.s]) dist[p] = 0, q.push({p, 0});

    while(!q.empty()){
        auto [p, dir] = q.front();
        q.pop();
        //cout << "at position: " << p << " with dir: " << dir << endl;

        for(auto pos: m[dir][dir?tab[p].s:tab[p].f]){
            if(dist[pos] > dist[p] + 1){
                q.push({pos, !dir});
                dist[pos] = dist[p] + 1;
            }
        }
    }
    
    cout << dist[0] << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("lasers"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```