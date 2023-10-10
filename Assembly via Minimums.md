---
Question Link: https://codeforces.com/contest/1857/problem/C
Problem Set:
  - DIV3C
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Greedy
  - Sorting
Key Takeaway: When a question looks like greedy, but you’re unable to come up with a solution, try randomly sorting stuff and see if something comes up.
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
    // Functionality for fx
    int n;
    cin >> n;
    
    int x = (n * (n-1))/2;
    
    vi tab(x);
    
    for(auto &i: tab) cin >> i;
    
    sort(tab.begin(), tab.end());
    
    vi ori(n);
    
    int counter = n-1;
    int curr = 0;
    
    // for(auto &item: ori){
    //     item = tab[curr];
        
    //     curr += counter;
    //     counter--;
    // }
    
    for(int i = 0; i < ori.size()-1; i++){
        ori[i] = tab[curr];
        
        curr += counter;
        counter--;
    }
    
    ori[ori.size()-1] = 1000000000;
    
    for(auto &i: ori) cout << i << " ";
    cout << endl;
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

### Editorial Explanation

  

Suppose we have an array 𝑎a that we want to construct, with elements 𝑎1,𝑎2,…,𝑎𝑛a1,a2,…,an. To simplify the process, let's assume that the elements of 𝑎a are sorted in non-decreasing order, meaning 𝑎1≤𝑎2≤⋯≤𝑎𝑛a1≤a2≤⋯≤an.

  

Let's start with 𝑎1a1. Since the elements of 𝑎a are sorted, the pairs (𝑎1,𝑎2),(𝑎1,𝑎3),…,(𝑎1,𝑎𝑛)(a1,a2),(a1,a3),…,(a1,an) will have 𝑎1a1 as the smallest element in each pair. Therefore, the number of occurrences of 𝑎1a1 in array 𝑏b will be 𝑛−1n−1.

  

Moving on to 𝑎2a2, we already know that 𝑎1a1 appears 𝑛−1n−1 times in 𝑏b. Since the elements of 𝑎a are sorted, all pairs involving 𝑎2a2 will have 𝑎2a2 as the second smallest element. This means 𝑎2a2 will appear 𝑛−2n−2 times in array 𝑏b.

  

We continue this process for each element 𝑎𝑖ai in 𝑎a. The number of occurrences of 𝑎𝑖ai in array 𝑏b will be 𝑛−𝑖n−i.

  

We can't determine the exact value of 𝑎𝑛an , because it won't be written to array b. Therefore, for 𝑎𝑛an we can choose any number in the range [𝑎𝑛−1;109][an−1;109].

  

In case there are multiple elements 𝑏𝑖bi in array 𝑏b that satisfy the condition for a particular 𝑎𝑖ai, we choose the smallest 𝑏𝑖bi. This greedy approach works, because we are constructing 𝑎a in non-decreasing order.

  

The complexity is 𝑂(𝑛2log𝑛)O(n2log⁡n).

  

### Editorial Code (Reallyyyyyy Short)

```C++
\#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int m=n*(n-1)/2,b[m];
        for(int i=0;i<m;i++)cin>>b[i];
        sort(b,b+m);
        for(int i=0;i<m;i+=--n)cout<<b[i]<<' ';
        cout<<"1000000000\n";
    }
}
```