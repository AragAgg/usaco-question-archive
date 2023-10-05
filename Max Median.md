---
Question Link: https://codeforces.com/contest/1486/problem/D
Problem Set:
  - "*2100"
  - Code Forces
  - DIV2D
Last edited time: 2023-10-05T20:26
Status: Seen Editorial
tags:
  - Binary-Search
  - Implementation
  - Problem-Decomposition
  - Structure
What's up: Pretty nice idea. (Relational Transformation)
Key Takeaway: Transforming array elements into binary indicators (+1/-1) based on a condition can simplify complex problems, especially those involving subarray properties. This approach, often coupled with prefix sums, converts intricate element comparisons into straightforward binary computations, enabling the application of optimized algorithms and revealing hidden problem properties, thereby streamlining solution development.
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

int n, k;
vi tab;

bool isViable(int x){
    vi psum(n, 0);
    
    psum[0] = ((tab[0] >= x)?1:-1);
    
    for(int i = 1; i < n; i++) psum[i] += psum[i-1] + ((tab[i] >= x)?1:-1);
    
    int mn = 0;
    
    for(int i = k; i < n; i++){
        mn = min(mn, psum[i-k]);
        if(psum[i] - mn >= 1) return true;
    }
    
    return (psum[k-1] >= 1);
}

void fx() {
    // Functionality for fx
    
    cin >> n >> k;
    tab.assign(n, 0);
    ll hi = INT_MIN;
    ll lo = INT_MAX;
    for(auto &i: tab){ cin >> i; hi = max(hi, (ll)i);}
    
    lo = 0;
    
    while(lo < hi){
        int mid = lo + (hi - lo+1)/2;
        
        if(isViable(mid)) lo = mid;
        else hi = mid-1;
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

### Relational Transformation

### Overview

In the realm of algorithmic problem-solving, particularly those involving arrays and numerical comparisons, employing a **binary transformation strategy** can be a pivotal and insightful approach. This involves converting array elements into simplified binary indicators, such as `+1` or `-1`, based on a specific condition or threshold, thereby morphing a potentially complex problem into a more tractable form.

### Core Concept

- **Binary Transformation:** Elements in the array are transformed into `+1` or `1` based on whether they satisfy a particular condition, often related to a pivotal value or threshold.

### Advantages

1. **Simplicity:** The binary transformation simplifies the numerical values, making them easier to work with and reason about.
2. **Efficiency:** When combined with techniques like prefix sums, it facilitates efficient and rapid calculations related to subarray sums or other aggregate measures.
3. **Revealing Patterns:** This strategy can unveil hidden patterns or properties in the problem, such as monotonicity or other structural insights, which might be obfuscated in the original array.

### Application

- **Problem Simplification:** Convert a complex problem involving raw numerical elements into a simpler, binary form, enabling more straightforward algorithmic applications.
- **Optimized Algorithms:** The simplified, binary nature often allows for the application of optimized algorithms, such as binary search or dynamic programming, in a more direct and computationally efficient manner.

### Conclusion

The binary transformation strategy is not merely a technique but a paradigm, offering a lens through which problems can be viewed and understood from a fresh, simplified perspective. It streamlines the problem-solving process, often revealing a more direct path to efficient and elegant algorithmic solutions, and thus stands as a potent tool in the computational problem solver's arsenal. This approach underscores the broader principle that sometimes, the path to solving complex problems involves transforming them into a simpler, more digestible form.

### Solution Explanation

This solution employs a **binary search** algorithm to find the maximum median in an array, and it cleverly utilizes **prefix sums** to optimize the check for whether a median is valid. Let's delve into the core logic, observations, and key takeaways from this solution.

### Core Logic

1. **Binary Search for Median:**
    - The binary search is used to find the maximum median in the range `[l, r)`, where `l` starts as 1 and `r` starts as `n + 1`. The median `mid` is calculated as `(l + r) // 2` in each iteration.
    - The binary search is applied because it is known that if a number `x` can be a median of some subarray, then any number less than `x` can also be a median of some subarray. This property allows us to apply binary search to find the largest possible median.

1. **Transforming the Array:**
    - An array `b` is created, where each element is `1` if the corresponding element in `a` is greater than or equal to `mid`, and `1` otherwise. This transformation is crucial because it converts the problem into finding a subarray of length at least `k` with a positive sum, which can be solved efficiently.
    - The array `b` is then transformed into its prefix sum to facilitate quick calculation of sums of any subarray.
2. **Checking the Validity of Median:**
    - If the sum of the first `k` elements of `b` is positive, `mid` is a valid median.
    - Otherwise, iterate through `b` starting from index `k`. If at any point, the sum of a subarray ending at `i` and starting at any index `j < i` (where `i - j >= k`) is positive, `mid` is a valid median. This is equivalent to checking if `b[i] - min(b[i-k], b[i-k+1], ..., b[i-1]) > 0`.

### Observations and Insights

- **Transforming the Problem:** The transformation of array `a` into array `b` and then into its prefix sum is a clever way to simplify the problem into a form that can be solved more efficiently.
- **Optimizing Subarray Sum Calculation:** The use of prefix sums allows for the calculation of the sum of any subarray in O(1) time, which is crucial for keeping the solution efficient.
- **Ensuring Subarray Length:** The algorithm ensures that any subarray considered has a length of at least `k` by checking the sum of the first `k` elements separately and starting the subsequent loop from index `k`.

### Key Takeaways

- **Problem Transformation:** Sometimes, transforming the problem or the input data into a different form can make it much easier to solve.
- **Binary Search Application:** Binary search can be applied in various scenarios, not just searching in a sorted array. Here, it's used to efficiently find a value that satisfies certain conditions.
- **Efficient Subarray Sum Calculation:** Prefix sums are a powerful tool for problems involving subarray sums, allowing for constant-time calculations.

In summary, this solution is a beautiful blend of binary search and prefix sums, demonstrating how combining different algorithms and techniques can lead to an efficient solution. It also showcases the power of problem transformation and how looking at a problem from a different angle can sometimes reveal a simpler path to the solution.

### Solution Inspiration

### Observational Insights:

1. **Monotonic Property:**
    - **Observation:** If a number `x` can be a median of some subarray, then any number less than `x` can also be a median of some subarray.
    - **Inspiration:** This observation should hint towards binary search since binary search is often applicable when there’s a monotonic relationship.
2. **Subarray and Median:**
    - **Observation:** The problem is about finding a subarray with a certain property related to its median.
    - **Inspiration:** Problems involving subarrays often benefit from prefix sums because they allow for constant-time calculations of subarray sums.
3. **Median as a Pivot:**
    - **Observation:** The median divides the set into two halves, one part will always be greater than or equal to the median, and the other will be less than or equal to it.
    - **Inspiration:** This could inspire transforming the array into a form that makes it easier to work with these two halves, such as converting elements into `1` or `-1` based on their relationship with the median.

### Problem-Solving Path:

1. **Binary Search:**
    - **Why:** The monotonic property of the median.
    - **How to Apply:** Use binary search to find the maximum possible median by checking if it's possible for a number to be a median and adjusting the search space accordingly.
2. **Transforming the Problem:**
    
    - **Why:** The original problem might be complex to solve directly.
    
    - **How to Apply:** Convert the array into a form that simplifies the problem. Here, converting the array into `1`s and `-1`s based on a potential median and then using prefix sums simplifies the problem to finding a subarray of length at least `k` with a positive sum.
3. **Checking Subarray Conditions:**
    - **Why:** Need to check if a number can be a median of some subarray of length at least `k`.
    - **How to Apply:** Use the transformed array and prefix sums to efficiently check if there exists a subarray of length at least `k` with a positive sum.

### Key Takeaways for Future Problems:

- **Look for Monotonic Properties:** If adjusting one parameter (like the median here) makes the problem easier or harder in a consistent direction, consider binary search.

- **Simplify with Transformation:** If the direct approach is complex, think about how you can transform the problem or the input data into a simpler form.

- **Utilize Prefix Sums:** For problems involving subarrays, especially those asking about the sum of elements in a subarray, consider if prefix sums or a similar transformation can make the problem easier.
- **Efficient Checking:** Ensure that the method to check the condition (whether a number can be a median in this case) is efficient, keeping the overall time complexity in mind.

By internalizing these observations and strategies, you'll be better equipped to devise similar solutions when encountering problems with related patterns in the future!

### Editorial

> [!info] Codeforces Round #703 (Div. 2) Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/87849](https://codeforces.com/blog/entry/87849)