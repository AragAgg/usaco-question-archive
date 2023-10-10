---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=918
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Binary-Search
  - Implementation
  - Sorting
  - Two-Pointer
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
    int n;
    cin >> n;

    vi tab(n, 0);
    for(auto &i: tab) cin >> i;

    sort(all(tab));
    
    int minimum = INT_MAX, maximum = 0;

    if(((tab[n-2] - tab[0]) == n-2 and (tab[n-1] - tab[n-2] - 1 >= 2)) or (tab[n-1] - tab[1]) == n-2 and (tab[1] - tab[0] - 1 >= 2)) minimum = 2;

    for(int i = 2; i < n-1; i++) maximum += (tab[i] - tab[i-1] -1);

    maximum += max((tab[1] - tab[0] -1), (tab[n-1] - tab[n-2] -1));

    if (minimum != 2) for(int i = 0; i < n; i++){
        int dist = n-(upper_bound(all(tab), (tab[i]+n-1)) - (tab.begin()+i));
        minimum = min(minimum, dist);
    }

    cout << minimum << endl << maximum << endl;


}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("herding"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

**Problem Statement:**  
You are given a sequence of `N` integers, representing the positions of cows on a number line. The problem asks for two things:

1. The minimum number of moves required to make the cows consecutive.
2. The maximum number of moves the cows can be moved while keeping them consecutive.

A move consists of taking a cow from one end of the sequence and moving it to the other end.

**Solution Explanation:**

1. **Initialization and Input:**
    - The solution starts by defining some type aliases and macros for convenience.
    - The `fx()` function is where the main logic resides.
    - The program reads `n` (number of cows) and their positions into the `tab` vector.
2. **Sorting:**
    - The positions of the cows (`tab`) are sorted. This makes it easier to determine the gaps between the cows and decide on the moves.
3. **Minimum Moves Calculation:**
    - The minimum number of moves is a bit tricky. The solution checks two edge cases:
        1. If the second last cow and the first cow have a difference of `n-2` and the gap between the last two cows is more than 1, then the minimum moves are 2.
        2. If the last cow and the second cow have a difference of `n-2` and the gap between the first two cows is more than 1, then the minimum moves are 2.
    - If neither of the above conditions is met, the solution calculates the minimum moves by iterating over the cows and checking the distance between the current cow and the cow that would be at the end if the cows were consecutive.
4. **Maximum Moves Calculation:**
    - The maximum moves are calculated by summing up the gaps between all cows minus 1 (because if they are consecutive, the gap is 1). This gives the number of moves to make them consecutive.
    - Additionally, the solution adds the maximum of the gaps between the first two cows and the last two cows to the total.
5. **Output:**
    - The solution then prints the minimum and maximum moves.

**Key Takeaways:**

1. **Sorting for Simplicity:** Sorting the positions of the cows simplifies the problem a lot. Once sorted, it's easier to determine the gaps between cows and decide on the moves.
2. **Edge Cases:** The solution cleverly checks for two edge cases for the minimum moves. These cases handle situations where moving a cow from one end to the other twice will result in consecutive positions.
3. **Maximum Moves:** For the maximum moves, the solution leverages the fact that you can always move the cows to increase the number of moves until they are consecutive. This is done by summing up the gaps between the cows.
4. **Efficiency:** The solution uses binary search (`upper_bound`) to efficiently find the cow that would be at the end if the cows were consecutive. This ensures that the solution is efficient and can handle larger inputs.

In summary, the solution to this problem leverages sorting, careful consideration of edge cases, and efficient algorithms to determine the minimum and maximum moves required to make the cows consecutive on a number line.

### Editorial (USACO)

[https://usaco.guide/problems/usaco-918-sleepy-cow-herding/solution](https://usaco.guide/problems/usaco-918-sleepy-cow-herding/solution)

### Editorial (starCoder)

[https://www.youtube.com/watch?si=9IceJnPf0KM9jcx8&embeds_referring_euri=https://usaco.guide/&source_ve_path=Mjg2NjQsMTY0NTA2&feature=emb_share&v=BvgV7f3pwcI](https://www.youtube.com/watch?si=9IceJnPf0KM9jcx8&embeds_referring_euri=https://usaco.guide/&source_ve_path=Mjg2NjQsMTY0NTA2&feature=emb_share&v=BvgV7f3pwcI)