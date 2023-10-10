---
Question Link: https://codeforces.com/problemset/problem/1158/A
Problem Set:
  - "*1500"
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Constructive
  - Greedy
  - Implementation
  - Math
  - Sorting
What's up: Nice Question. 🙂
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



void fx(){
    int n, m;
    cin >> n >> m;
    
    long long ans = 0;
    
    priority_queue<pii>pq;
    long long boysMax = 0;
    
    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        ans += (t*m);
        pq.push({t, m-1});
        boysMax = max(boysMax, t);
    }
    
    bool violated = false;
    
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        
        if(t < boysMax or (t < boysMax and !pq.size())){ violated = true; continue;}
        else if(t == boysMax) continue;
        
        pii curr = pq.top();
        pq.pop();
        
        ans += (t - curr.f);
        curr.s--;
        
        if(curr.s) pq.push(curr);
        
    }
    
    if(violated) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("cardgame"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

---

### **Problem Recap**:

Given n boys and m girls, each boy presents some number of sweets to each girl. For each boy, we know the minimum number of sweets he gave to any girl, and for each girl, we know the maximum number of sweets she received from any boy. The goal is to find the minimum total number of sweets that the boys could have presented.

---

### **Key Observations**:

1. **Total Sweets**: The total number of sweets given by the boys is at least the sum of the minimum number of sweets each boy gave multiplied by m (because each boy gives sweets to m girls).
2. **Impossible Condition**: If the maximum number of sweets a girl received is less than the maximum of the minimum number of sweets any boy gave, then it's impossible to satisfy the conditions.
3. **No Adjustments Needed**: If the maximum number of sweets a girl received is equal to the maximum of the minimum number of sweets any boy gave, then we don't need to make any adjustments.
4. **Adjustments Needed**: If the maximum number of sweets a girl received is greater than the maximum of the minimum number of sweets any boy gave, then we need to adjust the total number of sweets.

---

### **Solution Breakdown**:

1. **Initialization**:
    - Read n and m.
    - Initialize 'ans' to 0. This will store the total number of sweets.
    - Use a priority queue 'pq' to store the boys' minimum sweets and the number of girls left to give sweets to.
    - Initialize 'boysMax' to 0. This will store the maximum of the minimum number of sweets any boy gave.
2. **Reading Boys' Data**:
    - For each boy, read the minimum number of sweets he gave.
    - Add to 'ans' the product of this number and m (because he gives at least this number of sweets to each of the m girls).
    - Push this number and m-1 (representing the number of girls left to give sweets to) into the priority queue.
    - Update 'boysMax'.
3. **Reading Girls' Data and Adjusting**:
    - For each girl, read the maximum number of sweets she received.
    - If this number is less than 'boysMax', set 'violated' to true (because it's impossible to satisfy the conditions).
    - If this number is equal to 'boysMax', continue to the next girl.
    - If this number is greater than 'boysMax', pop the top of the priority queue (which represents the boy who gave the most minimum number of sweets). Adjust 'ans' by adding the difference between this number and the boy's minimum number of sweets. Decrease the number of girls left to give sweets to by 1. If this number is greater than 0, push the boy's data back into the priority queue.
4. **Output**:
    - If 'violated' is true, print -1.
    - Otherwise, print 'ans'.

---

### **Key Takeaways**:

1. **Priority Queue**: The use of a priority queue to keep track of the boys' minimum sweets in descending order is crucial. This ensures that we always adjust the total number of sweets using the boy who gave the most minimum number of sweets.
2. **Greedy Approach**: The solution uses a greedy approach to adjust the total number of sweets. By always using the boy who gave the most minimum number of sweets to adjust the total, we ensure that we get the minimum total number of sweets that satisfy the conditions.
3. **Handling Edge Cases**: The solution carefully handles the edge cases where it's impossible to satisfy the conditions. This is done using the 'violated' flag and the checks on the maximum number of sweets each girl received.

In summary, this problem tests the ability to use data structures like priority queues effectively, combined with a greedy approach, to solve a seemingly complex problem. The key is to break down the problem into smaller parts, handle each part separately, and then combine the results to get the final solution.

---

### Editorial (Codeforces)

> [!info] Codeforces Round #559 — editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/66993?locale=en](https://codeforces.com/blog/entry/66993?locale=en)  

  

### Editorial (USACO)

> [!info] Solution - The Party and Sweets (CF)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cf-the-party-and-sweets/solution](https://usaco.guide/problems/cf-the-party-and-sweets/solution)