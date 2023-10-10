---
Problem Set:
  - "*2000"
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Constructive
  - Implementation
  - Math
  - Observation
What's up: Question was supposed to be solved using binary search, but could be solved in a much easier fashion using greedy methods.
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

void fx() {
    // Functionality for fx
    ll n, k;
    cin >> n >> k;
    
    map<ll, ll>m;
    
    for(int i = 0; i < n; i++){
        ll t;
        cin >> t;
        m[t]++;
    }
    
    vector<pair<ll, ll>> tab;
    for(auto &i: m) tab.pb({i.f, i.s});
    
    int start = 0;
    int end = tab.size()-1;
    
    while((end - start) and k > 0){
        if(tab[start].s <= tab[end].s){
            //case one...
            ll take = min(k, tab[start].s*(tab[start+1].f - tab[start].f));
            take = floor(take/tab[start].s)*tab[start].s;
            
            if(take == 0) break;
            
            k -= take;
            
            tab[start].f += take/tab[start].s;
            
            if(tab[start].f == tab[start+1].f){ tab[start+1].s += tab[start].s; start++;}
            
        }else{
            ll take = min(k, tab[end].s*(tab[end].f - tab[end-1].f));
            take = floor(take/tab[end].s)*tab[end].s;
            
            if(take == 0) break;
            
            k -= take;
            
            tab[end].f -= take/tab[end].s;
            
            if(tab[end].f == tab[end-1].f){ tab[end-1].s += tab[end].s; end--;}
        }
    }
    
    cout << (tab[end].f - tab[start].f) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

### Problem Recap:

You're given a sequence of integers and you can either increase or decrease any integer by 1, up to `k` times in total. The goal is to minimize the difference between the largest and smallest numbers in the sequence.

### Observations:

1. **Sorting**: By sorting the sequence, we can easily access the smallest and largest numbers. This is crucial because we're trying to minimize the difference between these two numbers.
2. **Greedy Approach**: The problem lends itself to a greedy approach. We should always try to minimize the difference between the smallest and largest numbers in the most efficient way possible. This means that if we have a choice between increasing a smaller number and decreasing a larger number, we should choose the option that affects more numbers with fewer operations.

### Core Logic:

1. **Mapping the Numbers**: The solution uses a map (`m`) to store each unique number in the sequence and its frequency. This is useful because if multiple numbers are the same, they can be increased or decreased together, using fewer operations.
2. **Creating a Table**: The map is then converted into a vector of pairs (`tab`), where each pair consists of a unique number and its frequency. This table is essentially a sorted version of the sequence, with duplicates grouped together.
3. **Two Pointers**: The solution uses two pointers, `start` and `end`, to point to the smallest and largest numbers in the table, respectively.
4. **Greedy Operations**: The solution then enters a loop where it greedily tries to minimize the difference between the numbers pointed to by `start` and `end`. It does this by either increasing the smaller number or decreasing the larger number, depending on which operation affects more numbers with fewer total operations. The number of operations used is subtracted from `k` in each iteration.
5. **Edge Cases**: If at any point the number of operations required to change a number exceeds `k`, or if the two pointers meet (i.e., all numbers have become the same), the loop breaks.

### Key Takeaways:

1. **Greedy Algorithms**: This problem is a classic example of where a greedy algorithm is both intuitive and effective. By always choosing the most efficient operation at each step, the solution ensures that the difference between the smallest and largest numbers is minimized.
2. **Two Pointers**: The two-pointer technique is a powerful tool for solving problems that involve sequences or arrays. In this problem, it allows the solution to efficiently access and modify the smallest and largest numbers.
3. **Data Structures**: The use of maps and vectors in this solution highlights the importance of choosing the right data structure for the problem. The map allows for efficient grouping of duplicate numbers, while the vector allows for easy sorting and access.

In summary, this solution employs a combination of greedy algorithms, the two-pointer technique, and efficient data structures to solve the problem. The main insight is to always choose the most efficient operation at each step, and to use data structures that facilitate this approach.

### Editorial

![[Screenshot_2023-10-04_at_10.16.21_PM.png]]