---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=940
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Complete-Search
  - DFS
  - Graph
  - Optimisation
What's up: Prove by AC 🙂
Key Takeaway: "Try out storing the adjacency list in this structure: destination → source."
---
### Solution

```Markup
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


vvi tab;

unordered_set<int>curr;

void fx2(int root){
    
    curr.insert(root);
    
    for(auto &i: tab[root]){
        if(curr.count(i)) continue;
        fx2(i);
    }
}


void fx(){
    int n;
    cin >> n;
    
    tab.assign(n, {});
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        
        tab[b-1].pb(a-1);
    }
    
    
    for(int i = 0; i < n; i++){
        curr.clear();
        
        curr.insert(i);
        
        fx2(i);
        
        if(curr.size() == n){
            cout << i+1 << endl;
            return;
        }
    }
    
    cout << -1 << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("factory"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### A Better Solution

```Markup
\#include <fstream>
\#include <iostream>
\#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	std::ifstream read("factory.in");
	int station_num;
	read >> station_num;

	vector<int> outgoing(station_num);
	for (int w = 0; w < station_num - 1; w++) {
		int s1, s2;
		read >> s1 >> s2;
		// We actually don't care about s2 here!
		outgoing[--s1]++;
	}

	vector<int> no_outs;
	// Check all stations and see if they don't have any outgoing walkways
	for (int s = 0; s < station_num; s++) {
		if (outgoing[s] == 0) {
			// Remember, we have to output the 1-indexed stations!
			no_outs.push_back(s + 1);
		}
	}

	// If there's two stations without any outs, then we can't find a station
	int root = no_outs.size() == 1 ? no_outs[0] : -1;
	std::ofstream("factory.out") << root << endl;
}
```

### Idea behind the better solution

The solution is a simple implementation that takes advantage of the fact that the desired station, if it exists, must not have any outgoing edges (i.e., conveyor belts). The reason is that if a station has an outgoing edge, it would be impossible to reach it from the station at the end of this edge.

  

Here's the explanation of the code:

1. The code first reads the number of stations from the input file "[factory.in](http://factory.in/)".
2. It initializes a vector `outgoing` to count the number of outgoing edges for each station.
3. It then reads the edges from the input file. For each edge, it increments the corresponding entry in `outgoing`.
4. The code then iterates over the `outgoing` vector to find stations with no outgoing edges. These stations are the candidates for the desired station.
5. If there is exactly one such station, it is the desired station. If there is more than one, it means that there is no station that can be reached from all other stations. In this case, the code outputs -1.
6. The result is written to the output file "factory.out".

  

This is an efficient and correct solution. The time complexity is linear, \(O(n)\), which is the best possible for this problem given that we have to read all the edges.