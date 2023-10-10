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

void fx(){
    long long n, m;
    cin >> n >> m;
    
    vector<long long> cities(n, 0);
    for(auto &i: cities) cin >> i;
    
    vector<long long> towers(m, 0);
    for(auto &i: towers) cin >> i;
    
    int cPtr = 0;
    int tPtr = 0;
    
    long long ans = 0;
    
    for(; cPtr < n; cPtr++){
        while(tPtr < m-1 and abs(cities[cPtr] - towers[tPtr]) >= abs(cities[cPtr] - towers[tPtr+1])) tPtr++;
        
        ans = max(ans, abs(cities[cPtr] - towers[tPtr]));
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("pairup"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
