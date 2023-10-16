---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=860
Problem Set:
  - Silver
Last edited time: 2023-10-16T19:05
Status: Solved
tags:
  - Flood-Fill
Key Takeaway: When you some sub-task, that is not-trivial to do efficiently, generally the problem setters would allow you to simply simulate it. For example in game like Tetris and the one described in the current question, it’s completely acceptable to simply simulate gravity.
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

int n, k;
vvi tab, visited;
vii toErase;

void dfs(int i, int j, int color){
    if((i < 0) or (i >= n) or (j < 0) or (j >= 10) or (tab[i][j] != color) or visited[i][j]) return;
    
    visited[i][j] = 1;
    toErase.pb({i, j});
    
    for(int d = 0; d < 4; d++) dfs(i + dx[d], j + dy[d], color);

}

void gravity(){
    vvi newTab(n, vi(10, 0));
    
    for(int i = 0; i < 10; i++){
        int jCounter = n-1;
        for(int j = n-1; j >= 0; j--) if(tab[j][i] != 0) newTab[jCounter--][i] = tab[j][i];
    }
    
    tab = newTab;
}

void fx() {
    cin >> n >> k;
    tab.assign(n, vi(10, 0));
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 10; j++) tab[i][j] = (s[j] - '0');
    }
    
    bool flag = true;
    
    while(flag){
        
        flag = false;
        visited.assign(n, vi(10, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                if(visited[i][j] or tab[i][j] == 0) continue;

                toErase.clear();
                dfs(i, j, tab[i][j]);
                flag = flag | (toErase.size() >= k);
                
                if(toErase.size() >= k) for(auto item: toErase) tab[item.f][item.s] = 0;
            }
        }
        gravity();
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++) cout << tab[i][j];
        cout << endl;
    } 
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("mooyomooyo"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

**Key Observations**:

1. **Gravity Effect**: When cells are removed, the ones above them fall down. This is similar to how blocks fall in games like Tetris.
2. **Connected Cells**: We need to identify groups of connected cells with the same color. This is a classic application of the Depth First Search (DFS) algorithm.

**Core Logic**:

1. **DFS for Connected Cells**: The function `dfs` is used to identify all cells connected to a given cell `(i, j)` with a specific color. The cells identified by this DFS are stored in the `toErase` vector.
2. **Gravity Simulation**: The function `gravity` simulates the effect of gravity. It creates a new board (`newTab`) and populates it by moving non-zero cells from the bottom up.
3. **Main Loop**: The `while(flag)` loop in the `fx` function repeatedly identifies groups of connected cells and removes them until no such groups are found. The flag is set to `true` if any group is found and removed in a given iteration.

**Key Takeaways**:

1. **Simulation**: The problem is essentially about simulating the game's rules. This requires careful implementation to ensure all rules are followed correctly.
2. **Repeated Application**: The process of identifying and removing groups of cells is repeated until no such groups are found. This ensures that the effect of removing one group (which can lead to the formation of new groups) is taken into account.
3. **DFS for Connectivity**: DFS is a powerful tool for identifying connected components in a grid. It's used here to identify groups of connected cells with the same color.

**Valuable Insights**:

1. **Gravity Simulation**: When simulating gravity, it's often easier to construct a new board (or column) from scratch rather than trying to modify the existing one in place.
2. **DFS Boundaries**: When using DFS on a grid, always check boundary conditions to ensure you don't go outside the grid.
3. **Efficiency**: The solution is efficient because it only checks cells that haven't been visited and only simulates gravity when necessary.

In summary, this problem tests the ability to simulate a set of rules on a grid, the understanding of DFS for connectivity, and the careful implementation of game mechanics. The solution provided efficiently addresses the problem by repeatedly applying the game's rules until a stable state is reached.

### Solution Inspiration

1. **Nature of the Problem**: The problem is a simulation of a game. In many such problems, the solution often involves directly implementing the rules of the game in code. This should give you a hint that your solution will involve a loop or iterative process that repeatedly applies these rules until a certain condition is met.
2. **Connectivity**: The problem mentions "connected regions" of cells. Whenever you see terms related to connectivity in a grid (like islands, clusters, regions), it's a strong hint towards using Depth First Search (DFS) or Breadth First Search (BFS) to explore these connected components.
3. **Gravity**: The problem has a gravity mechanic where cells fall down. This should remind you of other games like Tetris. When simulating gravity, it's often simpler to reconstruct the affected part (like a column) from the bottom up, rather than trying to shuffle cells downwards.
4. **Repetition Until Stability**: The problem specifies that after removing a group of cells, the process repeats. This is a hint that you'll need a loop that continues until no more groups can be removed. This is a common pattern in simulation problems: repeat a process until the system reaches a stable state.
5. **Size Constraint**: The problem specifies a grid that's always 10 cells wide but can be up to 100 cells tall. This constraint is manageable for a simulation approach. If the grid were much larger, you might have to think about more optimized or algorithmic solutions rather than direct simulation.
6. **Visualization**: Try to visualize a few steps of the game on paper. This can help you understand the mechanics better and guide your implementation. For example, visualizing the gravity effect can lead you to the insight of reconstructing columns from the bottom up.
7. **Modularity**: Notice how the solution is broken down into functions like `dfs` and `gravity`.

  

### Editorial

> [!info] Solution - Mooyo Mooyo (USACO Silver 2018 December)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-860-mooyo-mooyo/solution](https://usaco.guide/problems/usaco-860-mooyo-mooyo/solution)