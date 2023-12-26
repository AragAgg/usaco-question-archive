---
Question Link: https://oj.uz/problem/view/IOI09_mecho
Problem Set:
  - IOI OLD
Last edited time: 2023-12-26T20:38
Status: Implementation
tags:
  - BFS
  - Binary-Search
What's up: Messing up the implementation. Will retry.
---
### Sample Inputs

```C++
7 3
TTTTTTT
TGGGGGT
TGGGGGT
MGGGGGD
TGGGGGT
TGGGGGT
THHHHHT
```

```C++
7 3 
TTTTTTT
TGGGGGT
TGGGGGT
MGGGGGD
TGGGGGT
TGGGGGT
TGHHGGT
```

### Solution (44/100) [really shitty BFS-Complete Search]

```C++
\#pragma GCC optimize("03,unroll-loops")
\#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
\#define INT_MIN -1000000000
\#define INT_MAX 1000000000

void fx() {
    // Functionality for fx
    int n, k;
    cin >> n >> k;

    vector<string>tab(n);
    vvi bee(n, vi(n, INT_MAX));
    vii hives;
    pii start;

    for(int i = 0; i < n; i++){
        cin >> tab[i];
        for(int j = 0; j < n; j++){
            if(tab[i][j] == 'M') start = {i, j};
            else if(tab[i][j] == 'H') hives.pb({i, j});
        }
    }

    queue<pair<int, pii>>q;
    for(auto &hive: hives){
        q.push({0, hive});
        bee[hive.f][hive.s] = 0;
    }

    while(!q.empty()){
        auto &[t, hive] = q.front();
        q.pop();
        auto &[x, y] = hive;
        
        for(int i = 0; i < 4; i++){
            auto [X, Y] = make_pair(x+dx[i], y+dy[i]);
            if(X >= 0 and X < n and Y >= 0 and Y < n and (tab[X][Y] == 'G' or tab[X][Y] == 'M') and bee[X][Y] > t + 1){
                q.push({t+1, {X, Y}});
                bee[X][Y] = t+1;
            }
        }
    }

    queue<pair<array<int, 3>, pii>>que;
    vector<vi>best(n, vi(n, INT_MIN)); // <- see init.
    que.push({{0, bee[start.f][start.s], k}, {start.f, start.s}}); //<- sure about init?
    best[start.f][start.s] = bee[start.f][start.s];
    int res = INT_MIN;

    while(!que.empty()){
        auto [T, C] = que.front();
        que.pop();
        auto [t, s, steps] = T;
        auto [x, y] = C;

        if(tab[x][y] == 'D') res = max(res, best[x][y]);
        
        for(int i = 0; i < 4; i++){
            auto [X, Y] = make_pair(x + dx[i], y + dy[i]);

            if(X >= 0 and X < n and Y >= 0 and Y < n and tab[X][Y] != 'T' and (bee[X][Y] > (steps?t:t+1)) and best[X][Y] < min(s, bee[X][Y] - (steps?t:t+1))){
                que.push({{(steps?t:t+1), min(s, bee[X][Y] - (steps?t:t+1)), (steps?steps-1:k-1)}, {X, Y}});
                best[X][Y] = max(best[X][Y], min(s, bee[X][Y] -(steps?t:t+1)));
            }
        }
    }

    cout << ((res <= 0)?-1:res-1) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"))
    cin.tie(0)->sync_with_stdio(0);

    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Buggy solution (18/100) [using a nicer BS+BFS solution]

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
vvi bee;
vector<string>tab;
int n, k;
pii start;
int best[801][801];

bool isViable(int target){
    if(bee[start.f][start.s] <= target) return false;

    memset(best, -1, sizeof best);
    queue<pair<pii, pii>>q;
    q.push({{target, k}, start});
    best[start.f][start.s] = bee[start.f][start.s] - target;
    int res = INT_MIN;

    while(!q.empty()){
        auto [T, curr] = q.front();
        auto [t, steps] = T;
        q.pop();

        if(tab[curr.f][curr.s] == 'D') res = (best[curr.f][curr.s]);

        for(int i = 0; i < 4; i++){
            auto [x, y] = make_pair(curr.f + dx[i], curr.s + dy[i]);
            if(x >= 0 and x < n and y >= 0 and y < n and (tab[x][y] == 'G' or tab[x][y] == 'D') and best[x][y] < min(best[curr.f][curr.s], bee[x][y] - (steps?t:t+1))){
                best[x][y] = min(best[curr.f][curr.s], bee[x][y] - (steps?t:t+1));
                q.push({{(steps)?t:t+1, (steps?steps-1:k-1)}, {x, y}});
            }
        }
    }

    return (res >= 0);

}

void fx() {
    // Functionality for fx
    cin >> n >> k;

    tab.assign(n, "");
    bee.assign(n, vi(n, INT_MAX));
    vii hives;

    for(int i = 0; i < n; i++){
        cin >> tab[i];
        for(int j = 0; j < n; j++){
            if(tab[i][j] == 'M') start = {i, j};
            else if(tab[i][j] == 'H') hives.pb({i, j});
        }
    }

    queue<pair<int, pii>>q;
    for(auto &hive: hives){
        q.push({0, hive});
        bee[hive.f][hive.s] = 0;
    }

    while(!q.empty()){
        auto &[t, hive] = q.front();
        q.pop();
        auto &[x, y] = hive;
        
        for(int i = 0; i < 4; i++){
            auto [X, Y] = make_pair(x+dx[i], y+dy[i]);
            if(X >= 0 and X < n and Y >= 0 and Y < n and (tab[X][Y] == 'G' or tab[X][Y] == 'M' or tab[X][Y] == 'D') and bee[X][Y] > t + 1){
                q.push({t+1, {X, Y}});
                bee[X][Y] = t+1;
            }
        }
    }

    if(!isViable(0)){
        cout << "-1" << endl;
        return;
    }

    int lo = 0;
    int hi = n*n+100;
    while(hi >= lo){
        int mid = (lo + hi )/2;
        if(isViable(mid)) lo = mid + 1;
        else hi = mid-1; 
    }

    cout << (lo-2) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"))
    cin.tie(0)->sync_with_stdio(0);

    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```