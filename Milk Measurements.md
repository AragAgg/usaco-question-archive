---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=763
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Structure
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

void fx() {
    // Functionality for fx
    int n, g;
    cin >> n >> g;
    
    vector<pair<int, pii>>events;
    map<int, int>cows;
    map<int, usi>milk;
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        
        pii event;
        cin >> event.f >> event.s;
        
        events.pb({t, event});
        cows[event.f] = g;
        milk[g].insert(event.f);
    }
    
    for(int i = 1; i <= 1e9; i++){
        if(!cows.count(i)){
            cows[i] = g;
            milk[g].insert(i);
            break;
        }
    }
    
    sort(all(events));
    
    int ans = 0;
    
    usi prevLeaders = (*milk.rbegin()).s;
    
    for(int i = 0; i < n;){
        int timeStamp = events[i].f;
        
        while(i < n and events[i].f == timeStamp){
            milk[cows[events[i].s.f]].erase(events[i].s.f);
            if(milk[cows[events[i].s.f]].size() == 0) milk.erase(cows[events[i].s.f]); 
            cows[events[i].s.f] += events[i].s.s;
            milk[cows[events[i].s.f]].insert(events[i].s.f);
            i++;
        }
        
        if(prevLeaders != (*milk.rbegin()).s){
            ans++;
        }
        
        prevLeaders = (*milk.rbegin()).s;
        
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("measurement"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```