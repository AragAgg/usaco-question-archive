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
    int n, k;
    cin >> n >> k;
    
    int ans = 0;
    int counter = 1;
    
    if(n%k == 0){
        while(counter < n){
            cout << "? " << counter << endl << endl;
            
            int res;
            cin >> res;
            
            if(res == -1) exit(1);
            
            ans = ans^res;
            
            counter += k;
        }
        
        cout << "! " << ans << endl << endl;
        return;
    }
    
    int times = max(n/k -1, 0);
    int till = n - times*k;
    
    while(times){
        int res;
        
        cout << "? " << (n+1 - (times--)*k) << endl << endl;
        cin >> res;
        
        if(res == -1) exit(2);
        
        ans = ans^res;
    }
    
    for(int i = 1; i <= till-k+1; i++){
        int res;
        
        cout << "? " << i << endl << endl;
        cin >> res;
        
        if(res == -1) exit(3);
        
        ans = ans^res;
    }
    
    cout << "! " << ans << endl << endl; 
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
