---
Question Link: https://codeforces.com/contest/1860/problem/A
Problem Set:
  - DIV2A
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Case-Work
  - Constructive
  - String
Key Takeaway: Greedy Leap of Faith
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

void fx() {
    // Functionality for fx
    string s;
    cin >> s;
    
    int n = s.size();
    
    if(n == 2 and s == "()"){
        no();
        return;
    }
    
    yes();
    
    bool alt = true;
    
    bool f = (s[0] == '(')?true:false;
    
    for(int i = 1; i < n; i++){
        if((s[i] == '(' and f) or (s[i] == ')' and !f)){
            alt = false;
            break;
        }
        
        f = !f;
    }
    
    string res = "";
    
    if(alt){
        for(int i = 0; i < n; i++) res += '(';
        for(int i = 0; i < n; i++) res += ')';
    }else{
        for(int i = 0; i < n; i++) res += "()";
    }
    
    cout << res << endl;
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

### Solution Explanation

Let's analyse the given solution step by step:

**Objective**: To generate a regular bracket sequence of length 2n that does not contain the input sequence s as a contiguous substring.

  

**Approach**:

1. If the input sequence s is of length 2 and it's "()", there's no possible regular sequence of length 4 that doesn't contain s as a contiguous substring. Therefore, the answer is "NO" for this case.
2. If s isn't "()", the code determines if s alternates between '(' and ')'. For instance, "(())" doesn't alternate, but "()()" does.
3. Depending on whether s alternates or not, the code constructs the result sequence as follows:
    
    - If s alternates: Generate a sequence with n opening brackets followed by n closing brackets. E.g., for n=3, the sequence is "((()))".
    - Otherwise: Generate a sequence where every character of s is replaced by "()". E.g., for s="(()", the result is "()()()".
    
      
    

**Evaluation**:

The logic behind this solution is solid. If the sequence alternates, constructing a block of opening brackets followed by closing brackets ensures that the input sequence will never appear in the resultant sequence as a contiguous substring. If the sequence does not alternate, replacing each character with "()" also ensures the same.

### Editorial

TBA