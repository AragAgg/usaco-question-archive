---
Question Link: https://codeforces.com/contest/1867/problem/E1
Problem Set:
  - DIV2E
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Constructive
  - Interactive
  - Math
  - Observation
What's up: Solved by observation. (Staring at it for long enough worked out pretty well)
Key Takeaway: "a%b < b "
---
### Solution (AC) [bit messy, could be refactored with helper functions]

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
    int n, k;
    cin >> n >> k;
    
    int ans = 0;
    int counter = 1;
    
    if(n%k == 0){
        while(counter < n){
            cout << "? " << counter << endl << endl;
            
            int res;
            cin >> res;
            
            if(res == -1) exit(1);
            
            ans = ans^res;
            
            counter += k;
        }
        
        cout << "! " << ans << endl << endl;
        return;
    }
    
    int times = max(n/k -1, 0);
    int till = n - times*k;
    
    while(times){
        int res;
        
        cout << "? " << (n+1 - (times--)*k) << endl << endl;
        cin >> res;
        
        if(res == -1) exit(2);
        
        ans = ans^res;
    }
    
    for(int i = 1; i <= till-k+1; i++){
        int res;
        
        cout << "? " << i << endl << endl;
        cin >> res;
        
        if(res == -1) exit(3);
        
        ans = ans^res;
    }
    
    cout << "! " << ans << endl << endl; 
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

### Solution Explanation (Possibly with minor oversight)

### Problem Statement:

Given an array of size `n` and a number `k`, you can query any index `i` of the array and get the XOR of all elements from index `i` to `i+k-1` (both inclusive). If `i+k-1` exceeds `n`, then the XOR will only be taken up to the `n`th element. The goal is to determine the XOR of the entire array using the minimum number of queries (upto a max of 100).

### Observations/Insights:

1. **XOR Properties**: The XOR operation has some unique properties that the solution leverages:
    - `A XOR A = 0`: XORing a number with itself results in 0.
    - `A XOR 0 = A`: XORing a number with 0 doesn't change the number.
    - `A XOR B XOR A = B`: If you XOR a number A with another number B and then XOR the result with A again, you get back B. This property is used to cancel out overlapping elements in the queries.
2. **Full Overlaps**: If `n` is divisible by `k`, then you can query the array at intervals of `k` without any overlap. This means you can directly XOR the results of these queries to get the XOR of the entire array.
3. **Partial Overlaps**: If `n` is not divisible by `k`, then there will be overlaps when querying the array. The solution handles this by querying the last `n mod k` elements separately and then querying the rest of the array at intervals of `k`. Due to the properties of XOR, the overlapping elements will cancel out, leaving the XOR of the entire array.

### Working of the Solution:

1. **Case when n is divisible by k**:
    - Start querying from the 1st element and keep jumping `k` elements until you reach the end of the array.
    - XOR all the results of these queries to get the XOR of the entire array.
2. **Case when n is not divisible by k**:
    - Calculate the number of full `k`sized segments in the array (`times = n/k - 1`).
    - Calculate the size of the last segment which is not of size `k` (`till = n - times*k`).
    - Query the last `times` segments of size `k` and XOR the results.
    - Query the first `till-k+1` elements one by one and XOR the results.
    - The XOR of the results from the above two steps will give the XOR of the entire array.

### Key Takeaways:

1. **XOR Properties**: Understanding the properties of XOR is crucial to solving this problem. The ability to cancel out overlapping elements using XOR is the main insight.
2. **Segmentation**: Dividing the array into segments and handling full and partial overlaps separately simplifies the problem.
3. **Efficiency**: The solution is efficient because it minimizes the number of queries by leveraging the properties of XOR and by querying segments of the array instead of individual elements.

Remember, the main idea behind the solution is to use the properties of XOR to cancel out overlapping elements in the queries and to handle full and partial overlaps separately to minimize the number of queries.

  

### Editorial

NOT YET OUT!