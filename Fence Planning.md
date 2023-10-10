---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=944
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Connected-Components
  - DFS
---
### Solution (AC)

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
\#define ll long long

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

vii locs;
vvi tab;

int lx = INT_MAX, ly = INT_MAX, hx = INT_MIN, hy = INT_MAX;

vb visited;

void dfs(int x){
    if(visited[x]) return;
    
    visited[x] = true;
    lx = min(lx, locs[x].f);
    hx = max(hx, locs[x].f);
    ly = min(ly, locs[x].s);
    hy = max(hy, locs[x].s);
    
    for(auto &i: tab[x]) dfs(i);
    
}

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;
    
    locs.assign(n+1, {0, 0});
    for(int i = 1; i < n+1; i++){
        int x, y;
        cin >> x >> y;
        
        locs[i] = {x, y};
    }
    
    tab.assign(n+1, {});
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        tab[a].pb(b);
        tab[b].pb(a);
    }
    
    visited.assign(n+1, false);
    
    int ans = INT_MAX;
    
    for(int i = 1; i < n+1; i++){
        if(visited[i]) continue;
        
        lx = INT_MAX, ly = INT_MAX, hx = INT_MIN, hy = INT_MIN;
        dfs(i);
        
        ans = min(ans, (2*(hx-lx+hy-ly)));
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("fenceplan"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

The provided solution utilizes Depth-First Search (DFS) and some geometric observations to solve the "Fence Planning" problem. Let's delve into the core logic and key takeaways:

### Core Logic:

1. **Moo Network Identification:**
    - The solution uses DFS to traverse through the moo networks. When a cow is visited, DFS is used to visit all cows in its moo network, marking them as visited and updating the bounding box for the network.
    - The `tab` 2D vector stores the moo connections between cows, facilitating the DFS traversal.
2. **Bounding Box Calculation:**
    - For each moo network identified, the algorithm calculates a bounding box that encloses all the cows in the network. This is done by keeping track of the minimum and maximum x and y coordinates (`lx`, `ly`, `hx`, `hy`) encountered during the DFS traversal.
    - The perimeter of this bounding box is calculated using the formula: \(2 \times (hx - lx + hy - ly)\).
3. **Minimum Perimeter:**
    - The algorithm keeps track of the smallest perimeter encountered across all moo networks, ensuring that the final answer is the minimum possible perimeter of a fence that encloses at least one moo network.

### Observations and Insights:

- **Disjoint Moo Networks:**
    - Moo networks are disjoint, meaning cows in one network do not moo at cows in another network. Thus, each network can be processed independently.
- **Bounding Box Insight:**
    - The smallest rectangle enclosing a moo network is its bounding box, which is determined by the cows with the minimum and maximum x and y coordinates in the network.
- **DFS Efficiency:**
    - DFS efficiently identifies all cows in a moo network in \(O(N + M)\) time, where N is the number of cows and M is the number of connections. This ensures that each cow and connection is processed exactly once.

### Key Takeaways:

1. **Graph Traversal:**
    - Understanding how to traverse graphs (using DFS or BFS) to explore connected components (moo networks, in this case) is crucial in solving such problems.
2. **Geometric Insight:**
    - Leveraging geometric properties (like calculating the bounding box) can simplify problems involving spatial relationships between entities.
3. **Optimization:**
    - Keeping track of the minimum perimeter while traversing through the networks avoids the need to store all perimeters and then find the minimum, thereby optimizing space usage.

### Explanation of Key Code Snippets:

- **DFS Function (**`**dfs**`**):**
    - The `dfs` function traverses the moo network, updating the bounding box coordinates (`lx`, `ly`, `hx`, `hy`) and marking cows as visited.
    - It recursively visits all connected cows, ensuring the entire network is explored and the bounding box is accurate.
- **Main Logic (**`**fx**` **function):**
    - The `locs` vector stores the (x, y) coordinates of each cow, and `tab` stores the moo connections.
    - The `visited` vector keeps track of whether a cow has been processed, ensuring each moo network is only processed once.
    - The loop `for(int i = 1; i < n+1; i++)` iterates through all cows, invoking DFS for each unvisited cow, and updating the minimum perimeter found so far.
    - Finally, the minimum perimeter found is output as the solution.

### Conclusion:

This problem beautifully blends graph theory and geometry, teaching valuable lessons about combining different domains of computer science to devise efficient solutions. Understanding the underlying logic of graph traversal and geometric properties is key to solving such problems effectively and efficiently.

### Solution Editorial

> [!info] Solution - Fence Planning (USACO Silver 2019 US Open)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-944-fence-planning/solution](https://usaco.guide/problems/usaco-944-fence-planning/solution)