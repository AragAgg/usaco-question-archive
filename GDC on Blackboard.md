---
Question Link: https://atcoder.jp/contests/abc125/tasks/abc125_c
Problem Set:
  - AtCoder
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - GCD
  - Math
Key Takeaway: GCD of a1, a2, a3 …. an = GCD( gcd_till_aj, aj+1, gcd_from_aj+2)
---
### Solution (AC but messy)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()

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

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

int gcd(vi &t, int i){
    if(i == 0) return t[0];
    else return __gcd(t[i], gcd(t, i-1));
}

void fx() {
    // Functionality for fx
    
    int n;
    cin >> n;
    
    vi tab(n);
    
    for(auto &i: tab) cin >> i;
    
    int ans = gcd(tab, n-1);
    
    int temp = tab[0];
    
    tab[0] = tab[n-1];
    
    ans = max(ans, gcd(tab, n-1));
    
    tab[0] = temp;
    
    temp = tab[n-1];
    
    tab[n-1] = tab[0];
    
    ans = max(ans, gcd(tab, n-1));
    
    tab[n-1] = temp;
    
    vi pre(n);
    
    pre[0] = tab[0];
    
    vi suf(n);
    
    suf[n-1] = tab[n-1];
    
    for(int i = 1; i < n; i++) pre[i] = gcd(pre[i-1], tab[i]);
    
    for(int i = n-2; i >= 0; i--) suf[i] = gcd(suf[i+1], tab[i]);
    
    for(int i = 1; i < n-1; i++){
        temp = tab[i];
        
        tab[i] = tab[i-1];
        
        ans = max(ans, __gcd(suf[i+1], __gcd(pre[i-1], tab[i])));
        
        tab[i] = temp;
        
    }
    
    cout << ans << endl;
    
    
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

### Editorial Solution

```C++
\#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;

int arr[maxN];
int prefGcd[maxN];  // prefGcd[i] = GCD of a1,a2, ..., ai
int suffGcd[maxN];  // suffGcd[i] = GCD of ai, ai+1, ..., an
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> arr[i];

	prefGcd[0] = 0;
	suffGcd[N + 1] = 0;

	for (int i = 1; i <= N; ++i) { prefGcd[i] = gcd(prefGcd[i - 1], arr[i]); }

	for (int i = N; i >= 1; --i) { suffGcd[i] = gcd(suffGcd[i + 1], arr[i]); }

	int res = 0;
	for (int i = 1; i <= N; ++i) {
		res = max(res, gcd(prefGcd[i - 1], suffGcd[i + 1]));
	}
	cout << res << '\n';
}
```