---
Question Link: https://codeforces.com/contest/994/problem/C
Problem Set:
  - "*1600"
  - Code Forces
  - DIV2C
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Geometry
  - Implementation
  - Math
Key Takeaway: "A point (x, y) can be rotated by 45deg by doing this transformation: (x, y) → (x+y, x-y). [but this increases our distance from the origin by a factor of sqrt(2)]bool pointIn(pii p, pii a, pii b){ return (p.f >= min(a.f, b.f) and p.f <= max(a.f, b.f) and p.s >= min(a.s, b.s) and p.s <= max(a.s, b.s));} is a nice way to check if a point p is in a square, defined by two opposite corners a and b."
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

bool pointIn(pii p, pii a, pii b){ return (p.f >= min(a.f, b.f) and p.f <= max(a.f, b.f) and p.s >= min(a.s, b.s) and p.s <= max(a.s, b.s));}
void transform(vii &a){
    for(auto &i: a){
        int t = i.f;
        i.f += i.s;
        i.s = t - i.s;
    }
}

void fx() {
    // Functionality for fx
    vii a(4), b(4);
    for(auto &i: a) cin >> i.f >> i.s;
    for(auto &i: b) cin >> i.f >> i.s;
    
    for(auto &p: b){
        if(pointIn(p, a[0], a[2])){
            yes();
            return;
        }
    }
    if(pointIn({(b[0].f + b[2].f)/d2, (b[0].s + b[2].s)/2}, a[0], a[2])){ yes(); return; };
    transform(a);
    transform(b);
    if(pointIn({(a[0].f + a[2].f)/2, (a[0].s + a[2].s)/2}, b[0], b[2])){ yes(); return;};
    for(auto &p: a){
        if(pointIn(p, b[0], b[2])){
            yes();
            return;
        }
    }
    
    no();
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

### Solution Explanation

### Problem Understanding:

The problem (which isn't provided but can be inferred from the code) seems to be related to geometry, specifically checking if two rectangles intersect or overlap. Each rectangle is defined by four points, and the goal is to determine if any part of one rectangle lies inside the other.

### Core Logic:

1. **Point Inside Rectangle Check (**`**pointIn**` **function)**:
    - This function checks if a given point `p` lies inside a rectangle defined by its diagonal points `a` and `b`. It checks if the x-coordinate and y-coordinate of `p` lie between the x and y coordinates of `a` and `b`, respectively.
2. **Transform Function**:
    - This function seems to be performing a transformation on the rectangle's points. It appears to rotate the rectangle around its center. This is inferred from the way the x and y coordinates are being swapped and adjusted.
3. **Main Logic (**`**fx**` **function)**:
    - The function first reads in the points defining two rectangles `a` and `b`.
    - It then checks if any corner point of rectangle `b` lies inside rectangle `a`. If any such point is found, the rectangles overlap, and the answer is "YES".
    - Next, it checks if the center of rectangle `b` lies inside rectangle `a`. If it does, the rectangles overlap.
    - The function then transforms both rectangles, essentially checking the overlap from another perspective (after rotating both rectangles).
    - It then checks if the center of the transformed rectangle `a` lies inside the transformed rectangle `b`.
    - Finally, it checks if any corner point of the transformed rectangle `a` lies inside the transformed rectangle `b`.

### Observations and Insights:

- **Checking Corners and Center**: One of the key insights here is that to check if two rectangles overlap, it's sufficient to check if any corner of one rectangle lies inside the other. Additionally, checking the center provides another quick way to determine overlap, especially after transforming the rectangles.
- **Transformation**: The transformation (or rotation) step is crucial. It's possible that in their initial positions, the rectangles don't overlap, but when viewed (or rotated) from another perspective, they do. This step ensures that the solution doesn't miss such cases.

### Key Takeaways:

1. **Geometry Problems**: Geometry problems often require visualizing the problem space. In this case, visualizing how rectangles can overlap is crucial.
2. **Checking Multiple Perspectives**: Sometimes, checking a problem from multiple perspectives (like the transformation here) can simplify the solution or ensure all cases are covered.
3. **Efficiency**: Instead of checking every single point inside one rectangle against another (which would be inefficient), the solution smartly checks only the corners and the center, reducing the number of checks significantly.

In summary, the solution employs a combination of geometric insights and efficient checking to determine if two rectangles overlap. The use of transformation to rotate and check from another perspective is a clever way to ensure all overlapping scenarios are captured.

### Editorial

![[Screenshot_2023-09-20_at_7.59.16_PM.png]]