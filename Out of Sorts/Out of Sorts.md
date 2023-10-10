---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=834
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Observation
  - Sorting
  - Structure
Key Takeaway: The approach used in this solution could prove helpful in scenarios where the problem asks to track the changes to a particular state after a (sorting like) operation is applied to the entire structure.Seen a bunch of questions where a commonly (or a variation thereof) known algorithm is described, and it asks to compute something that the given algo might (implicitly/explicitly) calculate. Solving such problem require deeper understanding of the described algorithm and the general class of such algorithms as well.
---
### What i’ve thought of till now

1. store every element as a `pii` `(number, original_index)`
2. sort the vector
3. for every number in the original list,
    1. in an unordered_map,
    2. store the minimum appearance index,
    3. and the maximum appearance index
4. now for every element in the sorted vector,
    
    1. if the current index is larger than the max_app_index of the number, use curr - max_app+1
    
    1. if the curr index is smaller than the min_app_index of the number, use min_app - curr+1 (this is `wrong` because element “bubbles” to the right in one go and not in min_app - curr +1 times.) 🙂
    
    1. if it is between the two values, continue
5. we want to track the maximum such value, which in-turn would be our answer.

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
    int n;
    cin >> n;
    
    vii tab(n, {0, 0});
    
    for(int i = 0; i < n; i++){ cin >> tab[i].f; tab[i].s = i;}
    
    sort(all(tab));
    
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++){
        if(!mp.count(tab[i].f)){
            mp.insert({tab[i].f, i});
        }else{
            mp[tab[i].f] = max(mp[tab[i].f], i);
        }
    }
    
    int ans = 1;
    
    for(auto &i: tab){
        if(mp[i.f] < i.s) ans = max(ans, i.s - mp[i.f]+1);
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("sort"));
    
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

The problem is from the USACO contest platform, and it's titled "Out of Sorts". The problem is about sorting a list of integers, but with a twist. After each swap in the sorting process, we want to know the length of the subsequence of numbers that are still out of order.

### Solution Explanation:

1. **Type Definitions and Macros**:  
    The solution starts by defining several type aliases and macros for convenience. These are just to make the code more readable and concise.
2. **Input**:  
    The function `fx()` is the main function that solves the problem. It starts by reading an integer `n`, which is the number of integers in the list. Then, it reads the list of integers into a vector of pairs `tab`. Each pair consists of the integer itself and its original index.
3. **Sorting**:  
    The vector `tab` is then sorted based on the integers. This will help in determining the order of the numbers after sorting.
4. **Mapping**:  
    An unordered map `mp` is used to store the maximum index of each unique number in the sorted list. This is done by iterating over the sorted list `tab` and updating the map with the maximum index for each number.
5. **Finding the Answer**:  
    The main logic of the solution is to find the length of the subsequence of numbers that are still out of order. This is done by iterating over the sorted list `tab` and checking if the maximum index of a number (from the map `mp`) is less than its original index. If so, the length of the subsequence is updated.
6. **Output**:  
    Finally, the length of the longest subsequence of numbers that are still out of order is printed.

### Observations Used:

1. Sorting the list gives us the correct order of the numbers.
2. By keeping track of the original indices, we can determine which numbers are out of order after each swap.
3. The unordered map helps in quickly finding the maximum index of each number in the sorted list.

### Problem Quality:

The problem is good as it tests the understanding of sorting, data structures, and the concept of order. It's not just about sorting a list but understanding the implications of the sorting process.

### Alternate Approaches:

1. **Segment Trees or Fenwick Trees**: These data structures can be used to keep track of the order of numbers efficiently. However, this might be an overkill for this problem and the given solution is simpler and more intuitive.
2. **Direct Comparison**: Instead of sorting and then comparing, one could compare the current list with its sorted version directly. However, this might not be as efficient as the given approach.

### Broader Applicability of the solution model

### Core Logic:

The primary objective is to determine the length of the longest subsequence of numbers that are still out of order after sorting. The key observation here is that once a number reaches its correct position after sorting, it will never move again. So, the main challenge is to identify numbers that are still out of place.

1. **Storing Original Indices**:  
    By storing each number's original index, we can compare it to its position in the sorted array. This allows us to determine if a number has moved to its correct position or not.
2. **Using the Unordered Map**:  
    The unordered map `mp` is used to keep track of the maximum index of each unique number in the sorted list. This is crucial because if a number appears multiple times, we want to ensure we're considering the furthest occurrence of that number. The reason being, if any occurrence of a number is out of place, then the furthest occurrence will be the most out of place.
3. **Determining Out-of-Order Numbers**:  
    The logic iterates over the sorted list and checks if the maximum index of a number (from the map `mp`) is less than its original index. If it is, then the number is still out of order. The difference between the original index and the maximum index gives the length of the subsequence that is out of order.

  

### Generalizability:

The approach used in this solution can be generalized for problems where:

1. **Order Matters**: Any problem where the order or position of elements is crucial, this approach of storing original indices can be beneficial.
2. **Comparing Two States**: If you need to compare the current state of a list or array to another state (like its sorted version), then this approach can be useful.
3. **Movement or Displacement**: Problems where you need to track the movement or displacement of elements can benefit from this approach.

### Recognizing Suitable Problems:

1. **Order-based Queries**: If the problem asks questions based on the order or position of elements, consider this approach.
2. **Multiple Occurrences**: If elements can appear multiple times and you need to track each occurrence's position, think of using data structures like maps.
3. **Transformation or Transition**: If the problem involves transforming a list or array from one state to another (like sorting) and asks about the transformation process's properties, this approach might be applicable.

In conclusion, while the specific logic of tracking maximum indices in a map might not be universally applicable, the broader approach of storing original positions and comparing them to new positions is a versatile technique. Recognizing its applicability comes with practice and familiarity with order-based problems.

### Editorial (Pretty much the same)

![[Screenshot_2023-09-02_at_11.19.40_PM.png]]