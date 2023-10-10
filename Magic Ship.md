---
Question Link: https://codeforces.com/problemset/problem/1117/C
Problem Set:
  - "*1900"
  - Code Forces
  - DIV2C
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Binary-Search
Key Takeaway: Write the most basis code that just makes the cut.
---
### Solution History

- Code 1
    
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
    
    ll xa, ya, xb, yb;
    string s;
    
    ll alphax = 0, alphay = 0;
    
    void transform(ll &x, ll &y, int days){
        for(int i = 0; i < days; i++){
            if(s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
            else if(s[i] == 'L') x--;
            else x++;
        }
    }
    
    bool isViable(ll days){
        ll x = xa;
        ll y = ya;
        
        int cCycles = days/s.size();
        
        x += alphax*cCycles;
        y += alphay*cCycles;
        
        transform(x, y, days%s.size());
        
        ll delta = abs(xb - x) + abs(yb - y);
        
        return (delta <= days);
    }
    
    void fx() {
        // Functionality for fx
        cin >> xa >> ya >> xb >> yb;
        int n;
        cin >> n >> s;
        
        transform(alphax, alphay, n);
        
        ll lo = 0;
        ll hi = 1e18+1000;
        
        while(lo < hi){
            ll mid = lo + (hi - lo)/2;
            
            if(isViable(mid)) hi = mid;
            else lo = mid +1;
        }
        
        cout << ((lo == 1e18+1000)?-1:lo) << endl;
        
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

ll xa, ya, xb, yb;
string s;

ll alphax = 0, alphay = 0;

void transform(ll &x, ll &y, int days){
    for(int i = 0; i < days; i++){
        if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        else if(s[i] == 'L') x--;
        else x++;
    }
}

bool isViable(ll days){
    ll x = xa;
    ll y = ya;
    
    ll cCycles = days/s.size();
    
    x += alphax*cCycles;
    y += alphay*cCycles;
    
    transform(x, y, days%s.size());
    
    ll delta = abs(xb - x) + abs(yb - y);
    
    return (delta <= days);
}

void fx() {
    // Functionality for fx
    cin >> xa >> ya >> xb >> yb;
    int n;
    cin >> n >> s;
    
    transform(alphax, alphay, n);
    
    ll lo = 0;
    ll hi = 1e18+100;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        
        if(isViable(mid)) hi = mid;
        else lo = mid +1;
    }
    
    cout << ((lo == 1e18+100)?-1:lo) << endl;
    
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

### Core Logic

1. **Preprocessing Movements**: Calculate the net movement of the ship after one full cycle of the wind pattern. This is stored in `alphax` and `alphay`.
2. **Transform Function**: A function that simulates the ship's movement for a given number of days, adjusting its coordinates according to the wind pattern.
3. **Viability Check (isViable Function)**: A function that checks whether it's possible to reach the destination within a specified number of days. It considers the ship's movement due to full cycles of the wind pattern and additional days, and checks whether the remaining distance to the destination can be covered within the available days.
4. **Binary Search**: The algorithm employs binary search to find the minimum number of days required to reach the destination, using the viability check function to guide the search.

### Observations and Insights

- **Periodic Wind Pattern**: The wind pattern is periodic, meaning after every `n` days (length of string `s`), it repeats. This allows us to calculate the net movement due to the wind for one full cycle and use it for any multiple of `n` days.
- **Manhattan Distance**: The problem essentially boils down to minimizing the Manhattan distance between the ship and its destination, given the constraints of the wind. The Manhattan distance is the sum of the horizontal and vertical distances, which can be covered independently.
- **Binary Search**: The search space for the minimum number of days is large (up to $(10^{18}$)). A linear search is impractical, but the problem has a monotonic property: if it's possible to reach the destination in `d` days, it's also possible in `d+1` days. This property allows binary search to be applied effectively.

### Key Takeaways

- **Leveraging Monotonic Properties**: The ability to recognize and leverage the monotonic property of a problem to apply binary search is a valuable skill in algorithmic problem solving.
- **Effective Preprocessing**: Calculating the net movement due to one full cycle of the wind pattern and using it for simulation significantly optimizes the solution.
- **Checking Viability**: Developing a function to check the viability of a solution (whether the destination can be reached in a specified number of days) is crucial for guiding the binary search.
- **Handling Large Search Spaces**: Binary search provides a practical approach to handle large search spaces, reducing the time complexity from linear to logarithmic.

### Explanation of Code

- The `transform` function adjusts the ship's coordinates according to the wind pattern for a specified number of days.
- The `isViable` function checks whether the destination can be reached within a specified number of days, considering both the ship's voluntary movement and the wind's influence.
- The binary search is implemented in the `while(lo < hi)` loop, where `lo` and `hi` define the current search space for the minimum number of days. The mid-point `mid` is checked for viability, and the search space is adjusted accordingly.
- Finally, the minimum number of days (`lo`) is output. If `lo` exceeds \(10^{18}\), it's considered impossible to reach the destination, and `1` is output.

This problem beautifully blends concepts from geometry (Manhattan distance), algorithmic optimization (binary search), and simulation, providing a comprehensive exercise in algorithmic problem-solving.

### Solution Inspiration

### 1. Bounded Search Space

- **Observation**: The problem is asking for the "minimum number of days" — a scalar value within a certain range (0 to a very large number).
- **Insight**: Whenever you're asked to find a minimum or maximum scalar value, and especially when the search space is large, consider whether binary search could be applicable.

### 2. Monotonic Property

- **Observation**: If the ship can reach its destination in `d` days, it can also reach it in `d+1`, `d+2`, ... days by simply staying in place after reaching the destination.
- **Insight**: This monotonic property (feasibility is non-decreasing with the number of days) is a strong indicator that binary search can be effectively applied.

### 3. Periodic Behavior

- **Observation**: The wind pattern repeats periodically.
- **Insight**: Precompute the net effect of one cycle and use it to efficiently simulate the ship's movement over multiple cycles. This avoids simulating each day individually and reduces computational complexity.

### 4. Manhattan Distance

- **Observation**: The ship moves in a grid (Cartesian plane) and needs to minimize the sum of horizontal and vertical distances to the destination.
- **Insight**: Recognize that this is a Manhattan distance problem, where horizontal and vertical movements are independent and can be considered separately. This can simplify the simulation and viability check.

### 5. Simulation and Viability

- **Observation**: The ship's movement is influenced by both its own actions and the wind, and it's not immediately clear how they interact over multiple days.
- **Insight**: Develop a function to simulate the ship's movement over a given number of days and another to check whether the destination can be reached in that time. These functions allow you to abstract away the details of the simulation and focus on the binary search logic.

### 6. Problem Decomposition

- **Observation**: The problem involves both simulating the ship's movement and minimizing the number of days to reach the destination.
- **Insight**: Decompose the problem into smaller, manageable sub-problems: (a) simulating movement, (b) checking viability, and (c) minimizing days. Tackle each sub-problem independently and combine them to form the complete solution.

### 7. Efficient Viability Check

- **Observation**: The viability check needs to be efficient since it will be called multiple times during the binary search.
- **Insight**: Ensure that the viability check function is as optimized as possible. Precompute as much information as possible (like the net movement due to the wind over one cycle) to avoid redundant calculations.

### 8. Handling Edge Cases

- **Observation**: The solution needs to handle cases where reaching the destination is impossible.
- **Insight**: Ensure that your binary search and viability check can handle and correctly identify cases where the destination cannot be reached. This often involves carefully managing the boundaries of your search space and ensuring that your viability check returns false in these cases.

### Conclusion

These observational insights and strategies are not only applicable to this problem but can also be generalized and applied to a wide range of algorithmic problems. Recognizing patterns, properties, and potential simplifications in a problem is a crucial skill in competitive programming and algorithmic problem-solving. Practice identifying these aspects in various problems to enhance your problem-solving skills and develop efficient solutions in future contests.