---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=838
Problem Set:
  - Gold
Last edited time: 2024-02-09T11:12
Status: Nice Question
tags:
  - Binary-Search
  - Topological-Sort
Key Takeaway: Should have noticed the ‘lexicographic part’ and immediately switched to ‘khan’s algorithm’.
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
int n, m;
vvi ob;
vi topSort, visited, res;
vvi adj;

bool fx2(){
    priority_queue<int>pq;
    vi indegree(n, 0);
    for(int i = n-1; i >= 0; i--){
        for(auto &neigh: adj[i]) indegree[neigh]++;
    }

    for(int i = 0; i < n; i++) if(indegree[i] == 0) pq.push(-i);

    while(!pq.empty()){
        int node = -pq.top();
        pq.pop();
        topSort.pb(node);
        for(auto &neigh: adj[node]) if(--indegree[neigh] == 0) pq.push(-neigh);
    }

    return (topSort.size() == n);
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int num = 0; cin >> num;
        ob.push_back(vi(num, 0));
        for(auto &item: ob[i]) cin >> item, item--;
    }

    int lo = 0, hi = m;

    while(lo < hi){
        topSort.clear();
        visited.assign(n, false);
        adj.assign(n, {});
        int mid = (lo+hi)/2;

        for(int i = 0; i < mid; i++){
            for(int j = 0; j < ob[i].size()-1; j++) adj[ob[i][j]].pb(ob[i][j+1]);
        }

        if(fx2()){
            res = topSort;
            lo = mid +1 ;
        }
        else hi = mid;
    }

    for(int i = 0; i < n; i++){
        cout << (res[i]+1);
        if(i != n-1) cout << " ";
    }
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("milkorder"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```