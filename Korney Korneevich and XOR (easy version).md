---
Question Link: https://codeforces.com/contest/1582/problem/F1
Problem Set:
  - "*1800"
  - Code Forces
Last edited time: 2023-12-11T13:34
Status: Solved
tags:
  - Bitwise
  - Dynamic-Programming
  - Greedy
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

    vector<int>dp(1025, INT_MAX);
    dp[0] = 0;

    int t;
    
    for(int i = 0; i < n; i++){
        cin >> t;
        vector<int>temp(1025, INT_MAX);
        for(int j = 1024; j >= 0; j--){
            if(dp[j] != INT_MAX and dp[j] < t) temp[j^t] = min(temp[j^t], t);
            temp[j] = min(temp[j], dp[j]);
        }

        temp[t] = min(temp[t], t);
        swap(dp, temp);
    }

    int res = 0;
    for(int i = 0; i < 1025; i++) if(dp[i] != INT_MAX) res++;
    cout << res << endl;
    for(int i = 0; i < 1025; i++) if(dp[i] != INT_MAX) cout << i << " ";
    cout << endl;
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

### Editorial (not that good)

```C++
\#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1 << 9;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &i : arr) { cin >> i; }

	/*
	 * dp[x][i] = whether it is possible to get x using XOR of an increasing
	 * sequence which ends with a number smaller than or equal to i
	 */
	vector<vector<bool>> dp(MAXA, vector<bool>(MAXA, false));
	for (int i = 0; i < MAXA; i++) { dp[0][i] = true; }

	for (int &a : arr) {
		// 0 ^ x = x for all x, so there is no need to consider the element 0
		if (a == 0) { continue; }
		for (int i = 0; i < MAXA; i++) {
			/*
			 * For every i as a result of XOR operations on increasing sequences
			 * that end with a number less than a, we can add a to the end of it
			 * and get a new x = i ^ a
			 */
			dp[a ^ i][a] = dp[a ^ i][a] || dp[i][a - 1];
			/*
			 * x = a ^ i can be used to construct new increasing sequences by
			 * appending a number j >= a
			 */
			if (dp[a ^ i][a]) {
				int j = a + 1;
				while (j < MAXA && !dp[a ^ i][j]) { dp[a ^ i][j++] = true; }
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i < MAXA; i++) {
		if (dp[i][MAXA - 1]) { ans.push_back(i); }
	}

	cout << ans.size() << "\n";
	for (int &i : ans) { cout << i << " "; }
	cout << endl;
}
```