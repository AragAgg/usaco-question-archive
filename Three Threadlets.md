---
Question Link: https://codeforces.com/contest/1881/problem/B
Problem Set:
  - Code Forces
  - DIV3B
Last edited time: 2023-10-13T19:54
Status: Nice Question
tags:
  - Greedy
  - Implementation
  - Math
Key Takeaway: Greedy? Think priority queue.
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

void fx() {
    // Functionality for fx
    priority_queue<int>pq;
    
    vi tab(3, 0);
    for(auto &i: tab) cin >>i;
    sort(all(tab));
    
    int m = tab[0];
    
    pq.push(tab[1]); pq.push(tab[2]);
    
    int curr = 0;
    
    while(pq.size() and curr <= 3){
        if(pq.top() == m){ pq.pop(); continue;}
        
        int rem = pq.top();
        pq.pop();
        if(rem - m  < m){
            no();
            return;
        }
        
        pq.push(rem - m);
        curr++;
    }
    
    if(pq.size() == 0 and curr <= 3) yes();
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