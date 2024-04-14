---
Question Link: https://codeforces.com/gym/100886/problem/G
Problem Set:
  - Code Forces
Last edited time: 2024-04-15T00:34
Status: Nice Question
tags:
  - Digit-DP
  - Dynamic-Programming
  - Stress-Test
What's up: Used stress test for the first time.
---
### Solution (WA on T22)

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

string a, b;
pair<ll, string> dp[20][2][2];

pair<ll, string> fx2(ll digit, bool t, bool t2){
    if(digit == a.size()) return {1, ""};
    if(dp[digit][t][t2].f != -1) return dp[digit][t][t2];

    ll res = 1;
    string s;
    
    for(ll d = 0; d < 10; d++){
        if(!(t and d < (a[digit] - '0')) and !(t2 and d > (b[digit] - '0'))){
            auto option = fx2(digit+1, (t and d == (a[digit] - '0')), (t2 and (d == (b[digit] - '0'))));

            option.f *= ((t and d == (a[digit] - '0') and d == 0)?1:d);
            if(option.f >= res){
                res = option.f;
                s = to_string(d) + option.s;
            }

        }
    }

    return dp[digit][t][t2] = {res, s};
}

void fx() {
    // Functionality for fx
    ll x, y;
    cin >> x >> y;
    a = to_string(x), b = to_string(y);
    for(int i = 0; i < 20; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) dp[i][j][k] = {-1, ""};
    while(a.size() != b.size()) a = '0' + a;

    cout << (stoll(fx2(0, 1, 1).s)) << endl;
    
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
    string lo, hi;
    cin >> lo >> hi;

    ll dp[20][2][2];
    string res[20][2][2];
    memset(dp, -1, sizeof(dp));
    vi loN(19, 0), hiN(19, 0);

    for(int i = 0; i < lo.size(); i++) loN[i+1] = (lo[lo.size()-i-1] - '0');
    for(int i = 0; i < hi.size(); i++) hiN[i+1] = (hi[hi.size()-i-1] - '0');

    string ans;
    ll best = 0;

    for(int i = loN[hi.size()]; i <= hiN[hi.size()]; i++){
        dp[hi.size()][i == hiN[hi.size()]][i == loN[hi.size()]] = i; // <-sure??
        res[hi.size()][i == hiN[hi.size()]][i == loN[hi.size()]] = ('0' + i); // <-sure??
    }

    for(int digit = hi.size(); digit >= 2; digit--){
        for(int up = 0; up < 2; up++){
            for(int down = 0; down < 2; down++){
                if(dp[digit][up][down] == -1) continue;

                //cout << digit << " " << up << " " << down << endl;
                //debug(dp[digit][up][down]);
                for(ll d = (down?loN[digit-1]:0); d <= (up?hiN[digit-1]:9); d++){

                    //debug(d);

                    ll option = max(dp[digit-1][up and d == hiN[digit-1]][down and d == loN[digit-1]], max(dp[digit][up][down] * d, d));
                    
                    if(dp[digit-1][up and d == hiN[digit-1]][down and d == loN[digit-1]] < option){
                        dp[digit-1][up and d == hiN[digit-1]][down and d == loN[digit-1]] = option;
                        res[digit-1][up and d == hiN[digit-1]][down and d == loN[digit-1]] = res[digit][up][down] + to_string(d);
                    }
                }
            }
        }
    }

    for(int up = 0; up < 2; up++){ 
        for(int down = 0; down < 2; down++){ 
            if(dp[1][up][down] >= best){
                best = dp[1][up][down];
                ans = res[1][up][down];
            }
        }
    }

    //cout << best  << endl;

    cout << stoll(ans) << endl;
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