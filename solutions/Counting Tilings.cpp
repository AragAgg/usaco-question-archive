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

ll n, m;
vector<vector<ll>>dp(1001, vector<ll>(1 << 10, -1));
const ll mod = 1e9+7;

ll fx2(int mask, int level);
ll fx3(int mask, int level, int bit, int next){

    if(mask == 0) return fx2(next, level -1);
    if((mask & (1 << n)) or (bit >= n)) return 0;
    if(!(mask & ( 1 << bit))) return fx3(mask, level, bit+1, next);
    ll res = fx3(mask ^ ( 1 << bit), level, bit+1, next ^ (1 << bit));
    if(mask & ( 1 << (bit+1))) res += fx3((mask ^ ( 1 << bit)) ^ ( 1 << (bit+1)), level, bit+2, next);
    res %= mod;
    return res;
}

ll fx2(int mask, int level){
    if(level == 0) return (mask == (1 << n) -1 );
    if(dp[level][mask] != -1) return dp[level][mask];
    return dp[level][mask] = fx3(mask, level, 0, (1 << n) -1);
}

void fx() {
    cin >> n >> m;
    cout << fx2((1 << n) - 1, m) << endl;
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
