---
Question Link: https://codeforces.com/contest/1857/problem/D
Problem Set:
  - DIV3D
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Math
  - Sorting
  - Tree
Key Takeaway: Try manipulating constraint equations to better suit the interface of the data structure used.
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
    int n; cin >> n;
    
    vi a(n);
    vi b(n);
    vii c(n);
    
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    
    for(int i = 0; i < n; i++){
        c[i] = {(b[i]-a[i]), i};
    }
    
    sort(all(c));
    
    vi tab;
    
    for(int i = 0 ; i < n; i++){
        if(c[i].f == c[0].f) tab.pb(c[i].second+1);
    }
    
    cout << tab.size() << endl;
    
    sort(all(tab));
    
    for(auto i: tab) cout << i << " ";
    cout << endl;
    
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

### Editorial

The first step is to modify the inequality.

  

$$𝑎𝑢−𝑎𝑣≥𝑏𝑢−𝑏𝑣⇔𝑎𝑢−𝑏𝑢≥𝑎𝑣−𝑏𝑣au−av≥bu−bv⇔au−bu≥av−bv.$$

  

We can create a new array `c`, where `ci=ai−bi` and our inequality is transformed to `cu≥cv.`

Suppose the set `p1,…pm` is the set of such vertices `v` that `cv` is maximum possible. From each `pi` there will be a path to all other vertices, because `cpi` is not less than any other `cu`, so the set `p` is guaranteed will be in our answer.

  

Now the question is whether there are other vertices in our answer?

  

Let's prove that from any such vertex `v`, that is not maximum, there is no path to any vertex from `p`. The first observation, that there is no edge between `v` and any `p_i`. So the path must go through other vertices. But even if there exist a path to another vertex `u`, `c_u` will be still less that `c_{p_i}`, so it is impossible to get any `p_i`.

  

In such way we proved that the answer will always be the set of such `v`, that `c_v` is maximized.

  

The complexity is `O(n)`.