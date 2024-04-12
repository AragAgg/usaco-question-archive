---
Question Link: https://cses.fi/file/53dd44a670b759ddb6c8a7025a31752be4b4d25d9baef332877422e44b9a84cc
Problem Set:
  - Baltic OI
  - Priority
  - Review
Last edited time: 2024-04-12T14:44
Status: Seen Editorial
tags:
  - Dynamic-Programming
  - Geometry
  - LIS
  - Math
What's up: Really nice question. Would like to reread the editorial’
---
### Editorial

[https://usaco.guide/problems/baltic-oi-2009candy/solution](https://usaco.guide/problems/baltic-oi-2009candy/solution)  

  

  

see: [https://usaco.guide/gold/lis?lang=cpp](https://usaco.guide/gold/lis?lang=cpp)

  

### Solution (AC)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define p push
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
//\#define int ll
\#define endl "\n"
\#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

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


void fx() {
    int n;
    cin >> n;

    vii tab(n);
    for(int i = 0; i < n; i++){
        int s, t;
        cin >> s >> t;

        tab[i] = {s - t, -(s + t)};
    }

    sort(all(tab));

    vector<pii>wagons;
    
    vector<array<int, 3>>res;

    for(auto [l, r]: tab){
        r *= -1;
        int s = (l + r)/ 2;
        int t = r - s;


        auto iter = lower_bound(all(wagons), make_pair(r, INT_MIN));
        if(iter == wagons.end()){
            res.pb({s, t, (int)wagons.size()});
            wagons.pb({r, (int)wagons.size()});
        }else{
            int temp = iter->s;
            res.pb({s, t, temp});
            iter->f = r;        
        }
    }

    cout << (wagons.size()) << endl;
    for(auto [a, b, c] : res) cout << a << " " << b << " " << (c+1) << endl;

}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```