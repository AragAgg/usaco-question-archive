---
Question Link: https://codeforces.com/contest/1867/problem/C
Problem Set:
  - DIV2C
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Constructive
  - Game
  - Implementation
  - Interactive
  - Observation
  - Structure
Key Takeaway: "For game problems (especially interactive ones) do the sample by hand to get a picture of the game mechanics.Also note that there’s a high chance that the explanation of sample might be given in such a way that it masks the idea behind the actual optimal solution.Once again: When unsure about when to end a loop… use while(true)… and then add a termination condition. (LEAP OF FAITH). Then do an adversary analysis to try to find a bug (to cause premature termination of infinite loop)"
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
void yes() { printf("YES\n"); }
void no() { printf("NO\n"); }

void fx(){
    int n;
    cin >> n;
    set<int>tab;
    
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tab.insert(t);
    }
    
    int mex = -1;
    while(true) if(!tab.count(++mex)) break;
    
    cout << mex << endl << endl;
    
    tab.insert(mex);
    
    while(true){
        int res;
        cin >> res;
        
        if(res == -1) return;
        else if (res == -2) exit(1);
        else{
            cout << res << endl << endl;
        }
    }
    
    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("convention2"));
    
    // Uncomment the following lines for multiple test cases
    int t; scanf("%d", &t);
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

### Solution (TLE on TC6)

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
void yes() { printf("YES\n"); }
void no() { printf("NO\n"); }

int mex(set<int> &mp){
    int counter = 0;
    
    while(true){
        if(!mp.count(counter)) return counter;
        counter++;
    }
    
    return -1;
}

void fx(){
    int n;
    scanf("%d", &n);
    
    set<int> tab;
    for(int i = 0; i < n; i++){ 
        int t; 
        scanf("%d", &t); 
        tab.insert(t);
    }
    
    int temp;
    temp = mex(tab);
    printf("%d\n", temp);
    fflush(stdout);
    tab.insert(temp);
    
    while(true){
        int res;
        scanf("%d", &res);
        
        if(res == -1) return;
        else if (res == -2) exit(0);
        else{
            tab.erase(res);
            
            int t;
            t = mex(tab);
            printf("%d\n", t);
            fflush(stdout);
            tab.insert(t);
        }
    }
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("convention2"));
    
    // Uncomment the following lines for multiple test cases
    int t; scanf("%d", &t);
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

  

The problem with the second solution a small oversight that we needed to call `mex()` after every move `Bob` makes, which is untrue and caused `TLE`. It is easy (even trivial) to prove that after every move `Bob` makes, it is optimal to copy `Bob`.