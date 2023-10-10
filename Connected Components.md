---
Question Link: https://codeforces.com/contest/920/problem/E
Problem Set:
  - "*2100"
  - Code Forces
  - DIV2E
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Binary-Search
  - Connected-Components
  - DFS
What's up: Solved, encountered a bit of issue in implementation, had too take some help.
Key Takeaway: When you want to modify a set/map inside of a function or loop, and then modify the iterator again in the same construct, make sure it doesn’t get invalidated first. Try using it = container.erase(smt...)´,  or erase first and then update iterator using container.upper_bound() or container.begin()A better method to do DFS (especially for identifying connected components) when the number of edges is too high (1e9+) is to use the unvisited_vertices.upper_bound(curr) method, described below.
---
### Solution History (MLE on TC9)

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

int n, m;
vector<set<int>>excluded;
set<int>notYetIncluded;
vb visited;

int curr;

void dfs(int i){
    if(visited[i]) return;
    
    notYetIncluded.erase(i);
    visited[i] = true;
    
    curr++;
    
    vi temp;
    for(auto x: notYetIncluded) temp.pb(x);
    
    for(auto x: temp){
        if(excluded[i].count(x)) continue;
        
        dfs(x);
    }
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    
    excluded.assign(n, {}); // <- does that work???
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        excluded[a].insert(b);
        excluded[b].insert(a);
    }
    
    visited.assign(n, false);
    for(int i = 0; i < n; i++) notYetIncluded.insert(i);
    
    vi ans;
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        
        curr = 0;
        dfs(i);
        ans.pb(curr);
        
    }
    
    sort(all(ans));
    cout << ans.size() << endl;
    for(auto &i: ans) cout << i << " ";
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

### Solution (AC) [Pretty much the same as the editorial solution]

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

int n, m;
set<int>excluded[200000];
set<int>notYetIncluded;
vb visited;

int curr;

void dfs(int i){
    if(visited[i]) return;
    
    notYetIncluded.erase(i);
    visited[i] = true;
    
    curr++;
    
    // vi temp;
    // for(auto x: notYetIncluded) temp.pb(x);
    
    // for(auto x: temp){
    //     if(excluded[i].count(x)) continue;
        
    //     dfs(x);
    // }
    
    auto iter = notYetIncluded.begin();
    
    while(iter != notYetIncluded.end()){
        if(excluded[i].count(*iter)) iter++;
        else{
            int thisNode = *iter;
            
            notYetIncluded.erase(iter);
            
            dfs(thisNode);
            
            iter = notYetIncluded.upper_bound(thisNode);
        }
    }
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    
    // excluded.assign(n, {}); // <- does that work???
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        excluded[a].insert(b);
        excluded[b].insert(a);
    }
    
    visited.assign(n, false);
    for(int i = 0; i < n; i++) notYetIncluded.insert(i);
    
    vi ans;
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        
        curr = 0;
        dfs(i);
        ans.pb(curr);
        
    }
    
    sort(all(ans));
    cout << ans.size() << endl;
    for(auto &i: ans) cout << i << " ";
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

### Solution Explanation

The provided solution employs a **Depth-First Search (DFS)** algorithm to solve the problem. Let's break down the core logic and key insights used in the solution:

### Core Logic:

1. **Graph Representation:**
    - The graph is represented using an adjacency list, but in a slightly different manner. Instead of storing the adjacent vertices, it stores the vertices that are **not** connected to a given vertex, i.e., the non-neighbors.
    - `excluded[i]` stores the vertices that are not connected to vertex `i`.
    - `notYetIncluded` is a set that keeps track of the vertices that have not been visited yet.
2. **DFS Traversal:**
    - The DFS function (`dfs(int i)`) is designed to traverse the graph and find connected components.
    - It iteratively traverses through all vertices, and for each vertex, it performs a DFS to find all vertices in its connected component.
    - `curr` keeps track of the size of the current connected component.
3. **Handling Non-Neighbors:**
    - The DFS function is modified to handle the non-neighbor representation of the graph.
    - It iterates through `notYetIncluded` and checks whether a vertex is a non-neighbor of the current vertex using `excluded[i]`. If it is not a non-neighbor, it means it is connected, and DFS is performed on it.
    - The vertex is removed from `notYetIncluded` once it is visited.
4. **Calculating Components:**
    - For each vertex, if it is not visited, DFS is performed, and the size of the connected component (`curr`) is stored.
    - `ans` vector stores the sizes of all connected components found during the traversal.
5. **Output:**
    - The sizes of connected components are sorted and output in non-descending order.

### Observations and Insights:

- **Inverse Graph Representation:**
    - The problem provides non-edges instead of edges, which is an unusual graph representation. The solution smartly uses this to create an adjacency list of non-neighbors, which is crucial for efficiently finding connected components.
- **Efficient DFS with Non-Neighbors:**
    - The DFS is modified to work with the non-neighbor representation. It ensures that the DFS is only performed on vertices that are connected, which is determined by checking non-neighbors.
    - Using `notYetIncluded` set and erasing visited vertices ensures that the DFS does not revisit vertices, making the traversal efficient.
- **Dynamic Iteration:**
    - The solution uses an iterator to dynamically iterate through `notYetIncluded` while modifying it (erasing elements) during the iteration. This is a valuable technique to avoid issues related to modifying a container while iterating through it.

### Key Takeaways:

- **Graph Representation Flexibility:**
    - Understanding that graphs can be represented in various ways (e.g., edges, non-edges) and adapting algorithms to work with different representations is crucial.
- **Algorithm Modification:**
    - Modifying standard algorithms (like DFS) to work with specific problem constraints or representations is a valuable skill in competitive programming.
- **Efficient Traversal:**
    - Ensuring that graph traversal is done efficiently by avoiding revisiting vertices and minimizing unnecessary computations is key to solving graph problems within time limits.
- **Dynamic Iteration Technique:**
    - Learning to iterate through and modify a container dynamically is a useful technique that can be applied in various problems.

This solution is a great example of adapting standard algorithms to specific problem constraints and representations, which is a common requirement in competitive programming.

### Solution Inspiration

### Observational Insights:

1. **Non-Edge Representation:**
    - **Observation:** The problem provides non-edges instead of edges.
    - **Inspiration:** This unusual representation might hint at using it directly in the solution, i.e., considering non-neighbors during traversal instead of neighbors.
2. **Graph Connectivity:**
    - **Observation:** The problem asks for connected components and their sizes.
    - **Inspiration:** DFS and BFS are classic algorithms for finding connected components in a graph. Thus, thinking about how to adapt DFS/BFS to the given non-edge representation becomes a logical step.
3. **Large Input Size:**
    - **Observation:** The input size is quite large (\(n \leq 200000\)).
    - **Inspiration:** The solution must be efficient. Using data structures that allow fast insertion, deletion, and lookup (like `set` or `unordered_set`) and avoiding nested loops or repeated work during graph traversal becomes crucial.

### Strategy Development:

1. **Efficient Traversal:**
    - **Observation:** Directly using non-edges in a standard DFS might require checking all vertices to find connected ones, which is inefficient.
    - **Inspiration:** Keep track of vertices that are not yet included in any component and dynamically update this as you traverse. This way, you can efficiently find the next vertex to explore without checking all vertices.
2. **Dynamic Iteration:**
    - **Observation:** You need to iterate through vertices while simultaneously updating the set of non-visited vertices.
    - **Inspiration:** Using iterators to navigate through the set while modifying it allows you to efficiently find and traverse connected vertices without invalidating the iterator.
3. **Handling Non-Neighbors:**
    - **Observation:** The non-neighbor representation might complicate finding connected vertices.
    - **Inspiration:** Instead of trying to convert non-edges to edges or vice versa, adapt the DFS to work directly with non-neighbors. If a vertex is not a non-neighbor, it is connected, and you can traverse it.

### Key Takeaways for Future Problems:

- **Use Given Representations:**
    - If a problem provides data in a specific way (like non-edges), consider using it directly instead of converting it to a more standard form.
- **Adapt Standard Algorithms:**
    - Think about how to adapt standard algorithms (like DFS) to the specific constraints or representations in the problem.
- **Efficiency is Crucial:**
    - Always keep the efficiency in mind, especially with large input sizes. Use data structures and algorithms that minimize time complexity.
- **Dynamic Data Handling:**
    - Learn techniques to dynamically handle and update data during algorithm execution, like modifying a set while iterating through it.

By observing the problem's nuances and thinking about how to adapt standard algorithms to them, you can often find a path towards the solution. Always consider the specific details and constraints of the problem and think about how they might be used to your advantage in the solution.

### Editorial

> [!info] Educational Codeforces Round 37 — Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/57516](https://codeforces.com/blog/entry/57516)