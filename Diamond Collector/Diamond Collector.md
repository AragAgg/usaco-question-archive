---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=643
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Edge-Cases
  - Implementation
  - Sorting
  - Two-Pointer
Key Takeaway: "When unsure of a termination condition for a loop or a recursive function, take the leap of faith. Consider that it works and continue to write the rest of the construct and then later come back to it and make the changes.This method could also be generalised: when working your way through a solution, if a non-critical part seems tricky or non-trivial, take the leap of faith."
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

void fx() {
    // Functionality for fx
    int n, k;
    cin >> n >> k;
    
    vi tab(n, 0);
    vi beg(n, 1);
    vi end(n, 1);
    
    for(auto &i: tab) cin >> i;
    
    sort(all(tab));
    
    int left = 0, right = 0, ans = 0;
    
    while(left < n-1){
        while(right < n-1){
            right++;
            if((tab[right] - tab[left]) > k) break;
            
            beg[left] = end[right] = right - left+1;
        }
        
        while(left < right){
            left++;
            end[left] = max(end[left], end[left-1]);
            beg[left] = right - left + ((tab[right - tab[left] <= k])?1:0);
            if(tab[right] - tab[left] <= k) break;
        }
    }
    
    for(int i = 1; i < n; i++) ans = max(ans, beg[i] + end[i-1]);
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("diamond"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

### Problem Statement:

The problem is about a collection of diamonds, each with a different size. The goal is to find two non-overlapping subsets of diamonds such that:

1. The difference between the largest and smallest diamond in each subset is at most `K`.
2. The sum of the sizes of the two subsets is maximized.

### Core Logic:

1. **Sorting the Diamonds**:  
    The first step is to sort the diamonds in increasing order of their sizes. This is because we want to find subsets where the difference between the largest and smallest diamond is at most `K`. Sorting makes it easier to find such subsets.
2. **Two Pointers Technique**:  
    The solution uses the two pointers technique. The idea is to maintain two pointers, `left` and `right`, both initially pointing to the first diamond. The `right` pointer moves to the right until the difference between the diamond at the `right` pointer and the diamond at the `left` pointer is more than `K`. This way, we can find a subset of diamonds where the difference between the largest and smallest diamond is at most `K`.
3. **Maintaining Begin and End Arrays**:
    
    - `beg[]`: This array stores the maximum size of the subset start at each diamond such that the difference between the largest and smallest diamond in the subset is at most `K`.
    - `end[]`: This array stores the maximum size of the subset ending at each diamond such that the difference between the largest and smallest diamond in the subset is at most `K`.
    
    After finding a subset using the two pointers technique, the size of the subset is stored in the `beg[]` array for the `left` pointer and the `end[]` array for the `right` pointer.
    
4. **Updating the Left Pointer**:  
    After finding a subset using the `right` pointer, the `left` pointer is moved to the right. For each movement of the `left` pointer, the `end[]` array is updated. The `beg[]` array is also updated based on the difference between the diamonds at the `right` and `left` pointers.
5. **Finding the Maximum Sum**:  
    The final step is to find the maximum sum of the sizes of two non-overlapping subsets. This is done by iterating through the diamonds and for each diamond, adding the value in the `beg[]` array for that diamond and the value in the `end[]` array for the previous diamond. The maximum of these sums is the answer.

### Key Takeaways:

1. **Sorting is Crucial**: Sorting the diamonds is a crucial step as it simplifies the process of finding subsets where the difference between the largest and smallest diamond is at most `K`.
2. **Efficiency of Two Pointers**: The two pointers technique is an efficient way to find subsets of diamonds that meet the given criteria. It avoids the need for nested loops, which would have made the solution slower.
3. **Maintaining Information**: The `beg[]` and `end[]` arrays are essential for maintaining information about the maximum sizes of the subsets that meet the given criteria. This information is used to find the maximum sum of the sizes of two non-overlapping subsets.
4. **Dynamic Approach**: The solution uses a dynamic approach to update the `beg[]` and `end[]` arrays as the `left` pointer moves. This ensures that the arrays always contain the most up-to-date information.

In summary, the solution sorts the diamonds, uses the two pointers technique to find subsets of diamonds that meet the given criteria, maintains information about these subsets using the `beg[]` and `end[]` arrays, and finally finds the maximum sum of the sizes of two non-overlapping subsets.

### Editorial (Pretty much the same)

![[Screenshot_2023-09-05_at_1.20.35_AM.png]]

  

  

### USACO Editorial

[https://usaco.guide/problems/usaco-643-diamond-collector/solution](https://usaco.guide/problems/usaco-643-diamond-collector/solution)