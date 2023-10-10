---
Question Link: https://codeforces.com/contest/1859/problem/A
Problem Set:
  - DIV2A
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Constructive
  - Math
Key Takeaway: "Trivial: The largest number among a list of numbers is not a divisor of any of the other numbers."
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
    int m = INT_MIN;
    
    umii tab;
    vi r;
    
    int N = n;
    
    while(N--){
        int t;
        cin >> t;
        
        r.pb(t);
        
        m = max(m, t);
        
        tab[t]++;
        
    }
    
    
    if(tab[m] == n){
        cout << -1 << endl;
        return;
    }
    
    cout << n-tab[m] << " " << tab[m] << endl;
   
    
    for(auto &i: r){
        if(i == m) continue;
        
        cout << i << " ";
    }
    
    cout << endl;
    
    for(int i = 0; i < tab[m]; i++){
        cout << m << " ";
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

  

### Solution Ideas

### Approach 1: Prime Factorization

1. **Observation**: If an element in array \(a\) is not a prime number, then it has at least one prime divisor. If we place this element in array \(b\), then we can place its prime divisor in array \(c\). This ensures that no element in \(c\) divides any element in \(b\).
2. **Steps**:
    - Find the smallest non-prime number in array \(a\) and place it in array \(b\).
    - Find its smallest prime divisor and place it in array \(c\).
    - For the remaining elements in \(a\):
        - If they are divisible by the prime divisor, place them in \(b\).
        - Otherwise, place them in \(c\).
3. **Edge Case**: If all numbers in \(a\) are prime, then it's impossible to form arrays \(b\) and \(c\) as per the given conditions. In this case, output \(-1\).

### Approach 2: Based on Even and Odd Numbers

1. **Observation**: 2 is the smallest prime number and only even prime. If there's an even number in array \(a\) other than 2, we can place it in \(b\) and place 2 in \(c\).
2. **Steps**:
    - If there's an even number in \(a\) (other than 2), place it in \(b\) and place 2 in \(c\).
    - For the remaining elements in \(a\):
        - If they are even, place them in \(b\).
        - Otherwise, place them in \(c\).
3. **Edge Case**: If all numbers in \(a\) are odd primes, then it's impossible to form arrays \(b\) and \(c\). In this case, output \(-1\).

### Approach 3: Based on Maximum Element

1. **Observation**: If we place the maximum element of \(a\) in \(b\), then any number which is not a divisor of this maximum element can be placed in \(c\).
2. **Steps**:
    - Place the maximum element of \(a\) in \(b\).
    - For the remaining elements in \(a\):
        - If they are not divisors of the maximum element, place them in \(c\).
        - Otherwise, place them in \(b\).
3. **Edge Case**: If all numbers in \(a\) are the same, then it's impossible to form arrays \(b\) and \(c\). In this case, output \(-1\).

All three approaches have their own merits. The first approach is more mathematical, while the second and third approaches are more intuitive. Depending on the given input and constraints, one might prefer one approach over the others.