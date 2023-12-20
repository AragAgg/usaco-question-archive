---
Question Link: https://vjudge.net/problem/LightOJ-1068
Problem Set:
  - Uncategorised
Last edited time: 2023-12-20T20:03
Status: Solved
tags:
  - Digit-DP
  - Dynamic-Programming
What's up: Nice observation
Key Takeaway: The sum of digits of a huge number could be very less if analysed properly.
---
### Solution (AC) [messy]

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

string a, b, s;
int k, n;
//dp [digit][sum%k][rjm%k][tight]
int dp[20][2][101][101];

int fx2(int digit, bool tight, int sum, int rem){
    if(digit == s.size()) return (sum == 0 and rem == 0);

    int till = (tight)?(s[digit]-'0'):9;
    if(dp[digit][tight][sum][rem] != -1) return dp[digit][tight][sum][rem];

    dp[digit][tight][sum][rem] = 0;

    for(int d = 0; d <= till; d++)
        dp[digit][tight][sum][rem] += fx2(digit+1, (tight && ((s[digit] - '0') == d)), (sum+d)%k, (rem + (d * (int)pow(10, n-digit-1)))%k);

    return dp[digit][tight][sum][rem];
}

void fx() {
    // Functionality for fx
    cin >> a >> b >> k;

    s = b;
    n = b.size();
    memset(dp, -1, sizeof(dp));
    int B = fx2(0, 1, 0, 0);

    int t = stoi(a);
    s = to_string(t-1);
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int A = fx2(0, 1, 0, 0);
    cout << (B-A) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    int curr = 1;
    while(t--){ 
        cout << "Case " << (curr++) << ": ";
        fx();
    }
    
    // Single test case
    //fx();
    
    return 0;
}
```