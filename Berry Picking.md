---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=990
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Solved with Help
Key Takeaway: Try to explicitly find implicit hints (expected time complexities, solution approach, or any other subtlety) in the problem statement itself, often the problem setter’s language will hint towards a possible path.If a = min(b, c) s.t. b ≤ c, then it suffices to say a = b%c
---
### Solution (from the editorial)

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
    int n, k;
    cin >> n >> k;
    
    int maxn = 0;
    
    vi tab(n);
    for(auto &i: tab){ cin >> i; maxn = max(maxn, i);}
    
    sort(all(tab));
    reverse(all(tab));
    
    int ans = 0;
    
    for(int i = 1; i <= maxn; i++){
        priority_queue<int>pq(all(tab));
        
        int counter = k/2;
        while(pq.size() and counter--){
            int t = pq.top();
            pq.pop();
            if(t < i) break;
            if(t > i) pq.push(t - i);
        }
        
        if(counter+1) continue;
        
        counter = k/2;
        int curr = 0;
        
        while(pq.size() and counter--){
            int t = pq.top();
            pq.pop();
            curr += min(i, t);
            if(t > i) pq.push(t -i);
        }
        
        ans = max(ans, curr);
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("berries"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial (from: USACO)

> [!info] Solution - Berry Picking (USACO Silver 2020 January)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-990-berry-picking/solution](https://usaco.guide/problems/usaco-990-berry-picking/solution)