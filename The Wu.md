---
Question Link: https://codeforces.com/contest/1017/problem/D
Problem Set:
  - "*1900"
  - Code Forces
  - DIV2D
Last edited time: 2023-10-25T00:48
Status: Solved with Help
tags:
  - Bitwise
  - Implementation
  - Optimisation
Key Takeaway: Do not do << endl; when the number of I\O operations are too high.Use fast_io.
---
### Solution One (TLE TC4)

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

int freq[5000] = {};
int n, m, q;
vi wu;
int memo[5000][5000];
unordered_map<ll, int>sMemo;
vector<vi> ans;

int transform(ll num){
    int res = 0;
    int cnt = n-1;
    while(cnt >= 0){
        if(num%10) res |= (1 << cnt);
        cnt--;
        num /= 10;
    }
    return res;
}

int wuValue(unsigned int a, unsigned int b){
    if(memo[a][b] != -1) return memo[a][b];
    unsigned int t = ~(a ^ b);
    memo[a][b] = 0;
    int res = 0;
    for(int i = 0; i < n; i++) if(t & (1 << (i))) res += wu[i];
    return memo[a][b] = res;
}

void fx() {
    cin >> n >> m >> q;
    wu.assign(n, 0);
    ans.assign(pow(2, n), vi(102, 0));
    
    for(auto &i: wu) cin >> i;
    for(int i = 0; i < pow(2, n); i++) for(int j = 0; j < pow(2, n); j++) memo[i][j] = -1;
    
    for(int i = 0; i < m; i++){
        ll t;
        cin >> t;
        freq[transform(t)]++;
    }
    
    for(int mask = 0; mask < pow(2, n); mask++) for(int i = 0; i < pow(2, n); i++) ans[mask][min(wuValue(mask, i), 101)] += freq[i];
    
    for(int i = 0; i < pow(2, n); i++){
        for(int j = 1; j < 102; j++) ans[i][j] += ans[i][j-1];
    }
    
    while(q--){
        ll k;
        int te;
        cin >> te >> k;
        
        cout << ans[transform(te)][k] << endl;
        
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

### Solution Two (AC)

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

void fx() {
    int n, m, q;
    cin >> n >> m >> q;

    int w[n] = {}, freq[1 << n] = {}, wu[1 << n] = {};
    for(auto &i: w) cin >> i;
    
    int res[1 << n][101] = {};
    
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int t = 0;
        for(int i = 0; i < n; i++) if(s[i] == '1') t |= (1 << i);
        freq[t]++;
    }
    
    for(int mask = 0; mask < (1 << n); mask++) for(int i = 0; i < n; i++) if(mask & (1 << i)) wu[mask] += w[i];
    
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < (1 << n); j++){
            int canTake = wu[(1 << n)-1] - wu[i^j];
            if(canTake < 101) res[i][canTake] += freq[j];
        }
        
        for(int j = 1; j < 101; j++) res[i][j] += res[i][j-1];
    }
    
    while(q--){
        string s;
        int k, val = 0;
        cin >> s >> k; 
        
        for(int i = 0; i < n; i++) if(s[i] == '1') val |= (1 << i);
        cout << res[val][k] << "\n";
    }
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    cin.tie(0)->sync_with_stdio(0);
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Solution - The Wu (CF)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cf-the-wu/solution](https://usaco.guide/problems/cf-the-wu/solution)  

> [!info] Codeforces Round #502 (in memory of Leopoldo Taravilse, Div. 1 + Div. 2) —— Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/61081](https://codeforces.com/blog/entry/61081)