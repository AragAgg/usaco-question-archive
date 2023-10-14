---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=620
Problem Set:
  - Silver
Last edited time: 2023-10-15T03:05
Status: Solved
tags:
  - BFS
  - Flood-Fill
  - Implementation
Key Takeaway: READ the fucking prompt. And then read it again. Do not begin to write a solution before you completely understand the problem construct.When going through the search space, if the problem discourages solutions with more hops (or cost increases monotonically with the number of node visits) then you should consider using BFS, as this method sequentially searches the solution space (thereby minimising the number of hops)
---
### Solution (AC)

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

int x, y, k, m;
vvi visited;

bool isValid(int i, int j){
    return (i >= 0 and i <= 100 and j >= 0 and j <= 100);
}

void fx() {
    cin >> x >> y >> k >> m;
    
    visited.assign(101, vi(101, INT_MAX));
    queue<pair<int, pii>>q;
    q.push({0, {0, 0}});
    
    int ans = INT_MAX;
    
    while(!q.empty()){
        int i = q.front().s.f;
        int j = q.front().s.s;
        int currDepth = q.front().f;
        
        q.pop();
        
        if(!isValid(i, j) or (visited[i][j] <= currDepth) or (currDepth > k)) continue;
        
        visited[i][j] = currDepth;
        
        ans = min(ans, abs(i+j - m));
        
        q.push({currDepth+1, {i - min(i, y - j), j + min(i, y - j)}});
        q.push({currDepth+1, {i + min(j, x - i), j - min(j, x - i)}});
        q.push({currDepth+1, {0, j}});
        q.push({currDepth+1, {i, 0}});
        q.push({currDepth+1, {i, y}});
        q.push({currDepth+1, {x, j}});
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("pails"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation (wrong about time_complexity)

---

The provided solution employs a **Breadth-First Search (BFS)** algorithm to explore all possible states of the two milk pails and find the minimum error in achieving the target milk quantity M. Let's delve into the core logic and key insights of the solution:

**Core Logic:**

1. **State Representation:**
    - Each state is represented as a pair (i, j), where i and j are the quantities of milk in the two pails, respectively.
    - The solution space is explored by transitioning from one state to another using the allowed operations (fill, empty, and pour).
2. **BFS Exploration:**
    - BFS is used to explore the solution space level-wise, ensuring that the solution found is optimal (minimum steps or minimum error).
    - The BFS queue stores a triplet (d, (i, j)), where d is the depth (number of operations performed) and (i, j) represents the state.
    - The BFS explores all possible transitions from a state and enqueues them for further exploration, ensuring all states reachable within K steps are considered.
3. **Pruning and Validity:**
    - Pruning is crucial to avoid unnecessary computations. If a state is reached with a depth greater than K or if it has been visited before with a smaller or equal depth, it is not explored further.
    - The `isValid` function ensures that the states being explored are within valid bounds.
4. **Error Calculation:**
    - For each state (i, j) explored, the error |i + j - M| is calculated, and the minimum error encountered so far is updated.
    - The goal is to minimize this error while exploring all possible states within K steps.

**Key Insights and Takeaways:**

1. **State Space Search:**
    - The problem is a classic example of state space search where the solution space is explored systematically to find an optimal solution.
    - Representing and transitioning between states effectively is crucial.
2. **Optimality of BFS:**
    - BFS ensures that the solution found is optimal in terms of the number of steps, as it explores the solution space level-wise.
    - It is guaranteed to find the smallest error possible within K steps.
3. **Pruning Strategies:**
    - Pruning is essential in state space search problems to avoid exploring redundant or unnecessary states.
    - Efficient pruning and validity checks can significantly optimize the solution.
4. **Problem Modeling:**
    - Effectively modeling the problem into a search problem and identifying the appropriate algorithm (BFS in this case) is a key takeaway.
    - Understanding how to represent states and transitions is crucial in solving such problems.
5. **Algorithm Complexity:**
    - Considering the complexity of the algorithm and ensuring it is feasible within the problem's constraints is vital.
    - The solution explores a maximum of O(K * X * Y) states, which is feasible within the given problem constraints.

**Conclusion:**

The solution effectively models the problem as a state space search problem and employs BFS to explore possible states of the milk pails, ensuring an optimal solution in terms of the minimum error in achieving the target quantity M. Pruning strategies and validity checks are employed to optimize the search, and the solution ensures feasibility within the problem's constraints. The key takeaways involve insights into state space search, BFS optimality, and problem modeling.

### Solution Inspiration

Certainly! Observational insights and pattern recognition are crucial in devising solutions for algorithmic problems. Here are some aspects and observations that might inspire a solution like the one provided for the "Milk Pails" problem:

### 1. Discrete States and Transitions:

- **Observation:** The problem involves moving between discrete states (different amounts of milk in the pails) using specific operations.
- **Insight:** This naturally lends itself to a graph-based solution where each state is a node, and transitions (via operations) are edges.

### 2. Shortest Path to Solution:

- **Observation:** The problem asks for a minimum value (error) and allows a sequence of operations up to a limit \(K\).
- **Insight:** This hints towards a shortest-path problem in a graph, where BFS is a natural choice due to its level-wise exploration, ensuring an optimal solution.

### 3. Limited Operations:

- **Observation:** The operations are limited and well-defined (fill, empty, pour).
- **Insight:** This suggests that you can systematically explore all possible states from a given state, making BFS a feasible approach due to the limited branching factor.

### 4. Bounded Solution Space:

- **Observation:** The sizes of the pails \(X\) and \(Y\) and the maximum number of operations \(K\) are bounded and relatively small.
- **Insight:** The bounded solution space (\(O(X \times Y \times K)\)) indicates that a BFS approach is computationally feasible.

### 5. Optimal Substructure:

- **Observation:** Achieving a smaller error in fewer steps is always preferable to achieving it in more steps.
- **Insight:** This optimal substructure suggests that a greedy approach like BFS, which always explores the shortest paths first, is suitable.

### 6. Pruning Possibilities:

- **Observation:** Some states are redundant or unnecessary to explore (e.g., revisiting a previous state).
- **Insight:** Pruning such states will optimize the search, making the solution more efficient.

### 7. Solution Not Always Possible:

- **Observation:** It’s not always possible to reach the exact target \(M\).
- **Insight:** The focus should be on minimizing the error, which implies keeping track of the closest possible solution while exploring the states.

### Key Takeaways for Future Problems:

- **State Transition Problems:** When you observe a problem involving transitioning between discrete states using specific operations, consider graph-based solutions.
- **Optimality and Shortest Path:** If the problem seeks an optimal solution or a solution within a limited number of steps, consider shortest-path algorithms like BFS or Dijkstra’s algorithm.
- **Bounded Solution Space:** Always consider the computational feasibility of your approach by analyzing the solution space and ensuring it’s bounded within acceptable limits.
- **Pruning:** Always look for opportunities to prune the search space by identifying and avoiding redundant or unnecessary explorations.
- **Optimal Substructure:** Identify if smaller subproblems contribute to optimal solutions for larger problems, guiding the choice of algorithm.

By recognizing these patterns and applying these insights, you can devise similar solutions when encountering problems with analogous structures in the future!