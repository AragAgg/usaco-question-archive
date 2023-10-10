---
Question Link: https://codeforces.com/contest/1867/problem/B
Problem Set:
  - DIV2B
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Bitwise
  - Case-Work
  - Constructive
  - Problem-Decomposition
  - String
What's up: Done… Basic Casework. Coming up with an aesthetic solution is hard but an branching one is easy.
Key Takeaway: In a contest environment, when unsure how to handle multiple branches, just write dumb code using if…elseif…else. NOBODY CARES how good the code looks + reading it is much more simplistic then writing an aesthetic but (possibly) buggy answer.
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
    
    int diffPolar = 0;
    for(int i = 0; i < (s.size())/2; i++){
        if(s[i] != s[n-i-1]) diffPolar++;
    }
    
    for(int i = 0; i <= n; i++){
        if(i < diffPolar) cout << 0;
        else if(i == diffPolar) cout << 1;
        else if(s.size()%2){
            int add = i - diffPolar;
            if((add <= s.size() - 2*diffPolar)) cout << 1;
            else cout << 0;
            
            
        }else{
            int add = i - diffPolar;
            if((add <= s.size() - 2*diffPolar) and add%2 == 0) cout << 1;
            else cout << 0;
        }
    }
    
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("convention2"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```