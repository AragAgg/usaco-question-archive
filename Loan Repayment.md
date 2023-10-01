---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=991
Problem Set:
  - Silver
Last edited time: 2023-10-02T01:15
Status: Seen Editorial
tags:
  - Binary-Search
  - SQRT-Optimisation
What's up: Seen the editorial. My original approach was a bit off.
Key Takeaway: "@import url('https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.16.9/katex.min.css')O(1012)O(10^{12})O(1012)﻿ suggests something to do with sqrt(n).1 + 2 + 3 + …. @import url('https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.16.9/katex.min.css')sqrt(2∗n)sqrt(2*n)sqrt(2∗n)﻿ ≥ @import url('https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.16.9/katex.min.css')NNN﻿Nested binary search is a powerful technique.Take time to plan out implementation and look for code simplifications if the question you’re doing is an original.If a sequence of operation is ‘sequential’, do not try to estimate it if you don’t know the error bounds."
---
### Solution (Wrong Approach) [the one I wrote initially]

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

ll N, K, M;

bool isViable(ll x){
    
    if(x == 1){
        return true;
    }
    ll lo = 0;
    ll hi = K+1;
    
    double c = 1.0/x;
    c = 1 - c;
    while(lo < hi){
        ll mid = lo + (hi - lo+1)/2;
        ll curr = ceil((pow(c, mid)*N));
        if(curr > M) lo = mid;
        else hi = mid - 1;
    }
    return (lo >= 0 and lo <= K and ceil((pow(c, lo)*N)/M) <= K - lo);
}

void fx() {
    // Functionality for fx
    cin >> N >> K >> M;
    
    ll lo = 1;
    ll hi = 1e13;
    
    ll best = 1;
    
    while(lo <= hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)){ lo = mid +1; best = max(best, lo-1);}
        else hi = mid-1;
    }
    
    cout << best << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("loan"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Intended Approach [quite nice]

```C++
\#include <algorithm>
\#include <fstream>
\#include <iostream>

using std::cout;
using std::endl;

/**
 * @return whether Farmer John gives Bessie at least N (numGallons)
 * gallons of milk within withinDays with the given X value
 */
bool can_repay(long long num_gallons, long long within_days, long long at_least,
               long long x_val) {
	long long g = 0;
	while (within_days > 0 && g < num_gallons) {
		long long y = (num_gallons - g) / x_val;
		if (y < at_least) {
			long long leftover =
			    ((num_gallons - g) + (at_least - 1)) / at_least;
			return leftover <= within_days;
		}

		long long max_match = num_gallons - (x_val * y);
		long long num_days = std::min((max_match - g) / y + 1, within_days);

		g += y * num_days;  // update values
		within_days -= num_days;
	}

	return g >= num_gallons;
}

int main() {
	std::ifstream read("loan.in");

	long long num_gallons;
	long long within_days;
	long long at_least;
	read >> num_gallons >> within_days >> at_least;

	// binary search on the largest X
	long long low = 1;
	long long high = INT64_MAX / 2;
	while (low < high) {
		long mid = (low + high + 1) / 2;
		if (can_repay(num_gallons, within_days, at_least, mid)) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}

	std::ofstream("loan.out")
	    << low << endl;  // low == high, we can output either
}
```

### Editorial

> [!info] Contest Results  
> Binary search on $X$.  
> [http://www.usaco.org/current/data/sol_loan_silver_jan20.html](http://www.usaco.org/current/data/sol_loan_silver_jan20.html)