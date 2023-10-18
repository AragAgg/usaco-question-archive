---
Question Link: https://cses.fi/problemset/task/1073
Problem Set:
  - CSES
Last edited time: 2023-10-18T19:10
Status: Solved
tags:
  - Greedy
  - LIS
  - Sorting
  - Structure
Key Takeaway: Multiset is the one of the best structures that allows to value with the least absolute difference from the input element.
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

struct cmp{

    bool operator()(pii &a, pii &b) const{
        if(a.f == b.f) return a.s < b.s;
        else return (a.f > b.f);
    }  
};

void fx() {
    int n;
    cin >> n;
    
    int ans = 0;
    
    multiset<int>towers;
    
    for(int i = 0; i < n; i++){
        int newTower;
        cin >> newTower;
        
        auto iter = towers.upper_bound(newTower);
        
        if(iter != towers.end()){
            towers.erase(iter);
            ans--;
        }
        ans++;
        towers.insert(newTower);
        
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

### Editorial (from: USACO)

> [!info] Solution - Towers (CSES)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cses-1073-towers/solution](https://usaco.guide/problems/cses-1073-towers/solution)