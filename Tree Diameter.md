---
Question Link: https://cses.fi/problemset/task/1131
Problem Set:
  - CSES
Last edited time: 2023-10-18T19:14
Status: Solved
tags:
  - Tree
  - Trick
What's up: Used the two DFS Trick to find the diameter of the tree.
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

int bestDist;
int bestNode;

vvi tab;

void findFurthest(int x, int parent, int dist){
    if(dist > bestDist){
        bestDist = dist;
        bestNode = x;
    }
    
    for(auto neigh: tab[x]){
        if(neigh == parent) continue;
        
        findFurthest(neigh, x, dist+1);
    }
}

void fx() {
    cin >> n;
    
    tab.assign(n, {});
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        tab[a].pb(b);
        tab[b].pb(a);
    }
    
    bestDist = 0;
    bestNode = 0;
    
    findFurthest(0, -1, 0);
    
    bestDist = 0;
    findFurthest(bestNode, -1, 0);
    
    cout << (bestDist) << endl;
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

### **Core Logic:**

The problem is about finding the diameter of a tree. The diameter of a tree is the longest path between any two nodes in the tree.

A key observation here is that if you start from any node and find the furthest node from it, that furthest node will always be one of the endpoints of the diameter. This is because, if there was a longer path that didn't include this furthest node, then this node wouldn't have been the furthest in the first place.

Using this observation, the solution uses a two-step DFS (Depth First Search) approach:

1. Start DFS from any node (in this case, node 0) to find the furthest node. Let's call this node A.
2. Start another DFS from node A to find the furthest node from A. The distance to this node will be the diameter of the tree.

### **Key Takeaways:**

1. **DFS in Trees:** Trees are a special kind of graph where there are no cycles. This means that DFS can be used without worrying about visiting a node multiple times. In this solution, DFS is used to traverse the tree and find the furthest node from a given starting node.
2. **Diameter Endpoint:** The furthest node from any given node in a tree will always be one of the endpoints of the diameter. This insight reduces the problem of finding the diameter to two DFS traversals.
3. **Adjacency List Representation:** The tree is represented using an adjacency list (`tab`), which is a common way to represent graphs. This makes it easy to traverse the tree and find neighbors of a given node.

### **Code Explanation:**

- The function `findFurthest` is the DFS function. It starts from node `x`, and for each neighbor of `x` (except the parent node to avoid going back), it recursively finds the furthest node. The `bestDist` and `bestNode` variables keep track of the furthest node found so far and its distance.
- The `fx` function reads the input, constructs the tree, and then performs the two DFS traversals to find the diameter. The first DFS finds the node A (stored in `bestNode`), and the second DFS finds the diameter by starting from A.
- There are some utility functions and definitions at the beginning of the code, like `yes`, `no`, and the floodfill deltas, but they are not used in this solution.

### **Conclusion:**

The problem teaches the importance of understanding the properties of trees and how DFS can be used effectively to traverse them. The key insight about the diameter's endpoint simplifies the problem and reduces the complexity of the solution.