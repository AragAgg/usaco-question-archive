---
Question Link: https://codeforces.com/contest/1556/problem/D
Problem Set:
  - "*1800"
  - Code Forces
  - DIV2D
Last edited time: 2023-10-24T13:10
Status: Nice Question
tags:
  - Bitwise
  - Constructive
  - Interactive
  - Math
Key Takeaway: a + b = 2*(a|b) + a xor b.a xor b = ~(a&b) & (a|b).a + b = (a|b) + (a&b).
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

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

// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

int take_inp(bool isOr, int i, int j){
    cout << ((isOr?"or":"and")) << " " << i << " " << j << endl;
    
    int res; 
    cin >> res;
    if(res == -1){
        cout << "Wrong Answer, interactor said -1\n";
        exit(1);
    }
    return res;
}

void fx() {
    int n, k;
    cin >> n >> k;
    
    int a_a_b, b_a_c, a_a_c, a_o_b, a_o_c, b_o_c;
    
    a_a_b = take_inp(false, 1, 2);
    a_a_c = take_inp(false, 1, 3);
    b_a_c = take_inp(false, 2, 3);
    a_o_b = take_inp(true, 1, 2);
    a_o_c = take_inp(true, 1, 3);
    b_o_c = take_inp(true, 2, 3);
    
    vi tab(n);
    
    int ab, ac, bc;
    
    ab = 2*(a_a_b) + (~(a_a_b) & (a_o_b));
    ac = 2*(a_a_c) + (~(a_a_c) & (a_o_c));
    bc = 2*(b_a_c) + (~(b_a_c) & (b_o_c));
    
    tab[0] = (ab + ac - bc)/2;
    tab[1] = ab - tab[0];
    tab[2] = bc - tab[1];
    
    for(int i = 3; i < n; i++){
        int OR = take_inp(true, i, i+1);
        int AND = take_inp(false, i, i+1);
        
        tab[i] = 2*(AND) + (~(AND) & (OR)) - tab[i-1];
    }
    
    sort(all(tab));
    
    cout << "finish " << tab[k-1] << endl;
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

### Solution From USACO Editorial [much more elegant]

```C++
\#include <bits/stdc++.h>
using namespace std;

int ask(string s, int a, int b) {
	cout << s << ' ' << a << ' ' << b << endl;
	int res;
	cin >> res;
	return res;
}

/** @return the sum of the elements at a and b (0-indexed) */
int sum(int a, int b) {
	int and_ = ask("and", ++a, ++b);
	int or_ = ask("or", a, b);

	int xor_ = ~and_ & or_;  // a ^ b = ~(a & b) & (a | b)

	return 2 * and_ + xor_;  // a + b = 2(a & b) + a ^ b
}

int main() {
	int n, k;
	cin >> n >> k;

	// Acquire the first 3 elements
	int a_plus_b = sum(0, 1);
	int a_plus_c = sum(0, 2);
	int b_plus_c = sum(1, 2);

	// Get the actual values by solving the equations
	vector<int> arr{(a_plus_b + a_plus_c - b_plus_c) / 2};
	arr.push_back(a_plus_b - arr[0]);
	arr.push_back(a_plus_c - arr[0]);

	// Get the rest of the array
	for (int i = 3; i < n; i++) { arr.push_back(sum(i - 1, i) - arr.back()); }

	sort(arr.begin(), arr.end());
	cout << "finish " << arr[k - 1] << endl;
}
```

### Editorial

> [!info] Deltix Round, Summer 2021. Editorial - Codeforces  
> Codeforces.  
> [https://codeforces.com/blog/entry/94384](https://codeforces.com/blog/entry/94384)  

> [!info] Intro to Bitwise Operators  
> Six bitwise operators and the common ways they are used.  
> [https://usaco.guide/silver/intro-bitwise](https://usaco.guide/silver/intro-bitwise)