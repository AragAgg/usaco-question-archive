---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1159
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Skipped for now
tags:
  - Black-Magic
What's up: Looked at the editorial, tried copying the solution, but it doesn’t work. (code below)
---
### Solution History

- Code 1
    
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
    
    int n, m;
    vvi tab;
    
    vi ca;
    vi cb;
    vi curr;
    
    vb visited;
    
    void dfs(int i){
        if(visited[i]) return;
        visited[i] = true;
        
        curr.pb(i);
        
        for(auto &x: tab[i]) dfs(x);
    }
    
    void fx() {
        // Functionality for fx
        cin >> n >> m;
        ca.clear();
        cb.clear();
        curr.clear();
        visited.clear();
        tab.assign(n+1, {});
        visited.assign(n+1, false);
        
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            
            tab[a].pb(b);
            tab[b].pb(a);
        }
        
        dfs(1);
        ca = curr;
        sort(all(ca));
        
        for(auto &i: ca) if(i == n) { cout << 0 << endl; return; }
        curr.clear();
        
        dfs(n);
        cb = curr;
        sort(all(cb));
        
        int ans = INT_MAX;
        
        auto aIter = ca.begin();
        auto bIter = cb.begin();
        
        while(aIter != ca.end() and bIter != cb.end()){
            ans = min(ans, abs(*aIter - *bIter));
            
            if(*aIter < *bIter) aIter++;
            else bIter++;
        }
        
        for(int i = 2; i < n; i++){
            if(visited[i]) continue;
            
            curr.clear();
            dfs(i);
            sort(all(curr));
            
            auto caIter = ca.begin();
            auto cbIter = cb.begin();
            auto currIter = curr.begin();
            
            int roadOne = abs(*caIter - *currIter);
            
            while(caIter != ca.end() and currIter != curr.end()){
                roadOne = min(roadOne, abs(*caIter - *currIter));
                
                if(*caIter < *currIter) caIter++;
                else currIter++;
            }
            
            currIter = curr.begin();
            int roadTwo = abs(*cbIter - *currIter);
            
            while(cbIter != cb.end() and currIter != curr.end()){
                roadTwo = min(roadTwo, abs(*cbIter - *currIter));
                
                if(*cbIter < *currIter) cbIter++;
                else currIter++;
            }
            
            ans = min(ans, roadOne + roadTwo);
        }
        
        cout << (pow(ans, 2)) << endl;
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
    
- Code 2 (Passes first 5)
    
    ```C++
    \#include <bits/stdc++.h>
    
    using namespace std;
    
    // Type definitions for convenience
    
    \#define ll long long
    typedef vector<ll> vi;
    typedef vector<bool> vb;
    typedef pair<ll, ll> pii;
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
    
    ll n, m;
    vvi tab;
    
    vi ca;
    vi cb;
    vi curr;
    
    vb visited;
    
    void dfs(ll i){
        if(visited[i]) return;
        visited[i] = true;
        
        curr.pb(i);
        
        for(auto &x: tab[i]) dfs(x);
    }
    
    void fx() {
        // Functionality for fx
        cin >> n >> m;
        ca.clear();
        cb.clear();
        curr.clear();
        visited.clear();
        tab.assign(n+1, {});
        visited.assign(n+1, false);
        
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            
            tab[a].pb(b);
            tab[b].pb(a);
        }
        
        dfs(1);
        ca = curr;
        sort(all(ca));
        
        for(auto &i: ca) if(i == n) { cout << 0 << endl; return; }
        curr.clear();
        
        dfs(n);
        cb = curr;
        sort(all(cb));
        
        ll ans = 1e16;
        
        auto aIter = ca.begin();
        auto bIter = cb.begin();
        
        while(aIter != ca.end() and bIter != cb.end()){
            ans = min(ans, (ll)pow((*aIter - *bIter), 2));
            
            if(*aIter < *bIter) aIter++;
            else bIter++;
        }
        
        
        for(int i = 2; i < n; i++){
            if(visited[i]) continue;
            
            curr.clear();
            dfs(i);
            sort(all(curr));
            
            auto caIter = ca.begin();
            auto cbIter = cb.begin();
            auto currIter = curr.begin();
            
            ll roadOne = abs(*caIter - *currIter);
            
            while(caIter != ca.end() and currIter != curr.end()){
                roadOne = min(roadOne, (ll)pow((*caIter - *currIter), 2));
                
                if(*caIter < *currIter) caIter++;
                else currIter++;
            }
            
            currIter = curr.begin();
            ll roadTwo = abs(*cbIter - *currIter);
            
            while(cbIter != cb.end() and currIter != curr.end()){
                roadTwo = min(roadTwo, (ll)pow((*cbIter - *currIter), 2));
                
                if(*cbIter < *currIter) cbIter++;
                else currIter++;
            }
            
            ans = min(ans, roadOne + roadTwo);
        }
        
        cout << ans << endl;
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
    
- Code 3 [rewrote the editorial Solution] (Passes first 5)
    
    ```C++
    \#include <bits/stdc++.h>
    
    using namespace std;
    
    // Type definitions for convenience
    
    \#define ll long long
    typedef vector<ll> vi;
    typedef vector<bool> vb;
    typedef pair<ll, ll> pii;
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
    
    ll n, m;
    vi comp;
    vvi comps;
    vvi tab;
    
    void dfs(ll x, ll cnt){
        if(comp[x] != -1) return;
        
        comp[x] = cnt;
        
        for(auto &i: tab[x]) dfs(i, cnt);
    }
    
    ll cost(ll a, ll b){
        
        ll ans = 1e5;
        
        for(auto node : comps[a]){
            auto iter = lower_bound(comps[b].begin(), comps[b].end(), node);
            
            if(iter != comps[b].end()) ans = min(ans, abs(*iter - node));
            
            if(iter != comps[b].begin()) ans = min(ans, abs(*prev(iter) - node));
        }
    
        return (ll)ans*ans;
    }
    
    void fx() {
        cin >> n >> m;
        comp.clear();
        comps.clear();
        tab.clear();
        comp.assign(n, -1);
        tab.assign(n, {});
        
        for(int i = 0; i < m; i++){
            ll a, b;
            cin >> a >> b;
            
            tab[--a].pb(--b);
            tab[b].pb(a);
        }
        
        int cnt = -1;
        
        for(int i = 0; i < n; i++){
            if(comp[i] != -1) continue;
            
            dfs(i, ++cnt);
        }
        
        comps.assign(cnt+1, {});
        
        for(int i = 0; i < n; i++) comps[comp[i]].pb(i);
        
        ll ans = cost(comp[0], comp[n-1]);
        
        for(int i = 0; i < comps.size(); i++) ans = min(ans, cost(comp[0], i) + cost(i, comp[n-1]));
        
        cout << ans << endl;
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
    

  

  

  

  

This seriously is one of the most annoying problem i’ve ever encountered.

  

Just ~~do~~ skip it.