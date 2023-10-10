---
Question Link: https://codeforces.com/contest/862/problem/E
Problem Set:
  - "*2100"
  - Code Forces
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Implementation
  - Math
  - Sorting
  - Structure
What's up: Solved.
Key Takeaway: If a math based question appears too difficult, try to simplify the math. If its’s an equation, try playing around with it for a while and if it’s not an equation, try to form one and then follow through. Try to use prev(iter) and next(iter) wherever you can, because the increment and decrement operators might behave unexpectedly in some places. Basically iterator function are more robust and reliable than pointer mathematics.
---
### Solution Version History

- Code 1 `(Incomplete)`
    
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
        int n, m, q;
        cin >> n >> m >> q;
        
        vi a(n);
        vi b(m);
        
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        
        int term_a = 0;
        bool neg = false;
        
        for(auto &i: a){
            term_a += (neg?-1:1)*i;
            neg = !neg;
        }
        
        set<int>term_bs;
        
        int ods = 0;
        int evs = 0;
        neg = false;
        
        for(int j = 0; j < i; j++){
            ods += (neg?1:0)*b[j];
            evs += (neg?0:1)*b[j];
            neg = !neg;
        }
        
        term_bs.insert(ods - evs);
        neg = false;
        
        for(int j = 1; j <= m-n; j++){ // might cause ec139
            ods -= b[j-1];
            
            if(n%2){
                ods += b[i-1+j];
            }else{
                evs += b[i-1+j];
            }
            
            term_bs.insert(ods - evs);
            
            swap(ods, evs);
        }
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
    
- Code 2 `(Incomplete)`
    
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
        int n, m, q;
        cin >> n >> m >> q;
        
        vi a(n);
        vi b(m);
        
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        
        int term_a = 0;
        bool neg = false;
        
        for(auto &i: a){
            term_a += (neg?-1:1)*i;
            neg = !neg;
        }
        
        set<int>term_bs;
        
        int ods = 0;
        int evs = 0;
        neg = false;
        
        for(int j = 0; j < i; j++){
            ods += (neg?1:0)*b[j];
            evs += (neg?0:1)*b[j];
            neg = !neg;
        }
        
        term_bs.insert(ods - evs);
        neg = false;
        
        for(int j = 1; j <= m-n; j++){ // might cause ec139... but probably not...
            ods -= b[j-1];
            
            if(n%2){
                evs += b[n-1+j];
            }else{
                ods += b[n-1+j];
            }
            
            swap(ods, evs);
            
            term_bs.insert(ods - evs);
            
        }
        
        
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
    
- Code 3 `(Incomplete)`
    
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
    
    
    set<int>term_bs;
    
    int calcAns(int term_a){
        auto iter = term_bs.lower_bound(term_a);
        if(*iter == term_a or iter == term_bs.begin()) return *iter - term_a;
        return min(*iter - term_a, term_a - *(--iter));
    }
    
    void fx() {
        // Functionality for fx
        int n, m, q;
        cin >> n >> m >> q;
        
        vi a(n);
        vi b(m);
        
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        
        int term_a = 0;
        bool neg = false;
        
        for(auto &i: a){
            term_a += (neg?-1:1)*i;
            neg = !neg;
        }
        
        
        int ods = 0;
        int evs = 0;
        neg = false;
        
        for(int j = 0; j < i; j++){
            ods += (neg?1:0)*b[j];
            evs += (neg?0:1)*b[j];
            neg = !neg;
        }
        
        term_bs.insert(ods - evs);
        neg = false;
        
        for(int j = 1; j <= m-n; j++){ // might cause ec139... but probably not...
            ods -= b[j-1];
            
            if(n%2){
                evs += b[n-1+j];
            }else{
                ods += b[n-1+j];
            }
            
            swap(ods, evs);
            
            term_bs.insert(ods - evs);
            
        }
        
        cout << calcAns(term_a) << endl;
        
        for(int i = 0; i < q; i++){
            int l, r, x;
            cin >> l >> r >> x;
            
            if(((r-l+1)%2)){
                term_a += (l%2?-1:+1)*x;
            }
            
            cout << calcAns(term_a) << endl;
        }
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
    
- Code 4 `(Incomplete)`
    
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
    
    
    set<int>term_bs;
    
    int calcAns(int term_a){
        auto iter = term_bs.lower_bound(term_a);
        if(iter == term_bs.end()) return (term_a - *(--(term_bs.end())));
        if(*iter == term_a or iter == term_bs.begin()) return *iter - term_a;
        return min(*iter - term_a, term_a - *(--iter));
    }
    
    void fx() {
        // Functionality for fx
        int n, m, q;
        cin >> n >> m >> q;
        
        vi a(n);
        vi b(m);
        
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        
        int term_a = 0;
        bool neg = false;
        
        for(auto &i: a){
            term_a += (neg?-1:1)*i;
            neg = !neg;
        }
        
        
        int ods = 0;
        int evs = 0;
        neg = false;
        
        for(int j = 0; j < i; j++){
            (neg?ods:evs) += b[j];
            neg = !neg;
        }
        
        term_bs.insert(evs - ods);
        neg = false;
        
        for(int j = 1; j <= m-n; j++){ // might cause ec139... but probably not...
            ods -= b[j-1];
            
            if(n%2){
                evs += b[n-1+j];
            }else{
                ods += b[n-1+j];
            }
            
            swap(ods, evs);
            
            term_bs.insert(ods - evs);
            
        }
        
        cout << calcAns(term_a) << endl;
        
        for(int i = 0; i < q; i++){
            int l, r, x;
            cin >> l >> r >> x;
            
            if(((r-l+1)%2)){
                term_a += (l%2?-1:+1)*x;
            }
            
            cout << calcAns(term_a) << endl;
        }
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
    
- Code 5 `(Incomplete)`
    
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
    
    
    set<int>term_bs;
    
    int calcAns(int term_a){
        auto iter = term_bs.lower_bound(term_a);
        if(iter == term_bs.end()) return (term_a - *(--(term_bs.end())));
        if(*iter == term_a or iter == term_bs.begin()) return *iter - term_a;
        return min(*iter - term_a, term_a - *(--iter));
    }
    
    void fx() {
        // Functionality for fx
        int n, m, q;
        cin >> n >> m >> q;
        
        vi a(n);
        vi b(m);
        
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        
        int term_a = 0;
        bool neg = false;
        
        for(auto &i: a){
            term_a += (neg?-1:1)*i;
            neg = !neg;
        }
        
        
        int ods = 0;
        int evs = 0;
        neg = false;
        
        for(int j = 0; j < i; j++){
            (neg?ods:evs) += b[j];
            neg = !neg;
        }
        
        term_bs.insert(evs - ods);
        neg = false;
        
        for(int j = 1; j <= m-n; j++){ // might cause ec139... but probably not...
            (neg?odd:evs) -= b[j-1];
            
            if(n%2) (neg?evs:ods) += b[n+j-1];
            else (neg?ods:evs) += b[n+j-1];
            
            term_bs.insert((neg?(evs - ods):(ods - evs)));
            
            neg = !neg;
            
        }
        
        cout << calcAns(term_a) << endl;
        
        for(int i = 0; i < q; i++){
            int l, r, x;
            cin >> l >> r >> x;
            
            if(((r-l+1)%2)){
                term_a += (l%2?-1:+1)*x;
            }
            
            cout << calcAns(term_a) << endl;
        }
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
    

  

### Final Solution (AC)

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


set<long long>term_bs;

long long calcAns(long long term_a){
    auto iter = term_bs.lower_bound(term_a);
    if(iter == term_bs.end()) return abs(term_a - *((--term_bs.end())));
    if(*iter == term_a or iter == term_bs.begin()) return abs(*iter - term_a);
    return min(abs(*iter - term_a), abs(term_a - *prev(iter)));
}

void fx() {
    // Functionality for fx
    long long n, m, q;
    cin >> n >> m >> q;
    
    vector<long long> a(n), b(m);
    
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    
    long long term_a = 0, ods = 0, evs = 0;
    bool neg = false;
    
    for(auto &i: a){
        term_a += (neg?-1:1)*i;
        neg = !neg;
    }
    
    neg = false;
    
    for(int j = 0; j < n; j++){
        (neg?ods:evs) += b[j];
        neg = !neg;
    }
    
    term_bs.insert(evs - ods);
    neg = false;
    
    for(int j = 1; j <= m-n; j++){
        (neg?ods:evs) -= b[j-1];
        
        if(n%2) (neg?evs:ods) += b[n+j-1];
        else (neg?ods:evs) += b[n+j-1];
        
        term_bs.insert((neg?(evs - ods):(ods - evs)));
        neg = !neg;
    }
    
    cout << calcAns(term_a) << endl;
    
    for(int i = 0; i < q; i++){
        long long l, r, x;
        cin >> l >> r >> x;
        
        if((r-l+1)%2){
            term_a += (l%2?+1:-1)*x;
        }
        
        cout << calcAns(term_a) << endl;
    }
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

1. **Type Definitions and Macros**:  
    The code starts with a bunch of type definitions and macros to simplify and make the code more readable. This is a common practice in competitive programming.
2. **Global Data Structures**:
    - `set<long long>term_bs;`: This set will store the difference between the sum of even and odd indexed elements of the array `b` for different values of `j`.
3. **Function** `**calcAns**`:
    - This function calculates the minimum difference between `term_a` and any value in `term_bs`.
    - It uses the `lower_bound` function to find the closest value in `term_bs` to `term_a`.
    - The function returns the minimum difference between `term_a` and the closest values in the set `term_bs`.
4. **Function** `**fx**`:
    - This function implements the main logic of the solution.
    - It starts by reading the input values of `n`, `m`, `q`, `a`, and `b`.
    - `term_a` is calculated as the alternating sum of the elements of `a`.
    - The code then calculates the sum of even and odd indexed elements of the first `n` elements of `b` and inserts the difference into `term_bs`.
    - The loop that follows updates the values of `term_bs` for different values of `j` by sliding over the array `b`.
    - After populating `term_bs`, the code prints the result of `calcAns(term_a)`.
    - The next loop processes the `q` update queries. For each update, it modifies `term_a` if necessary and then prints the result of `calcAns(term_a)`.
5. **Main Function**:
    - The `main` function is the entry point of the program. It simply calls the `fx` function to process the input and produce the output.

**Logic and Thought Process**:

The main idea behind the solution is to precompute the possible values of the function `f(j)` for all valid `j` and store them in the set `term_bs`. This is done by calculating the difference between the sum of even and odd indexed elements of the array `b` for different values of `j`.

Once `term_bs` is populated, for each query, the code calculates the value of `term_a` (which is affected by the update) and then finds the closest value in `term_bs` to `term_a` using the `calcAns` function. This approach ensures that the solution is efficient and can handle multiple queries quickly.

In summary, the solution cleverly uses precomputation and efficient data structures to solve the problem in an optimal manner.

  

### Editorial (from: USACO)

> [!info] Solution - Mahmoud and Ehab and the function (CF)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cf-mahmoud--ehab--function/solution](https://usaco.guide/problems/cf-mahmoud--ehab--function/solution)