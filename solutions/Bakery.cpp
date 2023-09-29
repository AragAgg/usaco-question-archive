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

ll n, ta, tb;

vector<ll> a, b, c;

bool isViable(ll m){

    ll d = ta + tb - m;
    ll lx = max(1LL, ta - m);
    ll hx = min(ta, ta + tb - m -1);
    
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]) lx = max(lx, (b[i]*d - c[i] + b[i] - a[i] -1)/(b[i] - a[i]));
        else if(a[i] > b[i]) hx = min(hx, ((c[i] - b[i]*d)/(a[i] - b[i])));
        else if(a[i]*d > c[i]) return false;
    }
    
    return (lx <= hx);
}

void fx() {
    // Functionality for fx
    cin >> n >> ta >> tb;
    
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);
    
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    
    ll lo = 0;
    ll hi = ta + tb -2;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)) hi = mid;
        else lo = mid+1;
    }
    
    cout << lo << endl;
    
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
