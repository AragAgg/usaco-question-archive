---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=892
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Ad-Hoc
  - Math
---
- [[#Solution ]]
- [[#Much Better Solution]]

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
\#define debug(x) cout << \#x << " = " << (x) << '\n'
\#define debug_vector(v) _debug_vector(\#v, v)
template<typename T>
void _debug_vector(const string& name, const vector<T>& a) {
    cout << name << " = [ ";
    for(const auto &x : a) cout << x << ' ';
    cout << "]\n";
}

// I/O redirection for local testing
\#define iofile(io) \
        freopen((io + ".in").c_str(), "r", stdin); \
        freopen((io + ".out").c_str(), "w", stdout);

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

int ans;


vi preprocess(vi tab){
    
    // cout << "preprocess() with: ";
    // debug_vector(tab);
    
    vi temp = tab;
    
    sort(all(temp));
    
    while(tab.size() and tab[tab.size()-1] == temp[temp.size()-1]){
        temp.ppb();
        tab.ppb();
    }
    
    // cout << "finished with: ";
    // debug_vector(tab);
    
    return tab;
}

void fx2(vi tab){
    if(tab.size() <= 1) return;
    
    int ti = 0;
    int target = tab[0];
    
    // cout <<"target: "<< target << " " << ti << endl;
    
    for(int i = 0; i < tab.size(); i++){
        if(tab[i] > target){
            target = tab[i];
            ti = i;
        }
    }
    
    vi pre;
    vi post;
    
    for(int i = 0; i < tab.size(); i++){
        if(i < ti) pre.pb(tab[i]);
        else if(i > ti) post.pb(tab[i]);
    }
    
    ans += pre.size() +1;
    
    sort(pre.begin(), pre.end());
    
    post = preprocess(post);
    
    // for(auto &i: pre) post.pb(i);
    
    for(auto &item: pre){
        
        
        post.pb(item);
        if(post.size() == 1) continue;
        int offset = post[post.size()-2];
        int swapPos = post.size()-2;
        while(post[swapPos] > item and post[swapPos] <= offset){
            offset = post[swapPos];
            swap(post[swapPos], post[swapPos+1]);
            
            if(swapPos == 0) break;
            swapPos--;
        }
    
    }
    
    post = preprocess(post);
    
    fx2(post);
}

void fx() {
    int n;
    cin >> n;
    
    vi tab(n);
    
    for(auto &i: tab) cin >> i;
    
    tab = preprocess(tab);
    
    // debug_vector(tab);
    
    ans = 0;
    
    fx2(tab);
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("sleepy"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

  

### Much Better Solution

```C++
\#include <bits/stdc++.h>
using namespace std;

int cows[105];

int main() {
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> cows[i]; }
	int answer = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (cows[i] < cows[i + 1]) {
			answer = i;
		} else {
			break;
		}
	}
	cout << answer << endl;
}
```