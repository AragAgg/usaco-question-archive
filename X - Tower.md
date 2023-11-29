---
Question Link: https://atcoder.jp/contests/dp/tasks/dp_x
Problem Set:
  - AtCoder
  - Review
Last edited time: 2023-11-29T11:55
Status: Seen Editorial
tags:
  - Dynamic-Programming
What's up: Couldn’t figure out how to sort.
Key Takeaway: Sort by a value derived by using two or more values from the state.iota(begin_iter, end_iter, start) fills the values in the range [begin, end), by starting with start, and then incrementing by 1 for every element
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

void fx() {
    // Functionality for fx
    int n;
    cin >> n;

    vector<pair<pii, pii>>tab(n);
    for(int i = 0; i < n; i++) cin >> tab[i].f.s >> tab[i].s.f >> tab[i].s.s, tab[i].f.f = -1 * (tab[i].f.s + tab[i].s.f);
    sort(all(tab));

    vector<int> s(n, 0), v(n, 0), w(n, 0);
    for(int i = 0; i < n; i++) s[i] = tab[i].s.f, w[i] = tab[i].f.s, v[i] = tab[i].s.s; 
    
    vector<vector<ll>>dp(n+1, vector<ll>(10005));
    for(int i = 0; i < 1002; i++) for(int j = 0; j < 10005; j++) dp[i][j] = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10001; j++){
            if(!dp[i][j]) continue;
            
            if(min(j - w[i], s[i]) >= 0) dp[i+1][min(j - w[i], s[i])] = max( dp[i+1][min(j - w[i], s[i])], dp[i][j] + v[i]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }

        dp[i+1][s[i]] = max(dp[i+1][s[i]], (ll)v[i]);
    }

    cout << *max_element(all(dp[n])) << endl;
    
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

### Editorial Solution [clean]

```C++
\#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e3+1;

long long dp[20001];
int w[MAX_N], s[MAX_N], v[MAX_N], p[MAX_N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	for(int i = 0; i < N; ++i) cin >> w[i] >> s[i] >> v[i];

	iota(p, p + N, 0);

	sort(p, p + N, [&](const int &a, const int &b) {
		return w[a] + s[a] < w[b] + s[b];
	});

	for(int i = 0; i < N; ++i) {
		int x = p[i];
		for(int j = s[x]; j >= 0; --j) {
			dp[j + w[x]] = max(dp[j + w[x]], dp[j] + v[x]);
		}
	}

	cout << *max_element(dp, dp + 20001) << endl;
}
```