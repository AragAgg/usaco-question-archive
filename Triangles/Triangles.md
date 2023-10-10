---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1015
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Coordinate-Compression
  - Implementation
  - Math
  - Sorting
  - Structure
Key Takeaway: 1e9+7 is very different from 10e9+7.A different way of coordinate compression (if the range is small i.e. <10^4) is to store the new coordinates in an unordered/ordered map like [10^5*old.x + old.y] = 10^5*new.x + new.y.
---
### What i’ve thought of till now

1. use two arrays of size `2*|-4*10^5 - 4*10^5|` to store the number of points at each `x coord.` and `y coord.` Possible as `a[]` and `b[]`.
2. iterate over every point and treat that point as the centre point (the 90° point)
3. now for each point in our input, there would be `(a[x]-1) * (b[x]-1)`.
4. finally output the answer.

  

### Solution (AC) [the code is a bit messy]

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
    int n;
    cin >> n;
    
    vii tab(n);
    for(auto &i: tab){ cin >> i.f >> i.s;}
    
    sort(all(tab));
    
    unordered_map<long long, long long>mpx;
    
    const int offset = 100000;
    
    for(int i = 0; i < n; i++){
        mpx[offset*tab[i].f + tab[i].s] = 0;
        
        int counter = 0;
        
        int t = i+1;
        
        while(t < n and tab[t].f == tab[i].f){
            mpx[offset*tab[i].f + tab[i].s] += tab[t].s - tab[i].s;
            counter++;
            t++;
        }
        
        t = i+1;
        
        while(t < n and tab[t].f == tab[i].f){
            mpx[offset*tab[t].f + tab[t].s] = mpx[offset*tab[t].f + tab[t-1].s] + (tab[t].s - tab[t-1].s)*(t-i) - (tab[t].s - tab[t-1].s)*(counter--);
            t++;
        }
        i = t-1;
    }
    
  
    sort(all(tab), [](auto &a, auto &b){if(a.s == b.s) return (a.f < b.f); else return (a.s < b.s);});
    
    unordered_map<long long, long long>mpy;
    
    for(int i = 0; i < n; i++){
        mpy[offset*tab[i].f + tab[i].s] = 0;
        
        int counter = 0;
        
        int t = i+1;
        
        while(t < n and tab[t].s == tab[i].s){
            mpy[offset*tab[i].f + tab[i].s] += tab[t].f - tab[i].f;
            counter++;
            t++;
        }
        
        t = i+1;
        
        while(t < n and tab[t].s == tab[i].s){
            mpy[offset*tab[t].f + tab[t].s] = mpy[offset*tab[t-1].f + tab[t].s] + (tab[t].f - tab[t-1].f)*(t-i) - (tab[t].f - tab[t-1].f)*(counter--);
            t++;
        }
        i = t-1;
    }
    
    long long ans = 0;
    const long long mod = 1e9+7;
    
    for(auto &i: tab){
        long long curr = (mpx[offset*i.f + i.s] * mpy[offset*i.f + i.s])%mod;
        ans += curr;
        
        ans %= mod;
        
    }
    
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("triangles"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

### Problem Statement:

Given a set of points on a 2D plane, the task is to find the sum of the areas of all possible triangles that can be formed using these points as vertices. The triangles must have their sides parallel to the x-axis or y-axis. The answer can be large, so it should be given modulo \(10^9 + 7\).

### Observations:

1. If a triangle has its sides parallel to the x-axis or y-axis, then two of its vertices will have the same x-coordinate, and the other two vertices will have the same y-coordinate.
2. The area of such a triangle can be computed using the difference in x-coordinates and the difference in y-coordinates of the vertices.

### Solution Approach:

1. **Type Definitions and Macros**: The solution starts with some type definitions and macros for convenience. These are just to make the code more readable and concise.
2. **Input Reading**: The function `fx()` is the main function that solves the problem. It starts by reading the number of points `n` and then the coordinates of each point.
3. **Sorting by x-coordinate**: The list of points `tab` is sorted based on their x-coordinates. This will help in grouping points with the same x-coordinate together.
4. **Computing x-coordinate differences**: For each point, the solution computes the sum of the differences in y-coordinates for all points to its right with the same x-coordinate. This is stored in the `mpx` map.
5. **Sorting by y-coordinate**: The list of points `tab` is then sorted based on their y-coordinates. This will help in grouping points with the same y-coordinate together.
6. **Computing y-coordinate differences**: Similarly, for each point, the solution computes the sum of the differences in x-coordinates for all points to its right with the same y-coordinate. This is stored in the `mpy` map.
7. **Computing the answer**: For each point, the solution multiplies its x-coordinate differences (from `mpx`) with its y-coordinate differences (from `mpy`). This gives the total area contribution of that point when it is used as a vertex in triangles. The sum of these contributions for all points gives the final answer.

### Why the Solution Works:

1. By sorting the points based on x-coordinates and then y-coordinates, the solution efficiently groups points with the same coordinates together. This makes it easier to compute the differences in coordinates, which are essential for computing the triangle areas.
2. The use of maps (`mpx` and `mpy`) allows for efficient storage and retrieval of coordinate differences.
3. The final loop that computes the answer takes advantage of the previously computed coordinate differences to compute the total area contribution of each point.

### Key Observations Used:

1. The area of a triangle with sides parallel to the axes can be computed using the differences in coordinates of its vertices.
2. By grouping points with the same x or y coordinates together, we can efficiently compute the coordinate differences for all such points.

In summary, the solution efficiently computes the areas of all possible triangles by first computing the coordinate differences for all points and then using these differences to compute the total area contribution of each point.

### Editorial

![[Screenshot_2023-09-02_at_8.48.42_PM.png]]

### Editorial Explanation

### Problem Restatement:

Given a set of points, we want to find the sum of areas of all triangles that have one vertex at a given point `(X1, Y1)` and the other two vertices on the x-axis and y-axis, respectively.

### Key Insight:

The editorial starts with a key observation. If we want to calculate the area of triangles with a right angle at `(X1, Y1)`, then the other two vertices will lie on the vertical line `X = X1` and the horizontal line `Y = Y1`.

### Formulation:

Given this observation, the editorial defines two sets:

- `A1`: The set of all y-coordinates of points that lie on the vertical line `X = X1`.
- `B1`: The set of all x-coordinates of points that lie on the horizontal line `Y = Y1`.

The area of a triangle with a right angle at `(X1, Y1)` is proportional to the distance between the y-coordinates of the two points on `X = X1` and the distance between the x-coordinates of the two points on `Y = Y1`.

Thus, the total area of all such triangles is given by:  
\[ \text{Total Area} = \left( \sum_{y \in A1} |Y1 - y| \right) \times \left( \sum_{x \in B1} |X1 - x| \right) \]

### Efficient Computation:

The main challenge now is to compute the sum of absolute differences for each point efficiently. For a sorted list of x-coordinates `x1, x2, ..., xn`, we want to compute:  
\[ s_i = \sum_{j=1}^{n} |x_i - x_j| \]  
for each `i`.

The editorial provides a method to compute this in linear time. First, compute `s1`. Then, for each `i` from `1` to `N-1`, we can compute `s_{i+1}` using the formula:  
\[ s_{i+1} = s_i + (2i - N) \times (x_{i+1} - x_i) \]

### Explanation of the Formula:

Imagine you have a sorted list of numbers. When you move from one number to the next, the difference between that number and all numbers to its left increases, while the difference between that number and all numbers to its right decreases. The formula captures this behavior.