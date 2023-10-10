---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=737
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Ad-Hoc
  - Implementation
---
- [[#Solution ]]

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

umii tab;

vvi m;

void fx2(int target){
    // cout << "called fx2 for: " << target << endl;
    bool flag = false;
    
    pair<int, int>a, b;
    
    for(int i = 0;  i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            if(m[i][j] == target){
                if(!flag){
                    flag = true;
                    a.f = i;
                    a.s = j;
                    
                    b = a;
                }else{
                    a.f = min(a.f, i);
                    a.s = min(a.s, j);
                    
                    b.f = max(b.f, i);
                    b.s = max(b.s, j);
                }
                
                
            }
        }
    }
    
    
    if(!flag) return;
    
    
    
    // cout << "topmost: " << a.f << " " << a.s << endl;
    // cout << "bottomost: " << b.f << " " << b.s << endl;
    
    for(int i = a.f; i <= b.f; i++)
        for(int j = a.s; j <= b.s; j++)
            if(m[i][j] != target) tab[m[i][j]] = max(1, tab[m[i][j]] + 1);
    
    if(!tab.count(target)) tab[target] = -1;
}

void fx(){
    int n;
    cin >> n;
    
    m.assign(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        for(int j = 0; j < n; j++){
            m[i][j] = s[j] - '0';
        }
    }
    
    for(int i = 1; i < 10; i++) fx2(i);
    
    // for(auto &i: m){
    //     for(auto &j: i) cout << j << " ";
    //     cout << endl;
    // }
    
    int ans = 0;
    
    for(auto &i: tab){
        if(i.s == -1){ ans++;}
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("art"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```