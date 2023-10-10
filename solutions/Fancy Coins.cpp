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
    // Functionality for fx
    int m, k, a, b;
    cin >> m >> k >> a >> b;
    
    // int x = m - k*min(b, ((b > 0)?(m/k):(0)));
    
    // int y = x - min(a, x);
    
    // int ans1 = y/k;
    
    // int ans2 = y - ans1;
    
    int normalb = (b <= 0)?(0):min(b, m/k);
    
    int normala = min(a, m - k*normalb);
    
    int fancyb = (m - normalb*k - normala)/k;
    
    int fancya = (m - (normalb + fancyb)*k - normala);
    
    if(((fancya)%k + normala) >= k and fancya >= 2){
        int a = k - (fancya)%k;
        
        fancya -= fancya%k;
        fancyb++;
    }
    
    cout << (fancya + fancyb) << endl;
    
    // cout << (ans1 + ans2) << endl;
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
