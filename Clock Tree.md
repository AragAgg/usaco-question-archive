---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1016
Problem Set:
  - Review
  - Silver
Last edited time: 2023-10-19T22:02
Status: Nice Question
tags:
  - DFS
  - Math
  - Mod
  - Observation
  - Tree
What's up: Solved in O(N^2) using a very complicated method. But this question is solvable in O(N) time, so we’ll come back with more experience.
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
    cout << name << " = [ ";
    for(const auto &x : a) cout << x << ' ';
    cout << "]\n";
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

int n, a, b, ans = 0;
vvi tab;
vi t;

int dfs(int v, int parent){
    int burden = 0;
    for(auto neigh: tab[v]) if(neigh != parent) burden += dfs(neigh, v);
    return ((12 - t[v] - burden)%12 + 12)%12;
}

void fx() {
    cin >> n;
    
    t.assign(n, 0);
    tab.assign(n, {});
    
    for(auto &i: t) cin >> i;
    
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tab[--a].pb(--b);
        tab[b].pb(a);
    }
    
    for(int i = 0; i < n; i++){
        int rs = (dfs(i, -1));
        if(rs == 0 or rs == 11) ans++;
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("clocktree"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation [1]

**Key Observations:**

1. When Bessie enters a room, the clock advances by 1. This means that if a clock is at `x`, after Bessie's visit, it will be at `(x+1)%12`.
2. If Bessie visits a room `y` times, the clock will advance by `y`. Thus, the final position of the clock will be `(x+y)%12`.
3. The goal is to make all clocks point to 12. If a clock is at `x`, Bessie needs to visit the room `(12-x)%12` times to make it point to 12.
4. When Bessie traverses the barn, the number of times she visits each room depends on the path she takes. However, the total number of rooms she visits is constant for a given starting room.

**Core Logic:**  
The function `dfs(int v, int parent)` is a Depth First Search that calculates the "burden" of each room. The "burden" is the number of times Bessie needs to visit a room to make its clock point to 12. The DFS traverses the tree and accumulates the burden of child rooms to the parent room.

The main function `fx()` does the following:

1. Reads the number of rooms `n`.
2. Initializes the clocks in each room and the adjacency list for the rooms.
3. For each room `i`, it calculates the total burden using the `dfs` function. If the total burden is 0 or 11, it means Bessie can start from that room and make all clocks point to 12. This is because if the burden is 0, all clocks are already synchronized. If the burden is 11, Bessie can visit the starting room once more to make all clocks point to 12.
4. The answer is the number of rooms where Bessie can start her journey.

**Key Takeaways:**

1. **Tree Traversal:** The problem requires a deep understanding of tree traversal techniques, especially Depth First Search, to calculate the burden of each room.
2. **Modular Arithmetic:** The problem heavily relies on modular arithmetic to determine the number of times Bessie needs to visit a room.
3. **State Propagation:** The state (or burden) of child rooms affects the state of the parent room. This propagation of state is a common theme in tree-based problems.
4. **Optimization:** Instead of calculating all possible paths Bessie can take, the solution cleverly reduces the problem to calculating the total burden for each starting room.

In summary, this problem tests the understanding of tree traversal, state propagation in trees, and modular arithmetic. The solution is efficient and elegant, focusing on the core logic rather than brute force.

### Solution Explanation [2]

**Understanding the Problem:**  
The problem is about synchronizing clocks in a tree structure. Each room has a clock, and Bessie wants to make all clocks point to 12. Every time Bessie enters a room, she advances the clock in that room by 1. The challenge is to find out from which rooms Bessie can start her journey to synchronize all the clocks.

**Key Insight:**  
The main insight is that the order in which Bessie visits the rooms matters, but the number of rooms she visits is constant for a given starting room. So, instead of considering all possible paths, we can simplify the problem by calculating the "burden" of each room.

**What is "burden"?**  
The "burden" of a room is the number of times Bessie needs to visit that room to make its clock point to 12. If a clock is currently pointing at `x`, the burden of that room is `(12-x)%12`.

**DFS and Burden Calculation:**  
The function `dfs(int v, int parent)` calculates the burden of room `v`. The logic is recursive:

1. For each neighboring room (or child) of `v`, calculate its burden.
2. Accumulate the burdens of all child rooms.
3. Adjust the burden of room `v` based on its current clock position and the accumulated burden from child rooms.

**Why does this work?**  
When Bessie traverses the tree, she will visit the child rooms before the parent room. The number of times she visits each child room will affect the state of the parent room's clock. By accumulating the burdens of child rooms, we can determine how many more times Bessie needs to visit the parent room to synchronize its clock.

**Main Logic in** `**fx()**` **function:**

1. For each room `i` as the starting room, calculate its total burden using the `dfs` function.
2. If the total burden of the starting room is 0, it means all clocks are already synchronized.
3. If the total burden is 11, it means Bessie can visit the starting room once more to synchronize all clocks.
4. For any other burden value, it's impossible to synchronize all clocks from that starting room.
5. Count the number of starting rooms with a burden of 0 or 11.

**Why are only burdens of 0 and 11 considered valid?**  
Remember, Bessie doesn't adjust the clock in her starting room initially. So, if the total burden after her journey is 0, all clocks are synchronized. If the burden is 11, Bessie can simply re-enter her starting room to advance its clock by 1, making all clocks point to 12.

In essence, the solution cleverly reduces the problem to calculating the total burden for each starting room using DFS. Instead of considering all possible paths, it focuses on the net effect of Bessie's journey on each room's clock. This approach is both efficient and elegant.

### Solution Inspiration

1. **Tree Structure:** The problem mentions rooms connected by corridors, and it's possible to walk from any room to any other room. This is a classic description of a tree. Whenever you see such a structure, tree traversal techniques like DFS and BFS should come to mind.
2. **Clock Advancement:** The problem states that every time Bessie enters a room, the clock advances by 1. This is a modular operation, as clocks wrap around after 12. Problems involving cycles, repetitions, or wrap-arounds often hint at modular arithmetic.
3. **Synchronization Goal:** The goal is to make all clocks point to 12. This means that for a clock pointing at `x`, Bessie needs to visit the room `(12-x)%12` times. This observation is crucial as it defines the "burden" of a room.
4. **Effect Propagation:** Bessie's visit to one room can affect the state of another room (its parent in the tree). This is because the number of times Bessie visits a child room will determine how many times she needs to visit its parent room. This observation hints at a bottom-up approach, where you first consider the leaves (child rooms) and then propagate the effect upwards to the root.
5. **Simplification:** Instead of considering all possible paths Bessie can take, focus on the net effect of her journey. This is where the idea of "burden" simplifies the problem. By calculating the burden of each room, you can determine the overall effect of Bessie's journey without considering every possible path.
6. **Starting Room Special Case:** Bessie doesn't adjust the clock in her starting room initially. This is a special case and hints that the starting room needs separate consideration. If after her entire journey, the burden of the starting room is 11, she can simply re-enter to synchronize all clocks.

**Key Takeaways for Future Problems:**

1. Recognize underlying structures (like trees) from the problem description.
2. Look for operations that repeat or wrap around, hinting at modular arithmetic.
3. Try to simplify the problem. Instead of considering all possibilities, focus on the net effect or outcome.
4. In tree-based problems, consider how the state of one node (room) affects another. This often hints at tree traversal techniques.
5. Always keep the problem's constraints in mind. They can hint at the required efficiency of your solution.

By internalizing these observational insights and strategies, you'll be better equipped to tackle similar problems in the future.

### Editorial

> [!info] Solution - Clock Tree (USACO Silver 2020 February)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-1016-clock-tree/solution](https://usaco.guide/problems/usaco-1016-clock-tree/solution)