---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1107
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Implementation
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

unordered_map<string, pair<int, string>>tab;

unordered_map<string, int>ymap = {
        {"Ox", 0},
        {"Tiger", 1},
        {"Rabbit", 2},
        {"Dragon", 3},
        {"Snake", 4},
        {"Horse", 5},
        {"Goat", 6},
        {"Monkey", 7},
        {"Rooster", 8},
        {"Dog", 9},
        {"Pig", 10},
        {"Rat", 11},
    };
    
int yearDiff(string &referee, string &reference, string &relation, string &yearType){
    if(relation == "previous"){
        if(ymap[yearType] < ymap[tab[reference].s]) return  (-(ymap[tab[reference].s] - ymap[yearType]));
        else return (-(12 - (ymap[yearType] - ymap[tab[reference].s])));
    }else{
        if(ymap[yearType] > ymap[tab[reference].s]) return (ymap[yearType] - ymap[tab[reference].s]);
        else return (12 - (ymap[tab[reference].s] - ymap[yearType]));
    }
}



void fx(){
    int n; 
    cin >> n;
    
    
    
    
    
    tab.insert({"Bessie", {0, "Ox"}});
    
    while(n--){
        string referee, reference, relation, temp, yearType;
        cin >> referee >> temp >> temp >> relation >> yearType >> temp >> temp >> reference;
        
        int year = tab[reference].f;
        
        year += yearDiff(referee, reference, relation, yearType);
        
        tab.insert({referee, {year, yearType}});
    }
    
    
    cout << abs(tab["Bessie"].f - tab["Elsie"].f) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile("cowqueue");
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // freopen("whereami.in", "r", stdin); 
    // freopen("whereami.out", "w", stdout);
    
    // Single test case
    fx();
    
    return 0;
}
```