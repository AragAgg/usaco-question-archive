---
Question Link: https://codeforces.com/gym/104536/problem/F
Problem Set:
  - Code Forces
Last edited time: 2023-10-18T19:37
Status: Solved
tags:
  - Tree
  - Trick
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

int n, m;
vvi ta, tb;

int bestDist, bestNode;

void findFurthest(int x, int parent, int dist, vvi &tab){
    if(dist > bestDist){
        bestDist = dist;
        bestNode = x;
    }
    
    for(auto neigh: tab[x]){
        if(neigh == parent) continue;
        findFurthest(neigh, x, dist+1, tab);
    }
}

void fx() {
    cin >> n;
    ta.assign(n, {});
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        ta[a].pb(b);
        ta[b].pb(a);
    }
    
    cin >> m;
    tb.assign(m, {});
    
    for(int i = 0; i < m-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        tb[a].pb(b);
        tb[b].pb(a);
    }
    
    int dia1 = 0, dia2 = 0;
    bestNode = 0; bestDist = 0;
    
    findFurthest(0, -1, 0, ta);
    bestDist = 0;
    findFurthest(bestNode, -1, 0, ta);
    
    dia1 = bestDist;
    
    bestDist = 0;
    bestNode = 0;
    
    findFurthest(0, -1, 0, tb);
    bestDist = 0;
    findFurthest(bestNode, -1, 0, tb);
    dia2 = bestDist;
    
    cout << max((int)(ceil((float)dia1/2) + ceil((float)dia2/2) + 1), max(dia1, dia2)) << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

  

Editorial not available at the time of writing.