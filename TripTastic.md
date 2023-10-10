---
Question Link: https://www.codechef.com/problems/TRPTSTIC#
Problem Set:
  - Code Chef
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - 2D-Prefix-Sum
  - Binary-Search
  - Implementation
  - Problem-Decomposition
Key Takeaway: When binary searching, it is often better to set hi to really high. It avoids one-off errors a lot of the times.Try to write code that works, don’t try to perfect it. (maintain reversibility tough)
---
### Solution History [WA]

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

ll N, M, K;
vector<vector<ll>>tab;

bool isVaible(ll r){
    r *= 2;
    r += 1;
    
    for(int i = min(1 + r, N); i < N+1; i++){
        for(int j = min(1+r, M); j < M+1; j++){
            ll total = tab[i][j] - tab[i][max(0LL, j-r-1)] - tab[max(0LL, i-r-1)][j] + tab[max(0LL, i-r-1)][max(0LL, j-r-1)];
            
            if(total >= K+1) return true;
        }
    }
    
    return false;
}

void fx() {
    // Functionality for fx
    cin >> N >> M >> K;
    tab.assign(N+1, vector<ll>(M+1, 0));
    
    for(int x = 1; x < N+1; x++){
        for(int y = 1; y < M+1; y++) cin >> tab[x][y];
    }
    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            tab[i][j] += tab[i-1][j] + tab[i][j-1] - tab[i-1][j-1];
        }
    }
    
    ll lo = 0;
    ll hi = max(N, M)/2 + 1;
    
    while(lo < hi){
        ll = lo + (hi - lo)/2;
        
        if(isVaible(mid)) hi = mid;
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

ll N, M, K;
vector<vector<ll>>tab;

bool isViable(ll r){
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if((tab[i][j] - tab[i][j-1] - tab[i-1][j] + tab[i-1][j-1])){
                ll total = tab[min(i+r, N)][min(j+r, M)] 
                            - tab[min(i+r, N)][max(0LL, j-r-1)]
                            - tab[max(0LL, i-r-1)][min(j+r, M)]
                            + tab[max(0LL, i-r-1)][max(0LL, j-r-1)];

                if(total >= K+1) return true;
            }
        }
    }
    return false;
}

void fx() {
    // Functionality for fx
    cin >> N >> M >> K;
    
    tab.clear();
    tab.assign(N+1, vector<ll>(M+1, 0));
    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++) cin >> tab[i][j];
    }
    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++) tab[i][j] += tab[i-1][j] + tab[i][j-1] - tab[i-1][j-1];
    }
    
    ll lo = 0;
    ll hi = 2 + max(N, M)/2;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)) hi = mid;
        else lo = mid+1;
    }
    
    cout << ((lo == 2 + max(N, M)/2)?-1:lo) << endl;
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

### Solution Explanation

### Core Logic:

1. **Prefix Sum Matrix:**
    - The code first constructs a 2D prefix sum matrix from the input matrix. This step is crucial as it allows for the calculation of the sum of any submatrix in constant time, which is used to check if a certain arrangement can accommodate all students and the mentor.
2. **Binary Search:**
    - The code performs a binary search on the possible maximum distances from the mentor's room to any student's room. For each possible distance `r`, it checks if there is a room such that all students and the mentor can be accommodated in the surrounding rooms within distance `r`. This is done by using the prefix sum matrix to quickly calculate the total capacity of the rooms within distance `r` from each room.

### Observations and Insights:

- **Utilizing Prefix Sum Matrix:**
    - The use of a prefix sum matrix is a valuable insight. It allows for efficient computation of the total capacity of a submatrix, enabling the solution to quickly check the viability of each possible distance `r`.
- **Binary Search for Optimal Distance:**
    - The problem involves finding a minimum distance that satisfies certain conditions. This is a hint that binary search can be used to efficiently find the optimal distance by checking the conditions for each possible distance.

### Key Takeaways:

1. **Efficient Submatrix Sum Calculation:**
    - Learn the technique of using a prefix sum matrix to efficiently compute the sum of elements in a submatrix. This technique is useful in many problems involving matrices.
2. **Applying Binary Search to Optimize Distance:**
    - Understand how to apply binary search to optimize distances or other similar parameters. Recognize when binary search can be used to efficiently find a value that meets certain conditions.
3. **Combining Techniques:**
    - Learn how to combine different techniques (prefix sum matrix and binary search in this case) to create an efficient solution to a complex problem.

In summary, the solution efficiently finds the minimum possible distance by using a prefix sum matrix for fast capacity calculations and binary search to optimize the distance. The key takeaways include understanding the use of a prefix sum matrix and applying binary search to optimize distances.