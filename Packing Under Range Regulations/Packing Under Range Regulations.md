---
Question Link: https://atcoder.jp/contests/abc214/tasks/abc214_e
Problem Set:
  - AtCoder
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Coordinate-Compression
  - Implementation
  - Sorting
  - Structure
Key Takeaway: "Priority Queue + Set/Map is a powerful duo.Efficient Operations: Combining the two allows for efficient operations on both ends. For instance, you can quickly access the smallest/largest element with the priority queue while ensuring uniqueness or associating additional data with the map/set.Flexibility: The combination can be adapted to various problems. For instance, you might use a priority queue of pairs where the first element is a priority and the second is an identifier, and a map to link the identifier to additional data."
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
    
    map<int, vi>tab;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        
        tab[a].pb(b);
        
        tab[b+1];
    }
    
    int prev = 0;
    
    priority_queue<int, vi, greater<int>>pq;
    
    for(auto &loc: tab){
        
        int curr = loc.f;
        int removeElems = curr - prev;
        while(removeElems-- and pq.size()) pq.pop();
        
        if(pq.size() and pq.top() < curr){
            no();
            return;
        }
        
        for(auto &i: loc.s){
            pq.push(i);
        }
        
        prev = curr;
    }
    
    yes();
    
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

## Problem Statement

The problem is from AtCoder Beginner Contest 214 and is titled "Packing Under Range Regulations."

## Problem Description

- You are given T test cases.
- For each test case:
    - There are 10^9 boxes numbered from 1 to 10^9.
    - There are N balls numbered from 1 to N.
    - Each box can contain at most one ball.
    - For each ball i, there are two numbers L_i and R_i such that the ball i must be placed in a box numbered between L_i and R_i (inclusive).
    - The task is to determine if it's possible to place all N balls in the boxes such that the above condition is met.

## Constraints

- 1 <= T <= 2 * 10^5
- 1 <= N <= 2 * 10^5
- 1 <= L_i <= R_i <= 10^9
- The sum of N across all test cases is at most 2 * 10^5.

## Solution Explanation

The solution uses a greedy approach combined with a priority queue to solve the problem.

1. **Mapping Ranges**: The solution first creates a map where the keys are the starting points of the ranges (i.e., L_i) and the values are vectors containing the ending points of the ranges (i.e., R_i). This map is used to keep track of all the balls that can be placed starting from a particular box.
2. **Priority Queue**: A priority queue is used to keep track of the ending points of the ranges. The priority queue is set up in such a way that the smallest ending point is at the top.
3. **Iterating through the Map**: The solution then iterates through the map. For each key (i.e., starting point):
    - It checks how many boxes have been skipped since the last key. For each skipped box, it pops an element from the priority queue.
    - If the top of the priority queue is smaller than the current key, it means that a ball cannot be placed in its range, and the solution returns "No."
    - Otherwise, for each ending point in the current key's value (i.e., vector), it pushes the ending point into the priority queue.
4. **Final Check**: If the solution hasn't returned "No" by the end of the iteration, it returns "Yes."

## Key Takeaways

1. **Greedy Approach**: The solution uses a greedy approach by always trying to place the balls in the earliest possible boxes.
2. **Priority Queue**: The priority queue is crucial for this solution as it allows for efficiently finding the smallest ending point and checking if a ball can be placed in its range.
3. **Mapping Ranges**: The map helps in organizing the data and understanding which balls can be placed starting from a particular box.

## Observations on the Implementation

- The use of the map (tab) to organize the data is a smart choice as it allows for efficient iteration through the starting points.
- The priority queue (pq) is set up to have the smallest element at the top, which is crucial for the greedy approach used in the solution.

  

### Editorial

![[Screenshot_2023-09-14_at_12.48.56_AM.png]]