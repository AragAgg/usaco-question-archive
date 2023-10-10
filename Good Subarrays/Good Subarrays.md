---
Question Link: https://codeforces.com/contest/1398/problem/C
Problem Set:
  - DIV2C
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Implementation
  - Math
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
    int n; cin >> n;
    
    string s; cin >> s;
    
    int prev = 0;
    int curr_sum = 0;
    int should_be = 0;
    
    unordered_map<long long, long long> tab;
    tab.insert({0, 1});
    
    long long ans = 0;
    
    for(int i = 0; i < n; i++){
        int d = s[i] - '0';
        
        curr_sum += d;
        should_be++;
    
        int curr_offset = should_be - curr_sum;
        
        ans += tab[curr_offset]++;
        
        //if(d == 1) ans++;
        //if(curr_offset == prev) ans--;
        
        prev = curr_offset;
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

### Explanation

### Problem Statement:

You are given a string `s` of length `n` consisting of digits from 1 to 9. You need to find the number of good subarrays of `s`. A subarray is considered good if the sum of its digits is equal to the length of the subarray.

For example, the subarray "111" is good because the sum of its digits is 3, and its length is also 3.

  

### Solution Explanation:

The solution uses a prefix sum and a hash table to efficiently count the number of good subarrays.

1. **Read Input**: The solution reads the number of test cases `t` and then reads the length `n` and the string `s` for each test case.
2. **Initialize Variables**:
    - `curr_sum`: Keeps track of the current sum of the digits.
    - `should_be`: Keeps track of the expected sum (i.e., the length of the subarray).
    - `prev`: Keeps track of the previous offset.
    - `tab`: A hash table to store the count of occurrences of each offset.
3. **Iterate Through the String**:
    - For each digit `d` in the string, the solution calculates the current sum and the expected sum.
    - The offset is calculated as `curr_offset = should_be - curr_sum`.
    - The answer is incremented by the count of the current offset in the hash table.
    - If the digit is 1, the answer is incremented again.
    - If the current offset is the same as the previous offset, the answer is decremented.
    - The current offset is stored in the hash table, and the previous offset is updated.
4. **Print the Result**: The solution prints the final answer for each test case.

  

### How It Works:

The key insight is that if the sum of the digits in a subarray is equal to the length of the subarray, then the difference between the sum of the digits and the length of the subarray will be the same for all good subarrays.

By using a hash table to store the count of occurrences of each offset, the solution can efficiently count the number of good subarrays without having to check each possible subarray individually.

The additional increments and decrements in the solution handle edge cases and ensure that the count is accurate.

Overall, the solution is an efficient way to solve the problem, using a combination of prefix sums and hash tables to achieve a time complexity of O(n) for each test case.

### Editorial

![[Screenshot_2023-08-09_at_8.52.52_PM.png]]