---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=839
Problem Set:
  - Gold
Last edited time: 2023-12-02T16:11
Status: Nice Question
tags:
  - Dynamic-Programming
  - Observation
  - Optimisation
What's up: Interesting Question. Passes due to bad test data… will work normally if we change unordered_map to a simple array/vector. Did’t notice that we don’t have to keep track of weights higher that 1e6. (which is a very important optimization)
Key Takeaway: If you want to write a code quick for subtasks, consider literally storing states in an unordered_set or unordered_map, just make sure that it don’t blow up exponentially. (≤ 1e7 or something).
---
### Solution (AC) [Maybe TLE on last case]

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

    int n, w;
    cin >> n >> w;

    vector<pii>tab(n);
    for(auto &i: tab) cin >> i.s >> i.f;

    sort(all(tab), [](auto a, auto b){
            return ((double)(a.f))/(a.s) >= ((double)(b.f))/(b.s);
        });
    
    
    unordered_map<int, int>dp; // will work properly after changing to vector.
    dp.insert({0, 0});

    for(int i = 0; i < n; i++){
        vector<pair<int, int>>ins;

        for(auto &item: dp){
            ins.pb({item.f + tab[i].s, item.s + tab[i].f});
        }

        ins.pb({tab[i].s, tab[i].f});

        for(auto &item: ins){
            if(item.f > 1000000) continue; // change to 1e5??
            auto iter = dp.find(item.f);
            if(iter == dp.end()) dp.insert({item.f, item.s});
            else iter->s = max(iter->s, item.s);
        }

    }

    ll ratio = 0;

    for(auto &i: dp){
        if(i.f >= w and ((ll)i.s*1000)/i.f > ratio){
            ratio = (((ll)i.s*1000)/i.f);
        }
    }

    cout << ratio << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("talent"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```