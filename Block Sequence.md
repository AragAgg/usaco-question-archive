---
Question Link: https://codeforces.com/contest/1881/problem/E
Problem Set:
  - Code Forces
  - DIV3E
Last edited time: 2023-10-13T20:56
Status: Solved
tags:
  - Dynamic-Programming
What's up: Nice Implementation question
---
### Solution (AC)

```C++
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
\#define ll long long

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

void fx() {
    // Functionality for fx
    int n;
    cin >> n;
    
    vi isValid(n, 0);
    vi trail(n+1, INT_MAX);
    vi tab(n, 0);
    
    int trailing = 0;
    
    for(auto &i: tab) cin >> i;
    
    for(int i = n-1; i >= 0; i--) if(tab[i] <= n - i -1) isValid[i] = 1;
    
    trail[0] = 0;
    
    for(int i = 0; i < n; i++){
        trailing = trail[i];
        if(isValid[i]) trail[i + tab[i] + 1] = min(trail[i + tab[i] + 1], trailing);
    
        trail[i+1] = min(trail[i+1], trailing+1);
    }
    
    cout << trail[n] << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

### Solution Explantion

### Core Logic:

1. **Validity Check:**
    - The code first checks whether a subsequence starting from each index `i` can be valid or not. A subsequence starting from index `i` is valid if `tab[i] <= n - i - 1`. This is because the first element of a block tells us its length, and it must be possible to have that many elements after it in the sequence to form a valid block.
2. **Dynamic Programming Approach:**
    - The solution uses dynamic programming to find the minimum number of deletions required to make the sequence beautiful. The state `trail[i]` represents the minimum number of deletions required to make the subsequence `tab[i, i+1, ..., n-1]` beautiful.
    - The `trail` array is initialized with `INT_MAX` to represent that we don't know the minimum deletions yet and will update these values as we find smaller ones. `trail[0]` is initialized with `0` since no deletions are needed for an empty sequence.
    - The solution iterates through the sequence from left to right, updating the `trail` array based on the previous states and whether the subsequence starting from the current index is valid or not.
3. **Transition Between States:**
    - If the subsequence starting from index `i` is valid (`isValid[i]` is `true`), we can form a block using `tab[i]` elements starting from `i`. Therefore, `trail[i + tab[i] + 1]` can be updated to be at most `trail[i]` because we don't need to delete any of these `tab[i]` elements.
    - Regardless of whether the subsequence starting from `i` is valid or not, we can always delete `tab[i]` and try to make the subsequence `tab[i+1, i+2, ..., n-1]` beautiful. Therefore, `trail[i+1]` can be updated to be at most `trail[i] + 1`.
4. **Result Retrieval:**
    - Finally, `trail[n]` gives the minimum number of deletions required to make the entire sequence beautiful.

### Key Observations and Takeaways:

- **Subproblem Dependency:**
    - The problem can be broken down into smaller subproblems where the solution to the larger problem depends on the solutions to its subproblems. This is a key insight that leads to the use of dynamic programming.
- **State Transition:**
    - Understanding how to transition between states is crucial. The solution smartly updates the `trail` array by considering whether to use the current element to form a block or to delete it.
- **Efficiency:**
    - The solution is efficient with a time complexity of O(n) per test case, as it only requires a single pass through the sequence to fill the `trail` array. This is suitable for the problem's constraints and ensures that the solution runs in a reasonable time for all inputs.
- **Problem Modeling:**
    - Modeling the problem in a way that allows for dynamic programming (i.e., defining the `trail` array and the state transition) is a valuable skill. It involves recognizing the recursive nature of the problem and defining states that can be computed using previously computed states.

### Conclusion:

Understanding how to break a problem down into subproblems, define states, and determine state transitions is crucial for solving dynamic programming problems. This solution demonstrates these principles effectively and provides a clean and efficient solution to the problem. The key takeaway is recognizing and applying dynamic programming to optimize the solution by storing and reusing previously computed results.

### Solution Inspiration

### Observational Insights:

1. **Subsequence Validity:**
    - Observing that a subsequence starting from an index can only form a valid block if it has enough elements following it to satisfy its declared length might lead you to think about checking the validity of subsequences starting from each index.
2. **Greedy Deletion:**
    - You might notice that if you just greedily delete elements that don't fit into a block, you might end up with a non-optimal solution. For example, deleting a `1` that could start a valid block later in the sequence might require more deletions overall than keeping it.
3. **Overlapping Subproblems:**
    - Observing that the minimum deletions required for a subsequence `tab[i, i+1, ..., n-1]` might be related to the minimum deletions required for its subsequence `tab[i+1, i+2, ..., n-1]` could lead you to think about dynamic programming. This is because dynamic programming is suitable for problems with overlapping subproblems, where solving larger problems involves solving their smaller subproblems.
4. **Optimal Substructure:**
    - Realizing that an optimal solution to a problem (minimum deletions for a sequence) can be constructed from optimal solutions to its subproblems (minimum deletions for a subsequence) is another hint towards using dynamic programming. This property, known as optimal substructure, is vital for ensuring that the dynamic programming solution is correct.

### Guiding Observations:

1. **Local Decisions and Global Impact:**
    - Understanding how a local decision (like deleting an element) impacts the global solution (making the entire sequence beautiful) could guide you towards defining states that capture the impact of local decisions on the global solution.
2. **State Definition:**
    - Thinking about how to represent the subproblems is crucial. In this case, defining a state that represents the minimum deletions required for a subsequence starting from each index and trying to find a relationship between these states could be a key observation.
3. **State Transition:**
    - Observing how the decision at a particular index (whether to delete an element or use it to start a block) impacts the solution for the rest of the sequence is crucial for defining the state transition. This involves understanding how the current decision impacts future decisions and how the optimal solution can be built from these decisions.

### Strategy for Future Problems:

- **Identify Subproblems:**
    - Always try to break down the problem into smaller parts and see if solving the smaller parts can help solve the larger problem.
- **Look for Optimal Substructure:**
    - Check if the problem has an optimal substructure, meaning the optimal solution to the problem can be constructed from optimal solutions to its subproblems.
- **Define States Clearly:**
    - Clearly define what each state in your dynamic programming solution represents. Ensure that every aspect of the problem is captured in these states.
- **Determine State Transitions:**
    - Understand how decisions at one state affect the next state. Ensure that your state transitions are logical and cover all possibilities.
- **Analyze Time and Space Complexity:**
    - Ensure that your solution is efficient and adheres to the problem's constraints to avoid timeouts and memory limits.

By focusing on these aspects and practicing more problems, you'll develop an intuition for identifying patterns and devising solution strategies for similar problems in the future!