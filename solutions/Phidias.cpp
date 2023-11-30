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

int n, m, x;
vvi dp;


int fx2(int a, int b){
    if(a <= 0 or b <= 0) return 360001;
    if(dp[a][b] != 360001) return dp[a][b];
    if((a == 1 and b == 1)) return 1;
    
    dp[a][b] = a * b;
    for(int i = 1; i <= a/2; i++) dp[a][b] = min(dp[a][b], fx2(i, b) + fx2(a - i, b));
    for(int i = 1; i <= b/2; i++) dp[a][b] = min(dp[a][b], fx2(a, i) + fx2(a, b-i));

    return dp[a][b];
}
void fx() {
    // Functionality for fx
    cin >> n >> m >> x;
    dp.assign(n+1, vi(m+1, 360001));

    for(int i = 0; i < x; i++){
        int a, b;
        cin >> a >> b;
        dp[a][b] = 0;
    }

    cout << fx2(n, m) << endl;
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
