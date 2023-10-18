---
Question Link: https://cses.fi/problemset/task/1632
Problem Set:
  - CSES
Last edited time: 2023-10-18T19:10
Status: Nice Question
tags:
  - Interval-Scheduling
  - Sorting
  - Structure
  - Unclear-Statement
What's up: Solved +7
Key Takeaway: "Maybe: When solving greedy, try being irrationality greedy. If you could optimize your code to be ‘just no worse’, just do it."
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

void fx() {
    int n, k;
    cin >> n >> k;
    
    vii movies(n);
    for(auto &movie : movies) cin >> movie.s >> movie.f;
    
    sort(all(movies));
    
    int ans = 0;
    
    multiset<int>people;
    for(int i = 0; i < k; i++) people.insert(0);
    
    for(auto &movie: movies){
        auto iter = people.upper_bound(movie.s);
        
        if(iter == people.begin()) continue;
        else{
            --iter;
            
            people.insert(movie.f);
            people.erase(iter);
            ans++;
        }
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

### Another Solution (stolen) [better comments]

```C++
/*
Visit through all the points in order. Keep a set to store movies that can be
seen at the moment, using end time to compare. When the current set size is
greater than k, we pick the movie with the largest end time to drop. (because a
larger end time is more likely to overlap with upcoming movies)

Time: O(n log n)
*/
\#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = n;
  map<int, vector<int>> to_add;
  set<int> points;
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    int start, end;
    cin >> start >> end;
    points.insert(start);
    points.insert(end);
    to_add[start].push_back(end);
  }
  for (int pt : points) {
    while (!s.empty() && *s.begin() == pt) s.erase(s.begin());
    for (int end : to_add[pt]) {
      s.insert(end);
      if (s.size() > k) {
        ans--;
        s.erase(s.find(*s.rbegin()));
      }
    }
  }
  cout << ans;
}
```

### Editorial (Really Unintuitive)

> [!info] Solution - Movie Festival II (CSES)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cses-1632-movie-festival-ii/solution](https://usaco.guide/problems/cses-1632-movie-festival-ii/solution)