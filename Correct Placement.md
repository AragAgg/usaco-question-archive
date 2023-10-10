---
Question Link: https://codeforces.com/problemset/problem/1472/E
Problem Set:
  - "*1700"
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Observation
  - Sorting
  - Structure
  - Two-Pointer
What's up: 12 Tries to AC. The problem-setter has cleverly exploited the common mistakes people make while implementing similar solutions to actually cause the worse case time-complexity to drop down to below the author’s expectations.
Key Takeaway: When a high-rated question appears to be a simple modification on a well-known method, it’s usually the implementation that the question authors are gambling on.PAY ATTENTION TO IMPLEMENTATION Usually it suffices to ask questions like, could I come up with a pattern of inputs that will exploit the simple implementation bug, to cause a worst-case time-complexity to something bad?
---
### What i’ve thought of till now

1. store every point `(x, y)` as `#id` → `{(x, y), (y, x)`
2. insert every point (both original and mirrored) into a set and sort them
3. then going from `low x to high x` we should try doing this:
    1. if any of the prev. elements’ y has been lower than current, then use that prev. element as an overlapping friend of the current friend
    2. continue
4. then sort by y and repeat the same (but with `x` coordinate this time.)
5. go over the input again and output any of the result (from x’s ans and y’s ans)

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

\#define id second
\#define x first.first
\#define y first.second



inline void fx(){
    int n;
    cin >> n;
    
    vector<pair<pii, int>>tab;
    
    for(int i = 0; i < 2*n; i+=2){
        tab.pb({{0, 0}, 0});
        tab.pb({{0, 0}, 0});
        cin >> tab[i].x >> tab[i].y;
        tab[i].id = i/2;
        tab[i+1].id = tab[i].id;
        tab[i+1].x = tab[i].y;
        tab[i+1].y = tab[i].x;
    }
    
    vi ans(n, -1);
    sort(all(tab));
    int low = 0;
    int cachedTemp = 0;
    
    for(int i = 1; i < 2*n; i++){
        
        for(int temp = cachedTemp; temp < i; temp++){
            if(tab[temp].x != tab[i].x and tab[temp].y < tab[low].y) low = temp;
            cachedTemp = temp;
            if(tab[temp].x == tab[i].x) break;
        }
        
        if((tab[low].x < tab[i].x and tab[low].y < tab[i].y)) ans[tab[i].id] = tab[low].id;
        
    }
    
    for(int i = 0; i < n; i++) cout << ((ans[i] == -1)?-1:ans[i]+1) << " ";
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

### Solution Explanation

### Core Idea:

The solution aims to find for each friend `i`, any other friend `j` who can be located in front of him. To do this, the solution uses a sorting-based approach combined with some clever observations.

### Observations and Insights:

1. **Dual Representation:** Each friend can be represented in two ways: standing (`h, w`) and lying (`w, h`). This is why for every friend's input, two entries are added to the `tab` vector.
2. **Sorting:** The `tab` vector is sorted based on the first dimension (either height or width). This is crucial because, after sorting, you can easily find friends that have a smaller first dimension than the current friend.
3. **Finding the Minimum Second Dimension:** As you iterate over the sorted `tab` vector, you want to find the friend with the smallest second dimension (either width or height) before the current friend. This is done using the `low` variable, which keeps track of the friend with the smallest second dimension seen so far.
4. **Caching:** The `cachedTemp` variable is used to avoid redundant comparisons. It remembers the last position where the first dimension changed, so you don't have to re-check friends that you've already considered.

### Good or Bad?

- **Pros:**
    1. **Efficiency:** The solution is efficient with a time complexity of \(O(n \log n)\), which is suitable for the problem's constraints.
    2. **Simplicity:** The solution avoids complex data structures and relies on basic sorting and iteration, making it relatively easy to understand once you grasp the core idea.
- **Cons:**
    1. **Redundancy:** The solution creates two entries for each friend in the `tab` vector. While this is a clever way to handle both orientations, it also means that the solution processes twice the number of entries than there are friends. This isn't a significant issue concerning efficiency but is worth noting.

### Conclusion:

The provided solution is a good and efficient approach to solving the problem. It cleverly handles the dual representation of each friend and uses sorting to simplify the process of finding a friend that can be placed in front of another. While there are some readability issues, the solution's core logic is sound and well-suited for the problem.

### Editorial (Probably Worse)

> [!info] Codeforces Round #693 (Div. 3) Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/86406](https://codeforces.com/blog/entry/86406)