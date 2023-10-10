---
Question Link: https://codeforces.com/contest/1878/problem/E
Problem Set:
  - Code Forces
  - DIV3E
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Binary-Search
  - Bitwise
  - Greedy
  - Problem-Decomposition
  - Structure
What's up: Solved using segment tree, in combination with binary search. But this could also have been solved without segment Tree. (using prefix sums instead)
Key Takeaway: Another question where a Segment Tree is an overkill. Could have use a much more simpler linear structure (prefix sums of individual bits over elements).In future, when you’re sure that using a segment tree would do the trick, it is worth trying to recreate the same effect using a linear structure. And make sure to try out Prefix Sums (in one form or the other), this save a lot of implementation time and headache.
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


class SegmentTree {
public:
    int n;
    vi tree;
    
    SegmentTree(const vi& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    int q(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }


    void build(const vi& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, node * 2, start, mid);
            build(data, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] & tree[node * 2 + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return -1;
        }
        if (l <= start && r >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(node * 2, start, mid, l, r);
        int p2 = query(node * 2 + 1, mid + 1, end, l, r);
        return p1 & p2;
    }
};




void fx() {
    int n;
    cin >> n;
    
    vi tab(n);
    for(auto &i: tab) cin >> i;
    
    SegmentTree segTree(tab);
    
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        l--;
        
        int lo = l-1;
        int hi = n-1;
        
        while(lo < hi){
            int mid = lo + (hi - lo+1)/2;
            
            if(segTree.q(l, mid) >= k) lo = mid;
            else hi = mid -1;
        }
        
        if(segTree.q(l, lo) >= k) cout << (lo+1) << " ";
        else cout << -1 << " ";
        
    }
    
    cout << endl;
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

### Solution Explanation

---

This solution is a classic example of using a Segment Tree data structure to answer range bitwise AND queries efficiently and then performing a binary search to find the rightmost index in the array that satisfies a certain condition. Below is the breakdown of the core logic, observations, and key takeaways.

Core Logic:

1. **Segment Tree Construction:**
    - A Segment Tree is built based on the given array, where each node in the Segment Tree stores the bitwise AND of a range of elements in the array.
    - The `build` function is used to construct the Segment Tree. It recursively divides the array into two equal halves until each segment represents a single element of the array. The bitwise AND of segments is calculated and stored in the Segment Tree.
2. **Answering Queries:**
    - For each query, a binary search is performed to find the rightmost index (`r`) such that the bitwise AND of the range from `l` to `r` is greater than or equal to `k`.
    - The `query` function in the Segment Tree is used to calculate the bitwise AND of any given range in logarithmic time.
    - The binary search checks the middle of the range, and based on the result, it either moves to the left half or the right half of the range.

Observations:

- **Bitwise AND Operation:**
    - The bitwise AND operation is associative, which means the order of the numbers does not affect the result. This property is essential for the Segment Tree to work correctly.
    - The bitwise AND of a range of numbers can never increase if more numbers are added to the range. This observation is crucial for ensuring that the binary search will work correctly.
- **Binary Search:**
    - The binary search is used to efficiently find the rightmost index that satisfies the condition. It takes advantage of the fact that if a range does not satisfy the condition, extending the range to the right will also not satisfy the condition.

Key Takeaways:

1. **Efficient Query Processing:**
    - The use of a Segment Tree allows for efficiently answering range bitwise AND queries in \(O(\log n)\) time, where \(n\) is the number of elements in the array.
2. **Binary Search for Optimal Index:**
    - Binary search is a powerful technique for quickly finding an index that satisfies a certain condition in a sorted or partially ordered dataset.
3. **Combining Data Structures:**
    - The solution demonstrates how combining different data structures (Segment Tree and Binary Search) can lead to an efficient solution for a complex problem.

Explanation of Code:

- The `SegmentTree` class is used to represent the Segment Tree. It contains functions for building the Segment Tree (`build`) and querying the Segment Tree (`query`).
- The `fx` function is used to process each test case. It reads the input array and queries, constructs a Segment Tree, and then answers each query by performing a binary search to find the rightmost index that satisfies the condition.
- The `main` function reads the number of test cases and processes each test case using the `fx` function.

In summary, this solution is an excellent example of how to efficiently process range queries and find specific indices in an array by combining Segment Trees and Binary Search.

### Solution Inspiration

---

  

### Observations and Inspirations:

### **1. Range Queries:**

- **Observation:** The problem involves answering multiple queries on ranges of an array.
- **Inspiration:** This is a hint that a data structure that can efficiently handle range queries, like a Segment Tree or Fenwick Tree, might be useful.

### **2. Bitwise AND Operation:**

- **Observation:** The queries involve the bitwise AND operation on a range of numbers.
- **Inspiration:** Since the bitwise AND operation is associative, a Segment Tree can be used to precompute the AND for ranges of elements, allowing for efficient queries.

### **3. Finding the Rightmost Index:**

- **Observation:** The problem requires finding the rightmost index in a range that satisfies a certain condition.
- **Inspiration:** This is a hint that a binary search can be used to efficiently find the rightmost index, as it works by repeatedly dividing the search interval in half.

### **4. Non-Increasing Property:**

- **Observation:** The bitwise AND of a range of numbers never increases as more numbers are added to the range.
- **Inspiration:** This property ensures that the binary search will work correctly, as if a range does not satisfy the condition, extending the range to the right will also not satisfy the condition.

---

### Steps to Implement a Similar Solution:

### **1. Identify the Type of Problem:**

- Recognize that the problem involves range queries and requires finding a specific index in a range.

### **2. Consider Suitable Data Structures:**

- Think about data structures that can efficiently handle range queries, such as Segment Trees or Fenwick Trees.

### **3. Analyze the Operations:**

- Consider the properties of the operations involved (e.g., bitwise AND) and how they can be efficiently computed and queried.

### **4. Combine Techniques:**

- Don’t hesitate to combine different techniques and data structures (e.g., Segment Tree with Binary Search) to arrive at an efficient solution.

---

By observing these aspects and drawing inspiration from them, you can be led in the direction of implementing a similar efficient solution for such problems in the future.