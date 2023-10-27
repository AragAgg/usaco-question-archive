---
Question Link: https://cses.fi/problemset/task/1713
Problem Set:
  - CSES
Last edited time: 2023-10-27T21:19
Status: Solved
tags:
  - Math
  - Sieve
Key Takeaway: You could efficiently calculate the prime-factorisation of a number till n, after a n log n preprocessing, using a modified version of the sieve algorithm.Also the sieve algorithm could be made to run in O(N) time using some optimisations.
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

cin.tie(0)->sync_with_stdio(0);

vi seive;
int maxn = 1e6+1;

void fx() {
    int n, x;
    cin >> n;
    
    for(int i = 0; i < maxn; i++) seive.pb(i);
    for(int i = 2; i < maxn; i++) if(seive[i] == i) for(int j = i; j < maxn; j += i) seive[j] = i;
    
    while(n--){
        cin >> x;
        int divisors = 1;
        
        while(x > 1){
            int prime = seive[x], count = 0;
            while(x % prime == 0) count++, x /= prime;
            divisors *= (count+1);
        }
        
        cout << divisors << endl;
    }
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

### Editorial

> [!info] Divisibility  
> Using the information that one integer evenly divides another.  
> [https://usaco.guide/gold/divisibility](https://usaco.guide/gold/divisibility)