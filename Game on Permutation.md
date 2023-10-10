---
Question Link: https://codeforces.com/contest/1860/problem/C
Problem Set:
  - DIV2C
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Game
  - Greedy
  - Structure
---
### Solution

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
    int n; cin >> n;
    vi tab(n);
    
    for(auto &i: tab) cin >> i;
    
    set<int>zeros;
    set<int>ones;
    
    zeros.insert(0);
    ones.insert(0);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(*zeros.upper_bound(-tab[i]) == 0) zeros.insert(-tab[i]);
        else if(*ones.upper_bound(-tab[i]) == 0){
            ones.insert(-tab[i]);
            ans++;
        }
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

### Solution Explanation

**Understanding the Logic:**

- **Sets, zeros, and ones**:
    - Two sets `zeros` and `ones` are created. Both start with the element `0`. This is crucial as the function `upper_bound` used later in the solution requires a reference point.
- **Negative Values and The Use of** `**upper_bound**`:
    - The solution inserts negative values of the permutation into `zeros` and `ones`. The purpose of using negative values is to effectively reverse the order of the set, so we can move from larger values to smaller values.
    - `upper_bound` for a set gives an iterator pointing to the first element that is "greater" than the provided value. By working with negative numbers, this means we are effectively looking for numbers that are smaller (because -5 is "greater" than -6).
- **Iterating through the permutation**:
    - For every value in the permutation:
        - First, it checks `zeros` to see if the value can be placed there (i.e., if it's larger than the currently considered value in the permutation).
        - If it can't be inserted into `zeros`, the solution checks `ones` to see if it can be placed there.
        - If the condition for `ones` is met, `ans` (answer) is incremented.
- **Main Logic Deciphered**:
    - When you see `zeros.upper_bound(-tab[i]) == 0` or `ones.upper_bound(-tab[i]) == 0`, the solution is essentially checking if it's possible to find a value greater than the negative of the current permutation value in those sets.
    - This checks if there's a smaller value to the left of the current value (`tab[i]`). If there's no such value in `zeros`, the value gets inserted there. Otherwise, if there's no such value in `ones`, the value gets inserted there, and the counter is incremented.
    - The distinction between the two sets allows us to effectively count the number of moves Bob will be forced to make. By having two sets (`zeros` and `ones`), we're mimicking the two players' alternating moves and determining the positions where Alice can always win.

  

**Why does it work?**

- The problem has a core constraint: a chip can be moved to a number to the left that is strictly less than the current number. If Alice can, after her first move, force a situation where Bob is forced to move the chip in a way that always lets Alice find a smaller number to its left, she can guarantee her win.
- The solution essentially maps out these forced movements. By maintaining two sets, we are able to simulate and track possible movements after Alice's initial placement of the chip. If the current number being considered can be placed into `ones`, it's counted as a winning position for Alice.

In essence, the solution cleverly uses data structures to model the game's constraints and simulate the possible sequences of moves for both players. This allows it to quickly identify positions that ensure a win for Alice.

### Editorial

TBA