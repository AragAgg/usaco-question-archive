---
Question Link: https://codeforces.com/contest/1866/problem/G
Problem Set:
  - "*2100"
  - Code Forces
  - ICPC Regional
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Binary-Search
  - Implementation
  - Problem-Decomposition
Key Takeaway: Simply simulate when the time constraints allows you to. Remember that the goal is to write code that works, not code that looks aesthetic.
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
    
    int N;
    
    \#define start first.first
    \#define end first.second
    \#define people second
    
    vector<pair<pii, int>>tab;
    
    bool isViable(ll x){
        priority_queue<pii, vector<pii>, greater<pii>>q;
        
        int counter = 0;
        int tme = 0;
        
        int n = N;
        
        while(tme < n and ((counter < n) or (tme < n))){
            while(counter < n and tab[counter].start <= tme){ q.push({tab[counter].end, tab[counter].people}); counter++;}
            
            if(q.size() and q.top().first.second < tme) return false;
            ll take = 0;
            
            while(q.size() and (x - take)){
                ll temp = min(q.front().people, (x - take));
                q.front().people -= temp;
                if(q.front().people == 0) q.pop();
                
                take += temp;
            }
            
            tme++;
        }
        
        return (q.size() == 0);
    }
    
    void fx() {
        // Functionality for fx
        cin >> N;
        
        vector<ll> a(N, 0), d(N, 0);
        
        for(auto &i: a) cin >> i;
        for(auto &i: d) cin >> i;
        
        for(int i = 0; i < N; i++){
            tab.pb({{max(0LL, i - d[i]), min(N-1LL, i + d[i])}, a[i]});
        }
        
        sort(all(tab));
        
        ll lo = 0;
        ll hi = 1e9+100; 
        
        while(lo < hi){
            ll mid = lo + (hi - lo)/2;
            
            if(isViable(mid)) hi = mid;
            else lo = mid +1;
        }
        
        cout << lo << endl;
        
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

int N;

vector<pair<pii, int>>tab;

bool isViable(ll x){
    priority_queue<pii, vector<pii>, greater<pii>>q;
    
    int counter = 0;
    int tme = 0;
    
    while(tme < N and ((counter < N) or (q.size()))){
        while(counter < N and tab[counter].first.first <= tme){
            if(tab[counter].second) q.push({tab[counter].first.second, tab[counter].second});
            counter++;
        }
        
        if(q.size() and q.top().f < tme) return false;
        ll take = 0;
        
        while(q.size() and (x - take)){
            pii curr = q.top();
            q.pop();
            
            ll temp = min((ll)curr.s, (x - take));
            curr.s -= temp;
            take += temp;
            
            if(curr.s > 0) q.push(curr);
        }
        
        tme++;
    }
    
    return (q.size() == 0);
}

void fx() {
    cin >> N;
    
    vector<ll> a(N, 0), d(N, 0);
    
    for(auto &i: a) cin >> i;
    for(auto &i: d) cin >> i;
    
    for(int i = 0; i < N; i++) tab.pb({{max(0LL, i - d[i]), min(N-1LL, i + d[i])}, a[i]});
    
    sort(all(tab));
    
    ll lo = 0;
    ll hi = 1e9+100; 
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)){ hi = mid;}
        else lo = mid +1;
    }
    
    cout << lo << endl;
    
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

### Core Logic:

1. **Preprocessing:**
    - The `tab` vector stores pairs, where each pair contains another pair and an integer. The inner pair represents the minimum and maximum time (or position) a passenger from carriage `i` can reach, and the integer represents the number of passengers in carriage `i`.
    - The `tab` vector is sorted based on the minimum time (or position) a passenger can reach.
2. **Binary Search:**
    - The binary search is used to find the minimum possible value of \( Z \) (denoted as `lo` in the code). The search space ranges from `0` to \( 10^9 + 100 \).
    - The `isViable(x)` function checks whether a given `x` is a viable candidate for \( Z \).
3. **Checking Viability (isViable(x)):**
    - A priority queue `q` (implemented as a min-heap) is used to keep track of the carriages that passengers can move to, sorted by the maximum time (or position) they can be reached.
    - The function iterates through each time `tme` from `0` to `N-1` and checks whether it's possible to distribute the passengers such that no carriage has more than `x` passengers at any time.
    - If a passenger can start moving at time `tme`, it is added to the priority queue with its maximum reachable time and the number of passengers.
    - The algorithm tries to distribute the passengers in the priority queue to the carriages available at time `tme` without exceeding `x` passengers in any carriage.
    - If at any point, the passengers cannot be distributed according to the constraints, `isViable(x)` returns `false`.

### Key Observations:

- **Movement Constraints:**
    - Passengers can only move to adjacent carriages, and the number of doors they can pass through is limited.
    - This constraint implies that a passenger in carriage `i` can only move to carriages in the range `[i - D_i, i + D_i]`.
- **Binary Search Application:**
    - The binary search is applied to find the minimum possible value of \( Z \) because if it's possible to distribute the passengers such that no carriage has more than `x` passengers, it's also possible for any value greater than `x`.
    - Thus, the problem of checking whether a certain `x` is viable is a monotonic function, which is a key property that allows the use of binary search.
- **Priority Queue Usage:**
    - The priority queue efficiently keeps track of the carriages to which passengers can move, ensuring that the algorithm always considers the carriage with the earliest maximum reachable time first.
    - This ensures that passengers are distributed in a way that avoids violating the time constraints.

### Key Takeaways:

- **Combining Algorithms:**
    - The solution demonstrates how combining different algorithms (binary search and priority queue) can efficiently solve a problem with multiple constraints.
- **Optimization:**
    - The binary search optimizes the solution by reducing the search space for \( Z \) logarithmically, ensuring that the solution is efficient even for large input sizes.
- **Problem Modeling:**
    - The way the problem is modeled, particularly how the movement of passengers is represented in terms of time and position, is crucial for developing an efficient solution.
    - The transformation of spatial movement into a time/position-based model allows for the efficient checking of viability using the priority queue.
- **Data Preprocessing:**
    - Preprocessing the input data (calculating and sorting the minimum and maximum reachable positions) simplifies the main algorithm and reduces computational complexity during the main computation (binary search and viability checking).

This solution elegantly combines various algorithmic techniques and problem modeling to solve a complex optimization problem with multiple constraints. It's a great example of how understanding and applying algorithmic principles can lead to efficient solutions in competitive programming.

### Solution Inspiration

### Observations and Inspirations:

1. **Bounded Answer:**
    - **Observation:** The answer, which is the minimum possible value of \( Z \), is bounded (between 0 and a maximum possible value, which can be derived from the input constraints).
    - **Inspiration:** When you observe that the answer lies within a certain range and especially when the problem involves minimizing or maximizing a certain value, consider using binary search to explore the possible answers.
2. **Local to Global Movement:**
    - **Observation:** Passengers have a local movement constraint (can’t move through more than \( D_i \) doors).
    - **Inspiration:** When you have local constraints like this, think about how you might represent or convert them into a global context (e.g., considering the movement across the entire train as a function of time or position).
3. **Feasibility Check:**
    - **Observation:** The problem essentially asks whether a certain distribution of passengers (a certain value of \( Z \)) is feasible given the constraints.
    - **Inspiration:** When a problem revolves around checking the feasibility of a certain configuration or value, consider using a helper function (like `isViable(x)` in the solution) to check whether a candidate solution satisfies the problem’s constraints.
4. **Multiple Constraints:**
    - **Observation:** The passengers have multiple constraints on their movement (limited by both the number of doors they can move through and the initial distribution of passengers).
    - **Inspiration:** When dealing with multiple constraints, consider using data structures that allow you to efficiently manage and check these constraints. Priority queues, sets, and maps are often useful in such scenarios.
5. **Ordering Relevance:**
    - **Observation:** The order in which passengers move (or are considered) can impact whether a solution is found.
    - **Inspiration:** When order matters, consider sorting the elements or using a data structure that maintains order (like a priority queue) to ensure that you consider elements in the most logical or efficient order.

### Strategies for Future Problems:

- **Problem Decomposition:**
    - Try to decompose the problem into smaller, more manageable sub-problems. In this case, the problem was decomposed into finding a candidate \( Z \) and checking its viability.
- **Model Simplification:**
    - Consider whether there’s a way to simplify or reframe the problem to make it easier to solve. Here, spatial movement was reframed in terms of time/position, simplifying the checking of constraints.
- **Algorithm Mapping:**
    - Map the problem to known algorithms or data structures. Recognizing that the problem could be solved using binary search and priority queues was key to developing the solution.
- **Test Small Cases:**
    - Work through small test cases manually and observe any patterns or constraints that might not be immediately obvious. This can often provide insights into how to develop your solution.
- **Optimization Insight:**
    - Always be on the lookout for opportunities to optimize your solution, especially in terms of reducing time complexity. Binary search, for instance, significantly reduces the search space and time complexity.

By focusing on these observations and strategies, you can often find a path toward developing a solution for complex problems. Remember that practice is key to honing these skills and that each problem you solve provides an opportunity to develop your observational and problem-solving abilities!