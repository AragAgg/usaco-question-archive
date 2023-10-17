---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=836
Problem Set:
  - Silver
Last edited time: 2023-10-17T20:54
Status: Solved with Help
tags:
  - Flood-Fill
  - Implementation
  - Optimisation
  - Problem-Decomposition
Key Takeaway: When the number of nodes in a tree is too high, consider write your traversal method on the basis of edges and similarly when the number of edges in a graph is too high when compared to the number of nodes, consider writing your traversal method on the basis of nodes.
---
### Solution History (AC)

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
vvi color;
vvi region;
vi occupancy;
set<int>colorSet;
vi colors;

map<pii, vector<pair<pii, pii>>>edges;

void fx() {
    cin >> n;
    
    color.assign(n, vi(n, 0));
    region.assign(n, vi(n, -1));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> color[i][j];
            colorSet.insert(color[i][j]);
        }
    }
    
    for(auto item: colorSet) colors.pb(item);
    
    int rCounter = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(region[i][j] != -1) continue;
            
            queue<pii>q;
            q.push({i, j});
            
            int occupants = 0;
            
            while(!q.empty()){
                pii curr = q.front(); q.pop();
                
                if(region[curr.f][curr.s] != -1) continue;
                region[curr.f][curr.s] = rCounter;
                occupants++;
                
                for(int d = 0; d < 4; d++){
                    int x = curr.f + dx[d];
                    int y = curr.s + dy[d];
                    
                    if(x < 0 or x >= n or y < 0 or y >= n) continue;
                    else if(color[curr.f][curr.s] != color[x][y]){
                        edges[{color[curr.f][curr.s], color[x][y]}].pb({{curr.f, curr.s}, {x, y}});
                        continue;
                    }
                    
                    q.push({x, y});
                }
            }
            
            rCounter++;
            occupancy.pb(occupants);
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < colors.size()-1; i++){ 
        for(int j = i + 1; j < colors.size(); j++){
            
            map<int, set<int>>tree;     //map mapping region to other connected regions (an adjacency list...)
            int pairAns = 0;            // to calculate the best answer this pair of colors gives us...
            set<int>notVisited;         // set of notVisited regions...
            
            for(auto edge: edges[{i, j}]){
                int r1 = region[edge.f.f][edge.f.s];
                int r2 = region[edge.s.f][edge.s.s];
                
                tree[r1].insert(r2);
                tree[r2].insert(r1);
                
                notVisited.insert(r1);
                notVisited.insert(r2);
            }
            
            for(auto node: notVisited){
                
                int compAns = 0; //to calculate the best answer this particular connected component gives us...
                queue<int>q;    //to perfom BFS
                q.push(node);   //root node
                
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    
                    if(!notVisited.count(curr)) continue;
                    notVisited.erase(curr);
                    compAns += occupancy[curr];
                    
                    for(auto neigh: tree[curr]) q.push(neigh);
                }
                
                pairAns = max(pairAns, compAns);
            }
            
            ans = max(ans, pairAns);
        }
    }
    
    cout << *max_element(all(occupancy)) << endl;
    cout << ans << endl;
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
vvi color, region;
vi occupancy;
map<pii, set<pair<pii, pii>>>edges;

void fx() {
    cin >> n;
    color.assign(n, vi(n, 0));
    region.assign(n, vi(n, -1));
    
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> color[i][j];
    
    int rCounter = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if(region[i][j] != -1) continue;
            queue<pii>q;
            q.push({i, j});
            int occupants = 0;
            
            while(!q.empty()){
                pii curr = q.front(); q.pop();
                if(region[curr.f][curr.s] != -1) continue;
                region[curr.f][curr.s] = rCounter;
                occupants++;
                
                for(int d = 0; d < 4; d++){
                    int x = curr.f + dx[d];
                    int y = curr.s + dy[d];
                    
                    if(x < 0 or x >= n or y < 0 or y >= n) continue;
                    else if(color[curr.f][curr.s] != color[x][y]){
                        edges[{color[curr.f][curr.s], color[x][y]}].insert({{curr.f, curr.s}, {x, y}});
                        continue;
                    }
                
                    q.push({x, y});
                }
            }
            
            rCounter++;
            occupancy.pb(occupants);
        }
    }                               
    
    int ans = 0;
    
    for(auto nodePair: edges){
        
        int i = nodePair.f.f;
        int j = nodePair.f.s;
        
        map<int, set<int>>tree;     
        int pairAns = 0;           
        set<int>notVisited;      
        unordered_set<int>vis;    
        
        for(auto edge: nodePair.s){
            int r1 = region[edge.f.f][edge.f.s];
            int r2 = region[edge.s.f][edge.s.s];
            
            tree[r1].insert(r2);
            tree[r2].insert(r1);
            
            notVisited.insert(r1);
            notVisited.insert(r2);
        }                          
        
        for(auto node: notVisited){

            if(vis.count(node)) continue;
            
            int compAns = 0;
            queue<int>q;
            q.push(node);
            
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                
                if(vis.count(curr)) continue;
                vis.insert(curr);
                compAns += occupancy[curr];
                
                for(auto neigh: tree[curr]) q.push(neigh);
            }
            
            pairAns = max(pairAns, compAns);
        }
        
        ans = max(ans, pairAns);
        
    }
    
    cout << *max_element(all(occupancy)) << endl;
    cout << ans << endl;
}

int main() {
    iofile(string("multimoo"));
    fx();
}
```

### Solution Explanation

**Key Observations:**

1. The problem can be solved using a flood-fill algorithm to identify regions of the same color.
2. To find the largest region that can be claimed by a two-cow team, we need to identify regions that are adjacent to each other and have different colors.
3. The adjacency between two regions can be represented using a graph where each region is a node, and an edge exists between two nodes if their corresponding regions are adjacent on the board.

**Core Logic:**

1. **Initialization and Input Reading:**
    - The grid is read into the `color` 2D vector.
    - The `region` 2D vector is initialized with -1, which will later store the region ID for each cell.
    - `occupancy` vector will store the number of cells in each region.
2. **Identifying Regions:**
    - For each cell in the grid, if its region is not yet identified (i.e., `region[i][j] == -1`), a flood-fill is performed starting from that cell to identify all cells belonging to the same region.
    - The `edges` map is used to store edges between regions of different colors. If during the flood-fill, a neighboring cell of a different color is found, an edge is added between the current cell's region and the neighboring cell's region.
3. **Finding the Largest Region for a Two-Cow Team:**
    - For each pair of colors that have an edge between them, a graph is constructed where each node represents a region, and an edge exists between two nodes if their regions are adjacent on the board.
    - BFS is used to traverse the graph and find the largest connected component that consists of regions of the two colors.
    - The size of the largest connected component is updated as the answer if it's larger than the current answer.
4. **Output:**
    - The size of the largest single-color region is printed, which is the maximum value in the `occupancy` vector.
    - The size of the largest two-color region is printed, which is stored in the `ans` variable.

**Key Takeaways:**

1. **Flood-fill Algorithm:** This problem is a classic example of how the flood-fill algorithm can be used to identify connected regions in a grid.
2. **Graph Representation:** Representing the problem as a graph where nodes are regions and edges represent adjacency between regions provides a clear way to solve the problem.
3. **BFS for Graph Traversal:** BFS is a powerful tool for traversing graphs and finding connected components.

In summary, this solution combines the flood-fill algorithm with graph theory concepts to solve the problem. The key is to first identify single-color regions and then find the largest region that can be formed by combining two adjacent regions of different colors.

### Solution Inspiration

1. **Grid-Based Problem:**
    - The problem is based on a grid, and many grid-based problems can be tackled using traversal algorithms like DFS or BFS.
    - When you see terms like "connected", "adjacent", or "region", it's a hint that you might need to explore or traverse parts of the grid to find or define these regions.
2. **Identifying Regions of Same Color:**
    - The problem asks for the largest region of a single color. This is a direct hint towards using a flood-fill algorithm. Flood-fill is a classic algorithm to identify and mark connected regions in a matrix or grid.
3. **Two-Cow Team Regions:**
    - The problem's twist is finding regions for two-cow teams. This requires identifying regions that are adjacent but of different colors.
    - When you think of connections between different entities (in this case, regions), a graph is a natural data structure to consider. Edges in the graph can represent the adjacency between regions.
4. **Connected Components:**
    - The problem essentially boils down to finding the largest connected component in a graph, where nodes are regions, and edges represent adjacency between regions of two different colors.
    - Recognizing this, BFS or DFS becomes an obvious choice to traverse and identify these connected components.
5. **Efficiency Concerns:**
    - The constraints (\(1 \leq N \leq 250\)) hint that an \(O(N^2)\) or even \(O(N^3)\) solution might be feasible. This means that checking every cell or every pair of cells is acceptable.
    - However, a naive \(O(N^4)\) approach (like trying every possible pair of regions) would be too slow. This should inspire you to look for more efficient methods, like the graph-based approach used in the solution.
6. **Edge Cases and Observations:**
    - The problem specifies that diagonal connections don't count. This is a hint that you should be careful about how you define "adjacency" in your solution.
    - The problem also specifies that a two-cow team region must contain cells of both cows. This means you can't just combine two large regions of a single color; they must be intermixed.

**In Summary:**  
When faced with similar problems in the future:

- Recognize the nature of the problem (grid-based, traversal, connected regions).
- Think of classic algorithms that fit the problem's nature (flood-fill for grid regions, BFS/DFS for graph traversal).
- Consider the problem's constraints to ensure your solution is efficient enough.
- Always keep an eye out for special conditions or twists that might require additional logic or data structures.

By recognizing these patterns and hints, you'll be better equipped to devise similar solutions for related problems in the future.

### Editorial

> [!info] Solution - Multiplayer Moo (USACO Silver 2018 US Open)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-836-multiplayer-moo/solution](https://usaco.guide/problems/usaco-836-multiplayer-moo/solution)