---
Question Link: https://codeforces.com/contest/782/problem/B
Problem Set:
  - "*1600"
  - Code Forces
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Binary-Search
  - Implementation
Key Takeaway: The code uses lo and hi values to carry out a binary search, and while this is correct, it is often a better idea to use a const number of converging iterations (typically 100- 200) when trying to find a double value with a pre-defined epsilon.A nice method to check if a sequence of n segments intersect or not, is to simply check if the max(starting points of all segments) is less than or equal to the min(ending points of all segments)
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
vector<double>x, v;
double eps = 1e-6;

bool isViable(double t){
    // cout << "called isViable(" << setprecision(10)<< t << ")\n";
    double overlapA = x[0]-(v[0]*t);
    double overlapB = x[0]+(v[0]*t);
    
    for(int i = 0; i < N; i++){
        double actualOverlap = min(overlapB, x[i]+(v[i]*t)) - max(overlapA, x[i]-v[i]*t);
        if(0 - actualOverlap > eps) return false;
        
        overlapA = max(overlapA, x[i]-v[i]*t);
        overlapB = min(overlapB, x[i]+(v[i]*t));
    }
    
    // cout << "retruning true\n";
    return true;
}

void fx() {
    // Functionality for fx
    cin >> N;
    x.assign(N, 0);
    v.assign(N, 0);
    
    for(auto &i : x) cin >> i;
    for(auto &i : v) cin >> i;
    
    double lo = 0;
    double hi = 1e9;
    

    while(hi - lo > eps){
        double mid = lo + (hi - lo)/2;
        
        if(isViable(mid)) hi = mid;
        else lo = mid + 0.0000001;
    }
    
    cout << setprecision(8)<< hi << endl; // might cause precision and rounding errors...
    
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

This solution employs a binary search algorithm to find the minimum time needed for all friends to meet at some point on the road, given their initial positions and maximum speeds. The core logic revolves around minimizing the time taken for all friends to meet within a certain range, which is determined by checking whether it's possible for all friends to meet within a certain time `t`.

### Core Logic and Observations

1. **Binary Search on Time:**
    - The binary search is applied to the time variable, not directly to the positions of the friends. The search space for time is `[0, 1e9]` (where `1e9` is a sufficiently large value).
    - The binary search tries to minimize the time `t` such that all friends can meet at a common point within time `t`.
2. **Checking Viability:**
    - The `isViable(double t)` function checks whether it's possible for all friends to meet within time `t`.
    - For each friend, it calculates the maximum and minimum possible positions they can be in after time `t` using their speed and initial position. This range is `[x[i] - v[i]*t, x[i] + v[i]*t]`.
    - The function ensures that there is a common overlap in the possible positions of all friends after time `t`. If there is no common overlap, it's not possible for all friends to meet within time `t`.
3. **Overlap Calculation:**
    - The algorithm keeps track of the overlapping range where all friends can possibly meet within time `t` (`overlapA` and `overlapB`).
    - For each friend, it adjusts the overlapping range based on the friend's possible position after time `t`.
    - If at any point, the overlapping range becomes invalid (i.e., `overlapA > overlapB`), it returns `false` indicating it's not possible for all friends to meet within time `t`.
4. **Precision Handling:**
    - The algorithm uses a small epsilon value `eps` to handle precision issues and to determine when to stop the binary search.
    - The condition `while(hi - lo > eps)` ensures that the binary search continues until the difference between `hi` and `lo` is sufficiently small, indicating that a minimum time `t` has been found to a certain precision.

### Key Takeaways

1. **Binary Search Beyond Sorting:**
    - Binary search can be applied to optimize the solution in problems beyond simple sorted array searches, such as minimizing/maximizing a certain parameter (in this case, time).
2. **Precision and Efficiency:**
    - Handling precision in floating-point calculations and ensuring the algorithm is efficient (using binary search to minimize the number of checks needed) are crucial in solving problems with continuous variables.
3. **Range Overlap Calculation:**
    - Calculating the overlapping range of possible positions for all friends and adjusting this range based on each friend's possible position is a key insight. This ensures that the solution considers all friends and finds a common meeting point.
4. **Handling Continuous Variables:**
    - Problems with continuous variables (like time or position in a continuous space) often require considerations for precision and may involve algorithms that work on ranges or intervals.

### Explanation of Code Snippets

- `bool isViable(double t)`: Checks whether all friends can meet within time `t` by calculating and adjusting the overlapping range of possible positions.
- `while(hi - lo > eps)`: Binary search loop that continues until `hi` and `lo` are sufficiently close, ensuring the found time `t` is minimized and precise.
- `if(isViable(mid)) hi = mid; else lo = mid + 0.0000001;`: Adjusts the search space based on whether it's possible for all friends to meet within time `mid`.
- `cout << setprecision(8)<< hi << endl;`: Outputs the found minimum time `t` with a precision of 8 decimal places.

This problem beautifully illustrates how binary search can be applied in a non-traditional context (not on a sorted array) and emphasizes the importance of precision in problems involving continuous variables.

### Editorial

![[Screenshot_2023-10-04_at_1.54.41_PM.png]]