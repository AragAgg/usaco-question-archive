---
Question Link: https://codeforces.com/contest/1870/problem/B
Problem Set:
  - Code Forces
  - DIV2B
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Bitwise
  - Greedy
  - Math
  - Observation
Key Takeaway: "(A | B) ≥ max(A, B) not considering the sign bit.Whenever you have a question where XOR is applied on an array of number and it is an optimisation problem, consider factoring in the parity of the length of the array.Maybe: A bitmask question is not always hard?"
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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    
    for(auto &i: a) cin >> i;
    
    int del = 0;
    for(auto &i: b){ cin >> i; del = del | i;}
    
    int minimum = 0;
    int maximum = 0;
    
    if(n%2){
        //its odd..
        for(auto &i: a){
            maximum = maximum ^ (i | del);
            minimum = minimum ^ i;
        }
    }else{
        for(auto &i: a){
            minimum = minimum ^ (i | del);
            maximum = maximum ^ i;
        }
    }
    
    
    cout << minimum << " " << maximum << endl;
     
    
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

### Editorial

![[Screenshot_2023-09-19_at_9.21.25_PM.png]]

  

### Solution Explanation

### Core Idea:

1. **Bitwise OR of all elements in** `**b**`:  
    The code calculates the bitwise OR of all elements of array `b` and stores it in the variable `del`. This is because, to maximize the effect of array `b` on array `a`, we can OR all elements of `b` and then apply this result to `a`.
2. **Odd vs Even Length of Array** `**a**`:  
    The behavior of the solution changes based on whether the length of array `a` is odd or even. This distinction is crucial to determining the minimum and maximum values of \(x\).

### Key Observations:

1. **Effect of Odd Length**:  
    If the length of array `a` is odd, the maximum value of \(x\) is obtained by ORing each element of `a` with `del` and then XORing the results. The minimum value is simply the XOR of the original elements of `a`.
2. **Effect of Even Length**:  
    If the length of array `a` is even, the roles reverse. The minimum value of \(x\) is obtained by ORing each element of `a` with `del` and then XORing the results. The maximum value is the XOR of the original elements of `a`.
3. **Efficiency**:  
    The solution is efficient because it avoids nested loops. Instead of iterating through both arrays `a` and `b` for each operation, it calculates the combined effect of `b` on `a` in a single pass.

### Key Takeaways:

- The bitwise OR of all elements in `b` gives the maximum possible effect that `b` can have on `a`.
- The length of array `a` (odd vs even) plays a crucial role in determining the minimum and maximum values of \(x\).
- Understanding the properties of bitwise operations (especially XOR and OR) is essential to solving this problem efficiently.