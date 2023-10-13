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
    // Functionality for fx
    int n;
    cin >> n;
    
    vector<string>tab;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        tab.pb(s);
    }
    
    
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            vector<char>res = {tab[i][j], tab[j][(-i + n - 1)], tab[(-i + n - 1)][(-j + n -1)], tab[(-j + n -1)][-(-i + n - 1) + n-1]};
            
            
            sort(all(res));
            
            ans += res[3] - res[0];
            ans += res[3] - res[1];
            ans += res[3] - res[2];
        }
    }
    
    cout << (ans/4) << endl;
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
