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

int N;
vector<double>x, v;
double eps = 1e-6;

bool isViable(double t){
    // cout << "called isViable(" << setprecision(10)<< t << ")\n";
    double overlapA = x[0]-(v[0]*t);
    double overlapB = x[0]+(v[0]*t);
    
    for(int i = 0; i < N; i++){
        double actualOverlap = min(overlapB, x[i]+(v[i]*t)) - max(overlapA, x[i]-v[i]*t);
        if(0 - actualOverlap > eps) return false;
        
        overlapA = max(overlapA, x[i]-v[i]*t);
        overlapB = min(overlapB, x[i]+(v[i]*t));
    }
    
    // cout << "retruning true\n";
    return true;
}

void fx() {
    // Functionality for fx
    cin >> N;
    x.assign(N, 0);
    v.assign(N, 0);
    
    for(auto &i : x) cin >> i;
    for(auto &i : v) cin >> i;
    
    double lo = 0;
    double hi = 1e9;
    

    while(hi - lo > eps){
        double mid = lo + (hi - lo)/2;
        
        if(isViable(mid)) hi = mid;
        else lo = mid + 0.0000001;
    }
    
    cout << setprecision(8)<< hi << endl; // might cause precision and rounding errors...
    
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
