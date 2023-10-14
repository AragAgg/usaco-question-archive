---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=570
Problem Set:
  - Silver
Last edited time: 2023-10-14T23:40
Status: Nice Question
tags:
  - DFS
  - Flood-Fill
  - Implementation
What's up: Solved after a bit of trial-and-error.
Key Takeaway: Keep it simple, and straightforward. Become good at recognising state dependencies.Over optimisation is GOOD FOR NOTHING.
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

int n, m;

vector<vector<vector<pii>>>tab;

bool isValid(int i, int j){
    return (i >= 0 and i < n and j >= 0 and j < n);
}

void fx() {
    cin >> n >> m;
    
    tab.assign(n, vector<vii>(n));
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        tab[--a][--b].pb({--c, --d});
    }
    
    queue<pii>q;
    q.push({0, 0});
    
    vvi visited(n, vi(n, 0));
    
    //states in visited:
    //0: unvisited
    //1: accessible but not Lit
    //2: is Lit but not accessible
    //3: visited or currently in queue
    
    int ans = 1;
    
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        
        if(visited[curr.f][curr.s] == 4) continue;
        visited[curr.f][curr.s] = 4;
        
        for(auto item: tab[curr.f][curr.s]){
            
            if(visited[item.f][item.s] == 0){
                
                ans++;
                visited[item.f][item.s] = 2;
                
            }else if(visited[item.f][item.s] == 1){
                
                ans++;
                visited[item.f][item.s] = 3;
                q.push({item.f, item.s});
            }
        }
        
        for(int d = 0; d < 4; d++){
            int x = curr.f + dx[d];
            int y = curr.s + dy[d];
            
            if(!isValid(x, y)) continue;
            
            if(visited[x][y] == 0) visited[x][y] = 1;
            else if(visited[x][y] == 2){
                visited[x][y] = 3;
                q.push({x, y});
            }
        }
        
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("lightson"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

The provided solution employs a **Breadth-First Search (BFS)** algorithm to traverse through the barn's grid and determine the maximum number of rooms Bessie can illuminate. Let's break down the core logic and key takeaways:

### Core Logic:

1. **Initialization:**
    - The grid of rooms is represented as a 3D vector `tab`, where `tab[i][j]` stores a vector of pairs representing the rooms that can be lit by switches in room `(i, j)`.
    - The `visited` 2D vector keeps track of the state of each room: unvisited, accessible but not lit, lit but not accessible, and visited or currently in the queue.
    - A queue `q` is used to perform BFS, starting from room `(0, 0)`.
2. **Switch Toggling and Room Illumination:**
    - Bessie starts from room `(0, 0)`, and the algorithm uses BFS to explore accessible and lit rooms.
    - When Bessie enters a room, she toggles all the switches available in that room, potentially lighting up other rooms.
    - If a room is lit and accessible, Bessie moves to that room and repeats the process.
3. **BFS Traversal:**
    - Bessie can only move to adjacent rooms (North, East, South, West) if they are lit.
    - The BFS ensures that Bessie explores all possible paths and toggles all accessible switches to maximize the number of lit rooms.
    - The `visited` matrix is updated accordingly to avoid revisiting rooms and to keep track of the state of each room.
4. **Counting Illuminated Rooms:**
    - The algorithm keeps a count `ans` of the number of rooms that Bessie has illuminated.
    - Whenever Bessie lights up a new room, `ans` is incremented.

### Observations and Insights:

- **Switch Dependency:** A switch in one room might light up another room, which might contain another switch to light up a previously visited room. This dependency chain is crucial and is effectively handled by BFS.

- **State Management:** Managing the state of each room (whether it is visited, lit, or accessible) is vital to avoid infinite loops and to ensure all possible rooms are visited.

- **Optimization:** The solution ensures that Bessie does not revisit rooms and only toggles switches in newly visited rooms, which is crucial for optimizing the solution, especially for larger grids.

### Key Takeaways:

1. **Graph Traversal:** Understanding how to traverse a grid using BFS and how to manage the state during traversal is crucial for solving such problems.
2. **State Management:** Efficiently managing and updating the state of each node (room, in this case) during traversal can significantly optimize the solution.
3. **Problem Modeling:** Transforming a real-world problem into a graph problem (rooms as nodes, switches as edges) and identifying the appropriate algorithm (BFS) to solve it.
4. **Optimization:** Ensuring that the algorithm does not perform unnecessary operations (like revisiting nodes) is key to solving problems with potentially large input sizes.

In summary, this problem beautifully intertwines graph traversal with state management and provides a practical scenario where BFS can be applied effectively to navigate through interconnected nodes while managing their states.

### Solution Inspirations

### Observations:

1. **Movement Dependency on State:**
    - Bessie can only move through lit rooms, creating a dependency between the state of a room (lit/unlit) and the possibility to explore it.
    - This dependency hints towards a need for a traversal algorithm that can adapt to changing states (like BFS).
2. **Switch-Room Dependency:**
    - A switch in one room can light up another room, which might contain switches to light up other rooms, creating a chain of dependencies.
    - This cascading effect suggests that the solution needs to continuously update and check the states of rooms as they are explored.
3. **Grid Traversal:**
    - The problem involves moving through a grid, a common scenario where graph traversal algorithms (like DFS or BFS) are often applicable.
4. **Maximization Objective:**
    - The goal is to maximize the number of lit rooms, which implies that the algorithm should explore as many possibilities as it can.
    - BFS naturally fits this requirement as it explores level-wise, ensuring all possible paths are explored.

### Inspirations for Solution:

1. **Use of BFS:**
    - Observing that Bessie’s movement is restricted by the state of the rooms and that switches can alter this state, BFS becomes a suitable choice. BFS allows for the exploration of all possible paths and can adapt to changing states (like newly lit rooms becoming accessible).
2. **State Management:**
    - Noticing that a room can be in different states (unvisited, visited but unlit, visited and lit) should inspire the use of a data structure (like a matrix) to keep track of these states during traversal.
    - This ensures that Bessie doesn’t revisit rooms unnecessarily and that all possible rooms are lit.
3. **Switch Management:**
    - Realizing that a switch can light up a room that Bessie has already visited (or will visit) suggests that the algorithm needs to continuously check for new possibilities as new rooms are lit and visited.
    - This is implemented in the solution by toggling switches as rooms are visited and exploring newly lit rooms.
4. **Optimization:**
    - Observing the potential for a large search space (given the constraints \(2 \leq N \leq 100\) and \(1 \leq M \leq 20,000\)) implies a need for optimization.
    - Ensuring that Bessie doesn’t revisit rooms and that switches are only toggled when necessary helps to optimize the solution.

### Key Takeaways:

- **Recognize Dependencies:** Understand how different elements of the problem (rooms, switches) are interconnected and how changing one element (lighting up a room) affects the others (accessibility).
- **Identify Suitable Algorithms:** Recognize patterns (like grid traversal and state dependency) that hint towards suitable algorithms (like BFS).
- **Manage States Efficiently:** Understand the importance of managing and updating states efficiently to optimize the solution and explore all possibilities.
- **Optimize:** Always consider the constraints and ensure that the solution is optimized to handle the upper limits.

By observing these aspects and understanding the mechanics of how different elements of the problem interact, you can derive inspiration for a solution and potentially apply a similar approach to future problems.

### Editorial (USACO)

> [!info] Solution - Switching on the Lights (USACO Silver 2015 December)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-570-switching-on-the-lights/solution](https://usaco.guide/problems/usaco-570-switching-on-the-lights/solution)