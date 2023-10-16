---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=740
Problem Set:
  - Silver
Last edited time: 2023-10-16T13:37
Status: Nice Question
tags:
  - Connected-Components
  - Flood-Fill
  - Implementation
Key Takeaway: "When the question allows for a very high time complexity (n^4) or something like that, take advantage of the fact that the time limit on the question must be high so as to allow different solutions (maybe even suboptimal ones). We may be a bit lenient in our implementations of sub-routines, for example: maybe use a O(N) lookup on an array, when in fact it could be optimised to O(logN) at the cost of increased implementation time and code complexity."
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

int n;
vvi tab;
vector<pair<pii, pii>>PCLS;
vvi visited; 
int lxBound, lyBound, hxBound, hyBound;

void dfs(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = 1;
    
    for(int d = 0; d < 4; d++){
        int x = i + dx[d], y = j + dy[d];
        if(x < lxBound or x > hxBound or y < lyBound or y > hyBound or tab[x][y] != tab[i][j]) continue;
        dfs(x, y);
    }
}

bool isPCL(int i, int j, int x, int y){
    visited.assign(n, vi(n, 0));
    lxBound = i, lyBound = j, hxBound = x, hyBound = y;
    map<int, int> colors;
    int comps = 0;
    
    for(int l = i; l <= x; l++){
        for(int m = j; m <= y; m++){
            if(visited[l][m]) continue;
            comps++;
            colors[tab[l][m]]++;
            dfs(l, m);
            if(colors.size() > 2) return false;
        }
    }
    
    if(comps < 3) return false;
    for(auto item: colors) if(item.s == 1) return true;
    return false;
}

bool isUnique(int i, int j, int x, int y){
    bool f = true;
    bool add = false;
    vi toErase;
    
    for(int p = 0; p < PCLS.size(); p++){
        auto pcl = PCLS[p];
        
        if(pcl.f.f >= i and pcl.s.f <= x and pcl.f.s >= j and pcl.s.s <= y){
            f = false;
            add = true;
            toErase.pb(p);
        }
        
        if(i >= pcl.f.f and x <= pcl.s.f and j >= pcl.f.s and y <= pcl.s.s) f = false;
    }
    
    for(int p = toErase.size()-1; p >= 0; p--) PCLS.erase(PCLS.begin()+toErase[p]);
    if(add) PCLS.pb({{i, j}, {x, y}});
    return f;
}

void fx() {
    cin >> n;
    tab.assign(n, vi(n, 0));
    
    for(auto &r: tab) for(auto &c: r){ char ch; cin >> ch; c = (ch - 'A');}
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int x = i; x < n; x++){
                for(int y = j; y < n; y++){
                    if(isPCL(i, j, x, y) and isUnique(i, j, x, y)) PCLS.pb({{i, j}, {x, y}});
                }
            }
        }
    }
    
    cout << PCLS.size() << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("where"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

**Core Logic:**

1. **Grid Representation:** The grid is represented as a 2D vector `tab` of size `n x n`. Each cell in the grid contains a character, which is then converted to an integer (0 for 'A', 1 for 'B', and so on).
2. **PCL Definition:** A PCL is a contiguous region of the grid where:
    - There are exactly two distinct colors.
    - One of the colors appears in exactly one connected component, while the other color can appear in one or more connected components.
3. **DFS for Connectivity:** The function `dfs` is used to explore the connected components of a given color in the grid. It uses the flood-fill algorithm to traverse all cells of the same color that are connected to a given starting cell.
4. **Checking for PCL:** The function `isPCL` checks if a subgrid (bounded by `(i, j)` and `(x, y)`) is a PCL. It does this by:
    - Counting the number of connected components of each color in the subgrid.
    - Checking if there are exactly two colors and one of them appears in exactly one connected component.
5. **Ensuring Uniqueness:** The function `isUnique` ensures that a found PCL is not entirely contained within another PCL. If a smaller PCL is found inside a larger one, the larger one is removed.
6. **Main Logic (**`**fx**` **function):** The code iterates over all possible subgrids of the main grid and checks if they are PCLs and if they are unique. All unique PCLs are stored in the `PCLS` vector.
7. **Output:** The code outputs the number of unique PCLs found.

**Key Observations and Insights:**

- **Connected Components:** The problem requires identifying connected components of the same color. This is a classic application of the DFS algorithm.
- **Nested Loops:** The nested loops in the `fx` function ensure that all possible subgrids are checked. This is a brute-force approach, but given the constraints, it's feasible.
- **Uniqueness of PCLs:** The problem has an added complexity of ensuring that PCLs are unique. This is handled by the `isUnique` function, which checks if a PCL is contained within another.

**Key Takeaways:**

1. **DFS/Flood-fill:** This algorithm is essential for problems involving grids and connectivity. It's versatile and can be adapted for various tasks, like counting connected components.
2. **Brute-force with Pruning:** While the solution uses a brute-force approach to check all subgrids, it also employs pruning techniques (like `isUnique`) to reduce the search space.
3. **Problem Decomposition:** The solution breaks down the problem into smaller tasks (like checking for PCL, ensuring uniqueness, and traversing connected components). This makes the code modular and easier to understand.

In summary, this problem is a good exercise in grid traversal, the application of DFS for connectivity, and problem decomposition. It tests the ability to combine multiple algorithms and techniques to solve a more complex task.

### Solution Inspiration

1. **Grid-Based Problem:**
    - **Observation:** The problem is based on a grid where each cell has a value (color in this case).
    - **Inspiration:** Grid-based problems often involve traversing the grid, checking neighbors, and sometimes exploring all possible subgrids. This should immediately remind you of algorithms like DFS/BFS for traversal and flood-fill for connectivity.
2. **Connected Components:**
    - **Observation:** The problem mentions contiguous regions and connected components.
    - **Inspiration:** Whenever you hear "connected" in a grid problem, think of the flood-fill algorithm using DFS/BFS. This is a classic way to identify and traverse connected components.
3. **Constraints on Components:**
    - **Observation:** The problem has specific constraints on the number of colors and the number of connected components of each color in a PCL.
    - **Inspiration:** This suggests that after identifying a connected component, you'll need to keep track of some metadata about it (e.g., which colors are present, how many times each color appears, etc.).
4. **Uniqueness of Regions:**
    - **Observation:** The problem requires that PCLs be unique and not contained within another PCL.
    - **Inspiration:** This suggests that after identifying a potential PCL, you'll need a mechanism to check its uniqueness. This could involve comparing it with previously identified PCLs.
5. **Iterating Over All Subgrids:**
    - **Observation:** The problem doesn't provide any specific starting point or focus area within the grid. It's about finding regions anywhere in the grid.
    - **Inspiration:** This suggests a brute-force approach where you check all possible subgrids. The nested loops in the solution are a direct result of this observation.
6. **Character to Integer Conversion:**
    - **Observation:** The grid is filled with characters, but working with integers might be more straightforward for comparisons and counting.
    - **Inspiration:** Convert characters to integers for easier processing. This is a common trick when you need to perform arithmetic or comparisons on data.
7. **Efficiency Concerns:**
    - **Observation:** While the problem allows for a brute-force approach given the constraints, there's a need to ensure that the solution doesn't do redundant work.
    - **Inspiration:** Use memoization or other techniques to avoid re-computing results. In this solution, the `visited` array ensures that cells aren't re-visited.

**In Summary:**

When faced with a similar problem in the future:

- **Break Down the Problem:** Identify the core components of the problem. Does it involve traversal? Connectivity? Counting? Subgrids?
- **Recall Similar Problems:** Think back to other problems you've solved or seen that have similar components. What algorithms or techniques did they use?
- **Start Simple:** Begin with a brute-force approach or the most straightforward algorithm you know. Then optimize or refine as needed.
- **Iterate and Refine:** As you work on the problem, continually refine your approach. Maybe you start with a brute-force solution and then find ways to optimize or prune the search space.

Remember, problem-solving is as much about practice and experience as it is about knowledge. The more problems you tackle, the better you'll become at spotting these cues and drawing from your "toolbox" of algorithms and techniques.

### Editorial

> [!info] Contest Results  
> Any rectangle whose sides are parallel to the grid is uniquely defined by its  
> [http://www.usaco.org/current/data/sol_where_silver_open17.html](http://www.usaco.org/current/data/sol_where_silver_open17.html)