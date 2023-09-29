---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1302
Problem Set:
  - Silver
Last edited time: 2023-09-29T20:38
Status: Seen Editorial
tags:
  - Binary-Search
  - Implementation
What's up: Requires proficient understanding of inequalities. We could derive two inequalities and then use them to find an upper and an lower bound of x for the case where mooney is fixed to w. Also note that once we have a checker function, a binary search should suffice as if we can find a valid state using w mooney, we could also find a valid state using w+1 moonies.
Key Takeaway: Learn about inequalities. If a question gets messy because of too many mathematical constraints, use that as an advantage. Its usually a combination of inequalities.
---
### Solution History

- Code
    
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
    
    int n, ta, tb;
    
    vi a, b, c;
    
    
    bool isViable(ll m){
        for(int i = 0; i < n; i++){
            cout << i << " #" << endl;
            ll reqTime = a[i]*(ta) + b[i]*(tb);
            
            if(reqTime <= c[i]) continue;
            
            if(!m or (ta <= 1 and tb <= 1)) return false;
            
            if((a[i] > b[i] or (b[i] == a[i] and ta >= tb)) and ta > 1){
                ll target = ceil((c[i] - b[i]*tb)/a[i]);  // maximum ta that could still pass c[i]...
                assert(target < ta);
                ll take = min(m, (ta - target));
                
                m -= take;
                ta -= target;
                cout << take << endl;
            }else{
                ll target = ceil((c[i] - a[i]*ta)/b[i]); // maximum tb that could still pass c[i]...
                assert(target < tb);
                ll take = min(m, (tb - target));
                
                m -= take;
                tb -= target;
                cout << take << endl;
            }
            
            cout << "reached\n\n";
            
            if(a[i]*ta + b[i]*tb > c[i]) return false;
            
        }
        
        return true;
    }
    
    void fx() {
        // Functionality for fx
        cin >> n >> ta >> tb;
        
        a.clear();
        b.clear();
        c.clear();
        
        for(int i = 0; i < n; i++){
            int tempa, tempb, tempc;
            cin >> tempa >> tempb >> tempc;
            
            a.pb(tempa); b.pb(tempb); c.pb(tempc);
        }
        
        ll lo = 0;
        ll hi = 1e2+100;
        
        while(lo < hi){
            ll mid = lo + (hi - lo+1)/2;
            cout << lo << " " << mid << " " << hi << endl;
            
            if(isViable(mid)) lo = mid;
            else hi = mid -1;
        }
        
        cout << lo << endl;
        
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
    
- Code [correct approach and direction, wrong formulas]
    
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
    
    int n, orita, oritb;
    
    vi a, b, c;
    
    
    bool isViable(ll m){
        int ta = orita;
        int tb = oritb;
        for(int i = 0; i < n; i++){
            cout << i << " #" << endl;
            ll reqTime = a[i]*(ta) + b[i]*(tb);
            
            if(reqTime <= c[i]) continue;
            
            if(!m or (ta <= 1 and tb <= 1)) return false;
            
            if((a[i] > b[i] or (b[i] == a[i] and ta >= tb)) and ta > 1){
                cout << "c1\n";
                ll target = max((long long)ceil((c[i] - b[i]*tb)/a[i]), 1LL);  // maximum ta that could still pass c[i]...
                assert(target < ta);
                ll take = min(m, (ta - target));
                cout << "target : " <<target<< " take: " << take << " ta: " << ta<<  endl;
                
                m -= take;
                ta -= target;
                
            }else{
                cout << "c2\n";
                ll target = max((long long)ceil((c[i] - a[i]*ta)/b[i]), 1LL); // maximum tb that could still pass c[i]...
                assert(target < tb);
                ll take = min(m, (tb - target));
                
                m -= take;
                tb -= target;
            }
            
            cout << "reached\n\n";
            
            if(a[i]*ta + b[i]*tb > c[i]) return false;
            
        }
        
        return true;
    }
    
    void fx() {
        // Functionality for fx
        cin >> n >> orita >> oritb;
        
        a.clear();
        b.clear();
        c.clear();
        
        for(int i = 0; i < n; i++){
            int tempa, tempb, tempc;
            cin >> tempa >> tempb >> tempc;
            
            a.pb(tempa); b.pb(tempb); c.pb(tempc);
        }
        
        ll lo = 0;
        ll hi = 1e2+100;
        
        while(lo < hi){
            ll mid = lo + (hi - lo)/2;
            cout << lo << " " << mid << " " << hi << endl;
            
            if(isViable(mid)) hi = mid;
            else lo = mid+1;
        }
        
        cout << lo << endl;
        
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

ll n, ta, tb;

vector<ll> a, b, c;

bool isViable(ll m){

    ll d = ta + tb - m;
    ll lx = max(1LL, ta - m);
    ll hx = min(ta, ta + tb - m -1);
    
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]) lx = max(lx, (b[i]*d - c[i] + b[i] - a[i] -1)/(b[i] - a[i]));
        else if(a[i] > b[i]) hx = min(hx, ((c[i] - b[i]*d)/(a[i] - b[i])));
        else if(a[i]*d > c[i]) return false;
    }
    
    return (lx <= hx);
}

void fx() {
    // Functionality for fx
    cin >> n >> ta >> tb;
    
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);
    
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    
    ll lo = 0;
    ll hi = ta + tb -2;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)) hi = mid;
        else lo = mid+1;
    }
    
    cout << lo << endl;
    
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

### Editorial

> [!info] Contest Results  
> Suppose Bessie's oven ends up taking $x$ units of time to produce a cookie and  
> [http://www.usaco.org/current/data/sol_prob1_silver_feb23.html](http://www.usaco.org/current/data/sol_prob1_silver_feb23.html)