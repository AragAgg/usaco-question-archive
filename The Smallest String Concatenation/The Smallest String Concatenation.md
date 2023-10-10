---
Question Link: https://codeforces.com/contest/632/problem/C
Problem Set:
  - "*1700"
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Observation
  - Sorting
  - String
Key Takeaway: "When working for question that require mathematical operations to be performed on a string (lexicographical comparison, character-wise addition, etc…), we could consider the string as a number in base-26.This also helps in proving that a particular relation between two strings hold if they hold for normal base-10 numbers.We could not compare 2 strings of different sizes: for example bx and b? because the ? would determine which comes first."
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
    int n;
    cin >> n;
    
    vector<string>tab(n);
    
    for(auto &i: tab) cin >> i;
    
    sort(all(tab), [](string &a, string &b){return (a+b) < (b+a)});
    
    for(auto &i: tab) cout << i;
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("split"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

### Problem Statement:

The problem is about finding the lexicographically smallest string by concatenating a given list of strings.

### Solution Explanation:

1. **Headers and Macros**:  
    The solution starts with including necessary headers and defining some macros and type definitions for convenience. These are standard practices in competitive programming to speed up the coding process.
2. **Input Reading**:  
    The function `fx()` is the main function that solves the problem. It starts by reading the number of strings `n` and then reads the `n` strings into the `tab` vector.
3. **Sorting Logic**:  
    The core logic of the solution lies in the sorting function:
    
    ```C++
    sort(all(tab), [](string &a, string &b){return (a+b) < (b+a)});
    ```
    
    Here, the strings are sorted based on the concatenated value of two strings. For two strings `a` and `b`, if `a+b` is lexicographically smaller than `b+a`, then `a` should come before `b` in the final concatenated string. This logic ensures that the final concatenated string is lexicographically the smallest possible.
    
4. **Output**:  
    After sorting, the strings are simply concatenated in order and printed.

### Why does this solution work?

The key insight is understanding how two strings should be ordered relative to each other to achieve the lexicographically smallest concatenated string. By comparing the concatenated values of `a+b` and `b+a`, we can determine the correct order of the strings. This approach guarantees that the final concatenated string is the smallest possible.

### Editorial

![[Screenshot_2023-09-01_at_2.49.44_PM.png]]

### Editorial (from: USACO)