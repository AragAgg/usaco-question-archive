---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=690
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Binary-Search
  - Sorting
What's up: Could have use a dummy element in the priority_queue (0), this would have saved a lot of keystrokes.
Key Takeaway: Pay attention to the six parts of the binary search implementation. Whenever doubtful, use the leap of faith method
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


vi tab;
int t;

bool isVaible(int k){
    debug(k);
    priority_queue<int, vi, greater<int>>pq;
    
    int iter = 0;
    int prevTime = 0;
    int currTime = 0;
    for(int i = 0; i < min(k, (int)tab.size()); i++){
        pq.push(tab[iter]);
        currTime = max(currTime, (tab[iter++])); // buggy
    }
    
    if(iter == tab.size()) return (currTime <= t);
    
    while(iter != tab.size()){
        int prevTime = pq.top();
        pq.pop();
        pq.push(prevTime + tab[iter]);
        currTime = max(currTime, prevTime + tab[iter++]); // <- buggy
    }
    
    return (currTime <= t);
}

void fx(){
    int n;
    cin >> n >> t;
    
    tab.assign(n, 0);
    
    for(auto &i: tab) cin >> i;
    
    int low = 1;
    int high = n+1;
    
    while(low < high){
        int mid = low + (high - low)/2;
        
        if(isVaible(mid)) high = mid;
        else low = mid+1;
    }
    
    cout << low << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("cowdance"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Solution - Cow Dance Show (USACO Silver 2017 January)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-690-cow-dance-show/solution](https://usaco.guide/problems/usaco-690-cow-dance-show/solution)