---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=597
Problem Set:
  - Gold
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Binary-Search
  - Greedy
  - Implementation
  - Problem-Decomposition
  - Simulation
Key Takeaway: Try your hardest to avoid working with floating point values. (The author of the intended solution, scaled the values by a factor of 2, to do it 😐)Try to write a single construct to calculate values based on an array (when topology matters) and then offset the variable and maybe reverse the rest of the array to use the construct.
---
### What I’ve thought of till now [is correct :)]

```Plain
Basically we could binary search the power (r), as if r works, r +1 should also work, and if r doesn't work, r -1 shouldn't work either.

This gives us a monotonic function to apply binary search on.

Our checker function should look something like this:

1. sweep till either .end() is reached or an interval is encountered whose delta is > mid. Meanwhile maintain the current maximum variable, and update with everysegment as: currMax = max(prev+1, curr).

2. when you encounter such an interval, place the cow at last l pos + mid, then continue with #3

3. sweep till either .end() is encountered or an infeasible interval is encountered. the dist between two consecutive elements doesn't exceed expectations.
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

int n;
vector<double>tab;

bool isViable(double r){
    
    auto iter = tab.begin();
    double blastRadius = 0;
    
    // till the pivot
    while(iter != prev(tab.end())){
        
        blastRadius = max(blastRadius + 1, *next(iter) - *iter);
        if(blastRadius >= r-1) break;
        
        iter = prev(upper_bound(all(tab), *iter + blastRadius));
    }
    
    //at pivot
    if(iter == prev(tab.end())) return true;
    if(*next(iter) - *iter - r > r) return false;
    
    iter = prev(upper_bound(all(tab), *iter + 2*r));
    blastRadius = r-1;
    
    //after pivot
    while(iter != prev(tab.end())){
        
        if((*next(iter) - *iter) > blastRadius) return false;
        iter = prev(upper_bound(all(tab), *iter + blastRadius));
        blastRadius--;
    }
    
    return true;
}

void fx() {
    cin >> n;
    tab.assign(n, 0.0);
    for(auto &i: tab) cin >> i;
    
    sort(all(tab));
    
    //binary serach the value of r
    double lo = 0;
    double hi = tab[n-1] - tab[0] +100;
    while(hi - lo > 0.0001){
        double mid = lo + (hi - lo)/2;
        if(isViable(mid)) hi = mid;
        else lo = mid + 0.1;
    }
    
    lo = floor(lo*10)/10;
    
    cout << fixed << setprecision(1) << lo << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("angry"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Contest Results  
> One approach for solving this problem is by combining a  
> [http://www.usaco.org/current/data/sol_angry_gold_jan16.html](http://www.usaco.org/current/data/sol_angry_gold_jan16.html)  

  

### A better Greedy\DP solution [from Editorial]

```C++
\#include <iostream>
\#include <vector>
\#include <algorithm>
\#include <cstdio>

using namespace std;

\#define INF 2000000000

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] *= 2;
  }
  sort(A.begin(), A.end());
  A.resize(unique(A.begin(), A.end()) - A.begin());

  vector<int> DP[2];
  for (int it = 0; it < 2; it++) {
    int lstj = 0;
    DP[it].resize(N, INF);
    DP[it][0] = -2;
    for (int i = 1; i < N; i++) {
      while (lstj + 1 < i && abs(A[i] - A[lstj + 1]) > DP[it][lstj + 1] + 2) {
        lstj++;
      }
      DP[it][i] = min(abs(A[i] - A[lstj]), DP[it][lstj + 1] + 2);
    }
    reverse(A.begin(), A.end());
  }
  reverse(DP[1].begin(), DP[1].end());

  int i = 0;
  int j = N - 1;
  int result = INF;
  while (i < j) {
    result = min(result, max((A[j] - A[i]) / 2, 2 + max(DP[0][i], DP[1][j])));
    if (DP[0][i + 1] < DP[1][j - 1]) {
      i++;
    } else {
      j--;
    }
  }
  cout << result / 2 << '.' << (result % 2 ? 5 : 0) << '\n';

  return 0;
}
```

### Probably the single best solution [from some user]

```C++
/* Binary search on the radius value r
 * For a given radius, binary search on the location to detonate a haybale
	* Two symmetric cases: detonate to the right or to the left
	* In the right case, binary search for the left-most haybale that can detonate all bales to its right
	* Check if this bale can also detonate all bales to its left
 * If so, we have a working radius value that explodes all bales!
 */

\#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;

bool works_right(int start, int rad){
	// does everything after start detonate?
	int cur = start, nex = 0;
	while(cur < A.back()){
		while(nex+1 < n && A[nex+1] <= cur + rad) nex++;
		if(A[nex] == cur){
			return false;
		}
		cur = A[nex];
		rad -= 2;
	}
	return true;
}

// We can negate and reverse the A array, then run works_right with -start as the parameter
// See if you can figure out why this trick works!
bool works_left(int start, int rad){
    for(int &x: A) x *= -1;
    reverse(A.begin(), A.end());
    bool ans = works_right(-start, rad);
	reverse(A.begin(), A.end());
    for(int &x: A) x *= -1;
    return ans;
}

int main()
{
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n;
    A.resize(n);
    for(int i=0; i<n; ++i){
        cin >> A[i];
		// We only need 2r to be the distance between two haybales in the initial explosion
		// So to make r an integer, we can multiply the haybale locations by 2.
		A[i] *= 2;
    }
    sort(A.begin(), A.end());
    int lo = 0, hi = 2e9;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        int l = A.front(), r = A.back();
		while(l < r){
			int m = l+(r-l)/2; // leftmost start location that works_right
			if(works_right(m, mid)) r = m;
			else l = m+1;
		}
		if(works_left(l, mid)){
			hi = mid;
		} else{
			lo = mid+1;
		}
    }
    cout << lo/2 << '.' << (lo % 2 ? 5 : 0) << '\n';
}
```

### Best Solution Inspiration

### Observations and Inspiration:

1. **Observing the Radius and Position Relationship**:
    - The problem involves finding a radius and a position such that all hay bales can be detonated. This is a hint towards considering each parameter (radius and position) and observing their effects.
2. **Noticing the Search Space**:
    - The radius and the position to detonate the hay bales are not known, and the search space for them is large. This is a hint towards using a search algorithm to efficiently explore the search space. Binary search is a common choice for such problems.
3. **Breaking Down the Problem**:
    - The problem can be broken down into two subproblems: finding the optimal position for a given radius and finding the minimum radius. This decomposition makes the problem more manageable and is a common strategy for solving complex problems.
4. **Observing the Effects of Changing Parameters**:
    - Observing how changing the radius and position affects the detonation of hay bales can provide insights into how to approach the problem. For example, increasing the radius increases the range of detonation, and changing the position affects which hay bales are detonated.

### Smart Implementation Tricks:

1. **Reusing Code for Symmetric Cases**:
    - The `works_left` function reuses the `works_right` function by negating and reversing the array. This trick takes advantage of the symmetry of the problem (detonating hay bales to the left is symmetric to detonating hay bales to the right) and avoids duplicating code.
2. **Handling Decimal Points**:
    - Multiplying the hay bale locations by 2 ensures that the radius is an integer, simplifying the calculations and avoiding floating-point errors. The final radius is then divided by 2, and the decimal point is handled by checking whether the radius is odd or even.
3. **Efficiently Finding the Optimal Position**:
    - The code performs another binary search to efficiently find the leftmost position that can detonate all the hay bales to its right for a given radius. This efficient search for the optimal position is crucial for the solution's efficiency.

### Conclusion:

When faced with a similar problem in the future, consider the following:

- Observe the relationships between the parameters and their effects on the problem.
- Consider breaking down the problem into subproblems.
- Explore the search space efficiently using algorithms like binary search.
- Take advantage of symmetry to reuse code and avoid duplication.
- Use integer arithmetic to avoid floating-point errors and simplify calculations.
- Efficiently find the optimal values by using efficient search algorithms within the solution.

By making these observations and using these tricks, you can come up with efficient and elegant solutions to similar problems in the future.