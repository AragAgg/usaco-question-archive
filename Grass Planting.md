---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=894
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Graph-Partition
Key Takeaway: A undirected graph can be colored with n(max_edges_among_all_vertex) + 1 colors, such that there is no two adjacent vertices with two same color and there is no two vertices with same color with a common neighbour vertex.
---
### Solution (AC)

```Plain
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

void fx() {
    // Functionality for fx
    
    int n;
    cin >> n;
    
    unordered_map<int, int>tab;
    
    int ans = 0;
    
    for(int i = 0; i < n-1; i++){
        int s, d;
        cin >> s >> d;
        
        tab[s]++;
        tab[d]++;
        
        ans = max(ans, max(tab[s], tab[d]));
    }
    
    cout << ans +1 << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("planting"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

[http://www.usaco.org/current/data/sol_planting_silver_jan19.html](http://www.usaco.org/current/data/sol_planting_silver_jan19.html)

USACO Official Editorial

  

  

### Another Solution with Actual Color Build

```Markup
\#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;

// FastIO: see General -> Fast Input and Output
void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<int> grass_type;
vector<vector<int>> neighbors;

void process_fields(int at, int prev) {
	// Start with grass type 1.
	int type_num = 1;
	for (int n : neighbors[at]) {
		if (n == prev) { continue; }
		// While the current grass type is being used, increment it.
		while (type_num == grass_type[at] || type_num == grass_type[prev]) {
			type_num++;
		}

		// Set the grass type for the neighboring field.
		grass_type[n] = type_num;

		// Recursively color the other fields.
		process_fields(n, at);

		// We can't use this grass type again.
		type_num++;
	}
}

int main() {
	setIO("planting");

	int field_num;
	cin >> field_num;

	grass_type = vector<int>(field_num);
	neighbors = vector<vector<int>>(field_num);
	for (int f = 0; f < field_num - 1; f++) {
		int field1, field2;
		cin >> field1 >> field2;
		neighbors[--field1].push_back(--field2);
		neighbors[field2].push_back(field1);
	}

	// Set our starting field to be type 1.
	grass_type[0] = 1;
	process_fields(0, 0);

	int min_type = 0;
	for (int t : grass_type) { min_type = max(min_type, t); }

	cout << min_type << endl;
}
```