---
Question Link: https://codeforces.com/contest/1851/problem/E
Problem Set:
  - Code Forces
  - DIV3E
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - DAG-Relaxation
  - DFS
  - Implementation
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

struct node;

vector<node>tab;

struct node{
    long long cost = INT_MAX;
    vector<int> dependencies;
    bool isFinal = false;
    
    long long costOf(){
        
        if(isFinal){return cost;}
        
        long long ans = 0;
        for(auto &dep: dependencies){ 
            ans += tab[dep].costOf();
            if(ans > cost) break;
        }
        
        if(ans < cost) cost = ans;
        
        isFinal = true;
        
        // cout << "costof returinig: " << cost << endl;
        return cost;
        
    }
};


void fx(){
    int n, k;
    cin >> n >> k;
    
    tab.clear();
    
    for(int i = 0; i < n+1; i++){
        node temp;
        tab.pb(temp);
    }
    
    for(int i = 1; i < n+1; i++){
        cin >> tab[i].cost;
    }
    
    for(int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        
        tab[temp].cost = 0;
        tab[temp].isFinal = 1;
    }
    
    for(int i = 1; i < n+1; i++){
        int t;
        cin >> t;
        
        if(t == 0){
            tab[i].isFinal = true;
            continue;
        }
        
        tab[i].dependencies.clear();
        tab[i].dependencies.assign(t, 0);
        
        
        int counter = 0;
        while(t--){
            cin >> tab[i].dependencies[counter++];
        }
    }
    
    // cout << "begin: ";
    // for(auto &i: tab) cout << i.cost << " ";
    
    // cout << endl;
    
    for(int i = 1; i < tab.size(); i++) tab[i].costOf();
    
    // cout << "end: ";
    for(int i = 1; i < tab.size(); i++) cout << tab[i].cost << " ";
    cout << endl;
    
    
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