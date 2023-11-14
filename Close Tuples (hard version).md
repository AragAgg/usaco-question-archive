---
Question Link: https://codeforces.com/contest/1462/problem/E2
Problem Set:
  - "*1700"
  - Code Forces
  - DIV3F
Last edited time: 2023-11-14T23:11
Status: Solved
tags:
  - Implementation
  - Math
---
### Solution (not working)

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
ll x = 2000100;
vector<ll> fact(x, 1), modinv(x, 1);
ll mod = 1e9+7;

ll fastExpo(ll n, ll m){
    ll res = 1;
    while(m){
        if(m&1) res = res * n % mod;
        n = n * n % mod;
        m /= 2;
    }
    return res;
} 

ll nchoosek(ll n, ll k){
    ll res = fact[n] * modinv[k] % mod;
    res = res * modinv[n-k] % mod;

    return res;
}

void fx() {
   ll n, m, k;
   cin >> n >> m >> k;

   vi tab(x, 0);
   for(int i = 0; i < n; i++){
       int t;
       cin >> t;
       tab[t]++;    
   }

   for(int i = 1; i < x; i++) tab[i] += tab[i-1];

   ll res = 0;

   for(int i = 1; i < x; i++){
       if(tab[i] - tab[i-1] == 0 or tab[i+k] - tab[i-1] < m) continue;
       ll temp = nchoosek(tab[i + k] - tab[i-1], m);
       res = res + temp %mod;
    }

   cout << res << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    for(int i = 1; i < x; i++) fact[i] = fact[i-1] * i % mod;
    modinv[x-1] = fastExpo(fact[x-1], mod-2);
    for(int i = x-2; i >= 0; i--) modinv[i] = (i+1) * modinv[i+1] % mod;


    // Uncomment the following lines for multiple test cases
     int t; cin >> t;
     while(t--) fx();
    
    // Single test case
   // fx();
    
    return 0;
}
```

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

ll mod = 1e9+7;
vector<ll> fact(2e6+100, 1), modinv(2e6+100, 1);

ll fastExpo(ll n, ll m){
    ll res = 1;
    while(m){
        if(m&1) res = (res * n) %mod;
        n = (n * n) %mod;
        m /= 2;
    }
    return res;
}

ll nchoosek(ll n, ll k){
    if(n < k or k < 0) return 0ll;
    ll res = fact[n] * modinv[k] %mod;
    res = res * modinv[n-k] %mod;
    return res;
}

void fx() {
    // Functionality for fx
    ll n, m, k;
    cin >> n >> m >> k;

    map<int, int>t;

    ll res = 0, sum = 0, x;

    for(int i = 0; i < n; i++) cin >> x, t[x]++;

    //identity element to ease implementation;
    t[0] = 0;

    for(auto &i: t) sum += i.s, i.s = sum;
    for(auto iter = t.begin(); iter != t.end(); iter++){
        ll num = (*iter).f;
        ll val = (*iter).s;
        if(num == 0) continue;
        auto it = prev(t.upper_bound(num + k));
        for(int take = 1; take <= val - (*prev(iter)).s; take++){
            res = (nchoosek(val - (*prev(iter)).s, take)*nchoosek((*it).s - val, m - take) + res) %mod;
        }
    }

    cout << res << endl;

}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases

    for(int i = 1; i < 2e6+100; i++) fact[i] = fact[i-1] * i %mod;
    modinv[2e6+99] = fastExpo(fact[2e6+99], 1e9+5);
    for(int i = 2e6+98; i >= 1; i--) modinv[i] = ((i+1) * modinv[i+1]) %mod;

    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    //fx();

    return 0;
}
```

### Editorial

> [!info] Codeforces Round #690 (Div. 3) Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/85594](https://codeforces.com/blog/entry/85594)