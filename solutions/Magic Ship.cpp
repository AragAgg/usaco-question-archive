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

ll xa, ya, xb, yb;
string s;

ll alphax = 0, alphay = 0;

void transform(ll &x, ll &y, int days){
    for(int i = 0; i < days; i++){
        if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        else if(s[i] == 'L') x--;
        else x++;
    }
}

bool isViable(ll days){
    ll x = xa;
    ll y = ya;
    
    ll cCycles = days/s.size();
    
    x += alphax*cCycles;
    y += alphay*cCycles;
    
    transform(x, y, days%s.size());
    
    ll delta = abs(xb - x) + abs(yb - y);
    
    return (delta <= days);
}

void fx() {
    // Functionality for fx
    cin >> xa >> ya >> xb >> yb;
    int n;
    cin >> n >> s;
    
    transform(alphax, alphay, n);
    
    ll lo = 0;
    ll hi = 1e18+100;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        
        if(isViable(mid)) hi = mid;
        else lo = mid +1;
    }
    
    cout << ((lo == 1e18+100)?-1:lo) << endl;
    
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
