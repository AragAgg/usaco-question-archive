---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_c
Problem Set:
  - AtCoder
Last edited time: 2023-11-25T18:43
Status: "Very Interesting "
tags:
  - Dynamic-Programming
What's up: Solved. To review the Editorial
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

void fx() {
    // Functionality for fx
    int n;
    cin >> n;

    vector<vector<int>>tasks(n, vector<int>(3));
    for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> tasks[i][j]; 

    vector<vector<ll>>dp(n, vector<ll>(3, 0));

    dp[0][0] = tasks[0][0];
    dp[0][1] = tasks[0][1];
    dp[0][2] = tasks[0][2];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(k == j) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + tasks[i][j]);
            }
        }
    }


    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
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

### Anther interesting Idea from Editorial

```C++
\#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+1;

bool ckmax(int& a, const int& b) {
	return a < b ? a = b, 1 : 0;
}

int dp[mx][3];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	for(int i = 1; i <= N; ++i) {
		int a, b, c; cin >> a >> b >> c;
		ckmax(dp[i][0], max(dp[i - 1][1] + b, dp[i - 1][2] + c));
		ckmax(dp[i][1], max(dp[i - 1][0] + a, dp[i - 1][2] + c));
		ckmax(dp[i][2], max(dp[i - 1][0] + a, dp[i - 1][1] + b));
	}

	cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
}
```

> [!info] AtCoder DP Editorial - Neo Wang, Dong Liu  
> An editorial for all the problems contained in the AtCoder DP Contest  
> [https://nwatx.me/post/atcoderdp](https://nwatx.me/post/atcoderdp)