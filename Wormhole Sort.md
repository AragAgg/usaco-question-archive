---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=992
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Binary-Search
  - DFS
  - DSU
  - Implementation
What's up: To try implementation.
Key Takeaway: Binary search pops up at random places (so much so that it is a good idea to check if it works for any question that doesn’t immediately clarify the intended approach.)
---
### What i’ve thought of till now

1. **Sorting Edges:** Begin by sorting every edge based on its weight (represented as `(u, v, weight[width])`).
2. **Binary Search:** Apply binary search on the sorted set of edges.
3. **Determining the Answer:** The desired answer is the first index 'i' where:
    - Using the smallest 'i' edges, a sequence of steps can be formulated.
    - This sequence ensures every cow reaches its designated place.
4. **Connected Components:**
    
    - **Purpose:** Use connected components to verify if a component can be arranged using only the wormholes with a weight less than or equal to the weight of the ith edge.
    - **Condition:** If a connected component contains a list of cows `{c1, c2, c3, c4 ... ck}`, it should also have them in the corresponding positions `{c1, c2, c3, c4 ... ck}`.
    - Note: The order within the list can vary.
    
      
    

### Solution (TLE on final case, AC on others)

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

vector<pair<int, pair<int, int>>>wormholes;
vi cows;

inline void dfs(unordered_map<int, vi>&edges, usi &visited, usi &tcows, usi &tpos, int node){
    
    if(visited.count(node)) return;
    
    // cout << "inserting cow: " << cows[node] << " to set with node : " << node << endl;
    
    visited.insert(node);
    tcows.insert(cows[node]);
    tpos.insert(node);
    
    for(auto &i: edges[node]){ 
        if(visited.count(i)) continue;
        dfs(edges, visited, tcows, tpos, i);
    }
    
    // tpow.erase()
}

inline bool works(int till){
    unordered_map<int, vector<int>>edges;
    
    for(int i = 0; i <= till; i++){
        edges[wormholes[i].s.f].pb(wormholes[i].s.s);
        edges[wormholes[i].s.s].pb(wormholes[i].s.f);
    }
    
    usi visited;
    
    for(auto &i: edges){
        if(visited.count(i.f)) continue;
        
        usi tcows;
        usi tpos;
        
        dfs(edges, visited, tcows, tpos, i.f);
        
        for(auto &i: tcows) if(!tpos.count(i)) return false;
    }
    
    return true;
}

void fx() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cows.pb(0);
        cin >> cows[i];
        cows[i]--;
    }
    
    for(int i = 0; i < m; i++){
        wormholes.pb({0, {0, 0}});
        cin >> wormholes[i].s.f >> wormholes[i].s.s >> wormholes[i].f;
        wormholes[i].s.f--;
        wormholes[i].s.s--;
        
        wormholes[i].f *= -1;
    }
    
    sort(all(wormholes));
    
    bool already = true;
    for(int i = 0; i < n; i++) if(cows[i] != i){ already = false; break;}
    
    if(already){
        cout << -1 << endl;
        return;
    }
    
    int low = 0, high = m-1;
    
    while(low <= high){
        
        if(low == high){
            cout << -wormholes[low].f << endl;
            return;
        }
        
        int mid = low + (high - low)/2;
        
        if(works(mid)){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    
    // cout << -1 << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("wormsort"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Possible speed ups

1. Moving away from time-heavy data structures (USI or UMII) `**[most promising]**`
2. Using DSU
3. Using ternary search instead of binary search `**[least promising]**`
4. Some other way of minimising the search space

### AC - Optimisation One (partially using a better data structure)

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

vector<pair<int, pair<int, int>>>wormholes;
vi cows;
vector<bool>visited;

inline void dfs(unordered_map<int, vi>&edges, usi &tcows, usi &tpos, int node){
    
    // cout << "dfs(" << node << ")\n";
    // if(visited[node]) return;
    
    // cout << "inserting cow: " << cows[node] << " to set with node : " << node << endl;
    
    visited[node] = true;
    tcows.insert(cows[node]);
    tpos.insert(node);
    
    for(auto &i: edges[node]){ 
        if(visited[i]) continue;
        dfs(edges, tcows, tpos, i);
    }
    
    // tpow.erase()
}

bool works(int till){
    unordered_map<int, vector<int>>edges;
    
    for(int i = 0; i <= till; i++){
        edges[wormholes[i].s.f].pb(wormholes[i].s.s);
        edges[wormholes[i].s.s].pb(wormholes[i].s.f);
    }
    
    // usi visited;
    
    for(auto &i: edges){
        if(visited[i.f]) continue;
        
        usi tcows;
        usi tpos;
        
        // cout << "calling dfsRun(" << i.f << ")\n";
        dfs(edges, tcows, tpos, i.f);
        
        for(auto &i: tcows) if(!tpos.count(i)) return false;
    }
    
    return true;
}

void fx() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cows.pb(0);
        cin >> cows[i];
        cows[i]--;
    }
    
    for(int i = 0; i < m; i++){
        wormholes.pb({0, {0, 0}});
        cin >> wormholes[i].s.f >> wormholes[i].s.s >> wormholes[i].f;
        wormholes[i].s.f--;
        wormholes[i].s.s--;
        
        wormholes[i].f *= -1;
    }
    
    sort(all(wormholes));
    
    
    
    bool already = true;
    for(int i = 0; i < n; i++) if(cows[i] != i){ already = false; break;}
    if(already){
        cout << -1 << endl;
        return;
    }
    
    int low = 0, high = m-1;
    
    while(low <= high){
        // cout << low << " / " << high << endl;
        visited.assign(n, false);
        if(low == high){
            cout << -wormholes[low].f << endl;
            return;
        }
        
        int mid = low + (high - low)/2;
        
        if(works(mid)){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    
    // cout << -1 << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("wormsort"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

### Problem Statement:

The problem is about a set of cows, each with a unique ID, that are initially in a certain order. The cows want to rearrange themselves into the order of their IDs. There are wormholes that can be used to swap the positions of two cows. The goal is to find the minimum width of the wormholes required to sort the cows in the desired order. If it's impossible to sort the cows using the wormholes, the answer should be -1.

### Solution Analysis:

1. **Type Definitions and Macros**:
    
    The solution starts with several type definitions and macros for convenience. These are just to make the code more readable and concise.
    
2. **Global Variables**:
    - `wormholes`: A vector that stores the wormholes. Each wormhole is represented as a pair where the first element is the width of the wormhole and the second element is another pair representing the two positions that the wormhole connects.
    - `cows`: A vector that stores the initial positions of the cows.
    - `visited`: A vector that keeps track of which positions have been visited during the DFS traversal.
3. **DFS Function**:  
    The `dfs` function is a standard Depth First Search function. It's used to traverse the graph of wormholes and determine which cows can be swapped using the wormholes. The function also keeps track of which cows and positions are visited during the traversal.
4. **Works Function**:  
    The `works` function checks if it's possible to sort the cows using wormholes of width up to a given value. It does this by building a graph of the wormholes and then using the `dfs` function to traverse the graph. If all cows can be swapped to their desired positions using the wormholes, the function returns `true`. Otherwise, it returns `false`.
5. **Main Logic (fx Function)**:
    - The function starts by reading the initial positions of the cows and the wormholes.
    - If the cows are already in the desired order, the function prints -1 and returns.
    - The function then uses a binary search approach to find the minimum width of the wormholes required to sort the cows. The `works` function is used to check if the cows can be sorted using wormholes of a certain width.
    - The binary search continues until the minimum width is found, and then the function prints the result.
6. **Main Function**:
    - The main function sets up file I/O for reading and writing to files (as required by the USACO format).
    - It then calls the `fx` function to solve the problem.

### Another approach (using binary-search + DSU)

- code
    
    ```C++
    \#include <fstream>
    \#include <iostream>
    \#include <vector>
    
    using std::cout;
    using std::endl;
    using std::vector;
    
    // BeginCodeSnip{DSU}
    class DSU {
      private:
    	vector<int> parent;
    	vector<int> size;
    
      public:
    	DSU(int size) : parent(size), size(size, 1) {
    		for (int i = 0; i < size; i++) { parent[i] = i; }
    	}
    
    	int get_top(int n) {
    		return parent[n] == n ? n : (parent[n] = get_top(parent[n]));
    	}
    
    	bool link(int n1, int n2) {
    		n1 = get_top(n1);
    		n2 = get_top(n2);
    		if (n1 == n2) { return false; }
    		if (size[n2] > size[n1]) { return link(n2, n1); }
    		parent[n2] = n1;
    		size[n1] += size[n2];
    		return true;
    	}
    };
    // EndCodeSnip
    
    struct Wormhole {
    	int c1, c2;
    	int width;
    };
    
    int main() {
    	std::ifstream read("wormsort.in");
    	int cow_num;
    	int wormhole_num;
    	read >> cow_num >> wormhole_num;
    
    	vector<int> cows(cow_num);
    	for (int &c : cows) {
    		read >> c;
    		c--;  // make the cows 0-indexed
    	}
    
    	int max_width = 0;
    	vector<Wormhole> wormholes(wormhole_num);
    	for (Wormhole &w : wormholes) {
    		read >> w.c1 >> w.c2 >> w.width;
    		w.c1--;
    		w.c2--;
    		max_width = std::max(max_width, w.width);
    	}
    
    	int lo = 0;
    	int hi = max_width + 1;
    	int valid = -1;
    	while (lo <= hi) {
    		int mid = (lo + hi) / 2;
    
    		DSU dsu(cow_num);
    		for (const Wormhole &w : wormholes) {
    			if (w.width >= mid) { dsu.link(w.c1, w.c2); }
    		}
    
    		bool sortable = true;
    		for (int c = 0; c < cow_num; c++) {
    			if (dsu.get_top(c) != dsu.get_top(cows[c])) {
    				sortable = false;
    				break;
    			}
    		}
    
    		if (sortable) {
    			valid = mid;
    			lo = mid + 1;
    		} else {
    			hi = mid - 1;
    		}
    	}
    
    	std::ofstream("wormsort.out")
    	    << (valid == max_width + 1 ? -1 : valid) << endl;
    }
    ```
    

  

The basic idea here is to use binary search and then instead of using `DFS` or `BFS` for checking for `sortability`, we use `DSU`.

  

### Editorial

[https://usaco.guide/problems/usaco-992-wormhole-sort/solution#solution-1---binary-search-and-floodfill](https://usaco.guide/problems/usaco-992-wormhole-sort/solution#solution-1---binary-search-and-floodfill)