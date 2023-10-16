---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=811
Problem Set:
  - Silver
Last edited time: 2023-10-17T00:42
Status: Nice Question
tags:
  - DFS
  - Flood-Fill
  - Implementation
What's up: My solution is probably within the worst 10% of submissions :| Very shitty implementation. Should have noticed that using DFS would have resulted in a much more concise code.
Key Takeaway: "Before starting to work on the solution, just for a very brief moment, think about other common approaches, in hopes of finding a better suited algorithm. (e.g: DFS vs BFS)"
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
vi tab;
vii boots;

void fx() {
    cin >> n >> k;
    tab.assign(n, 0);
    
    for(auto &i: tab) cin >> i;
    boots.assign(k, {0, 0});
    
    for(auto &i: boots) cin >> i.f >> i.s;
    queue<pii>q;
    q.push({0, 0});
    
    int ans = k-1;
    vi visited(n, 0);
    set<pii>s;
    
    while(!q.empty()){
        if(ans == 0) break;
        
        pii curr = q.front();
        q.pop();
        visited[curr.f] = true;
        
        if(curr.f == n-1) ans = min(ans, curr.s);
        for(int step = 1; step <= min(boots[curr.s].s, n - curr.f -1); step++){
            if(tab[curr.f + step] <= boots[curr.s].f){
                if(s.count({curr.f+step, curr.s})) continue; 
                q.push({curr.f+step, curr.s}); 
                s.insert({curr.f+step, curr.s});
            }
        }
        
        if(!q.size() and curr.s < k-1){
            for(int i = 0; i < n; i++){
                if(!visited[i]) continue;
                if(tab[i] <= boots[curr.s+1].f){ 
                    if(s.count({i, curr.s+1})) continue; 
                    q.push({i, curr.s+1}); 
                    s.insert({i, curr.s+1});
                }
            }
        }
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("snowboots"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation [A little bit wrong]

**Core Logic:**  
The problem is essentially a pathfinding problem with constraints. The goal is to find the minimum number of boots Farmer John needs to discard to reach the barn. The solution uses a BFS (Breadth-First Search) approach to explore the possible paths Farmer John can take, given the constraints of each boot.

**Observations and Insights:**

1. **Boots Order Matters:** Farmer John can only access the topmost pair of boots at any given time. This means that the order in which the boots are presented is crucial. The solution takes advantage of this by starting with the last boot and working its way up.
2. **State Representation:** Each state in the BFS is represented by a pair `{position, boot_index}`, where `position` is Farmer John's current position and `boot_index` is the index of the boot he's currently wearing.
3. **Boot Transition:** If Farmer John can't move forward with the current boot, the solution checks if he can move with the next boot (by discarding the current one). This is done by re-enqueuing all visited positions with the next boot index.
4. **Optimization with Set:** To avoid revisiting the same state, a set `s` is used to keep track of visited states. This ensures that each state is processed only once, reducing the time complexity.
5. **Goal Check:** If Farmer John reaches the last tile (n-1), the solution updates the answer with the current boot index. The goal is to minimize this index.

**Key Takeaways:**

1. **BFS for Pathfinding:** BFS is a versatile algorithm that can be used for pathfinding problems, especially when there are constraints on the moves.
2. **State Management:** In problems where the state is not just a single value (like position), it's essential to carefully define and manage the state. In this problem, the state was a combination of position and boot index.
3. **Optimization Techniques:** Using data structures like sets can significantly speed up the solution by avoiding reprocessing of states.
4. **Transition Logic:** In problems with constraints on moves or transitions, it's crucial to handle all possible transitions correctly. In this problem, transitions were based on the depth of snow and the properties of the boots.
5. **Order Matters:** Sometimes, the order in which elements (like boots in this problem) are presented can be crucial to the solution. It's essential to recognize such scenarios and handle them appropriately.

**Explanation of the Solution:**

1. The solution starts by reading the input and initializing the BFS queue with the starting position and the last boot.
2. In the BFS loop, the solution dequeues the current state and checks if Farmer John has reached the barn. If he has, the answer is updated.
3. The solution then tries to move forward based on the current boot's properties. If a move is valid, the new state is enqueued.
4. If Farmer John can't move forward with the current boot, the solution checks if he can move with the next boot. This is done by re-enqueuing all visited positions with the next boot index.
5. The BFS loop continues until the queue is empty or Farmer John has reached the barn with the first boot.
6. Finally, the solution prints the minimum number of boots Farmer John needs to discard.

In summary, the solution uses BFS to explore all possible paths Farmer John can take, given the constraints of each boot, and finds the minimum number of boots he needs to discard. The use of sets for optimization and careful state management are key aspects of this solution.

### Solution Inspiration [Also a bit inaccurate]

1. **Pathfinding Nature:** The problem essentially asks Farmer John to find a path from the start to the end. Whenever you encounter a problem that involves finding a path, especially with constraints, pathfinding algorithms like BFS and DFS should come to mind.
2. **Constraints on Movement:** The boots have constraints on how deep the snow can be and how far Farmer John can step. This suggests that not all paths are valid, and we need a systematic way to explore all possible paths. BFS is particularly suited for this because it explores all possibilities level by level.
3. **Order of Boots:** The fact that Farmer John can only access the topmost pair of boots and can decide to wear or discard them suggests a decision-making process at each step. This is another hint towards a BFS approach where each state in the BFS represents a decision.
4. **State Representation:** The problem has two main variables that change - the position of Farmer John and the boot he's wearing. This should hint at a state representation that combines both these variables. In BFS, each state can represent a unique combination of these variables.
5. **Optimization Requirement:** Given the constraints (2 ≤ N, B ≤ 250), a brute-force approach that tries every combination would be too slow. This suggests that we need a more optimized approach, and using data structures like sets to avoid reprocessing states is a common optimization technique in BFS.
6. **Goal Check:** The problem asks for the minimum number of boots Farmer John needs to discard. This means we're looking for the earliest boot (from the top) that can reach the end. BFS, by its nature, explores paths in increasing order of steps, making it suitable for this.
7. **Transition Logic:** The boots have specific constraints, and Farmer John can decide to discard a boot if it's not suitable. This suggests that at each step, we need to consider multiple transitions (moving forward with the current boot or trying with the next boot). BFS allows us to handle such multiple transitions systematically.

**To Summarize:**  
When faced with similar problems in the future, look for these hints:

- Is it a pathfinding problem?
- Are there constraints on movement or decisions to be made at each step?
- Is there a need for a systematic exploration of all possibilities?
- Is there a clear goal that requires optimization?

Recognizing these patterns and hints will guide you towards a BFS-based approach or similar systematic exploration techniques. Over time, as you solve more problems, you'll develop an intuition for recognizing these patterns more quickly.

### Editorial

> [!info] Solution - Snow Boots (USACO Silver 2018 February)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-811-snow-boots/solution](https://usaco.guide/problems/usaco-811-snow-boots/solution)