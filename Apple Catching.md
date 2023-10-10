---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1233
Problem Set:
  - Gold
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Greedy
  - Math
  - Sorting
  - Structure
What's up: Solved with a bit of assistance.
Key Takeaway: "When you recognise that a problem boils down to finding answers to queries like: the smallest element larger than this x on the x-axis, but still smaller than y on the y-axis.You’re probably on the right track, just manipulate the graph or representation a bit to suit the needs.In this case, the core problem was the v-shape (see usaco tutorial).So we rotated the graph by 45deg in the clockwise direction, and from there it was a simple implementation using the .lower_bound() & .upper_bound() methods on maps"
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

struct event{
    int q, t, x, n;
    
    void trans(){
        int temp = x;
        x += t;
        t = t - temp;
    }
};

bool cpr(event &a, event &b){ 
    if(a.t == b.t) return (a.q == 1);
    return (a.t < b.t);
} // <- possibly buggy


void fx() {
    // Functionality for fx
    int q;
    cin >> q;
    
    multimap<int, event>cows;
    
    vector<event>events;
    
    while(q--){
        event e;
        cin >> e.q >> e.t >> e.x >> e.n;
        e.trans();
        events.pb(e);
    }
    
    sort(all(events), cpr);
    
    int ans = 0;
    
    for(auto &e : events){
        // cout << "executing: " << e.q << " " << e.t << " " << e.x << " " << e.n << endl;
        if(e.q == 1){
            cows.insert({e.x, e});
        }else{
            while(e.n){
                // cout << e.n << endl;
                auto iter = cows.upper_bound(e.x);
            
                if(iter == cows.begin()) break; // <- check
                
                --iter;
                
                int take = min((*iter).s.n, e.n);
                // cout << "taking: " << take << endl;
                
                e.n -= take;
                ans += take;
                
                if(((*iter).s.n - take) == 0) cows.erase(iter);
                else (*iter).s.n -= take;
                
            }
        }
    }
    
    
    cout << ans << endl;
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

This solution is based on the idea of sorting events (both the arrival of cows and the falling of apples) based on time and handling them in order. The main observations and insights used to solve the question are:

### Observations:

1. **Ordering of Events**: The events are ordered by time. If two events occur at the same time, the arrival of cows is processed before the falling of apples. This ensures that if a cow and an apple arrive at the same time, the cow catches the apple.
2. **Position Transformation**: The `trans` function is used to transform the coordinates. It adds the time to the x-coordinate and subtracts the x-coordinate from the time. This transformation is used to simplify the comparison of events.
3. **Multimap for Storing Cows**: A multimap is used to store the cows, with the key as the transformed x-coordinate. This allows efficient finding of the nearest cow to a falling apple.
4. **Greedy Approach**: The solution uses a greedy approach to assign apples to cows. For each apple event, it finds the nearest cow and assigns the apple to the cow, if possible.

### Core Logic:

1. **Reading and Transforming Events**: The events are read from the input, transformed using the `trans` function, and stored in a vector.
2. **Sorting Events**: The events are sorted based on the transformed time and type (arrival of cows before falling of apples).
3. **Processing Events**: The events are processed in order.
    - If it’s a cow event, the cow is added to the multimap with the transformed x-coordinate as the key.
    - If it’s an apple event, the algorithm tries to assign the apples to the nearest cows. It finds the nearest cow using the `upper_bound` function on the multimap and assigns as many apples as possible to the cow. The number of assigned apples is added to the answer.
4. **Updating the Multimap**: After assigning apples to a cow, the cow is removed from the multimap if it has caught an apple, or its count is decreased if it can catch more apples.

### Key Takeaways:

1. **Event Sorting**: Sorting events based on time and handling them in order is a useful technique for problems involving scheduling and simulation.
2. **Coordinate Transformation**: Transforming coordinates can simplify the comparison and handling of events.
3. **Data Structures**: Using appropriate data structures like a multimap can efficiently handle and process events.
4. **Greedy Approach**: A greedy approach of assigning resources (apples to cows in this case) can lead to an optimal solution in certain problems.

### Conclusion:

In essence, the solution sorts and processes events in order, efficiently handles the cows using a multimap, and greedily assigns apples to the nearest cows. The use of coordinate transformation, event sorting, and appropriate data structures are the key techniques used in this solution.

### Solution Inspirations

### Observations:

1. **Time-Based Events:**
    - **Observation:** The problem involves events happening at specific times (arrival of cows and falling of apples).
    - **Inspiration:** This should lead you to think about sorting the events based on time and processing them in order. This is a common approach in simulation and scheduling problems.
2. **Two Types of Events:**
    - **Observation:** There are two types of events, and their handling is different.
    - **Inspiration:** Consider processing different types of events separately in the sorted order. Determine which event should be processed first if two events have the same timestamp.
3. **Location-Based Interaction:**
    - **Observation:** The interaction (catching apples) happens based on the location on the number line.
    - **Inspiration:** Use data structures that can efficiently handle queries based on location, such as sets, maps, or segment trees.
4. **One-Time Interaction:**
    - **Observation:** Each cow can catch only one apple, and each apple can be caught by only one cow.
    - **Inspiration:** Think about greedy approaches. Try to match each apple with the nearest available cow.

### Insights for Solution:

1. **Event Sorting:**
    - **Insight:** Sort all events (both cow and apple events) based on time.
    - **Why It Works:** This ensures that you are processing events in chronological order, which is essential for simulation and scheduling problems.
2. **Coordinate Transformation:**
    - **Insight:** Transform the coordinates to simplify the comparison and handling of events.
    - **Why It Works:** It can make the logic simpler and more intuitive, leading to cleaner and more efficient code.
3. **Efficient Data Structure:**
    - **Insight:** Use a multimap to store the cows based on their location.
    - **Why It Works:** It allows efficient queries to find the nearest cow to a given location, which is essential for assigning apples to cows.
4. **Greedy Assignment:**
    - **Insight:** Greedily assign each apple to the nearest available cow.
    - **Why It Works:** It ensures that you are maximizing the number of apples caught by utilizing the available cows optimally.

### Conclusion:

In essence, when faced with a similar problem, observe the nature of events, their interactions, and constraints. Think about sorting events, using efficient data structures for queries, and employing greedy strategies for assignments or interactions. These observations and insights can guide you towards developing an efficient and effective solution for such problems.

### Editorial

> [!info] Solution - Apple Catching (USACO Gold 2022 Open)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-1233-apple-catching/solution](https://usaco.guide/problems/usaco-1233-apple-catching/solution)