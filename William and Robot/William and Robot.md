---
Question Link: https://codeforces.com/gym/104002/problem/E
Problem Set:
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Game
  - Greedy
  - Sorting
  - Structure
Key Takeaway: "In a game problem, where the question asks to optimise an score, it might help to first get an idea on the bounds of the score. "
---
### Editorial [uses multiset]

![[Screenshot_2023-09-12_at_7.20.59_PM.png]]

  

### Solution (AC) [uses Priority_Queue]

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

void fx(){
    int n;
    cin >> n;
    
    vi tab(n);
    for(auto &i: tab) cin >> i;
    
    priority_queue<int, vi, greater<int>>pq;
    
    long long ans = 0;
    
    for(int i = 0; i < n; i+=2){
        pq.push(tab[i]);
        pq.push(tab[i+1]);
        
        pq.pop();
    }
    
    while(pq.size()){ ans += pq.top(); pq.pop();}
    
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

### Editorial (USACO)

[https://usaco.guide/problems/cf-william-and-robot/solution](https://usaco.guide/problems/cf-william-and-robot/solution)