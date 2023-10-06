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

ll n;

bool isVaible(ll x){
    ll bridges = (x+1)/2;
    ll remVertices = (n - bridges);
    
    return ((remVertices*(remVertices-1))/2 >= (x - bridges));
}

void fx() {
    // Functionality for fx
    int q;
    cin >> q;
    
    while(q--){
        cin >> n;
        
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        ll lo = n-1;
        ll hi = 2*n;
        
        while(lo < hi){
            ll mid = lo + (hi - lo+1)/2;
            
            if(isVaible(mid)) lo = mid;
            else hi = mid-1;
        }
        
        cout << lo << endl;
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
