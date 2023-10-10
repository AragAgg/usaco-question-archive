---
Question Link: https://codeforces.com/contest/1878/problem/C
Problem Set:
  - Code Forces
  - DIV3C
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Math
  - Observation
Key Takeaway: "The maximum sum of k distinct numbers from 1 to n is is : (n*(n+1))/2 - ((n-k)*(n-k+1))/2)"
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
    ll n, k, x;
    
    cin >> n >> k >> x;
    
    if(((k*(k+1))/2 <= x) and ((n*(n+1))/2 - ((n-k)*(n-k+1))/2) >= x) yes();
    else no();
    
    
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

### Explaination

Observations:

1. Minimum Possible Sum: The minimum possible sum of k distinct numbers between 1 and n is the sum of the first k natural numbers, which is calculated using the formula (k*(k+1))/2.
2. Maximum Possible Sum: The maximum possible sum of k distinct numbers between 1 and n is the sum of the last k natural numbers in the range, which is calculated using the formula (n*(n+1))/2 - ((n-k)*(n-k+1))/2.

Core Logic:

- The code first checks whether the desired sum x is at least the minimum possible sum and at most the maximum possible sum for k numbers in the range 1 to n.
- If x falls within this range, it is possible to select k distinct numbers that sum up to x, and the output is "YES".
- Otherwise, it is impossible to select such numbers, and the output is "NO".

Code Explanation:

- The function fx() is called for each test case.
- It takes three inputs n, k, and x representing the range, the number of elements to choose, and the desired sum, respectively.
- It checks the two conditions explained above:
    - ((k*(k+1))/2 <= x) checks whether x is at least the minimum possible sum.
    - ((n*(n+1))/2 - ((n-k)*(n-k+1))/2) >= x) checks whether x is at most the maximum possible sum.
- If both conditions are true, it outputs "YES"; otherwise, it outputs "NO".

Key Takeaways:

- Understanding the mathematical properties and constraints of the problem is crucial.
- The minimum and maximum possible sums of k distinct numbers in a range can be calculated using simple mathematical formulas.
- Checking whether the desired sum falls within the range of the minimum and maximum possible sums provides a quick and efficient solution to the problem.

This solution is efficient and concise, leveraging mathematical insights to solve the problem in constant time for each test case, making it highly scalable for large inputs.