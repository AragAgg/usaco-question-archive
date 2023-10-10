---
Question Link: https://codeforces.com/problemset/problem/1474/C
Problem Set:
  - "*1700"
  - Code Forces
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Brute-Force
  - Constructive
  - Greedy
  - Implementation
  - Sorting
  - Structure
Key Takeaway: Some times when we need to trace back to our answer after finding that one exists, we could use an vector of steps. But using a global vector of steps could come with a ton of overhead as we would have to clear it every time we backtrack. So we could have the checker function return a vector. But then we parse it only if we conclude that the solution is the one we’re looking for (its correct!)When using ordered_sets, its better to store the iterators and use them, rather than doing containter.find(x) every time, as over a lot of calls, it could make our code slower.When optimising the code (especially in low time limit questions), first optimise the part that get called the most. (Helper function and stuff) [Be GREEDY] Also when using ordered_sets try to minimise container.find() calls, for instance, use container.erase(--(container.end())) to remove the largest element instead of container.erase(container.find(*container.rbegin())).
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

vi tab;
vii track;

inline bool fx2(int k){
    multiset<int>nums;
    for(auto &i: tab) nums.insert(i);
    
    while(true){
        if(nums.size() == 0) return true;
        
        auto bIter = (nums.end());
        bIter--;
        int b = *bIter;
        nums.erase(bIter);
        
        int a = k - b;
        
        if(max(a, b) > k) return false;
        
        auto aIter = nums.find(a);
        
        if(aIter == nums.end()){
            return false;
        }
        
        nums.erase(aIter);
        
        track.pb({a, b});
        
        k = max(a, b);
    }
}

void fx() {
    // Functionality for fx
    int n;
    cin >> n;
    
    n *= 2;
    
    tab.clear();
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        tab.pb(t);
    }
    
    sort(all(tab));
    
    for(int i = 0; i < n-1; i++){
        int x = tab[i] + tab[n-1];
        
        track.clear();
        if(fx2(x)){
            yes();
            cout << x << endl;
            for(auto &item: track) cout << item.f << " " << item.s << endl;
            return;
        } 
    }
    
    no();
    
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

### Editorial

> [!info] Codeforces Round #696 Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/86933](https://codeforces.com/blog/entry/86933)  

### Editorial (USACO)

> [!info] Solution - Array Destruction (CF)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cf-array-destruction/solution](https://usaco.guide/problems/cf-array-destruction/solution)