---
Question Link: https://www.codechef.com/INOIPRAC/problems/AMONGUS2#
Problem Set:
  - Code Chef
  - INOI
Last edited time: 2023-10-11T15:04
Status: Nice Question
tags:
  - Bipartite
  - Connected-Components
  - DFS
  - Implementation
What's up: One of the key observations involved in solving the question (simply) is to notice that fact that if we could divide the nodes into two dis-joint sets (humans and parasites), we could always just swap all the elements between the two sets, without invalidating any of the statement constraints.
Key Takeaway: If a question has a lot of circular and logical conditions, try modelling it as a graph problem. (Try bipartite if you could divide node states into a binary notion)When working with a question with a ton of logic (maybe your need to perform a very similar traversal two times), try to write a generic code and then offset the data to be able to use the same function twice.
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

struct edge{ int to, isSameAsMe; };

vector<vector<edge>>edges;
vi colors;
int currHuman, currParasite;

bool dfs(int x, bool isHuman){
    if(colors[x] != -1) return (colors[x] == isHuman);
    
    colors[x] = isHuman;
    
    if(isHuman) currHuman++;
    else currParasite++;
    
    for(auto &neigh: edges[x]) if(!dfs(neigh.to, (neigh.isSameAsMe?isHuman:!isHuman))) return false;
    return true;
}

void fx() {
    int n, q;
    cin >> n >> q;
    
    edges.assign(n, {});
    colors.assign(n, -1);
    
    for(int i = 0; i < q; i++){
        int from;
        edge e;
        
        cin >> e.isSameAsMe >> from >> e.to;
        from--; e.to--; e.isSameAsMe--;
        
        edges[from].pb(e);
        swap(e.to, from);
        edges[from].pb(e);
    }
    
    int bestAns = 0;
    
    for(int i = 0; i < n; i++){
        if(colors[i] != -1) continue;
        
        currParasite = 0;
        currHuman = 0;
        
        if(!dfs(i, true)){
            cout << -1 << endl;
            return;
        }
        
        bestAns += max(currHuman, currParasite);
    }
    
    cout << bestAns << endl;

}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

### Solution Explanation

### Core Logic:

1. **Graph Representation:**
    - Astronauts and their statements are represented as a graph where each node represents an astronaut and edges represent the statements between them.
    - An `edge` structure is used to store the destination astronaut (`to`) and whether the astronaut is the same type as the source astronaut (`isSameAsMe`).
2. **DFS Traversal:**
    - The DFS function (`dfs`) traverses through the graph, marking astronauts as human or parasite and counting them.
    - The `colors` vector keeps track of whether an astronaut is human or parasite (-1 for unvisited, 0 for parasite, and 1 for human).
    - `currHuman` and `currParasite` keep track of the count of humans and parasites in the current connected component of the graph.
3. **Consistency Check:**
    - During the DFS traversal, if it encounters a node that has been visited and the current assignment contradicts the previous assignment, it returns false, indicating inconsistent statements.
    - If the DFS function returns false at any point, the function `fx` outputs -1, as the statements are inconsistent.
4. **Maximizing Parasites:**
    - After a successful DFS traversal, it chooses the maximum count between `currHuman` and `currParasite` to maximize the possible number of parasites.
    - `bestAns` accumulates the maximum possible number of parasites.

### Observations and Insights:

- **Bipartite Graph:**
    - The problem essentially checks whether the graph is bipartite, where humans and parasites are two disjoint sets, and all edges go between the sets.
    - If the graph is not bipartite, the statements are inconsistent.
- **Maximization Insight:**
    - To maximize the number of parasites, after traversing each connected component, the algorithm chooses the larger number between humans and parasites.
    - This is because if the larger number is chosen as humans, then the smaller number (which would be parasites) would contradict the fact that parasites always lie.

### Key Takeaways:

1. **Graph Theory Application:**
    - Understanding how to model problems as a graph and apply graph traversal algorithms (like DFS) is crucial in solving such problems.
2. **Consistency in Statements:**
    - The problem demonstrates how to check for consistency in statements using graph theory, which is a common pattern in competitive programming.
3. **Maximization Strategy:**
    - The solution shows a strategy to maximize a certain parameter (number of parasites) while ensuring consistency in the system.
4. **Efficiency:**
    - Efficiently traversing the graph and keeping track of necessary parameters (like count of humans and parasites) without redundant computations is key to solving problems within time limits.

### Conclusion:

This problem elegantly blends graph theory, consistency checking, and maximization strategy, providing a rich learning experience in handling graph-related problems in competitive programming. It emphasizes the importance of accurately modeling problems to apply appropriate algorithms and derive insights for optimization.

### Solution Inspiration

### Observational Insights:

1. **Binary Classification:**
    - The problem involves classifying astronauts into two categories: humans and parasites, which might hint towards a bipartite graph since bipartite graphs involve two sets of vertices with no edges within the same set.
2. **Contradictory Statements:**
    - The fact that humans always tell the truth and parasites always lie, creating a scenario where statements can contradict each other, suggests a logical problem that can be modeled as a graph where consistency in statements can be checked through traversal.
3. **Statement Relationships:**
    - The astronauts make statements about each other, establishing relationships (edges) between them, which naturally suggests a graph representation.
4. **Consistency Check:**
    - The need to check whether the statements are consistent or not implies a need to traverse through the relationships and validate them, which is a common use-case for graph traversal algorithms like DFS or BFS.

### Guiding Observations for Similar Solutions:

1. **Identifying Graph Structures:**
    - Whenever you notice entities and relationships (especially if they involve some form of classification or grouping), consider modeling the problem as a graph.
2. **Logical Consistency:**
    - If the problem involves checking the consistency or validity of statements/relationships, think about graph traversal algorithms that can validate these relationships by traversing through nodes and edges.
3. **Bipartite Nature:**
    - If entities are being classified into two distinct groups and relationships are established between entities of different groups (or the same group), consider whether the problem can be modeled as a bipartite graph.
4. **Maximization/Minimization Aspect:**
    - If there's a need to maximize or minimize a certain parameter (like the number of parasites), consider how you might accumulate and optimize this parameter during your graph traversal.

### Strategy for Future Problems:

1. **Modeling as Graph:**
    - Always be on the lookout for entities and relationships that can be modeled as graphs, especially when there’s a binary classification involved.
2. **Traversal and Validation:**
    - If there’s a need to validate relationships or statements, consider implementing a DFS or BFS traversal and check for consistency during the traversal.
3. **Optimization:**
    - Identify if there’s an optimization aspect (like maximizing or minimizing a parameter) and consider how this can be integrated into your traversal logic to accumulate the desired parameter.
4. **Edge Cases:**
    - Always consider edge cases and how they might be handled within your logic (e.g., what if all statements are lies, or what if there are contradictory statements).
5. **Efficiency:**
    - Ensure that your solution is efficient and avoids redundant computations, especially in problems with higher constraints.

By keeping these observations and strategies in mind, you’ll be well-equipped to tackle similar problems in the future, identifying when and how to implement graph-based solutions to solve logical and optimization problems.

### Editorial [more advanced code \ possibly shitty]

> [!info] Solution - Among Us (CC)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cc-among-us/solution](https://usaco.guide/problems/cc-among-us/solution)