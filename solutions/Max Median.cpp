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

int n, k;
vi tab;

bool isViable(int x){
    vi psum(n, 0);
    
    psum[0] = ((tab[0] >= x)?1:-1);
    
    for(int i = 1; i < n; i++) psum[i] += psum[i-1] + ((tab[i] >= x)?1:-1);
    
    int mn = 0;
    
    for(int i = k; i < n; i++){
        mn = min(mn, psum[i-k]);
        if(psum[i] - mn >= 1) return true;
    }
    
    return (psum[k-1] >= 1);
}

void fx() {
    // Functionality for fx
    
    cin >> n >> k;
    tab.assign(n, 0);
    ll hi = INT_MIN;
    ll lo = INT_MAX;
    for(auto &i: tab){ cin >> i; hi = max(hi, (ll)i);}
    
    lo = 0;
    
    while(lo < hi){
        int mid = lo + (hi - lo+1)/2;
        
        if(isViable(mid)) lo = mid;
        else hi = mid-1;
    }
    
    cout << lo << endl;
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
