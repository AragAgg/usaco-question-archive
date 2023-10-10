---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=738
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Optimisation
  - Sorting
  - Two-Pointer
What's up: Solved using a map, instead of using 2-P, but the 2-P solution would have been much easier.
Key Takeaway: "Two pointer can be applied on a vector of pairs, with a bit of alteration. But usually doing that is much easier and faster than coming up with an entirely new (and possibly buggy) solution.TLDR: Use 2-P as this is a tried and tested approach. (A little bit harder to implement at first, but very easy to fix bugs)"
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
    int n;
    cin >> n;
    
    vii tab;
    
    long long total = 0;
    
    while(n--){
        pii temp;
        cin >> temp.s >> temp.f;
        
        total += temp.s;
        
        tab.pb(temp);
    }
    
    sort(all(tab));
    
    map<long long, long long>mp;
    
    long long offset = 0;
    
    for(auto &i: tab){
        offset += i.s;
        mp[offset] = i.f;
    }
    
    long long ans = 0;
    
    offset = 0;
    
    for(auto &i: tab){
        
        offset++;
        ans = max(ans, i.f+ (*mp.lower_bound(total+1-offset)).s);
        offset += i.s-1;
        
        // cout << "Accessing: mp[" << total+1-offset << "]" << endl;
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("pairup"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation (unchecked)

### Problem Statement:

The problem is about pairing up cows to maximize the total time taken by the slowest pair. Each cow has a specific time to milk, and when two cows are paired, they finish milking when the slower cow finishes. The goal is to pair them up such that the time taken by the slowest pair is minimized.

### Solution Logic:

1. **Type Definitions and Macros**:
    - The solution starts by defining several type aliases and macros for convenience. These are just to make the code more readable and concise.
2. **Input Reading**:
    - The function `fx()` is the core function that solves the problem.
    - It starts by reading an integer `n`, which represents the number of cows.
    - A vector `tab` of pairs is used to store the milk time and the cow's ID for each cow.
    - The total milk time for all cows is calculated and stored in `total`.
3. **Sorting**:
    - The cows are sorted based on their milk time. This is crucial because pairing the cow with the least milk time with the one with the most milk time will help in minimizing the maximum time taken by any pair.
4. **Mapping Offset to Cow ID**:
    - A map `mp` is used to store the cumulative milk time (offset) as the key and the cow's ID as the value. This map will be useful in the next steps to quickly find a cow based on the cumulative milk time.
5. **Finding the Maximum Pair Time**:
    - The main logic of the solution is in this step.
    - For each cow in `tab`, the solution calculates the maximum time taken by any pair that includes this cow.
    - This is done by pairing the current cow with the cow that has a cumulative milk time closest to `total + 1 - offset` (where `offset` is the current cumulative milk time). This ensures that the current cow is paired with a cow that has a milk time that complements its own milk time.
    - The maximum time taken by any pair that includes the current cow is the sum of the current cow's milk time and the milk time of the cow found in the previous step.
    - The solution keeps track of the overall maximum time taken by any pair in the variable `ans`.
6. **Output**:
    - Finally, the solution prints the value of `ans`, which is the maximum time taken by any pair.

### Key Observations and Takeaways:

1. **Pairing Strategy**: The key insight to solve this problem is to realize that to minimize the maximum time taken by any pair, cows should be paired in a specific way: the cow with the least milk time should be paired with the cow with the most milk time, the cow with the second least milk time should be paired with the cow with the second most milk time, and so on.
2. **Efficient Lookups with Maps**: Using a map to store the cumulative milk time and the cow's ID allows for efficient lookups when trying to find a cow based on its cumulative milk time.
3. **Sorting**: Sorting the cows based on their milk time is crucial to the solution. Without sorting, it would be challenging to pair the cows optimally.

Overall, the solution efficiently pairs up the cows to minimize the maximum time taken by any pair by leveraging sorting and efficient lookups using maps.

### A much simpler solution (from: Editorial)

```C++
\#include <algorithm>
\#include <cmath>
\#include <fstream>
\#include <iostream>
\#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ifstream fin("pairup.in");
	ofstream fout("pairup.out");
	int N;
	vector<pii> V;
	fin >> N;
	for (int i = 0; i < N; i++) {
		int num_cows, milk_time;
		fin >> num_cows >> milk_time;
		V.push_back(pii(milk_time, num_cows));
	}
	sort(V.begin(), V.end());
	int M = 0, left = 0, right = N - 1;

	while (left <= right) {
		// the maximum amount of cows we can group together.
		int sub = min(V[left].second, V[right].second);
		if (left == right) sub /= 2;
		M = max(M, V[left].first + V[right].first);
		V[left].second -= sub;
		V[right].second -= sub;

		// once there are no more cows available in our
		// pair, we can increment/decrement the left/right
		// pointer(s).
		if (V[left].second == 0) left++;
		if (V[right].second == 0) right--;
	}
	fout << M << "\n";
}
```

### Editorial Code Explanation

### Problem Statement:

The problem, as previously discussed, is about pairing up cows to maximize the total time taken by the slowest pair. Each cow has a specific time to milk, and when two cows are paired, they finish milking when the slower cow finishes. The goal is to pair them up such that the time taken by the slowest pair is minimized.

### Core Logic:

1. **Input Reading**:
    - The number of different milk times, `N`, is read.
    - For each milk time, the number of cows with that milk time (`num_cows`) and the milk time itself (`milk_time`) are read and stored as pairs in a vector `V`.
2. **Sorting**:
    - The pairs in `V` are sorted based on their milk time. This is crucial because pairing the cow with the least milk time with the one with the most milk time will help in minimizing the maximum time taken by any pair.
3. **Pairing Cows**:
    - Two pointers, `left` and `right`, are initialized to the start and end of the sorted vector `V`, respectively.
    - The cows at the `left` and `right` pointers are paired together.
    - The number of cows that can be paired from the `left` and `right` pointers is determined by the minimum of the number of cows at the two pointers. This is stored in the variable `sub`.
    - If `left` and `right` point to the same milk time, then only half of the cows at that milk time can be paired together.
    - The maximum time taken by any pair is updated using the sum of the milk times at the `left` and `right` pointers.
    - The number of cows at the `left` and `right` pointers is decremented by `sub`.
    - If there are no more cows left at the `left` or `right` pointer, the pointer is incremented or decremented, respectively.
4. **Output**:
    - The maximum time taken by any pair, `M`, is printed.

### Code Explanation:

- **Type Definitions and File Streams**:
    
    ```C++
    typedef pair<int, int> pii;
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");
    ```
    
    - A type alias `pii` is defined for pairs of integers.
    - Input and output file streams are opened.
- **Reading Input**:
    
    ```C++
    int N;
    vector<pii> V;
    fin >> N;
    for (int i = 0; i < N; i++) {
        int num_cows, milk_time;
        fin >> num_cows >> milk_time;
        V.push_back(pii(milk_time, num_cows));
    }
    ```
    
    - The number of different milk times, `N`, is read.
    - For each milk time, the number of cows and the milk time are read and stored as pairs in the vector `V`.
- **Sorting**:
    
    ```C++
    sort(V.begin(), V.end());
    ```
    
    - The pairs in `V` are sorted based on their milk time.
- **Pairing Cows**:
    
    ```C++
    int M = 0, left = 0, right = N - 1;
    while (left <= right) {
        int sub = min(V[left].second, V[right].second);
        if (left == right) sub /= 2;
        M = max(M, V[left].first + V[right].first);
        V[left].second -= sub;
        V[right].second -= sub;
        if (V[left].second == 0) left++;
        if (V[right].second == 0) right--;
    }
    ```
    
    - Two pointers, `left` and `right`, are used to pair the cows.
    - The number of cows that can be paired from the `left` and `right` pointers is determined and stored in `sub`.
    - The maximum time taken by any pair is updated.
    - The number of cows at the `left` and `right` pointers is decremented.
    - The pointers are incremented or decremented if there are no more cows left at their current positions.
- **Output**:
    
    ```C++
    fout << M << "\\n";
    ```
    
    - The maximum time taken by any pair, `M`, is printed.

### Editorial

![[Screenshot_2023-09-03_at_2.19.43_PM.png]]

  

### Video Editorial

[https://youtu.be/yIoUWlzH_7w](https://youtu.be/yIoUWlzH_7w)