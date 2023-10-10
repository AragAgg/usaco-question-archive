---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=809
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Ad-Hoc
  - Edge-Cases
  - Implementation
---
- [[#Solution ]]
- [[#Better Solution]]

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
    // Functionality for fx
    int n;
    cin >> n;
    
    vi tab(n);
    for(auto &i :tab) cin >> i;
    
    if(tab[0] != 0 and tab[0] != -1) {
        cout << -1 << endl;
        return;
    }
    
    tab[0] = 0;
    
    //align left (as required)
    
    int answerOffset = 0;
    
    for(int i = n-1; i >= 0; i--){
        if(tab[i] == -1) continue;
        
        int curr = tab[i];
        
        while(curr >= 0){
            if(curr == 0) answerOffset++;
            
            if(tab[i] == curr or tab[i] == -1){
                tab[i--] = curr--;
            }else{
                cout << -1 << endl;
                return;
            }
            
            if(curr < 0) i++;
        }
    }
    
    
    
    int mini = answerOffset;
    int maxi = answerOffset;
    
    for(int i = 0; i < n; i++){
        if(tab[i] != -1) continue;
        
        while(tab[i] == -1){
            maxi++;
            i++;
            if(i == n) break;
        }
    }
    
    
    cout << mini <<" "<< maxi << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("taming"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Better Solution

```C++
\#include <iostream>
\#include <algorithm>
using namespace std;
\#define MAXN 100000
 
int N;
int A[MAXN];
 
int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	if(A[0] > 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	A[0] = 0;
	int t = -1;
	int req = 0;
	int pos = 0;
	for(int i=N-1;i>=0;i--)
	{
		if(t != -1 && A[i] != -1 && A[i] != t)
		{
			cout << -1 << '\n';
			return 0;
		}
		if(t == -1)
			t = A[i];
		if(A[i] == -1)
			A[i] = t;
		if(A[i] == 0)
			req++;
		if(A[i] == -1)
			pos++;
		if(t > -1)
			t--;
	}
	cout << req << ' ' << req+pos << '\n';
}
```