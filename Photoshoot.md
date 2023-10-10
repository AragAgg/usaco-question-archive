---
Question Link: http://usaco.org/index.php?page=viewproblem2&cpid=1227
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Case-Work
  - Greedy
  - Implementation
  - Math
Key Takeaway: 11 hours worth of wisdom.Never stick to a single idea on a question. If it does not work, discard it. Do not keep AB testing it. Try not getting caught up in the details initially when solving the question. First, get a bird’s eye-view of the thing.When things starts to get messy, try working out the cases.
---
- [[#Solution ]]
- [[#Code Explanation]]

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

int val(string s){
    if(s == "GG" or s == "HH") return -1;
    else if (s == "HG") return 0;
    return 1;
}

void fx(){
    int n;
    string s;
    cin >> n >> s;
    vi tab;
    
    for(int i = 0; i < s.size(); i += 2) tab.pb(val(s.substr(i, 2)));
    
    tab.pb(0);
    int init = -1;
    
    for(auto i: tab) if(i != -1){ init = i; break;}
    
    int ans = 0;
    
    for(auto i: tab){
        if(i == -1) continue;
        if(i == init) continue;
        
        ans++;
        init = i;
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

  

### Code Explanation

  

This is a competitive programming problem involving the arrangement of cows for a photo shoot. The objective is to rearrange the cows, who are of two breeds (Guernseys and Holsteins), such that as many Guernseys as possible are in even-numbered positions. The only operation allowed is reversing the order of the first \(j\) cows (where \(j\) is even).

  

Here's the explanation of the code:

  

The code defines a function `fx()` which is the main function to solve the problem. The function takes no arguments, as input is read from the standard input.

  

- Step by Step Explanation
    1. First, the function reads an integer `n` and a string `s` from the standard input. `n` is the number of cows and `s` is a string describing the breed of the cows (each 'H' represents a Holstein and each 'G' represents a Guernsey).
    2. The function then constructs an array `tab` where each element is either -1, 0, or 1, representing the two-character substring of `s` starting at each even index. This is done by the function `val()`, which is defined earlier in the code. The function `val()` takes a string as input and returns -1 if the string contains two cows of the same breed, 0 if the string is "HG", and 1 if the string is "GH".
    3. The function then appends 0 to the end of `tab`.
    4. The function then finds the first element in `tab` which is not -1, and assigns it to `init`. This will be the initial state of the reversal operation.
    5. The function then iterates over `tab` again. If the current element is not equal to `init` (and is not -1), the function increments a counter `ans` and updates `init` to the current element. The counter `ans` keeps track of the number of reversals needed.
    6. Finally, the function prints `ans`, which is the minimum number of reversals needed to achieve the goal.

  

The `main()` function just calls `fx()`. If there were multiple test cases, we could uncomment the lines to handle that, but for this problem there is only one test case.

In summary, the code solves the problem by viewing it as a sequence of pairs of cows. It then counts the number of times the pair type needs to change in order to maximize the number of Guernseys in even positions, which is the same as minimizing the number of reversals needed.

  

  

**This approach takes advantage of the fact that reversals are performed on even-length prefixes of the cows, which means they don't disturb the pair structure.**