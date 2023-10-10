---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1013
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Cycle
  - Mod-Optimization
  - Permutation
Key Takeaway: "If a sequence of K operations brings back the system to it’s original state, then instead of simulation N operations, simulate just N%K operations. "
---
- [[#Solution ]]
- [[#Editorial Explanation (almost the same answer)]]

### Solution

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
    int n, k;
    cin >> n >> k;
    
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    
    a1--;
    a2--;
    b1--;
    b2--;
    
    vi cycle_length(n);
    vector<umii>tab(n);
    
    for(int i = 0; i < n; i++){
        int curr_pos = i, prev_pos = i;
        if(curr_pos >= a1 and curr_pos <= a2) curr_pos = a2 - (curr_pos - a1);
        if(curr_pos >= b1 and curr_pos <= b2) curr_pos = b2 - (curr_pos - b1);
        
        while(curr_pos != i){
            tab[i].insert({prev_pos, curr_pos});
            prev_pos = curr_pos;
            if(curr_pos >= a1 and curr_pos <= a2) curr_pos = a2 - (curr_pos - a1);
            if(curr_pos >= b1 and curr_pos <= b2) curr_pos = b2 - (curr_pos - b1);
        }
        
        if(prev_pos != curr_pos) tab[i].insert({prev_pos, curr_pos});
        cycle_length[i] = tab[i].size();
    }
    
    vector<int>ans(n);
    
    for(int i = 0; i < n; i++){
        if(cycle_length[i] == 0){
            ans[i] = i+1;
            continue;
        }
        
        int z = k%cycle_length[i];
        int final_pos = i;
        while(z--) final_pos = tab[i][final_pos];
        ans[final_pos] = i+1;
    }
    
    for(auto &i: ans) cout << i << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("swap"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial Explanation (almost the same answer)

[http://www.usaco.org/current/data/sol_swap_bronze_feb20.html](http://www.usaco.org/current/data/sol_swap_bronze_feb20.html)