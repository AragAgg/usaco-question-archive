---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=786
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Case-Work
  - Coordinate-Compression
  - Prefix-Sums
  - Sorting
Key Takeaway: "Coordinate compression can also be done without actually a one-to-one map.We could view every coordinate as an ‘event_timestamp’ and actually store the original coordinate in a list and then sort them. "
---
### Solution (AC)

- code
    
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
    vii shifts;
    map<int, int> mp;
    
    void fx() {
        // Functionality for fx
        cin >> n;
        shifts.assign(n, {0,0});
        for(auto &i: shifts){
            cin >> i.f >> i.s;
            mp[i.f+1] = 0;
            mp[i.s+1] = 0;
            mp[i.f] = 0;
            mp[i.s] = 0;
        }
        
        int counter = 1;
        unordered_map<int, int> revmp;
        for(auto &i: mp){ i.s = counter++; revmp[i.s] = i.f;}
        
        vi tab(counter, 0);
        
        for(auto shift : shifts){
            tab[mp[shift.f+1]]++;
            tab[mp[shift.s+1]]--;
        }
        
        for(int i = 1; i < counter; i++) tab[i] += tab[i-1];
        
        vi ones(counter, 0);
        
        int total = 0;
    
        for(int i = 1; i < counter; i++){
            ones[i] = ones[i-1] + ((tab[i-1] != 1)?0:(revmp[i]-revmp[i-1]-1)) + (tab[i] == 1);
            total += (tab[i-1] == 0)?0:(revmp[i] - revmp[i-1]);
        }
        
        int ans = 0;
        
        for(auto shift : shifts){
            int l = mp[shift.f];
            int r = mp[shift.s];
            
            ans = max(ans, (total - (ones[r] - ones[l])));
        }
        
        cout << ans << endl;
        
    }
    
    int main() {
        // Uncomment the following lines for file I/O
        iofile(string("lifeguards"));
        
        // Uncomment the following lines for multiple test cases
        // int t; cin >> t;
        // while(t--) fx();
        
        // Single test case
        fx();
        
        return 0;
    }
    ```
    
- why this works
    
    ### Why This Solution Works:
    
    1. **Mapping Time Points:**
        - The solution uses a map to assign a unique index to each time point. This is a form of coordinate compression, which is a common technique to deal with large ranges of numbers. By doing this, the solution can work with a smaller range of indices instead of the actual time points, which can be as large as \(1,000,000,000\).
        - The reverse map (`revmp`) is used to retrieve the original time points when needed.
    2. **Difference Array Technique:**
        - The `tab` array uses the difference array technique. For each lifeguard's shift, the start time is incremented, and the end time is decremented. This ensures that when we calculate the prefix sum, we get the number of lifeguards on duty at each time point.
        - This technique allows the solution to efficiently update ranges in an array and is particularly useful for problems where we need to keep track of overlapping intervals.
    3. **Calculating Total Coverage:**
        - The solution calculates the total coverage time by summing up the intervals between consecutive time points where at least one lifeguard is on duty. This gives the total time the pool is supervised.
    4. **Single Coverage Calculation:**
        - The `ones` array keeps track of the time points where only one lifeguard is on duty. This is crucial because when deciding which lifeguard to fire, we need to know how much coverage time will be lost. If a lifeguard is the only one on duty during her shift, firing her would result in a loss of coverage for that entire duration.
    5. **Finding the Optimal Lifeguard to Fire:**
        - For each lifeguard, the solution calculates the coverage time lost if that lifeguard is fired. The goal is to minimize this loss, so the solution keeps track of the maximum coverage time after firing each lifeguard.
    
    ### Strengths:
    
    1. **Efficiency:** The solution uses efficient techniques like coordinate compression and difference arrays to handle large ranges and overlapping intervals.
    2. **Scalability:** The solution can handle the maximum constraints of the problem, with up to \(100,000\) lifeguards and time points up to \(1,000,000,000\).
    3. **Clarity:** The use of type definitions and macros makes the code more readable and easier to understand.
    
    ### Potential Weaknesses:
    
    1. **Overhead:** The use of many type definitions, macros, and debugging functions might be overkill for this specific problem. While these are useful in a competitive programming setting, they can make the code seem more complex than it needs to be.
    2. **Memory Usage:** The use of maps and multiple arrays might lead to higher memory usage. However, given the constraints of the problem, this is unlikely to be an issue.
    3. **Generalization:** The solution is tailored specifically for this problem. Some of the techniques used might not be directly applicable to other problems without modifications.
    
    In conclusion, the solution is well-suited for the "Lifeguards" problem and uses efficient techniques to handle the problem's constraints. While there is some overhead in terms of code complexity, this is typical in competitive programming solutions where speed and efficiency are prioritized.
    

### Editorial Solution (Reallllly Interesting)

- code
    
    ```C++
    \#include <bits/stdc++.h>
    using namespace std;
    
    struct Cow {
    	int l, r;
    };
    
    bool operator<(const Cow &a, const Cow &b) { return a.l < b.l; }
    
    int main() {
    	freopen("lifeguards.in", "r", stdin);
    
    	int n;
    	cin >> n;
    
    	vector<Cow> cows(n);
    	for (int i = 0; i < n; i++) { cin >> cows[i].l >> cows[i].r; }
    
    	sort(cows.begin(), cows.end());
    
    	int total_time = 0;
    	// right = max ending point of lifeguards considered so far
    	int left = 0, right = 0;
    
    	// calculate total_time
    	for (int i = 0; i < n; i++) {
    		if (cows[i].r > right) {
    			left = max(right, cows[i].l);
    			total_time += cows[i].r - left;
    			right = cows[i].r;
    		}
    	}
    
    	Cow last;
    	last.l = cows[n - 1].r;
    	cows.push_back(last);
    
    	// min time a cow spends alone
    	int min_alone_time = total_time;
    	right = 0;
    	for (int i = 0; i < n; i++) {
    		int curr_res = min(cows[i + 1].l, cows[i].r) - max(cows[i].l, right);
    		min_alone_time = min(min_alone_time, curr_res);
    		right = max(right, cows[i].r);
    	}
    
    	freopen("lifeguards.out", "w", stdout);
    	// if min_alone_time < 0 then answer = tot
    	cout << total_time - max(min_alone_time, 0) << endl;
    }
    ```
    
- how this works
    
    ### Data Structure:
    
    ```C++
    struct Cow {
    	int l, r;
    };
    ```
    
    This structure represents a lifeguard's shift, with `l` being the start time and `r` being the end time.
    
    ### Sorting:
    
    ```C++
    bool operator<(const Cow &a, const Cow &b) { return a.l < b.l; }
    ```
    
    This is an overloaded operator to help sort the lifeguards based on their start times. Sorting will allow us to process the shifts in chronological order.
    
    ### Main Function:
    
    ```C++
    int main() {
    	freopen("lifeguards.in", "r", stdin);
    ```
    
    This line redirects the standard input to read from the file "[lifeguards.in](http://lifeguards.in/)". It's a common practice in USACO contests.
    
    ### Reading Input:
    
    ```C++
    	int n;
    	cin >> n;
    	vector<Cow> cows(n);
    	for (int i = 0; i < n; i++) { cin >> cows[i].l >> cows[i].r; }
    ```
    
    Here, the number of lifeguards `n` is read, and then the start and end times of each lifeguard's shift are stored in the `cows` vector.
    
    ### Sorting the Lifeguards:
    
    ```C++
    	sort(cows.begin(), cows.end());
    ```
    
    This sorts the lifeguards based on their start times, so we can process their shifts in chronological order.
    
    ### Calculating Total Coverage:
    
    ```C++
    	int total_time = 0;
    	int left = 0, right = 0;
    ```
    
    `total_time` will store the total time the pool is supervised. `left` and `right` are pointers to keep track of the current interval being considered.
    
    ```C++
    	for (int i = 0; i < n; i++) {
    		if (cows[i].r > right) {
    			left = max(right, cows[i].l);
    			total_time += cows[i].r - left;
    			right = cows[i].r;
    		}
    	}
    ```
    
    This loop calculates the total supervised time:
    
    - If the current lifeguard's end time is after the current `right` pointer, then there's a new interval to consider.
    - The `left` pointer is updated to the start of the new interval.
    - The `total_time` is incremented by the length of the current interval.
    - The `right` pointer is updated to the current lifeguard's end time.
    
    ### Calculating Minimum Alone Time:
    
    ```C++
    	Cow last;
    	last.l = cows[n - 1].r;
    	cows.push_back(last);
    ```
    
    A dummy lifeguard shift is added to ensure the last lifeguard's shift is considered when calculating alone time.
    
    ```C++
    	int min_alone_time = total_time;
    	right = 0;
    ```
    
    `min_alone_time` will store the minimum time any lifeguard spends alone. It's initialized to `total_time` as a starting point.
    
    ```C++
    	for (int i = 0; i < n; i++) {
    		int curr_res = min(cows[i + 1].l, cows[i].r) - max(cows[i].l, right);
    		min_alone_time = min(min_alone_time, curr_res);
    		right = max(right, cows[i].r);
    	}
    ```
    
    This loop calculates the minimum alone time:
    
    - For each lifeguard, `curr_res` calculates the time the lifeguard is alone.
    - `min_alone_time` is updated to the minimum of its current value and `curr_res`.
    - The `right` pointer is updated to the current lifeguard's end time.
    
    ### Output:
    
    ```C++
    	cout << total_time - max(min_alone_time, 0) << endl;
    ```
    
    The final answer is the total supervised time minus the maximum alone time. The `max` function ensures that the alone time is non-negative.
    
    ### Reasoning:
    
    The solution first calculates the total supervised time by processing the lifeguards' shifts in chronological order. It then calculates the minimum alone time for each lifeguard to determine which lifeguard to fire to minimize the loss of coverage. By subtracting the minimum alone time from the total supervised time, the solution finds the maximum coverage time after firing one lifeguard.
    
    This approach is efficient because it processes the lifeguards' shifts in a single pass, making it suitable for the given problem constraints.
    

### Proof that the solution manages case where one guard overshadows another guard

  

Consider two lifeguards:

- Lifeguard A with a shift from `a.l` to `a.r`
- Lifeguard B with a shift from `b.l` to `b.r`

If Lifeguard A's shift completely overshadows Lifeguard B's shift, it means:

- `a.l <= b.l` and `a.r >= b.r`

Now, let's see how the code handles this:

When calculating the alone time for Lifeguard A (i.e., when `i` corresponds to Lifeguard A):

```C++
int curr_res = min(cows[i + 1].l, cows[i].r) - max(cows[i].l, right);
```

Here, `cows[i + 1].l` is `b.l` and `cows[i].r` is `a.r`.

Since `a.r >= b.r`, the value of `min(cows[i + 1].l, cows[i].r)` will be `b.l`.

The alone time for Lifeguard A will be:

```C++
curr_res = b.l - max(a.l, right);
```

Now, when calculating the alone time for Lifeguard B (i.e., when `i` corresponds to Lifeguard B):

The value of `min(cows[i + 1].l, cows[i].r)` will be the start time of the lifeguard after Lifeguard B (or some large value if B is the last lifeguard).

The alone time for Lifeguard B will be:

```C++
curr_res = min(cows[i + 1].l, b.r) - max(b.l, a.r);
```

Since `a.r >= b.r`, the value of `max(b.l, a.r)` will be `a.r`, and thus, `curr_res` will be negative or zero, indicating that Lifeguard B has no alone time.

### Conclusion:

The current approach correctly handles the scenario where one lifeguard's shift completely overshadows another lifeguard's shift. For the overshadowed lifeguard (Lifeguard B in our example), the alone time will be calculated as zero or negative, indicating that they are never alone during their shift.

  

### Prove behind correctness of the non-overlap method (case by case)

### 1. Non-overlapping Shifts:

**Case A:** Lifeguard X's shift ends before Lifeguard Y's shift starts.

- `X.r < Y.l`

**Handling:**  
When calculating the alone time for Lifeguard X, the formula will correctly compute the entire duration of X's shift as alone time since `right` (the end time of the last considered lifeguard) will be less than `X.r` and the next lifeguard's start time `Y.l` will be greater than `X.r`.

### 2. Partially Overlapping Shifts:

**Case B:** Lifeguard X's shift starts before Lifeguard Y's shift and ends during Y's shift.

- `X.l < Y.l` and `X.r < Y.r` and `X.r > Y.l`

**Handling:**  
When calculating the alone time for Lifeguard X, the formula will compute the duration from the start of X's shift to the start of Y's shift as alone time. This is because the `right` will be less than `Y.l` and the next lifeguard's start time `Y.l` will be within X's shift.

### 3. Completely Overlapping Shifts:

**Case C:** Lifeguard X's shift starts before Lifeguard Y's shift and ends after Y's shift.

- `X.l <= Y.l` and `X.r >= Y.r`

**Handling:**  
When calculating the alone time for Lifeguard Y, the formula will result in a non-positive value, indicating that Y has no alone time. This is because the `right` (which will be at least `X.r` due to X's shift) will be greater than or equal to `Y.r`.

### 4. Nested Shifts:

**Case D:** Lifeguard X's shift starts after Lifeguard Y's shift starts and ends before Y's shift ends.

- `X.l > Y.l` and `X.r < Y.r`

**Handling:**  
This is essentially the inverse of Case C. When calculating the alone time for Lifeguard X, the formula will result in a non-positive value, indicating that X has no alone time.

### 5. Adjacent Shifts:

**Case E:** Lifeguard X's shift ends exactly when Lifeguard Y's shift starts.

- `X.r = Y.l`

**Handling:**  
When calculating the alone time for either lifeguard, the formula will correctly compute the entire duration of their respective shifts as alone time since there's no overlap.

### Conclusion:

For each of the possible relationships between two lifeguard shifts, the current approach correctly calculates the alone time. By extension, when considering all lifeguards, the approach will correctly determine the minimum alone time across all lifeguards, ensuring that the solution works for every possible pairing of lifeguard shifts.

### Idea behind the non-overlapping interval belong to a set (from: editorial)

### What the Line Does:

```C++
int curr_res = min(cows[i + 1].l, cows[i].r) - max(cows[i].l, right);
```

This line calculates the time during which the `i-th` lifeguard is alone on duty, i.e., the time when no other lifeguard's shift overlaps with the `i-th` lifeguard's shift.

- `cows[i].l` and `cows[i].r` represent the start and end times of the `i-th` lifeguard's shift, respectively.
- `right` represents the maximum end time of all lifeguards considered up to the `(i-1)-th` lifeguard.
- `cows[i + 1].l` represents the start time of the `(i+1)-th` lifeguard's shift.

### The Idea Behind It:

1. **Start of Alone Time:** The alone time for the `i-th` lifeguard starts either from the beginning of their shift or from the end of the last lifeguard's shift, whichever is later. This is represented by `max(cows[i].l, right)`.
2. **End of Alone Time:** The alone time for the `i-th` lifeguard ends either at the end of their shift or at the beginning of the next lifeguard's shift, whichever comes first. This is represented by `min(cows[i + 1].l, cows[i].r)`.

By subtracting the start of the alone time from the end of the alone time, we get the total duration during which the `i-th` lifeguard is alone on duty.

### Why It Works:

The logic ensures that we're only considering the non-overlapping portion of the `i-th` lifeguard's shift. By doing this for each lifeguard, we can determine which lifeguard has the smallest non-overlapping portion, and thus, firing that lifeguard would result in the least loss of coverage.

  

### Generalisation of the idea

This concept of finding non-overlapping intervals in a set of overlapping intervals is a common problem in computational geometry and scheduling. The idea can be generalized as:

1. **Sorting Intervals:** Sort the intervals based on their start times.
2. **Iterating Over Intervals:** For each interval, determine the non-overlapping portion by considering the maximum end time of the previous intervals and the start time of the next interval.

This approach can be applied to various problems, such as:

- **Room Scheduling:** Determine the time during which a room is not occupied by any event.
- **Resource Allocation:** Find the time slots during which a resource (e.g., a machine in a factory) is idle.
- **Traffic Analysis:** Determine the time intervals during which a road segment is not occupied by any vehicle.

In essence, this method is a way to find gaps or non-overlapping portions in a set of overlapping intervals.