---
Question Link: https://usaco.guide/silver/intro-sorted-sets
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Custom-Comparator
  - Sorting
  - Structure
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

struct cow{
    int a;
    int d;
    int p;
};

struct comp {
    bool operator()(cow &a, cow &b)
    {
       return (a.p < b.p);
    }
};

void fx(){
    int n;
    cin >> n;
    
    vector<cow>cows;
    for(int i = 0; i < n; i++){
        cow c;
        cin >> c.a >> c.d;
        c.p = -i;
        
        cows.pb(c);
    }
    
    sort(all(cows), [](cow &a, cow &b){
        if(a.a == b.a){
            a.p > b.p;
        } else return a.a < b.a;
    });
    
    priority_queue<cow, vector<cow>, comp>q;
    
    int t = cows[0].a;
    int cowCounter = 0;
    
    int ans = 0;
    
    q.push(cows[cowCounter++]);
    
    while(q.size()){
        ans = max(ans, t - q.top().a);
        t += q.top().d;
        
        q.pop();
        
        while(cowCounter < n and cows[cowCounter].a <= t) q.push(cows[cowCounter++]);
        if(!q.size() and cowCounter < n){ q.push(cows[cowCounter++]); t = q.top().a;}
        
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("convention2"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```