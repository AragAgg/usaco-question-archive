#include <bits/stdc++.h>

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
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long

// Debugging macros
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debug_vector(v) _debug_vector(#v, v)
template<typename T>
void _debug_vector(const string& name, const vector<T>& a) {
    cerr << name << " = [ ";
    for(const auto &x : a) cerr << x << ' ';
    cerr << "]\n";
}

// I/O redirection for local testing
#define iofile(io) \
        freopen((io + ".in").c_str(), "r", stdin); \
        freopen((io + ".out").c_str(), "w", stdout);

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

void fx() {
    int n;
    cin >> n;
    
    vi a(n+1, 0), c(n);
    
    stack<pii>invS;
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        
        while(invS.size() and invS.top().f >= t) invS.pop();
        
        invS.push({t, i});
    }
    
    int k;
    cin >> k;
    
    
    stack<pii>s;
    while(invS.size()){
        s.push(invS.top());
        invS.pop();
    }
    
    int offset = 0;
    
    stack<pii>changes;
    while((s.size()) and ((s.top().f - offset) <= k) and (k >= 1) and (offset == 0 or changes.size())){
        // if(offset == 0) a[0]++;
        // a[s.top().s+1]--;
        
        if(offset == 0){
            changes.push({0, s.top().s+1});
        }else{
            changes.pop();
            changes.push({0, s.top().s+1});
        }
        
        k -= (s.top().f - offset);
        
        if(k < s.top().f){
            offset = s.top().f;
            s.pop();
        }
    }
    
    while(changes.size()){
        a[changes.top().f]++;
        a[changes.top().s]--;
        changes.pop();
    }
    
    for(int i = 1; i < n+1; i++) a[i] += a[i-1];
    
    for(int i = 0; i < n; i++) cout << a[i] << " ";
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
