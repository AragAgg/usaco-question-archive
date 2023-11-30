---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=694
Problem Set:
  - Gold
Last edited time: 2023-11-30T13:29
Status: Solved
tags:
  - Dynamic-Programming
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
ll n, k;
vector<int>tab;
// dp[i][moves][move]
int dp[100000][21][3];

int fx2(int i, int moves, int curr){
    if(i == n or moves < 0) return 0;

    if(dp[i][moves][curr] != -1) return dp[i][moves][curr];

    int res = -1;
    for(int x = 0; x < 3; x++){
        if(x == curr) res = max(res, (tab[i] == curr) + fx2(i+1, moves, curr));
        else res = max(res, (tab[i] == curr) + fx2(i+1, moves-1, x));
    }

    return dp[i][moves][curr] = res;
}


void fx() {
    // Functionality for fx
    cin >> n >> k;
    tab.assign(n, 0);
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;

        if(c == 'H') tab[i] = 0;
        else if(c == 'P') tab[i] = 1;
        else tab[i] = 2;
    }

    for(int i = 0; i < 100000; i++) for(int j = 0; j < 21; j++) for(int k = 0; k < 3; k++) dp[i][j][k] = -1;

    cout << max(fx2(0, k, 0), max(fx2(0, k, 1), fx2(0, k, 2))) << endl;



}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("hps"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Not so good idea [Editorial]

```C++
//BeginCodeSnip{C++ Short Template}
\#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
\#define pb push_back
\#define all(x) begin(x), end(x)
\#define sz(x) (int) (x).size()

using pi = pair<int,int>;
\#define f first
\#define s second
\#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
//EndCodeSnip

const int MX = 1e5 + 5;

int dp[MX][25][3];  // dp[i][j][k] is the largest number of games she wins at
                    // games i with switches j with current item k
int A[MX];          // 0 == H 1 == P 2 == S

int main() {
	setIO("hps");

	int N, K;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		if (a == 'H') A[i] = 0;
		if (a == 'P') A[i] = 1;
		if (a == 'S') A[i] = 2;
	}

	// either she switches to h or p or s or stays

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 3; k++) {
				if (k == A[i]) dp[i][j][k]++;
				dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0],
				                          dp[i][j][k]);  // switch to not item
				dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1],
				                          dp[i][j][k]);  // switch to not item
				dp[i + 1][j + 1][2] = max(dp[i + 1][j + 1][2],
				                          dp[i][j][k]);  // switch to not item
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);  // stay
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < 3; i++) { ret = max(ret, dp[N - 1][K][i]); }

	cout << ret << endl;
}
```