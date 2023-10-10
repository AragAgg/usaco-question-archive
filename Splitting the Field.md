---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=645
Problem Set:
  - Gold
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Implementation
  - Prefix-Sums
  - Sorting
Key Takeaway: When working with problems which involves sweeping across a grid (or even an list), make sure to try out extreme indexes.
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

int n;
vii tab;

long long ans = INT_MIN;
long long totalArea = 0;

void fx2(){
    vi t(n, 0);
    vi b(n, 0);
    
    t[0] = tab[0].s;
    b[0] = tab[0].s;
    
    for(int i = 1; i < n; i++){
        t[i] = max(t[i-1], tab[i].s);
        b[i] = min(b[i-1], tab[i].s);
    }
    
    totalArea = (1LL)*(abs(tab[n-1].f - tab[0].f)) * (abs(t[n-1] - b[n-1]));
    
    t[n-1] = tab[n-1].s;
    b[n-1] = tab[n-1].s;
    
    for(int i = n-1; i > 0; i--){
        t[i] = max(((i == n-1)?tab[i].s:t[i+1]), tab[i].s);
        b[i] = min(((i == n-1)?tab[i].s:b[i+1]), tab[i].s);
        if(tab[i-1].f == tab[i].f and t[i] >= b[i-1]) continue;
        ans = max(ans, totalArea - (1LL)*(t[i-1] - b[i-1])*(tab[i-1].f - tab[0].f) - (1LL)*(t[i] - b[i])*(tab[n-1].f - tab[i].f));
    }

}

void fx() {
    cin >> n;
    tab.assign(n, {0, 0});
    
    for(auto &i: tab) cin >> i.f >> i.s;
    sort(all(tab), [](pii &a, pii &b){return a.f <= b.f;});
    fx2();
    
    for(auto &i: tab) swap(i.f, i.s);
    sort(all(tab), [](pii &a, pii &b){return a.f <= b.f;});
    fx2();
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("split"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

- **Key Insights:**
    1. **Sorting by x-coordinate:** The solution first sorts the cows based on their x-coordinates. This allows us to efficiently compute the minimum and maximum y-coordinates for any prefix or suffix of the sorted list.
    2. **Two Enclosures:** The solution tries to split the cows into two groups, where one group is a prefix of the sorted list, and the other group is the remaining suffix. This ensures that the two enclosures don't overlap in the x-direction.
    3. **Computing y-boundaries:** For each possible split, the solution computes the y-boundaries for the two groups using prefix and suffix maximum and minimum operations. This gives the y-coordinates of the top and bottom boundaries of the two enclosures.
    4. **Total Area:** The solution computes the total area required if all cows were enclosed in a single rectangle.
    5. **Area Savings:** For each possible split, the solution computes the area of the two enclosures and subtracts it from the total area to get the area savings.
    6. **Repeating for y-coordinate:** The solution repeats the above steps by sorting the cows based on their y-coordinates and swapping x and y coordinates. This ensures that the two enclosures don't overlap in the y-direction.
- **How the Solution Works:**
    1. The function `fx2()` computes the area savings for a given sorting of the cows. It uses prefix and suffix operations to efficiently compute the y-boundaries for each possible split.
    2. The function `fx()` reads the input, sorts the cows based on x-coordinates, calls `fx2()`, swaps x and y coordinates, sorts the cows based on y-coordinates, and calls `fx2()` again. It then outputs the maximum area savings.
    3. The `main()` function calls `fx()` to solve the problem.

  

In conclusion, this solution is efficient and cleverly exploits the properties of the problem to compute the maximum area savings. It uses sorting, prefix and suffix operations, and coordinate swapping to achieve this.

### Editorial

[http://www.usaco.org/current/data/sol_split_gold_open16.html](http://www.usaco.org/current/data/sol_split_gold_open16.html)