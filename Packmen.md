---
Question Link: https://codeforces.com/contest/847/problem/E
Problem Set:
  - "*1800"
  - Code Forces
  - ICPC Regional
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Binary-Search
  - Implementation
Key Takeaway: If a solution fails on a high enough TC, its probably a bound error or overflow error.When entities in a problem do not interact with each other, you can often consider each entity independently when constructing a solution. This can simplify the problem by breaking it down into smaller, independent sub-problems.
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

int N;
string s;
vi food, packmen;

bool isVaible(ll tme){
    set<int>f;
    for(auto &i: food) f.insert(i);
    
    int p = 0;
    auto fIter = f.begin();
    
    while(fIter != f.end() and p < packmen.size()){
        auto foodIter = fIter;
        if(packmen[p] - *foodIter > tme) return false;
        
        if(*foodIter <= packmen[p]){
            auto c1 = f.upper_bound(packmen[p] + max(0LL, tme - 2*(packmen[p] - *foodIter)));
            auto c2 = f.upper_bound(packmen[p] + max(0LL, (tme - (packmen[p] - *foodIter))/2));
            foodIter = c1;
            if(foodIter != f.end() and (c2 == f.end() or *foodIter < *c2)) foodIter = c2;
            
        }else foodIter = f.upper_bound(packmen[p] + tme);
        
        fIter = foodIter;
        p++;
    }
    
    return (fIter == f.end());
}

void fx() {
    cin >> N >> s;
    for(int i =  0; i < N; i++){
        if(s[i] == '*') food.pb(i);
        else if(s[i] == 'P') packmen.pb(i);
    }
    
    ll lo = 0;
    ll hi = 1e6+100;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        
        if(isVaible(mid)) hi = mid;
        else lo = mid +1;
    }
    
    cout << lo << endl;
    
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

The provided solution employs a binary search algorithm to minimize the time it takes for all Packmen to eat all asterisks. The core logic revolves around determining whether it's possible for all Packmen to eat all the asterisks within a specified time frame, and then minimizing that time frame using binary search.

### Core Logic:

1. **Identifying Positions**:
    - Store the positions of all Packmen and asterisks (food) in separate vectors.
2. **Binary Search**:
    - Implement a binary search to find the minimum time `t` needed for all Packmen to eat all the asterisks.
    - The lower bound `lo` is initialized to 0, and the upper bound `hi` is set to a sufficiently large number (1e6 + 100 in this case).
    - The binary search continues until `lo` is less than `hi`, and it calculates the mid-point `mid` to check whether it's possible for all Packmen to eat all asterisks within `mid` time units.
3. **Checking Viability**:
    - The `isVaible(ll tme)` function checks whether it's possible for all Packmen to eat all asterisks within a given time `tme`.
    - It uses a set `f` to store the positions of all uneaten asterisks.
    - It iterates through each Packman and tries to eat as many asterisks as possible within the given time `tme`, updating the set `f` accordingly.
    - The function returns `true` if all asterisks can be eaten within time `tme`, and `false` otherwise.
4. **Optimizing Time**:
    - If it's possible to eat all asterisks within `mid` time units, update `hi` to `mid` to search for a potentially smaller viable time frame.
    - If it's not possible, update `lo` to `mid + 1` to search for a viable time frame in the upper half of the current search space.
    - The binary search ends when `lo` is no longer less than `hi`, and the minimum time required is outputted as `lo`.

### Observations and Insights:

- **Multiple Strategies**: A Packman can either move left to eat left-side asterisks and then move right, or move right to eat right-side asterisks and then move left. The solution considers both strategies and chooses the one that allows the Packman to eat more asterisks within the given time frame.

- **Non-Interference**: Since Packmen do not interfere with each other, each Packman can be considered independently when determining which asterisks it will eat.
- **Binary Search**: The binary search is crucial for optimizing the solution to find the minimum time in a logarithmic time complexity, making the solution efficient and suitable for large input sizes.

### Key Takeaways:

- **Efficiency**: Efficient algorithms like binary search can significantly optimize the solution, especially in problems where the search space is large.
- **Divide and Conquer**: The problem is broken down into smaller sub-problems (can a solution be found within time `t`?), which are easier to solve and can be used to construct the solution to the original problem.
- **Greedy Approach**: The solution employs a greedy approach in the `isVaible` function, where each Packman tries to eat as many asterisks as possible within the given time frame.
- **Simulation**: Simulating the process (Packmen eating asterisks) and checking the viability of a solution within certain constraints (time `tme`) is a valuable strategy in problem-solving.

This problem beautifully blends binary search, simulation, and greedy algorithms to find an optimal solution, showcasing how different algorithms can be combined to solve a single problem effectively.

### Editorial

> [!info] Solution - Packmen (CF)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cf-packmen/solution](https://usaco.guide/problems/cf-packmen/solution)  

### Solution Inspiration

### 1. **Multiple Possibilities**:

- **Observation**: The Packmen can move in both directions and consume asterisks, which means there are multiple ways to approach the problem.
- **Insight**: When there are multiple possibilities and the task is to find the minimum/maximum or optimal among them, consider algorithms like binary search, dynamic programming, or greedy algorithms that can efficiently explore and optimize the solution space.

### 2. **Independence of Packmen**:

- **Observation**: Packmen do not interfere with each other's movements and can be in the same cell.

- **Insight**: When entities in a problem do not interact with each other, you can often consider each entity independently when constructing a solution. This can simplify the problem by breaking it down into smaller, independent sub-problems.

### 3. **Unbounded Time and Movement**:

- **Observation**: The Packmen can change directions unlimited times and there is no upper limit on the time to eat all asterisks.
- **Insight**: When there is no upper bound, consider binary search to efficiently find the optimal solution within a range. Define a sufficiently large upper bound for the binary search (like 1e6 in the solution) to ensure it encompasses all possible scenarios.

### 4. **Existence of a Threshold**:

- **Observation**: There exists a certain minimum time after which all asterisks can be eaten.
- **Insight**: When there is a threshold value to be found (like minimum time), binary search is often a suitable algorithm. Binary search can efficiently narrow down to the exact threshold by continuously halving the search space.

### 5. **Feasibility Check**:

- **Observation**: The problem involves checking whether a certain condition (eating all asterisks) can be satisfied within a given parameter (time).
- **Insight**: Problems that involve checking the feasibility of a condition under varying parameters often benefit from a binary search, especially when the condition may be more easily satisfied as the parameter increases (or vice versa).

### 6. **Variable Strategies for Packmen**:

- **Observation**: A Packman can adopt different strategies (like moving left first or right first) to eat asterisks.
- **Insight**: When multiple strategies are available, consider all viable strategies and choose the optimal one. This might involve a greedy approach, where you choose the best immediate option.

### 7. **Non-Linear Solution Space**:

- **Observation**: The relationship between the positions of Packmen/asterisks and the minimum time is not linear or direct.
- **Insight**: When the solution space is not linear or straightforward, heuristic, or algorithmic approaches like binary search or dynamic programming, which do not rely on a direct formula or relation, might be apt.

### Final Thoughts:

When you encounter a problem:

- Identify the nature of the solution space and the interactions between entities.
- Consider whether binary search, greedy algorithms, or dynamic programming might offer an efficient solution.
- Break down the problem and try to solve smaller sub-problems independently if possible.
- Always think about the feasibility and how you can check whether a solution is possible under certain parameters.

These observational insights and strategies can guide you towards implementing efficient solutions in future problems with similar characteristics.