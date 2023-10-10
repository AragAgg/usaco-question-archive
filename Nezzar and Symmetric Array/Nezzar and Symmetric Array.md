---
Question Link: https://codeforces.com/problemset/problem/1478/C
Problem Set:
  - "*1700"
  - Code Forces
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Implementation
  - Math
  - Precision-Error
  - Sorting
---
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

void fx();

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("split"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}

\#define int long long

void fx() {
    int n;
    cin >> n;
    
    vector<long long> tab(2*n);
    
    for(auto &i: tab) cin >> i;
    
    for(auto &i: tab){
        if(i == 0){
            all_of(all(tab), [](auto &x){return x == 0;})?yes():no();
            return;
        }
    }
    
    sort(all(tab));
    
    int offset = 0;
    
    const double EPS = 1e-12;
    
    int i = 2*n-1;
    
    long long last = INT_MAX;
    
    while(i >= 1){
        double curr = tab[i] - offset;
        
        curr /= (i+1);
        
        if(round(curr) > 0 and abs(curr - round(curr)) < EPS and !(tab[i]%2) and tab[i] == tab[i-1] and round(curr) != last){
            offset += 2*round(curr);
            i -= 2;
            last = round(curr);
        }else{
            no();
            return;
        }
        
    }
    
    yes();
}
```

### Editorial

![[Screenshot_2023-09-02_at_1.28.14_AM.png]]