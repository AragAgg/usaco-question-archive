---
Question Link: https://codeforces.com/contest/1882/problem/B
Problem Set:
  - Code Forces
  - DIV2B
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Constructive
  - Greedy
  - Observation
  - Simulation
  - Subset-Generation
What's up: Just dumb brute-force. (with a bit of logic)
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
    int n;
    cin >> n;
    
    map<int, set<int>>m;
    
    vvi tab(n);
    
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        
        while(k--){
            int t;
            cin >> t;
            
            m[t].insert(i);
            tab[i].pb(t);
        }
    }
    
    int mCounter = m.size();
    
    int ans = 0;
    
    for(auto &item: m){
        set<int>s;
        
        for(int i = 0; i < n; i++){
            if(item.second.count(i)) continue;
            
            for(auto &elem: tab[i]) s.insert(elem);
        }
        
        if(s.size() != mCounter) ans = max(ans, (int)s.size());
    }
    
    
    
    cout << ans << endl;
    
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

### Solution Inspiration

### Observations:

1. **Union of Sets:**
    - The problem is about finding the union of sets. This should immediately bring to mind data structures that handle sets efficiently, such as sets and maps in C++.
2. **Exclusion of Sets:**
    - The problem involves finding the union of some sets excluding others. This observation can lead to the idea of iterating over each element and considering the union of sets that do not contain that element.
3. **Maximum Number of Elements:**
    - The goal is to find the maximum number of elements in an attainable set. This suggests keeping a variable to track the maximum and updating it as you iterate through the possibilities.

### Insights for Solution:

1. **Use of Map for Element to Set Mapping:**
    - Noticing that you need to keep track of which elements belong to which sets can lead to the use of a map. The map can map each element to the sets it belongs to, allowing for efficient checking and operations.
2. **Iterating Over Each Element:**
    - Realizing that the solution involves considering the union of sets excluding each element one by one can lead to the idea of iterating over each element in the map and performing the necessary operations.
3. **Efficient Set Operations:**
    - Understanding that you need to perform set union operations efficiently can lead to the use of a set data structure to store the union of sets that do not contain the current element.
4. **Checking the Size of the Union:**
    - Observing that the union should not be equal to the union of all sets can lead to the idea of checking the size of the union and comparing it with the total number of unique elements.

### General Strategies for Similar Problems:

1. **Understand the Problem Deeply:**
    - Spend time understanding the problem and its requirements. Break it down into smaller parts and consider how you can solve each part.
2. **Consider Relevant Data Structures:**
    - Think about the data structures that can help solve the problem efficiently. For problems involving sets, consider using sets, maps, or other appropriate data structures.
3. **Think About the Operations Needed:**
    - Consider the operations you need to perform and how you can do them efficiently. Think about how you can use the data structures to perform these operations.
4. **Iterate Through Possibilities:**
    - For problems where you need to consider different possibilities, think about how you can iterate through each possibility and check or perform the necessary operations.
5. **Keep Track of the Answer:**
    - Remember to keep track of the answer (e.g., the maximum or minimum) as you iterate through the possibilities and update it as necessary.

By making these observations and considering these insights, you can come up with a similar efficient solution for such problems in the future.