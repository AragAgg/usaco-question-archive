---
Question Link: https://dmoj.ca/problem/ioi00p4
Problem Set:
  - IOI OLD
Last edited time: 2023-12-26T15:01
Status: Nice Question
tags:
  - BFS
  - Implementation
What's up: Nice use of structure
---
### Solution (turns out you can’t go through cities)

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
    int m, c, l;
    cin >> m >> c >> l;
    
    vi club(l);
    for(auto &i: club) cin >> i, i--;
    unordered_map<int, vi>regionsConnectedThrough;
    vvi regions(m);

    for(int i = 0; i < m; i++){
        int cities;
        cin >> cities;

        regions[i].assign(cities, 0);
        for(auto &city: regions[i]) cin >> city, city--, regionsConnectedThrough[city].pb(i);
    }

    vvi adj(m);
    for(int i = 0; i < m; i++){
        for(auto city: regions[i]){
            for(auto &region: regionsConnectedThrough[city]) if(region != i) adj[i].pb(region);
        }
    }

    int ans = INT_MAX;
    int bestStart = -1;

    for(int start = 0; start < m; start++){
        vi dist(m, 10000);
        dist[start] = 0;
        queue<int>q;
        q.push(start);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto &neigh: adj[curr]){
                if(dist[neigh] > dist[curr] +1){
                    q.push(neigh);
                    dist[neigh] = dist[curr]+1;
                }
            }

        }

        int res = 0;
        for(int i = 0; i < l; i++){
            int leastDist = INT_MAX;
            for(auto region: regionsConnectedThrough[club[i]]) leastDist = min(leastDist, dist[region]);
            res += leastDist;
        }

        if(ans > res){
            ans = res;
            bestStart = start;
        }
    }

    cout << ans << endl << bestStart << endl;
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
map<pii, unordered_set<int>>regionsConnectedThrough;
unordered_map<int, unordered_set<int>>regionsThroughCity;

void insertEdge(int n1, int n2, int region){
    if(n1 > n2) swap(n1, n2);
    regionsConnectedThrough[{n1, n2}].insert(region);
}

void fx() {
    // Functionality for fx
    int m, c, l;
    cin >> m >> c >> l;
    
    vi club(l);
    vvi regions(m);
    vector<usi> adj(m);

    for(auto &i: club) cin >> i, i--;

    //form strucute to find all regions connected to a city and all regions to a wall
    for(int i = 0; i < m; i++){
        int cities;
        cin >> cities;

        regions[i].assign(cities, 0);
        for(auto &city: regions[i]) cin >> city, city--, regionsThroughCity[city].insert(i);
        for(int j = 1; j < cities; j++) insertEdge(regions[i][j-1], regions[i][j], i);
        insertEdge(regions[i].back(), regions[i].front(), i);
    }

    //form the adj list of the regions
    for(int i = 0; i < m; i++){

        for(int j = 1; j < regions[i].size(); j++){ 
            int a = regions[i][j-1], b = regions[i][j];
            if(a > b) swap(a, b);
            for(auto &region: regionsConnectedThrough[{a, b}]) if(region != i) adj[i].insert(region);
        }

        int a = regions[i].back(), b = regions[i].front();
        if(a > b) swap(a, b);
        for(auto &region: regionsConnectedThrough[{a, b}]) if(region != i) adj[i].insert(region);
    }
    
    int ans = INT_MAX;
    int bestStart = -1;

    //bfs from all regions
    for(int start = 0; start < m; start++){
        vi dist(m, 1000000);
        dist[start] = 0;
        queue<int>q;
        q.push(start);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto &neigh: adj[curr]){
                if(dist[neigh] > dist[curr] +1){
                    q.push(neigh);
                    dist[neigh] = dist[curr]+1;
                }
            }
ggVGYgg
        }

        //calculate the single best region for all club members
        int res = 0;
        for(int i = 0; i < l; i++){
            int leastDist = INT_MAX;
            for(auto region: regionsThroughCity[club[i]]) leastDist = min(leastDist, dist[region]);
            res += leastDist;
        }

        if(ans > res){
            ans = res;
            bestStart = start;
        }
    }

    cout << ans << endl << (bestStart+1) << endl;
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