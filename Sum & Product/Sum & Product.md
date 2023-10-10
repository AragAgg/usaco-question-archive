---
Question Link: https://codeforces.com/contest/1857/problem/F
Problem Set:
  - DIV3F
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Case-Work
  - Edge-Cases
  - Math
  - Quadratic
  - Structure
Key Takeaway: If two equations are Simultaneous Linear Equations, check if they could be transformed into a Quadratic Equation.
---
### Solution

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
    
    map<long long, long long> tab;
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        
        tab[t]++;
    }
    
    vector<long long> res;
    
    int q; cin >> q;
    
    long long c = 0;
    
    while(q--){
        long long x, y;
        cin >> x >> y;
        
        long long ans = 0;
        
        if(x*x - 4*y < 0 or sqrt(x*x - 4*y) != ceil(sqrt(x*x - 4*y))) ans = 0;
        else if(x*x - 4*y == 0 ){
            int r1 = (x - sqrt(x*x - 4*y))/2;
            
            int c1 = x - r1;
            
            if(r1 == c1) ans = (tab[r1]*(c+tab[c1]-1))/2;
            else ans = tab[r1] * (c+tab[c1]);
        }else {
            int r1 = (x - sqrt(x*x - 4*y))/2;
            
            int c1 = x - r1;
            
            int r2 = (x + sqrt(x*x - 4*y))/2;
            
            int c2 = x - r2;
            
            if(r1 == c2) ans = (tab[r1]*(c+tab[c1])); //<- just fixed
            else{
                if(r1 == c1) ans += (tab[r1]*(c+tab[c1]-1))/2;
                else ans += tab[r1]*(c+tab[c1]);
                
                if(r2 == c2) ans += (tab[r2]*(c+tab[c2]-1))/2;
                else ans += tab[r2]*(c+tab[c2]);
            }
        }
        
        res.pb(ans);
    }
    
    for(auto item : res) cout << item << " ";
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

### Explanation

---

**Problem Description**

This problem is math-based and requires some prior knowledge about the equations of parabolas.

Given two numbers `x` and `y`, the problem asks to find how many pairs of numbers `a` and `b` are there such that:

1. `a + b = x`
2. `a * b = y`

The question itself is derived from a quadratic equation in the form of:

```Plain
ax^2 + bx + c = 0
```

The solutions for `x` in the above equation are:

```Plain
x1 = (-b + sqrt(b^2-4ac)) / 2a
x2 = (-b - sqrt(b^2-4ac)) / 2a
```

If we rearrange `a + b = x` and `a * b = y`, we can derive:

```Plain
x1 + x2 = -b / a = x
x1 * x2 = c / a = y
```

From the above, you can conclude:

```Plain
b = -x
c = y
```

So,

```Plain
b^2 - 4ac = x^2 - 4y
```

**Solution Breakdown**

1. **Input and Data Collection:**
    - The first part of the solution reads in the number of numbers `n` and then the actual list of numbers. It uses a map called `tab` to store the frequency of each number.
2. **Quadratic Analysis:**
    - For each query, the program calculates the value of `x^2 - 4y`.
    - If `x^2 - 4y < 0` or the square root of `x^2 - 4y` is not an integer, the answer is 0 because the quadratic equation does not have real solutions.
    - Otherwise, there are 2 possible values for `a` and `b`. The program calculates both possible pairs using the formulas for the roots of a quadratic equation and then checks the number of occurrences of these numbers in the input list to calculate the number of pairs that satisfy the conditions.
    - The special case when `x^2 - 4y = 0` means the quadratic equation has a double root, i.e., both roots are the same.
3. **Output:**
    - For each query, the program appends the result to the `res` vector, which is later printed.

The logic for counting the pairs uses the formula for combinations and permutations based on the problem requirements.

In summary, this problem transforms a combinatorics problem into a math-based quadratic equation problem and uses the properties of quadratic equations to deduce the answer.

### Editorial

![[Screenshot_2023-08-09_at_6.32.58_PM.png]]