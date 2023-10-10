---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=669
Problem Set:
  - Gold
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Binary-Search
  - Connected-Components
  - MST
What's up: Solved using MST. But the implementation was a bit convoluted.
Key Takeaway: Take a minute to plan out the implementation.
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
\#define ll long long
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> pii;
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

void fx() {
    // Functionality for fx
    int n;
    cin >> n;
    
    vii tab(n, {0, 0});
    priority_queue<pii, vii, greater<pii>>q;
    
    cin >> tab[0].f >> tab[0].s;
    
    set<int>notTaken;
    
    for(int i = 1; i < n; i++){
        cin >> tab[i].f >> tab[i].s;
        notTaken.insert(i);
        
        q.push({(pow(tab[0].s - tab[i].s, 2) + pow(tab[0].f - tab[i].f, 2)), i});
    }
    
    
    ll ans = INT_MIN;
    while(notTaken.size()){
        ans = max(ans, q.top().f);
        
        int curr = q.top().s;
        
        notTaken.erase(curr);
        
        q.pop();
        
        for(int i = 1;  i < n; i++){
            if(notTaken.count(i)){
                q.push({(pow(tab[curr].s - tab[i].s, 2) + pow(tab[curr].f - tab[i].f, 2)), i});
            }
        }
        
    }
    
    
    cout << ans << endl;
    
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("moocast"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial Solution (Much smaller)

```C++
\#include <bits/stdc++.h>
using namespace std;

int dist_sq(pair<int, int> &a, pair<int, int> &b) {
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return dx * dx + dy * dy;
}

int main() {
	freopen("moocast.in", "r", stdin);

	int N;
	cin >> N;
	vector<pair<int, int>> cows(N);
	for (auto &[x, y] : cows) { cin >> x >> y; }

	/*
	 * shortest distance to a cow in the spanning tree
	 * or INT_MAX - 1 if there are no cows in the spanning tree
	 * or INT_MAX if the cow is in the spanning tree
	 */
	vector<int> dist(N, INT_MAX - 1);
	dist[0] = 0;
	int m = 0;
	for (int t = 0; t < N; t++) {
		int i = min_element(dist.begin(), dist.end()) - dist.begin();
		m = max(m, dist[i]);
		dist[i] = INT_MAX;
		for (int j = 0; j < N; j++) {
			if (dist[j] != INT_MAX) {
				dist[j] = min(dist[j], dist_sq(cows[i], cows[j]));
			}
		}
	}

	freopen("moocast.out", "w", stdout);
	cout << m << endl;
}
```

### Editorial

> [!info] Solution - Moocast (USACO Gold 2016 December)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-669-moocast/solution](https://usaco.guide/problems/usaco-669-moocast/solution)