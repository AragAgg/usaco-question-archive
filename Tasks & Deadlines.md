---
Question Link: https://cses.fi/problemset/task/1630
Problem Set:
  - CSES
Last edited time: 2023-10-18T19:10
Status: Solved
tags:
  - Greedy
  - Interval-Scheduling
  - Sorting
What's up: In any scheduling problem, it is worth it to try prioritising the task with the least ending time.
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
    int n;
    cin >> n;
    
    vii tasks(n);
    for(auto &i: tasks){
        cin >> i.f >> i.s;
    }
    
    sort(all(tasks),[](pii &a, pii &b){
        
        //earlies maximum start time first...
        // if((a.s-a.f) == (b.s-b.f)){
        //     return (a.s < b.s);
        // }
        
        // return ((a.s - a.f) < (b.s - b.f));
        
        
        //smallest duriation first
        if(a.f == b.f) return a.s < b.s;
        else return a.f < b.f;
    });
    
    // for(auto i: tasks){
    //     cout << "task : duration: " << i.f << " and deadline: " << i.s << endl;
    // }
    
    long long ans = 0;
    long long t = 0;
    
    for(auto &task: tasks){
        t += task.f;
        ans += (task.s - t);
    }
    
    cout << ans << endl;
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