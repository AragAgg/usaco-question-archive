---
Question Link: https://codeforces.com/contest/1365/problem/D
Problem Set:
  - "*1700"
  - Code Forces
  - DIV2D
Last edited time: 2023-10-14T12:49
Status: Solved
tags:
  - DFS
  - Flood-Fill
  - Greedy
  - Implementation
Key Takeaway: If you’re trying to floodfill, maybe consider adding an helper or lambda function to check if the current coordinates are out of bounds.Floodfill implementation with BFS is simpler than DFS.
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long

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

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

int n, m;
vector<string>tab;
vii deltas = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

void check(int i, int j){
    
    for(auto delta : deltas){
        int x = i + delta.f;
        int y = j + delta.s;
        
        if(x < 0 or x >= n or y < 0 or y >= m or tab[x][y] != '.') continue;
        
        tab[x][y] = '#';
    }
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    tab.assign(n, "");
    for(auto &i: tab) cin >> i;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tab[i][j] == 'B') check(i, j);
        }
    }
    
    vvi visited(n, vi(m, 0));
    int goodPeopleEncountered = 0;
    
    int totalGoodPeople = 0;
    for(auto s: tab) for(auto c: s) if(c == 'G') totalGoodPeople++;
    
    queue<pii>q;
    q.push({n-1, m-1});
    
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        
        int i = curr.f;
        int j = curr.s;
        
        if(i < 0 or i >= n or j < 0 or j >= m or visited[i][j] or tab[i][j] == '#') continue;
        visited[i][j] = true;
        
        if(tab[i][j] == 'G') goodPeopleEncountered++;
        
        if(tab[i][j] == 'B'){
            no();
            return;
        }
        
        for(auto delta: deltas) q.push({i+delta.f, j + delta.s});
        
    }
    
    if(totalGoodPeople == goodPeopleEncountered) yes();
    else no();
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```