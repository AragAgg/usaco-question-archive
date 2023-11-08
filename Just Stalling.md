---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1085
Problem Set:
  - Bronze
Last edited time: 2023-11-08T21:16
Status: Nice Question
tags:
  - Math
Key Takeaway: 20 factorial fits in long long.
---
### Solution ONE (WA)

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
    // Functionality for fx
    int n;
    cin >> n;

    vi cows(n), barns(n);
    for(auto &item: cows) cin >> item;
    for(auto &item: barns) cin >> item;


    vector<ll>fact(21);
    fact[0] = 1;
    for(int i = 1; i <= 20; i++) fact[i] = fact[i-1] * i;


    vi invalidAt(n);
    for(int i = 0; i < n; i++){
        for(auto cow: cows) if(cow > barns[i]) invalidAt[i]++;
    }
    
    sort(all(invalidAt));

    ll res = 0;

    for(int mask = 0; mask <= (1 << n); mask++){
        ll t = 1;
        ll till = 0;
        bool flag = true;

        for(int i = 0; i <= n; i++){
            if(mask&(1 << i)){
                if(invalidAt[i] - till <= 0){
                    flag = false;
                    break;
                }
                t = t * invalidAt[i] - till++;
            }
        }

        if(!flag) continue;
        res += ((__builtin_popcount(mask)&1)?-1:1) * t * fact[(n - __builtin_popcount(mask))];
    
    }

    cout << res << endl;

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
    // Functionality for fx
    int n;
    cin >> n;

    vi cows(n), barns(n);

    for(auto &i: cows) cin >> i;
    for(auto &i: barns) cin >> i;

    vi invalid(n);
    for(int i = 0; i < n; i++){
        for(auto cow: cows) invalid[i] += (cow > barns[i]);
    }

    sort(invalid.rbegin(), invalid.rend());
    int valid = n;
    ll res = 1;
    for(auto item: invalid){
        if(valid - item < 0) break;
        res *= (valid - item);
        valid--;
    }
    cout << res << endl;
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

> [!info] Solution - Just Stalling (USACO Bronze 2021 January)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-1085-just-stalling/solution](https://usaco.guide/problems/usaco-1085-just-stalling/solution)