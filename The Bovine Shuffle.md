---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=764
Problem Set:
  - Silver
Last edited time: 2023-10-23T13:32
Status: Solved
tags:
  - Functional-Graph
---
### Solved (AC)

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

vi tab, visited;
vi s;
int ans = 0;

void dfs(int v){
    if(visited[v]) return;
    
    visited[v] = -1;
    s.pb(v);
    bool flag = true;
    
    if(visited[tab[v]] == -1){
        while(flag){
            
            if(s.back() == tab[v]) flag = false;
            visited[s.back()] = 2, ans++;
            s.ppb();
        }
    }else dfs(tab[v]);
    
    if(s.size() and s.back() == v) visited[v] = 1, s.ppb();
}

void fx() {
    int n; cin >> n;
    tab.assign(n, 0), visited.assign(n, 0);
    
    for(auto &i: tab) cin >> i, i--;
    
    for(int i = 0; i < n; i++) if(!visited[i]) dfs(i);
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("shuffle"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial Code

```C++
\#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> cows_after_shuffle(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		cows_after_shuffle[a[i]]++;
	}

	ll ans = n;
	queue<ll> no_cows;

	// Calculate positions that are empty after one shuffle.
	for (int i = 0; i < n; i++) {
		if (cows_after_shuffle[i] == 0) {
			no_cows.push(i);
			ans--;
		}
	}

	while (!no_cows.empty()) {
		ll curr = no_cows.front();
		no_cows.pop();

		// Position `curr` cannot contribute any cows.
		if (--cows_after_shuffle[a[curr]] == 0) {
			// If `a[curr]` has no cows, insert it into the queue.
			no_cows.push(a[curr]);
			ans--;
		}
	}
	cout << ans << endl;
}
```

### Editorial

> [!info] Solution - The Bovine Shuffle (USACO Silver 2017 December)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-764-the-bovine-shuffle/solution](https://usaco.guide/problems/usaco-764-the-bovine-shuffle/solution)