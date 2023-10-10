---
Question Link: https://codeforces.com/contest/1857/problem/B
Problem Set:
  - DIV3B
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Greedy
  - Implementation
  - Math
What's up: Fixed the O(n*n) time_complexity linked TLE on TC#8
Key Takeaway: If a question is describing a variant of a commonly known operation (Exponentiation/Rounding/etc…), understand how it is different from the original operation. And weather of not we could generalise it. Or weather or not it is a combination of two or more common operations.Assume the worst. If something could go wrong, prepare for it to go wrong.
---
### Solution (TLE on TC#8)

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
    string n; cin >> n;
    
    n = '0' + n;
    
    int a = 0, b = 1;
    
    while(b < n.size()){
        if(n[b] - '0' >= 5){
            n[a]++;
            
            for(; b < n.size(); b++){
                n[b] = '0';
            }
            
            a = 0;
            b = 1;
        }else{
            a++;
            b++;
        }
    }
    
    if(n[0] == '0') n = n.substr(1, n.size()-1);
    
    cout << n << endl;
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
    string n; cin >> n;
    
    n = '0' + n;
    
    int a = 0, b = 1;
    
    while(b < n.size()){
        if(n[b] - '0' >= 5){
            n[a]++;
            
            int c = a;
            
            c--;
            
            while(c >= 1 and n[c+1] - '0' >= 5){
                n[c]++;
                c--;
            }
            
            c += 2;
            
            for(; c < n.size(); c++){
                n[c] = '0';
            }
            
            a = 0;
            b = 1;
        }else{
            a++;
            b++;
        }
    }
    
    if(n[0] == '0') n = n.substr(1, n.size()-1);
    
    cout << n << endl;
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