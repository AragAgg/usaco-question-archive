---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=553
Problem Set:
  - Gold
Last edited time: 2024-04-15T14:15
Status: Solved
tags:
  - Dynamic-Programming
  - Grid
  - Implementation
Key Takeaway: prev = dp[i&2] implementation trick (see the other solution)
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
const ll mod = 1e9+7;

void fx() {
    // Functionality for fx
    int n;
    cin >> n;
    
    vector<string>tab(n);
    for(auto &i: tab) cin >> i;

    vector<vector<ll>>prev(n, vector<ll>(n, 0));

    for(int i = 0; i < n; i++) prev[i][i] = 1;

    for(int a =  1; a < n; a++){
        vector<vector<ll>>dp(n, vector<ll>(n, 0));
        for(int r1 = 0; r1 < n; r1++){
            int c1 = n - a - 1 - r1;

            if(c1 < 0) continue;

            for(int r2 = 0; r2 < n; r2++){
                int c2 = n + a - 1 - r2;
                if(c2 >= n) continue;

                if(tab[c1][r1] != tab[c2][r2]) continue;

                dp[r1][r2] = prev[r1][r2];
                if(r1 + 1 < n) dp[r1][r2] += prev[r1+1][r2];
                if(r2 - 1 >= 0) dp[r1][r2] += prev[r1][r2-1];
                if((r1 + 1 < n) and (r2 - 1 >= 0)) dp[r1][r2] += prev[r1+1][r2-1];
               
                dp[r1][r2] %= mod;
            }
        }

        swap(dp, prev);
    }

    cout << prev[0][n-1] << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("palpath"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution (from USACO Guide User Subs) [nice trick]

```C++
\#include <bits/stdc++.h>
using namespace std;

\#include <ext/pb_ds/assoc_container.hpp>
\#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = 
            tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

\#define ll long long
\#define ld long double
\#define ar array
\#define vi vector<int>
\#define vii vector<vector<int>>
\#define pii pair<int, int>
\#define pb push_back
\#define all(x) x.begin(), x.end()
\#define f first
\#define s second

const int MOD = 1e9+7;
const int inf = 1e9;
const ll linf = 1e18;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


// -------------------------------------------------- Main Code --------------------------------------------------

int n;
char grid[501][501];
int dp[2][501][501];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> grid[i][j];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                int c1 = (n-i-j+2), c2 = (i+n-k);
                if (c1 <= 0 || c2 <= 0 || c1 > n || c2 > n || grid[j][c1] != grid[k][c2]) {
                    dp[i%2][j][k] = 0;
                    continue;
                }
                if (abs(j-k) + abs(c1-c2) <= 1) {
                    dp[i%2][j][k] = 1; continue;
                }
                dp[i%2][j][k] = 0;
                dp[i%2][j][k] = (dp[i%2][j][k] + dp[1-(i%2)][j][k])%MOD;
                if (j+1 <= n) dp[i%2][j][k] = (dp[i%2][j][k] + dp[1-(i%2)][j+1][k])%MOD;
                if (k-1 >= 0) dp[i%2][j][k] = (dp[i%2][j][k] + dp[1-(i%2)][j][k-1])%MOD;
                if (j+1 <= n && k-1 >= 0) dp[i%2][j][k] = (dp[i%2][j][k] + dp[1-(i%2)][j+1][k-1])%MOD;
            }
        }
    }
    cout << dp[n%2][1][n] << endl;
}

int main () {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t; 
    while (t--) {
        sol();
    }
    return 0;
}
```

  

```C++

const ll mod = 1e9+7;

ll fx() {
    int n;
    cin >> n;
    vector<string>tab(n);
    for(auto &i: tab) cin >> i;

    vvll prev(n+5, vll(n+5, 0));
    vvll ways(n+5, vll(n+5, 0));

    for(int i = 0; i < n; i++) prev[i][i] = 1;

    for(int layer = 1; layer < n; layer++){

        ways.assign(n+5, vll(n+5, 0));

        for(int r1 = 0; r1 < n; r1++){

            for(int r2 = 0; r2 < n; r2++){

                int c1 = n - 1 - layer - r1;
                int c2 = n - 1 + layer - r2;

                if(r1 > r2 or c1 > c2 or r1 < 0 or c1 < 0) continue;

                if(tab[r1][c1] != tab[r2][c2]) continue;

                ways[r1][r2] = prev[r1][r2];

                if(r1 + 1 < n) ways[r1][r2] += prev[r1+1][r2];
                if(r2 - 1 >= 0) ways[r1][r2] += prev[r1][r2-1];
                if(r1 + 1 < n and r2 -1 >= 0) ways[r1][r2] += prev[r1+1][r2-1];
                
                /*
                if(c1 > 0 and c2 < n-1 and tab[r1][c1-1] == tab[r2][c2+1]) ways[r1][r2] += prev[r1][r2];
                if(c1 > 0 and r2 < n-1 and tab[r1][c1-1] == tab[r2+1][c2]) ways[r1][r2+1] += prev[r1][r2];
                if(r1 > 0 and r2 < n-1 and tab[r1-1][c1] == tab[r2+1][c2]) ways[r1-1][r2+1] += prev[r1][r2];
                if(r1 > 0 and c2 < n-1 and tab[r1-1][c1] == tab[r2][c2+1]) ways[r1-1][r2] += prev[r1][r2];
                */

                ways[r1][r2] %= mod;
            }
        }

        swap(prev, ways);
    }


    return prev[0][n-1];
    
}
```