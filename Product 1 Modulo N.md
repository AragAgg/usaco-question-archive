---
Question Link: https://codeforces.com/contest/1514/problem/C
Problem Set:
  - "*1600"
  - Code Forces
  - DIV2C
Last edited time: 2023-10-27T23:24
Status: Nice Question
tags:
  - Greedy
  - Math
  - Mod
  - Number-Theory
Key Takeaway: "Trivial: Two numbers are co-primes, if their gcd() is 1."
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

// cin.tie(0)->sync_with_stdio(0);

void fx() {
    ll n, fact = 1;
    cin >> n;

    int counter = 0;
    for(ll i = 1; i < n; i++) if(gcd(i, n) == 1){ fact *= i, fact %= n, counter++;}
    
    ll exculsion = (fact != 1)?fact:n;
    
    cout << (counter - (exculsion != n)) << endl;
    for(int i = 1; i < n; i++) if(gcd(i, n) == 1 and exculsion != i) cout << i << " ";
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

> [!info] Codeforces round #716 editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/89810](https://codeforces.com/blog/entry/89810)