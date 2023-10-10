---
Question Link: https://codeforces.com/contest/862/problem/B
Problem Set:
  - "*1300"
  - Code Forces
  - DIV2B
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Bipartite
  - DFS
  - Tree
What's up: My solution was too complicated. Editorial solution is much simpler
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
\#define ll long long

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


vector<int>tab[500000];
unordered_map<int, int>deg;
unordered_map<int, bool>colorOf;

pair<ll, ll>res = {0, 0};

void dfs(int x, bool col){
    if(colorOf.count(x)) return;
    colorOf[x] = col;
    (col?res.f:res.s)++;
    
    for(auto &i: tab[x]) dfs(i, !col);
}

void fx() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n -1; i++){
        int a, b;
        cin >> a >> b;
        
        a--; b--;
        
        tab[a].pb(b);
        tab[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    
    dfs(0, 1);
    ll ans = 0;
    
    for(int i = 0; i < n; i++) ans += (colorOf[i]?(res.s):(res.f)) - deg[i];
    cout << (ans/2) << endl;
    
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

### Editorial Code

```C++
\#include <iostream>
\#include <vector>
using namespace std;
vector<int> v[100005];
long long cnt[2];
void dfs(int node,int pnode,int color)
{
    cnt[color]++;
    for (int i=0;i<v[node].size();i++)
    {
        if (v[node][i]!=pnode)
        dfs(v[node][i],node,!color);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0,0);
    printf("%I64d",cnt[0]*cnt[1]-n+1);
}
```

### Editorial

![[Screenshot_2023-10-10_at_1.11.47_PM.png]]