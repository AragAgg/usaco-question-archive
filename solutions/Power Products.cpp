#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define endl "\n"

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

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

// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

// cin.tie(0)->sync_with_stdio(0);

#define MAXN 1e6+1

void fx() {
    int n, k;
    cin >> n >> k;
    
    vi phi;
    for(int i = 0; i < MAXN; i++) phi.pb(i);
    for(int i = 2; i < MAXN; i++) if(phi[i] == i) for(int j = i; j < MAXN; j += i) phi[j] = i;
    
    map<int, int>m;
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        ll curr, complement = 1, finalCurr = 1;
        cin >> curr;
        
        while(curr > 1){
            int prime = phi[curr];
            int primeCounter = 0;
            
            while(curr%prime == 0) primeCounter++, curr /= prime;
            
            primeCounter %= k;
            finalCurr *= pow(prime, primeCounter);
            complement *= pow(prime, (k - primeCounter)%k);
        }
        
        ans += m[complement];
        m[finalCurr]++;
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    cin.tie(0)->sync_with_stdio(0);
    fx();
    
    return 0;
}
