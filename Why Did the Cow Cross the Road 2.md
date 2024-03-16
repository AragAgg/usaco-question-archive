---
Question Link: https://usaco.org/index.php?page=viewproblem2&cpid=717
Problem Set:
  - Gold
Last edited time: 2024-03-16T13:25
Status: Nice Question
tags:
  - Dijkstra's-Algo
  - Implementation
---
### Solution (AC)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
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

const ll INF = 1e15;


void fx() {
    // Functionality for fx
    int n, t;
    cin >> n >> t;

    vector<vector<vector<ll>>>dist(4, vector<vector<ll>>(n, vector<ll>(n, INF)));
    dist[3][0][0] = 0;

    vvi cost(n, vi(n));
    for(int i = 0; i < n; i++) for(auto &item: cost[i]) cin >> item;

    priority_queue<tuple<ll, int, int, int>>pq; // <(-ve)len, x, y, rem>
    pq.push({0, 0, 0, 3});

    while(!pq.empty()){
        auto [len, x, y, rem] = pq.top();

        len *= -1;
        pq.pop();

        if(dist[rem][x][y] < len) continue;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if(!(nx >= 0 and nx < n and ny >= 0 and ny < n)) continue;
            ll nlen = len + ((rem == 1)?cost[nx][ny]:0) + t;

            if(dist[(rem - 1 + 3)%3][nx][ny] > nlen){
                dist[(rem - 1 + 3)%3][nx][ny] = nlen;
                pq.push({-dist[(rem - 1 + 3)%3][nx][ny], nx, ny, (rem - 1 + 3)%3});
            }
        }
    }

    cout << min(dist[0][n-1][n-1], min(dist[1][n-1][n-1], dist[2][n-1][n-1])) << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("visitfj"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```