---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=964
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Structure
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

void fx(){
    int n;
    cin >> n;
    
    string s; 
    cin >> s;
    
    for(int i = 1; i <= s.size(); i++){
        unordered_set<string>tab;
        bool flag = true;
        for(int j = 0; j <= s.size() - i; j++){
            if(tab.count(s.substr(j, i))){
                flag = false;
                break;
            }
            
            tab.insert(s.substr(j, i));
        }
        
        if(flag){
            cout << i << endl;
            return;
        }
        
    }
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile("cowqueue");
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    freopen("whereami.in", "r", stdin); 
    freopen("whereami.out", "w", stdout);
    
    // Single test case
    fx();
    
    return 0;
}
```