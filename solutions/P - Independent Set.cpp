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
ll n;
vector<vector<int>>tree(100001);
vector<vector<ll>>dp(2, vector<ll>(100001, -1));
const ll mod = 1e9+7;

//color: 0 - > red, 1 -> black;
ll fx2(int node, int prev, bool color){
    if(dp[color][node] != -1) return dp[color][node];
    dp[color][node] = 1;
    
    for(auto &neigh: tree[node]){
        if(neigh == prev) continue;

        dp[color][node] = dp[color][node] * ((fx2(neigh, node, 0) + (color?0:fx2(neigh, node, 1)))%mod) %mod;
    }

    return dp[color][node];
}

void fx() {
    // Functionality for fx
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        tree[--x].pb(--y);
        tree[y].pb(x);
    }

    cout << ((fx2(0, -1, 0) + fx2(0, -1, 1))%mod) << endl;
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
