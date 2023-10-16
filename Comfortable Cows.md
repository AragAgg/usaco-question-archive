---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1110
Problem Set:
  - Silver
Last edited time: 2023-10-16T22:36
Status: Nice Question
tags:
  - Flood-Fill
  - Implementation
  - Problem-Decomposition
Key Takeaway: "Read the ENTIRE question before starting to write a solution. "
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

int k;
int n = 3000;
vvi tab(3000, vi(3000, 0));
vvi visited(3000, vi(3000, 0));
set<pii>addedCows;

bool isComfy(int i, int j){
    int neighs = 0;
    
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        
        if(tab[x][y]) neighs++;
    }
    
    return (neighs == 3);
}

void fixIt(int &i, int &j){
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        
        if(!tab[x][y]){
            i = x;
            j = y;
            
            tab[x][y] = 1;
            addedCows.insert({x, y});
            return;
        }
    }
}

void fixAllViolated(int i, int j){
    
    if(isComfy(i, j)){
        int x = i, y = j;
        fixIt(x, y);
        
        fixAllViolated(x, y);
    }
    
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        
        if(tab[x][y] and isComfy(x, y)){
            fixIt(x, y);
            fixAllViolated(x, y);
        }
    }
}

void fx() {
    cin >> k;
    
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        
        a += 1000; b += 1000;
        tab[a][b] = 1;
        
        if(addedCows.count({a, b})) addedCows.erase({a, b});
        
        fixAllViolated(a, b);
        cout << addedCows.size() << endl;
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

### Solution Explanation

**Problem Recap:**  
The problem is about placing cows in a 2D grid. A cow is considered "comfortable" if it has exactly three neighbors (either horizontally or vertically). The goal is to add more cows to the grid such that no cow remains comfortable.

**Key Observations:**

1. If a cow is comfortable (has 3 neighbors), there's only one cell adjacent to it where a new cow can be added to make it uncomfortable.
2. When a new cow is added to make a comfortable cow uncomfortable, this new cow might make other cows comfortable. This can lead to a chain reaction.

**Core Logic:**

1. **isComfy(int i, int j)**: This function checks if a cow at position `(i, j)` is comfortable. It does this by counting the number of neighboring cows. If the count is 3, the cow is comfortable.
2. **fixIt(int &i, int &j)**: If a cow is comfortable, this function finds the empty adjacent cell to the cow at `(i, j)` and places a new cow there. This new cow's position is added to the `addedCows` set.
3. **fixAllViolated(int i, int j)**: This function is the heart of the solution. It recursively ensures that no cow in the grid is comfortable. If a cow at `(i, j)` is comfortable, it calls `fixIt` to add a new cow and make it uncomfortable. It then checks the neighbors of `(i, j)` and recursively ensures they are not comfortable. This handles the chain reaction mentioned in the key observations.
4. **fx()**: This is the main function that processes the input and implements the solution. For each cow's position `(a, b)` read from the input:
    - It adjusts the position to account for negative coordinates (by adding 1000).
    - It marks the cell as occupied by a cow.
    - If this cow was previously added to make another cow uncomfortable (i.e., it's in the `addedCows` set), it's removed from the set.
    - It then calls `fixAllViolated(a, b)` to ensure no cow is comfortable after adding this new cow.
    - Finally, it prints the size of the `addedCows` set, which represents the number of additional cows added to make all cows uncomfortable.

**Key Takeaways:**

1. **Recursive Solutions**: The problem showcases how a simple observation can lead to a recursive solution. The chain reaction of making cows uncomfortable is elegantly handled using recursion.
2. **State Management**: The use of the `addedCows` set to keep track of cows added to make others uncomfortable is crucial. It ensures that cows read from the input are not double-counted.
3. **Grid Problems**: This problem is a classic example of grid-based problems where local changes can have global effects. The use of delta arrays (`dx` and `dy`) for flood-fill type operations is a common technique in such problems.
4. **Efficiency**: The solution efficiently handles the chain reactions by only considering cells that are affected by recent changes, rather than rechecking the entire grid.

In conclusion, this problem teaches the importance of careful observation, the power of recursion in grid problems, and the need for efficient state management.

### Solution Inspiration

1. **Local Changes with Global Effects**: One of the first things to notice is that adding a cow in one cell can potentially affect the comfort level of cows in neighboring cells. This observation suggests that any solution will likely involve some form of propagation or chain reaction.
2. **Unique Solution for Comfortable Cows**: If a cow is comfortable (having exactly 3 neighbors), there's only one possible cell where you can place another cow to make it uncomfortable. This observation hints at a deterministic approach to "fix" comfortable cows.
3. **Recursive Nature of Comfort**: When you add a cow to make another cow uncomfortable, the newly added cow might make other cows comfortable. This chain reaction is recursive in nature. Recognizing this can lead you to think of a recursive solution.
4. **Efficiency through Targeted Checks**: Instead of checking the entire grid after adding each cow, you can focus only on the affected region (the immediate neighbors). This observation can guide you towards a more efficient solution.
5. **State Management with Sets**: Since the problem involves adding cows and potentially re-adding the same cows based on input, using a data structure like a set can be beneficial. Recognizing the need to manage and track the state of added cows can lead you to use such a data structure.
6. **Flood-fill Analogy**: If you're familiar with the flood-fill algorithm (commonly used in problems involving grids), you might notice similarities. In flood-fill, changes propagate to neighboring cells, much like the chain reaction of comfort in this problem. This analogy can inspire a solution that uses a similar approach.
7. **Boundary Conditions**: The problem doesn't restrict the added cows to be within a specific boundary. This observation can lead you to think of solutions that might add cows outside the given grid dimensions, hence the use of a larger grid size in the provided solution.
8. **Iterative Deepening**: The solution involves repeatedly checking and fixing comfortable cows until no more comfortable cows exist. This iterative deepening approach, where you keep refining the solution until a certain condition is met, is a common strategy in many algorithmic problems.

In summary, when faced with a similar problem in the future, focus on the local effects and how they propagate, look for deterministic solutions to subproblems, consider the recursive nature of changes, and always think about how to manage and track the state efficiently. Recognizing patterns and drawing analogies with known algorithms (like flood-fill) can also provide valuable insights.

### Editorial

> [!info] Contest Results  
> Whenever there exists a cow horizontally or vertically adjacent to three other  
> [http://www.usaco.org/current/data/sol_prob1_silver_feb21.html](http://www.usaco.org/current/data/sol_prob1_silver_feb21.html)