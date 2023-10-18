---
Question Link: https://cses.fi/problemset/task/1682
Problem Set:
  - CSES
Last edited time: 2023-10-18T19:10
Status: Seen Editorial
tags:
  - Connected-Components
  - Graph-Reversing-Technique
What's up: Gave up too easily
Key Takeaway: "Graph reversing is a very powerful technique you’ll encounter all the places (a lot  of the classical algorithms, like: Kosaraju’s, max-flow and other, exploit it), which could be used in path-finding and connectedness check problems. Consider playing around with this if the question has a bi-directional construct which does not seem to have an immediately obvious solution. Also this could be a nice shortcut if you want to quickly check if a connected component is indeed, strongly connected."
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

int n, m;

vvi tab;
vvi tabReversed;
vb visited;

void dfs(int x){
    if(visited[x]) return;
    
    visited[x] = true;
    
    for(auto &neigh: tab[x]) dfs(neigh);
}

void fx() {
    cin >> n >> m;
    tab.assign(n+1, {});
    tabReversed.assign(n+1, {});
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        tab[a].pb(b);
        tabReversed[b].pb(a);
    }
    
    visited.assign(n+1, false);
    
    dfs(1);
    
    for(int i = 2; i < n+1; i++){
        if(!visited[i]){
            no();
            cout << 1 << " " << i << endl;
            return;
        }
    }
    
    tab = tabReversed;
    
    visited.assign(n+1, false);
    dfs(1);
    
    for(int i = 2; i < n+1; i++){
        if(!visited[i]){
            no();
            cout << i << " " << 1 << endl;
            return;
        }
    }
    
    yes();
    
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

### Core Logic of the Solution

The problem is essentially asking whether the graph formed by the cities and their flight connections is **strongly connected**, meaning there is a path from any vertex to any other vertex in the directed graph. The solution provided uses **Depth-First Search (DFS)** to explore the graph and check its connectivity.

### Key Steps and Observations:

1. **Build the Graph:**
    - The graph is built using adjacency lists (`tab` for the original graph and `tabReversed` for the graph with reversed edges).
    - `tab[a].pb(b)` indicates there is a direct flight from city `a` to city `b`.
    - `tabReversed[b].pb(a)` stores the reversed edges of the graph, which will be used later.
2. **DFS Traversal:**
    - A DFS traversal is performed starting from city 1 (`dfs(1)`).
    - The `visited` array keeps track of which cities have been visited during the DFS traversal.
    - If `visited[x]` is `true`, it means city `x` can be reached from city 1.
3. **Check Connectivity:**
    - After the first DFS traversal, if any city is not visited (`!visited[i]`), it means that city `i` cannot be reached from city 1. In this case, the answer is "NO" and the unreachable city is printed along with city 1.
    - If all cities are visited, it means all cities can be reached from city 1.
4. **Check Reverse Connectivity:**
    - The graph's edges are reversed (`tab = tabReversed`) to check whether city 1 can be reached from all other cities.
    - Another DFS traversal is performed starting from city 1 on the reversed graph.
    - If any city is not visited in this second DFS traversal, it means city 1 cannot be reached from that city. Again, the answer is "NO" and the cities are printed.
    - If all cities are visited, it means city 1 can be reached from all other cities.
5. **Final Answer:**
    - If both DFS traversals visit all cities, the graph is strongly connected and the answer is "YES".
    - Otherwise, the answer is "NO" along with the pair of cities that violate the condition.

### Key Takeaways and Insights:

- **Graph Connectivity:**
    - The problem is fundamentally about checking the strong connectivity of a directed graph.
    - Understanding the concept of strong connectivity is crucial: a graph is strongly connected if there is a directed path from any vertex to any other vertex.
- **DFS Traversal:**
    - DFS is a powerful tool to explore graphs and check connectivity.
    - It's important to understand how DFS traverses through the graph and how the `visited` array is utilized to keep track of explored nodes.
- **Reversed Graph:**
    - Reversing the graph and performing DFS on it is a classic technique to check whether you can reach back to the starting node from all other nodes.
    - This technique is often used in algorithms like Kosaraju's algorithm for finding strongly connected components in a directed graph.
- **Efficiency:**
    - The solution is efficient with a time complexity of \(O(n + m)\), where \(n\) is the number of cities and \(m\) is the number of flights, since each node and each edge is visited once during the DFS traversals.
    - It's crucial to ensure that algorithms are efficient, especially in graph problems where the number of nodes and edges can be large.

### Conclusion:

Understanding the underlying graph theory concepts and mastering graph traversal algorithms like DFS are key to solving this problem. The solution elegantly demonstrates how to check for strong connectivity in a directed graph by utilizing DFS and the concept of reversed graph traversal. This problem and its solution provide valuable insights into handling graph connectivity problems and utilizing graph traversal algorithms effectively.

  

### Solution Inspiration

### Observational Insights for Inspiring the Solution

1. **Bidirectional Travel Requirement:**
    - The problem statement emphasizes the ability to travel between **any two cities**. This naturally hints towards checking the connectivity of the graph.
    - Observing that you need to check if you can travel **from** any city **to** any other city (and vice versa) should hint towards the concept of **strong connectivity** in directed graphs.
2. **One-Way Flights:**
    - The flights are one-way, which indicates a **directed graph**. This is crucial because the solution approach for directed graphs can be different from undirected graphs, especially when considering connectivity.
    - This should inspire thoughts about how to navigate back in a directed graph, leading to the concept of reversing edges.
3. **Existence of a Path, Not Shortest Path:**
    - The problem doesn’t ask for the shortest path or any path optimization. It simply asks whether a path exists or not.
    - This should guide you towards basic graph traversal algorithms like DFS or BFS, which are adept at exploring connectivity without concerning path optimization.
4. **Output Requirements:**
    - The need to output two cities that cannot be traveled between implies that the solution should be able to identify breaks in connectivity.
    - This might inspire the thought of tracking visited nodes during traversal and identifying nodes that couldn’t be reached.

### Guiding Observations for Future Problems:

1. **Identifying Graph Problems:**
    - Whenever a problem talks about connections, routes, or networks, consider graph theory as a potential approach.
    - Look for keywords or requirements like “path”, “route”, “connected”, “cycle”, etc., which are common in graph problems.
2. **Type of Graph:**
    - Always identify whether the graph is directed or undirected as it influences the approach.
    - Look at whether the connections or routes are bidirectional (undirected graph) or one-way (directed graph).
3. **Connectivity Questions:**
    - If the problem is asking about the possibility of reaching from one point to another (or every other), think about connectivity.
    - For directed graphs, remember to consider the possibility of checking connectivity in both directions, inspiring the use of the reversed graph.
4. **Traversal Algorithm Choice:**
    - If the problem is about finding a path or checking connectivity without optimizing the path, DFS and BFS are good starting points.
    - If there’s a need to find the shortest path or optimize the route, consider algorithms like Dijkstra’s or A*.
5. **Graph Representation:**
    - Consider how to represent the graph in code. Adjacency lists (like in the provided solution) are often a good choice due to their efficiency in representing sparse graphs and facilitating traversal.
6. **Algorithm Patterns:**
    - Familiarize yourself with common algorithm patterns like reversing a graph, finding strongly connected components, etc., as they often reappear in various problems.
    - Practice implementing basic algorithms like DFS and BFS in different contexts to build intuition about when and how to use them.

### Conclusion:

Observing the nature of connections, identifying the type of graph, and recognizing the core question (e.g., about connectivity, shortest path, etc.) are key to inspiring a suitable solution. Always relate the problem requirements to known algorithms or patterns in graph theory, and consider how basic algorithms like DFS might be adapted or extended to meet the specific needs of the problem. This observational and associative approach will guide you towards implementing effective solutions in future graph-related problems.

### Editorial

> [!info] Solution - Flight Routes Check (CSES)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cses-1682-flight-routes-check/solution](https://usaco.guide/problems/cses-1682-flight-routes-check/solution)