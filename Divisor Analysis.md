---
Question Link: https://cses.fi/problemset/task/2182
Problem Set:
  - CSES
Last edited time: 2023-11-01T20:23
Status: Nice Question
tags:
  - Implementation
  - Math
  - Mod
What's up: Reallllly nice question.
Key Takeaway: If you’re facing error, when using fast_exponentation, because of code becoming mess, try breaking it into steps to avoid confusion. As it doesn’t changes the time_complexity.Pay attention to overflows, specially when working with exponents, and mod, as it would magnify the error exponentially.
---
### Solution (AC) [MULTIPLICATIVE]

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

ll mod = 1e9+7;

ll powmod(ll a, ll b){
    ll res = 1;
    
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    
    return res;
}

ll modinv(ll a){ return powmod(a, mod - 2); }

void fx() {
    int n;
    cin >> n;
    
    ll nDivisors = 1;
    ll sumDivisors = 1;
    ll productDivisors = 1;
    ll trailing = 1;
    
    
    
    while(n--){
        ll prime, expo;
        cin >> prime >> expo;
        
        nDivisors = nDivisors * (expo +1) % mod;
        sumDivisors = (sumDivisors * (powmod(prime, expo+1) -1) % mod) * modinv(prime - 1) % mod;
        productDivisors = powmod(productDivisors, (expo+1)) * powmod(prime, (((expo)*(expo+1)/2 % (mod -1))*trailing) % (mod-1)) % mod;
        
        trailing = trailing * (expo + 1) % (mod-1);
        
    }
    
    cout << nDivisors << " " << sumDivisors << " " << productDivisors << endl;
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

### Solution (AC) [ITERATIVE]

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
 
ll mod = 1e9+7;
 
ll powmod(ll a, ll b){
    ll res = 1;
    
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    
    return res;
}
 
ll modinv(ll a){ return powmod(a, mod - 2); }
 
void fx() {
    int n;
    cin >> n;
    
    ll nDivisors = 1;
    ll sumDivisors = 1;
    ll productDivisors = 1;
    ll trailing = 1;
    
    
    
    while(n--){
        ll prime, expo;
        cin >> prime >> expo;
        
        nDivisors = nDivisors * (expo +1) % mod;
        sumDivisors = (sumDivisors * (powmod(prime, expo+1) -1) % mod) * modinv(prime - 1) % mod;
        productDivisors = powmod(productDivisors, (expo+1)) * powmod(powmod(prime, (((expo)*(expo+1))/2)), trailing) % mod;
        
        trailing = trailing * (expo + 1) % (mod-1);
        
    }
    
    cout << nDivisors << " " << sumDivisors << " " << productDivisors << endl;
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

> [!info] Solution - Divisor Analysis (CSES)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cses-2182-divisor-analysis/solution](https://usaco.guide/problems/cses-2182-divisor-analysis/solution)