---
Question Link: https://atcoder.jp/contests/agc015/tasks/agc015_c
Problem Set:
  - AtCoder
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - 2D-Prefix-Sum
  - Tree
Key Takeaway: " A connected component with n vertices has n-1 edges.The prefix sum technique is a powerful tool for problems where you need to compute sums over sub-arrays or sub-grids multiple times. By investing time in preprocessing, you can answer each query in constant time."
---
### Solution Explanation

The problem is essentially asking for the number of connected components within a sub-grid of the given grid. The problem's constraints, especially the size of the grid, make it unsuitable to perform a depth-first search (DFS) for every query, since that would be too slow. Instead, the solution pre-computes some information to make answering the queries faster.

  

The solution follows these steps:

- **Input and Initialisation**:
    - Read the grid dimensions, grid values, and number of queries.
    - Initialize several 2D arrays (`tab`, `l`, `r`, `t`, `b`) of size `n+1 x m+1` to store information about blue cells and their connections.
- **Populate Data**:
    - The `tab` array is filled with the values of the grid, where `tab[i][j]` is 1 if the corresponding cell is blue.
    - The other arrays (`l`, `r`, `t`, `b`) are used to track connections between blue cells.
        - `l[i][j]` is 1 if the blue cell at `(i,j)` is connected to another blue cell to its left.
        - `r[i][j]` is 1 if the blue cell at `(i,j)` is connected to another blue cell to its right.
        - `t[i][j]` is 1 if the blue cell at `(i,j)` is connected to another blue cell above it.
        - `b[i][j]` is 1 if the blue cell at `(i,j)` is connected to another blue cell below it.
- **Prefix Sum Calculation**:
    - Each of the 2D arrays (`tab`, `l`, `r`, `t`, `b`) is updated to store the prefix sum of its values. This allows us to efficiently compute the sum of values within any sub-grid.
- **Answer Queries**:
    - For each query defining a sub-grid `(x1, y1)` to `(x2, y2)`:
        1. Compute the number of vertices (blue cells) within the sub-grid using the `tab` array.
        2. Compute the number of edges (connections between blue cells) within the sub-grid using the `l`, `r`, `t`, `b` arrays.
        3. The number of connected components within the sub-grid is given by `vertices - edges`. This is because in a tree (which is a connected component without cycles), the number of vertices is always one more than the number of edges. So, subtracting the number of edges from the number of vertices gives the number of connected components.
        4. Print the number of connected components.

  

Overall, the idea behind this solution is to preprocess the grid to allow for fast computation of the number of connected components in any sub-grid. The prefix sum technique is used to quickly compute sums over sub-grids, and the number of connected components is computed using the relationship between vertices and edges in trees.

### Actual Solution

```JavaScript
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

int n, m, q;
vvi tab;
vvi l, r, t, b;


void fx() {
    // Functionality for fx
    cin >> n >> m >> q;
    tab.assign(n+1, vi(m+1, 0));
    l.assign(n+1, vi(m+1, 0));
    r.assign(n+1, vi(m+1, 0));
    t.assign(n+1, vi(m+1, 0));
    b.assign(n+1, vi(m+1, 0));

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        
        for(int j = 0; j < m; j++) if(s[j] - '0') tab[i+1][j+1] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!tab[i][j]) continue;
            
            if(tab[i-1][j]) t[i][j]++;
            if(i != n and tab[i+1][j]) b[i][j]++;
            if(tab[i][j-1]) l[i][j]++;
            if(j != m and tab[i][j+1]) r[i][j]++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tab[i][j] += tab[i-1][j] + tab[i][j-1] - tab[i-1][j-1];
            l[i][j] += l[i-1][j] + l[i][j-1] - l[i-1][j-1];
            r[i][j] += r[i-1][j] + r[i][j-1] - r[i-1][j-1];
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            t[i][j] += t[i-1][j] + t[i][j-1] - t[i-1][j-1];
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int vertices = tab[x2][y2] - tab[x2][y1-1] - tab[x1-1][y2] + tab[x1-1][y1-1];
        int edges = 0;
        
        if(y2-y1) edges += l[x2][y2] - l[x2][y1-1+1] - l[x1-1][y2] + l[x1-1][y1-1+1];
        if(y2-y1) edges += r[x2][y2-1] - r[x2][y1-1] - r[x1-1][y2-1] + r[x1-1][y1-1];
        if(x2-x1) edges += t[x2][y2] - t[x2][y1-1] - t[x1-1+1][y2] + t[x1-1+1][y1-1];
        if(x2-x1) edges += b[x2-1][y2] - b[x2-1][y1-1] - b[x1-1][y2] + b[x1-1][y1-1];
        
        edges /= 2;
        cout << (vertices - edges) << endl;
    }
    
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

  

### Editorial (One Royal Piece of Crap)

![[Screenshot_2023-08-13_at_11.53.30_PM.png]]

  

  

### A slightly more concise code

```JavaScript
\#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;
int grid[MAX][MAX], pf1[MAX][MAX], 
    pf2[MAX][MAX], pf3[MAX][MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c; grid[i][j] = c == '1';
            pf1[i][j] = grid[i][j] + pf1[i - 1][j] + 
                pf1[i][j - 1] - pf1[i - 1][j - 1];
            pf2[i][j] = (grid[i][j] && grid[i - 1][j]) + 
                pf2[i - 1][j] + pf2[i][j - 1] - pf2[i - 1][j - 1];
            pf3[i][j] = (grid[i][j] && grid[i][j - 1]) + 
                pf3[i - 1][j] + pf3[i][j - 1] - pf3[i - 1][j - 1];
        }
    }
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int tot = pf1[r2][c2] - pf1[r2][c1 - 1] - 
            pf1[r1 - 1][c2] + pf1[r1 - 1][c1 - 1];
        int adj1 = pf2[r2][c2] - pf2[r2][c1 - 1] - 
            pf2[r1][c2] + pf2[r1][c1 - 1];
        int adj2 = pf3[r2][c2] - pf3[r2][c1] - 
            pf3[r1 - 1][c2] + pf3[r1 - 1][c1];
        cout << tot - adj1 - adj2 << "\n";
    }
}
/*
Algorithm:
Create a 2D prefix sum of all the blue squares, a
prefix sum for all the horizontally connected
pairs of squares, and a prefix sum for all the 
vertically connected pairs of squares.
The answer is the total squares - horiz. adj.
- vert. adj. squares for a subrectangle.

Why This Works:
All the squares are guaranteed to only have 1 path
from one square to another. This means that if we 
subtract the total squares - horiz - vert, then 
we won't overcount the horizontally and vertically adjacent
connections. 
*/
```

### Explanation

### 1. Initialisation:

```C++
\#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;
int grid[MAX][MAX], pf1[MAX][MAX],
    pf2[MAX][MAX], pf3[MAX][MAX];
```

- **Header and Namespace**: The code begins by including the `bits/stdc++.h` header, a common header in competitive programming that includes most standard libraries. The `std` namespace is also being used.
- **Constants and Variables**: The constant `MAX` is set to `2001`, slightly more than the maximum grid size for padding. There are four 2D arrays:
    - `grid`: Represents the input grid.
    - `pf1`: Stores the prefix sum of all blue squares.
    - `pf2`: Stores the prefix sum of vertically adjacent blue squares.
    - `pf3`: Stores the prefix sum of horizontally adjacent blue squares.

### 2. Input Reading and Prefix Sum Calculation:

```C++
int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c; grid[i][j] = c == '1';
            ...
            // Prefix sums calculations
        }
    }
    ...
}
```

- **Fast I/O**: The statement `cin.tie(0) -> sync_with_stdio(false);` is used for faster input-output operations, which is especially useful when dealing with problems with high constraints.
- **Input Grid**: For each cell in the grid, the code reads a character and checks if it's '1' (indicating a blue square). It then computes the prefix sums for the blue squares (`pf1`), vertically adjacent blue squares (`pf2`), and horizontally adjacent blue squares (`pf3`).

### 3. Processing Queries:

```C++
while (q--) {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    ...
    // Computing totals and adjacencies
    cout << tot - adj1 - adj2 << "\\n";
}
```

- **Query Input**: For each query, the code reads the top-left and bottom-right coordinates of the subrectangle.
- **Compute Totals and Adjacencies**: Using the previously calculated prefix sums, the code computes the total number of blue squares in the subrectangle (`tot`) and the number of vertically (`adj1`) and horizontally (`adj2`) adjacent blue squares.
- **Output**: The answer for each query is `tot - adj1 - adj2`. This is printed for each query.

  

### Algorithm Explanation:

The core logic behind the solution is to leverage the concept of prefix sums to quickly compute sums over subrectangles. The problem asks for the number of connected components in a subrectangle. By understanding the constraints (that there's only one path between any two blue squares), we realize that the number of connected components is equal to the total number of blue squares minus the number of connections (adjacencies) between them.

The solution calculates three types of prefix sums:

- `pf1`: The number of blue squares.
- `pf2`: The number of vertical adjacencies between blue squares.
- `pf3`: The number of horizontal adjacencies between blue squares.

For a given subrectangle defined by its top-left `(r1, c1)` and bottom-right `(r2, c2)` corners, the number of connected components is given by:

\[  
\text{Connected components} = \text{Total blue squares} - \text{Vertical adjacencies} - \text{Horizontal adjacencies}  
\]

The total blue squares and the adjacencies are computed using the prefix sums.

### Key Takeaways:

1. **Prefix Sums**: This solution highlights the power of prefix sums. By investing time in preprocessing (calculating prefix sums), we can answer each query in constant time.
2. **Properties of the Grid**: Given the constraints of the problem (each blue cell is connected to any other blue cell by at most one path), we can determine the number of connected components by counting the blue cells and subtracting the number of connections between them.
3. **Efficiency**: This solution is efficient for large grids and a large number of queries due to the use of prefix sums.

The provided code is a concise and efficient solution to the problem, demonstrating the effectiveness of prefix sums for problems that require calculating sums over subarrays or subgrids.