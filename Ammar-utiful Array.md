---
Question Link: https://codeforces.com/gym/104468/problem/H
Problem Set:
  - Code Forces
  - ICPC Regional
  - Uncategorised
Last edited time: 2023-10-10T13:13
Status: Skipped for now
tags:
  - Binary-Search
  - Implementation
  - Problem-Decomposition
What's up: Problem part of ICPC Regional, Syria. The judge on CF says WA on TC9, but won’t reveal the test data. Couldn’t find Editorial, ChatGPT says it’s correct.
Key Takeaway: "Lazy Updates is a nice strategy. (maybe try delaying updates till the end of code termination) 😂 "
---
### Solution (NOT AC)

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
unordered_map<int, vector<ll>>m;
ll globalOffset = 0;
unordered_map<int, ll>localOffset;

void fx() {
    cin >> N;
    vector<ll> a(N, 0), c(N, 0);
    
    for(auto &i: a) cin >> i;
    for(auto &i: c) cin >> i;
    
    for(int i = 0; i < N; i++) m[c[i]].pb(a[i]);
    
    for(auto &i: m){
        ll offset = 0;
        for(auto &item : i.s){
            offset += item;
            item = offset;
        }
    }
    
    int q;
    cin >> q;
    
    while(q--){
        ll type, col, x;
        cin >> type >> col >> x;
        
        if(type == 1){
            globalOffset += x;
            localOffset[col] += x;
        }else{
            const auto &list = m[col];
            int lo = 0;
            int hi = list.size()-1;
            
            while(lo < hi){
                int mid = lo + (hi - lo + 1)/2;
                
                if(list[mid] + globalOffset*(mid+1) - localOffset[col]*(mid+1) <= x) lo = mid;
                else hi = mid -1;
            }
            
            cout << ((list[lo] + globalOffset*(lo+1) - localOffset[col]*(lo+1) <= x)?(lo+1):0) << endl;
            
        }
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

The provided solution employs a combination of **prefix sums**, **binary search**, and **offset adjustments** to efficiently answer the queries in the problem "H. Ammar-utiful Array". Let's delve into the core logic and key observations that make this solution work.

### Core Logic

1. **Storing Prefix Sums**:
    - The solution first reads the arrays `a` and `c` and then constructs a map `m` where each color `c[i]` maps to a vector of integers `a[i]` that have that color.
    - For each color, it calculates the prefix sum of its associated values and stores it back in the map. This allows for O(1) retrieval of the sum of any prefix of the values of a particular color.
2. **Handling Queries**:
    - The solution uses two offset variables: `globalOffset` and `localOffset`. The `globalOffset` is used to keep track of global increments (type 1 queries) to all elements, while `localOffset` keeps track of additional increments for specific colors.
    - For type 1 queries (`1 Col X`), it adds `X` to `globalOffset` and subtracts `X` from `localOffset[Col]`. This ensures that when we add `globalOffset` to all elements, the elements of color `Col` are not affected because the addition is nullified by the subtraction of `localOffset[Col]`.
    - For type 2 queries (`2 Col Y`), it performs a binary search to find the longest prefix of values of color `Col` that satisfies the condition of being an "Ammar-utiful Array". It adjusts the prefix sums using `globalOffset` and `localOffset[Col]` to account for the increments performed by type 1 queries.

### Observations and Insights

- **Binary Search**: The binary search is used to efficiently find the longest prefix that satisfies the condition. It searches for the highest index `mid` such that the adjusted prefix sum is less than or equal to `Y`. This is much more efficient than a linear search, especially considering the problem's constraints.
- **Offset Adjustments**: The use of `globalOffset` and `localOffset` is a clever way to handle type 1 queries without having to update all elements or all prefix sums. This ensures that type 1 queries are handled in O(1) time, which is crucial for the solution's efficiency.
- **Prefix Sums**: Storing the prefix sums of the values of each color allows the solution to retrieve the sum of any prefix in O(1) time, which is essential for the binary search in type 2 queries.

### Key Takeaways

- **Efficiency**: Always look for more efficient algorithms (like binary search) to solve the problem within the given constraints.
- **Data Organization**: Organizing data in a way that allows for efficient retrieval and modification (like using maps and prefix sums) is crucial for solving problems with complex queries.
- **Lazy Updates**: The concept of performing updates only when necessary (like using offsets to adjust values only when queried) is a valuable strategy in handling update queries without compromising time complexity.

This solution beautifully blends various algorithms and strategies to solve a problem that involves both updates and queries, providing a great example of how to handle such problems efficiently.