---
Question Link: https://codeforces.com/contest/1857/problem/E#
Problem Set:
  - DIV3E
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Math
  - Sorting
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
    
    vi ori(n);
    
    for(auto &i : ori) cin >> i;
    
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    
    vii oriSorted;
    for(int i = 0; i < n; i++){
        oriSorted.pb({ori[i], i});
    }
    
    sort(oriSorted.begin(), oriSorted.end());
    
    long long ans = 0;
    for(auto i: oriSorted){auto item = i.first; ans += abs(item - oriSorted[0].first) +1;}
    
    unordered_map<long long, long long> anss;
    
    anss.insert({oriSorted[0].second, ans});
    
    long long c = 0;
    
    for(int i = 1; i < n; i++){
        ans += abs(i*(c + oriSorted[i].first - oriSorted[i-1].first));
        ans -= abs((n-i)*(c + oriSorted[i].first - oriSorted[i-1].first));
        
        // cout << "got: " << i << " " << ans << endl;
         
        anss.insert({oriSorted[i].second, ans});
    }
    
    for(int i = 0; i < n; i++) cout << anss[i] << " ";
    cout<<endl;
    
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

### Problem Statement:

Given an array of integers, the task is to find the number of operations needed to make all elements of the array equal for each position in the array. An operation consists of choosing two indices `i` and `j` and increasing or decreasing the value of `a[i]` by `a[j]`.

### Solution Overview:

The solution involves sorting the array and then calculating the number of operations needed for each position in the original array.

### Code Explanation:

1. **Type Definitions and Macros**:
    - The solution starts with defining several type aliases and macros for convenience. These help in making the code more readable and concise.
2. **Function** `**fx**`:
    - This function contains the main logic for solving the problem.
    - First, the size of the array `n` is read.
    - If `n` is 1, the answer is directly 1 since no operations are needed.
    - The array `ori` is read, which contains the original integers.
    - `oriSorted` is a vector of pairs where each pair contains an integer from `ori` and its original index. This vector is then sorted based on the integers.
    - The variable `ans` is initialized to store the cumulative number of operations needed.
    - The unordered map `anss` is used to store the number of operations needed for each position in the original array.
    - The main logic involves iterating through the sorted array and calculating the number of operations needed for each position. This is done by considering the difference between consecutive elements in the sorted array and adjusting the cumulative count of operations.
    - Finally, the number of operations for each position in the original array is printed.
3. **Main Function**:
    - The main function reads the number of test cases and then calls the `fx` function for each test case.

### Key Logic:

The main idea behind the solution is to sort the array and then calculate the number of operations needed based on the differences between consecutive elements in the sorted array. By keeping track of the original indices, the solution can determine the number of operations needed for each position in the original array.

The logic for calculating the number of operations involves considering the cumulative difference between consecutive elements in the sorted array and adjusting the count based on the number of elements before and after the current position.

In summary, the solution sorts the array, calculates the cumulative number of operations needed, and then determines the number of operations for each position in the original array.

  

### Editorial

![[Screenshot_2023-08-09_at_6.23.43_PM.png]]