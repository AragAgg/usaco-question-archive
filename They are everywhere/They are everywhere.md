---
Question Link: https://codeforces.com/problemset/problem/701/C
Problem Set:
  - "*1500"
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - String
  - Two-Pointer
Key Takeaway: When working with two pointer techniques, the stopping (termination) condition is critical. At times it is non-trivial.
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
    
    string s;
    cin >> s;
    
    unordered_set<char>pokemons;
    
    for(auto &p: s) pokemons.insert(p);
    
    int left = 0;
    int right = 0;
    unordered_map<char, int>curr;
    curr.insert({s[0], 1});
    
    int ans = s.size();
    
    while(right < s.size()-1 and left <= right){
        // cout << left << " " << right << endl;
        while(curr.size() < pokemons.size() and right < s.size()-1){
            curr[s[++right]]++;
        }
        
        if(curr.size() == pokemons.size()) ans = min(ans, right - left +1);
        
        while(curr.size() == pokemons.size() and left < right){
            ans = min(ans, right - left +1);
            
            curr[s[left]]--;
            if(curr[s[left]] == 0) curr.erase(s[left]);
            
            left++;
        }
        
        if(ans == pokemons.size()) break;
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("pairup"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

![[Screenshot_2023-09-03_at_3.24.54_PM.png]]

  

  

The solution is a pretty simple 2-P implementation.