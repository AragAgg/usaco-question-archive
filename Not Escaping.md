---
Question Link: https://codeforces.com/contest/1627/problem/E
Problem Set:
  - Code Forces
  - DIV2E
Last edited time: 2024-03-17T21:19
Status: "Very Interesting "
tags:
  - Dijkstra's-Algo
  - Implementation
What's up: Correct algorithm, but coordinate compression needed to make it fast enough.
---
### Idea

1. Create a structure to find all the room on a particular floor which acts as an endpoint for a ladder
2. for each pair of endpoints on a particular floor, add edges between them,
3. use ladders as negative edges
4. finally run Dijkstra’s algo (no neg cycle)

### Solution (TLE)

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

const ll INF = 1e15;

void fx() {
    // Functionality for fx
    int n, m, k;
    cin >> n >> m >> k;

    vi dmg(n);
    vector<map<int, vector<tuple<int, int, int>>>>ladders(n); // <toFloor, toRoom, hpGain>
    vector<map<int, ll>> dist(n);
    priority_queue<tuple<ll, int, int>>pq; // <-len, floor, room>
    vvi fEndPoints(n);

    for(int i = 0; i < n; i++) cin >> dmg[i];

    while(k--){
        int a, b, c, d, hp;
        cin >> a >> b >> c >> d >> hp;

        --a, --b, --c, --d;

        dist[a][b] = dist[c][d] = INF;

        fEndPoints[a].pb(b);
        ladders[a][b].pb({c, d, hp});
    }

    fEndPoints[n-1].pb(m-1);

    dist[n-1][m-1] = INF;
    dist[0][0] = 0;

    pq.p({0, 0, 0});

    while(!pq.empty()){
        auto [len, a, b] = pq.top();
        pq.pop();

        len *= -1;

        if(dist[a][b] < len) continue;

        for(auto _endPoint: fEndPoints[a]){
            if(a == n-1 and _endPoint == m-1) dist[n-1][m-1] = min(dist[n-1][m-1], len + abs(m-1-b) * dmg[n-1]);
            for(auto &to : ladders[a][ _endPoint]){
                auto [toFloor, toRoom, hpGain] = to;
                ll _len = len + abs(_endPoint - b) * dmg[a] - hpGain;

                if(dist[toFloor][toRoom] > _len){
                    dist[toFloor][toRoom] = _len;

                    pq.p({-_len, toFloor, toRoom});
                    //add to priority_queue;
                }
            }

        }
    }


    if(dist[n-1][m-1] == INF) cout << "NO ESCAPE" << endl;
    else cout << dist[n-1][m-1] << endl;





}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
     int t; cin >> t; while(t--) fx();
    
    // Single test case
    
    return 0;
}
```