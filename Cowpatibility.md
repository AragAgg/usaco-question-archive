---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=862
Problem Set:
  - Gold
Last edited time: 2023-11-13T13:43
Status: Nice Question
tags:
  - Math
  - PIE
What's up: Question is quite awesome. (some issue with tc… might fail on tc 9).
Key Takeaway: Using unordered_map in OIs is not a problem. Try to view input in a way to minimise implementation.
---
### Solution (AC/TLETC9)

```C++
\#include <bits/stdc++.h>
using namespace std;
\#pragma gcc optimize("o3,unroll-loops")
\#pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt") 
// shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
\#define endl "\n"
 
// type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;
 
// debugging macros
\#define debug(x) cerr << \#x << " = " << (x) << '\n'
\#define debug_vector(v) _debug_vector(\#v, v)
template<typename t>
void _debug_vector(const string& name, const vector<t>& a) {
    cerr << name << " = [ ";
    for(const auto &x : a) cerr << x << ' ';
    cerr << "]\n";
}
 
// i/o redirection for local testing
\#define iofile(io) \
        freopen((io + ".in").c_str(), "r", stdin); \
        freopen((io + ".out").c_str(), "w", stdout);
 
// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};
 
// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};
 
// common outputs
void yes() { cout << "yes" << '\n'; }
void no() { cout << "no" << '\n'; }
 
 
void fx() {
    // functionality for fx
    vector<map<vector<int>, ll>> tab(6);
    ll n, n;
    cin >> n;
    n = n;
    ll res = 0;
    vi popcount(32, 0), t;
    for(int mask = 0; mask < (1 << 5); mask++) popcount[mask] = __builtin_popcount(mask);
    
    vvi cows(n, vi(5));
    for(auto &cow :cows){
        for(int i = 0; i < 5; i++) cin >> cow[i];
        sort(all(cow));
    }
    for(auto cow: cows){
        t.clear();

        for(int a = 0; a < 5; a++){
            tab[1][{cow[a]}]++;
            for(int b = a + 1; b < 5; b++){
                tab[2][{cow[a], cow[b]}]++;
                for(int c = b+1; c < 5; c++){
                    tab[3][{cow[a], cow[b], cow[c]}]++;
                    for(int d = c+1; d < 5; d++){
                        tab[4][{cow[a], cow[b], cow[c], cow[d]}]++;
                    }
                }
            }
        }

        tab[5][cow]++;
    }
    bool flag = false;
    for(auto &row: tab){
        for(auto &[vec, val]: row){
            if(flag) res += val * (val-1)/2;
            else res -= val * (val -1) /2;
        }
        flag = !flag;
    }
    cout << (((n*(n-1))/2) - res) << endl;
}
 
int main() {
    // uncomment the following lines for file i/o
    iofile(string("cowpatibility"));
    // uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    cin.tie(0)->sync_with_stdio(0);
    
    // single test case
    fx();
    
    return 0;
}
```

### Solution by somebody else [really really awesome]

```C++
\#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
\#define all(x) x.begin(), x.end()
//===================================
unordered_map<string, int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    ll n; cin >> n;
    ll tot = n*(n-1)/2;
    for (int i = 1; i <= n; i++){
        vector<string> v(5); for (string &x: v) cin >> x; sort(all(v));
        for (int mask = 1; mask < 1<<5; mask++){
            string s = "";
            for (int j = 0; j < 5; j++) if (mask&(1<<j)) s += v[j]+'|';
            tot -= (__builtin_popcount(mask)&1? 1 : -1) * (cnt[s]++);
        }
    }
    cout << tot << "\n";
}
```

### Editorial

> [!info] Solution - Cowpatibility (USACO Gold 2018 December)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-862-cowpatibility/solution](https://usaco.guide/problems/usaco-862-cowpatibility/solution)