---
Question Link: https://codeforces.com/contest/1870/problem/C
Problem Set:
  - Code Forces
  - DIV2C
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Binary-Search
  - Dynamic-Programming
  - Implementation
  - Math
  - Structure
What's up: Really interesting question. Nice Implementation.
Key Takeaway: Keep the problem constraints in the back of the mind when forming a solution. It acts as a tracer bullet.REUSE pointers to upper_bounds and lower_bounds on ordered sets and mapsIterative Optimisation + Iterative Elimination is a potentially very powerful technique.
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
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for(auto &i: a) cin >> i;
    
    map<ll, ll>forwards;
    
    for(ll i = 0; i < n; i++){
        if(forwards.count(a[i])) continue;
        if(forwards.upper_bound(a[i]) != forwards.end()){
            
            forwards[a[i]] = (*forwards.upper_bound(a[i])).s;

        }else{
            // bestYet = i;
            // bestYetNum = a[i];
            
            forwards[a[i]] = i;
        }
    }
    
    
    
    map<ll, ll>backwards;
    for(ll i = n-1; i >= 0; i--){
        if(backwards.count(a[i])) continue;
        if(backwards.upper_bound(a[i]) != backwards.end()){

            backwards[a[i]] = (*backwards.upper_bound(a[i])).s;

        }else{
            // bestYet = i;
            // bestYetNum = a[i];
            
            backwards[a[i]] = i;
        }
    }
    
    for(ll i = 1; i <= k; i++){
        if(!forwards.count(i)){
            cout << 0 << " ";
        }else{
            cout << ((backwards[i] - forwards[i] + 1)*2) << " ";
        }
        
        
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

### Editorial [boring solution, mine’s better (IMO)]

![[Screenshot_2023-09-19_at_9.36.56_PM.png]]

  

### Solution Explanation

### Problem Recap:

Given an array `a` of size `n` with elements ranging from 1 to `k`, we need to find the smallest rectangle in a 2D array `b` of size `n x n` that contains all cells of each color. The 2D array `b` is defined such that `b[i][j] = min(a[i], a[j])`.

### Observations:

1. **Single Occurrence Colors**: If a color appears only once in the array `a`, then the rectangle for that color in `b` will be a single cell. Hence, the sum of its width and height will be 2 (1 for width + 1 for height).
2. **Multiple Occurrence Colors**: If a color appears multiple times, the rectangle will span from the first occurrence to the last occurrence of that color. This is because any row or column between the first and last occurrence will have that color when paired with either the first or last occurrence.

### Core Logic:

1. **Forward Traversal**: Traverse the array `a` from the start to the end. For each number, if it hasn't been seen before, check if there's a larger number that has been seen (using `upper_bound`). If there is, set the current number's position to that larger number's position. Otherwise, set it to the current index. This gives us the starting position of the rectangle for each number.
2. **Backward Traversal**: Traverse the array `a` from the end to the start. This is similar to the forward traversal but gives us the ending position of the rectangle for each number.
3. **Calculate Rectangle Size**: For each number from 1 to `k`, if it doesn't exist in the `forwards` map, its rectangle size is 0. Otherwise, the size is `(backwards[i] - forwards[i] + 1) * 2`.

### Key Takeaways:

1. **Efficient Traversal**: Instead of brute-forcing to find the first and last occurrence of each number, the solution uses a single forward and backward traversal to determine the positions.
2. **Usage of Maps**: Maps (`forwards` and `backwards`) are used to store the first and last occurrence of each number. The `upper_bound` function helps in determining if a larger number has been seen before.
3. **Rectangle Calculation**: Once the start and end positions are known, calculating the rectangle's size is straightforward.

In summary, this problem tests the ability to make observations about the structure of the problem and then implement an efficient solution using data structures like maps. The key insight is understanding how the 2D array `b` is formed and how to efficiently find the smallest rectangle for each color.

  

### Solution Inspiration

1. **Nature of the 2D Array** `**b**`:
    - The first observation is understanding how the 2D array `b` is constructed. Given that `b[i][j] = min(a[i], a[j])`, it's clear that the value in `b` at any position depends on two values from the array `a`.
    - This means that if you know the positions of a particular number in `a`, you can determine its positions in `b`.
2. **Rectangle Formation**:
    - The next observation is about the formation of rectangles in `b`. If a number `x` appears at positions `p` and `q` in `a`, then in `b`, all positions from `p` to `q` will have the number `x` when paired with either `p` or `q`.
    - This is the crux of the problem. It means that to find the rectangle for a number, you only need to know its first and last occurrence in `a`.
3. **Efficiency**:
    - Brute force would involve checking every possible rectangle in `b` for each number, which is highly inefficient.
    - The observation here is that you don't need to construct `b` at all. By knowing the first and last occurrence of each number in `a`, you can deduce the size of its rectangle in `b`.
4. **Handling Single Occurrences**:
    - If a number appears only once in `a`, its rectangle in `b` is just that single cell. This is a straightforward observation but crucial for handling edge cases.
5. **Usage of Data Structures**:
    
    - Given that you need to track the first and last occurrence of each number, a map is a natural choice. It allows for efficient lookups and updates.
    
    - The use of `upper_bound` is a bit more nuanced. It's inspired by the need to check if there's a larger number that has been seen before. This is a classic use-case for ordered maps or sets.
6. **Direction of Traversal**:
    - The forward traversal helps in finding the starting position of the rectangle for each number.
    - The backward traversal helps in finding the ending position. This dual traversal is inspired by the need to find both the start and end of the rectangle efficiently.

### Tips for Future Problems:

1. **Understand the Problem Deeply**: Before jumping into coding, ensure you understand the problem's nuances. In this case, understanding how `b` is formed was crucial.
2. **Visualize**: Draw out examples. Visualizing how the 2D array `b` looks for different arrays `a` can give insights into patterns.

1. **Optimize Iteratively**: Start with a brute force approach, then look for optimizations. In this problem, realizing that you don't need to construct `b` was a significant optimization.

1. **Leverage Data Structures**: Think about which data structures can help. Maps and sets are often useful when dealing with unique elements and their properties.
2. **Test Edge Cases**: Always consider edge cases. In this problem, numbers that appear only once in `a` were an important edge case to consider.

In essence, the solution to this problem was inspired by a deep understanding of the problem statement, visualization, and the efficient use of data structures. Observing patterns and iterating on solutions is key to tackling such problems in the future.