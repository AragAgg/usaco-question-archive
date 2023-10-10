---
Question Link: https://codeforces.com/contest/1777/problem/C
Problem Set:
  - "*1700"
  - Code Forces
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Math
  - Sorting
  - Two-Pointer
Key Takeaway: When working with two pointer / sliding window technique, make sure to handle cases the n < the minimum n required for the construct to work.If you want to find the divisors of n ≤ a certain m , we could run a loop from 1 - > sqrt(n) and then check if n%i == 0 if yes then include it, else continue. Also if we choose to include i, then check if n/i <= m, if yes, include that too.At any time if i exceeds m, break out.
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

int m;

void fx2(int n, map<int, int>&curr, bool toAdd){
    for(int i = 1; i <= sqrt(n); i++){
        if(i > m) break;
        if(n%i != 0) continue;

        if(toAdd) curr[i]++;
        else{
            curr[i]--;
            if(curr[i] == 0) curr.erase(i);
        }

        int j = n/i;

        if(j <= m and j != i){
            if(toAdd) curr[j]++;
            else{
                curr[j]--;
                if(curr[j] == 0) curr.erase(j);
            }
        }
    }
}

void fx() {
    // Functionality for fx
    int n;
    cin >> n >> m;

    vi tab(n, 0);
    for(auto &i: tab) cin >> i;
    
    
    sort(all(tab));
    map<int, int>curr;
    
    if(n == 1){
        fx2(tab[0], curr, true);
        cout <<  ((curr.size() == m)?0:-1) << endl;
        return;
    }

    int left = 0, right = -1, ans = INT_MAX;


    // fx2(tab[0], curr, true);

    while(left < n-1 and right < n){ // <- possibly buggy
        while(right < n-1){
            right++;
            fx2(tab[right], curr, true);
            if(curr.size() >= m) break;
        }
        
        while(left < right){
            if(curr.size() >= m) ans = min(ans, tab[right] - tab[left]);
            fx2(tab[left++], curr, false);
            if(curr.size() < m) break;
        }
        
        if(curr.size() >= m) ans = min(ans, tab[right] - tab[left]);
    }

    cout << ((ans == INT_MAX)?-1:ans) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("herding"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

### Solution Explanation

### Problem Statement:

Given an array of integers, the problem asks to find the minimum difference between the maximum and minimum elements of a subarray such that the subarray has at least `m` distinct divisors.

### Core Logic:

1. **Preprocessing**: The given array is sorted. This helps in ensuring that when we slide the window, we are always considering the minimum difference between the maximum and minimum elements of the current subarray.
2. **Divisor Counting**: The function `fx2` is used to count the divisors of a number `n`. It does this by iterating from `1` to `sqrt(n)` and checking if `i` divides `n`. If it does, then both `i` and `n/i` are divisors of `n`. This function either adds or removes these divisors from the `curr` map based on the `toAdd` flag.
3. **Sliding Window**: The main logic of the solution is implemented using the sliding window technique. Two pointers, `left` and `right`, are used to represent the current subarray. The idea is to expand the `right` pointer until we have at least `m` distinct divisors and then shrink the window from the `left` to find the minimum difference. This process is repeated until the entire array is traversed.

### Observations:

1. **Distinct Divisors**: The divisors of a number can be found in `O(sqrt(n))` time. This is because if `n` is divisible by some number `p`, then `n/p` is also a divisor. If `p <= sqrt(n)`, then `n/p` will always be greater than `sqrt(n)`. So, we only need to check numbers up to `sqrt(n)`.
2. **Sliding Window**: The sliding window technique is efficient because it ensures that each element is processed only once. The `left` and `right` pointers move from the start to the end of the array, and at each step, we either add or remove divisors from the `curr` map.

### Key Takeaways:

1. **Efficient Divisor Counting**: The problem can be efficiently solved by counting divisors in `O(sqrt(n))` time.
2. **Sliding Window Technique**: This technique is powerful for problems where you need to find a subarray that satisfies certain conditions. It ensures that each element is processed in constant time, leading to a linear time solution.
3. **Use of Maps**: Maps are used to keep track of the count of divisors. This allows for efficient addition and removal of divisors as the window slides.
4. **Edge Cases**: The solution handles the case where `n=1` separately. This is important because the sliding window technique would not work for a single element.

In summary, the solution efficiently finds the minimum difference between the maximum and minimum elements of a subarray with at least `m` distinct divisors using the sliding window technique and efficient divisor counting.

### Editorial (Official)

![[Screenshot_2023-09-05_at_2.18.11_PM.png]]