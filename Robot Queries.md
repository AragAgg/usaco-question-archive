---
Question Link: https://codeforces.com/contest/1902/problem/D
Problem Set:
  - Code Forces
  - DIV2D
Last edited time: 2024-03-14T11:55
Status: Nice Question
tags:
  - Dynamic-Programming
  - Implementation
---
### Solution (AC)

```C++
\#pragma GCC optimize("03,unroll-loops")
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


map<pii, set<int>>locs;
map<pii, set<int>>locsR;

void trajectory(string moves, vi &x, vi &y, bool flag){

    int n = moves.size();
    for(int i = 0; i < n; i++){
        char move = moves[i];

        if(move == 'U') y[i+1] = y[i]+1, x[i+1] = x[i];
        else if(move == 'D') y[i+1] = y[i]-1, x[i+1] = x[i];
        else if(move == 'L') x[i+1] = x[i]-1, y[i+1] = y[i];
        else x[i+1] = x[i]+1, y[i+1] = y[i];

        if(flag) locs[{x[i+1], y[i+1]}].insert(i+1); // <- sure about i+1?
        else locsR[{x[i+1], y[i+1]}].insert(n-i);
    }
}

void fx() {
    // Functionality for fx

    int n, q;
    cin >> n >> q;

    vi x(n+1, 0);
    vi y(n+1, 0);
    vi xr(n+1, 0);
    vi yr(n+1, 0);
    

    string moves;
    cin >> moves;


    trajectory(moves, x, y, true);
    reverse(all(moves));
    trajectory(moves, xr, yr, false);

    while(q--){
        int a, b, l, r;
        cin >> a >> b >> l >> r;

        if(a == b and b == 0){
            yes();
            continue;
        }

        bool ans = false;

        if(locs.count({a, b})){
            auto item = locs[{a, b}].lower_bound(0);
            auto item2 = locs[{a, b}].lower_bound(r);
            //for(auto &t: locs[{a, b}]){
            //    if(t < l or t > r){
            //        ans = true;
            //        break;
            //    }
            //}

            if((item != locs[{a, b}].end() and *item < l) or (item2 != locs[{a, b}].end() and *item2 > r)){
                ans = true;
            }
        }

        int baseX = xr[n-r], baseY = yr[n-r];
        int deltaX = a - x[l-1], deltaY = b - y[l-1];
        auto iter = locsR.find({baseX+deltaX, baseY+deltaY});
        
        if(iter != locsR.end()){
            //for(auto &t: locsR[{baseX+deltaX, baseY+deltaY}]){
            //    if(t >= l and t <= r){
            //        ans = true;
            //        break;
            //    }
            //}


            //rewriteing th for loop

            auto item = locsR[{baseX+deltaX, baseY+deltaY}].lower_bound(l);
            if(item != locsR[{baseX+deltaX, baseY+deltaY}].end() and *item <= r){
                ans = true;
            }

        }

        if(ans){
            yes();
            continue;
        }

        no();
    }
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```