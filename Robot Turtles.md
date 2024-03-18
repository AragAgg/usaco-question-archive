---
Question Link: https://open.kattis.com/problems/robotturtles?tab=metadata
Problem Set:
  - Kattis
Last edited time: 2024-03-18T08:57
Status: Nice Question
tags:
  - Dijkstra's-Algo
  - Implementation
---
### Idea

1. Model the problem as a shortest path problem with the grid cells being the vertices, and the actions as edges and length of action sequence as the cost.
2. basically apply Dijkstra’s with actions constraints
3. expect heavy implementation (be smart with it)

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
vi dy = {0, 1, 0, -1};
vi dx = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }


bool isSafe(char ch){
    return ((ch == '.' or ch == 'D' or ch == 'T'));
}

const ll INF = 1e15;

void fx() {
    // Functionality for fx
    int n = 8;
    vector<vector<char>>grid(n, vector<char>(n));

    pii dest;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'D') dest = {i, j};
        }
    }

    ll dist[4][n][n];

    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) dist[dir][i][j] = INF;
        }
    }

    dist[1][n-1][0] = 0;

    priority_queue<tuple<ll, int, int, int, string>>pq; // <(-ve)len, x, y, dir, path>
    //dir: 0 -> up 1 -> right, 2->down, 3->left
    pq.p({0, n-1, 0, 1, ""});
    
    string res = "";

    while(!pq.empty()){
        auto [len, x, y, dir, path] = pq.top();
        pq.pop();

        len *= -1;

        if(dist[dir][x][y] < len) continue;
        if(x==dest.f and y==dest.s){res = path; break; }
        //try moving forward

        int _x = x+dx[dir], _y = y+dy[dir];
        if(_x >= 0 and _x < n and _y >= 0 and _y < n and isSafe(grid[_x][_y]) and  dist[dir][_x][_y] > len + 1){
            dist[dir][_x][_y] = len + 1;
            pq.p({-dist[dir][_x][_y], _x, _y, dir, (path + "F")});
        }


        //try using laser
        if(_x >= 0 and _x < n and _y >= 0 and _y < n and grid[_x][_y] == 'I' and dist[dir][_x][_y] > len + 2){
            dist[dir][_x][_y] = len + 2;
            pq.p({-dist[dir][_x][_y], _x, _y, dir, (path+"XF")});
        }

        //try turning left 

        int _dir = (dir+1)%4;
        if(dist[_dir][x][y] > len+1){
            dist[_dir][x][y] = len+1;
            pq.p({-dist[_dir][x][y], x, y, _dir, (path+"L")});
        }

        //try turning right 

        _dir = ((dir-1) + 4)%4;
        
        if(dist[_dir][x][y] > len+1){
            dist[_dir][x][y] = len+1;
            pq.p({-dist[_dir][x][y], x, y, _dir, (path+"R")});
        }
   }

    ll ans = INF;

    for(int i = 0; i < 4; i++) ans = min(ans, dist[i][dest.f][dest.s]);

    if(ans == INF) cout << "no solution" << endl;
    else{
        cout << res << endl;
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