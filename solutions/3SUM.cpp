//#pragma GCC optimize("03,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define p push
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long
//#define int ll
#define endl "\n"
#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

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

vvll dp(5005, vll(5005, 0));
const ll alpha = 1e6;
int test[2*alpha+5];

void fx() {
    int n, q;
    cin >> n >> q;

    vi tab(n);
    for(auto &i: tab) cin >> i;

    for(int len = 2; len < n; len++){
        for(int i = 0; i < n; i++) test[tab[i]+alpha] = 0;
        for(int i = 1; i < len; i++) test[tab[i] + alpha]++;
        for(int i = 0; i + len < n; i++){
            int j = i + len;
            int delta = -(tab[i] + tab[j]) + alpha;
            dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + ((delta >= 0 and delta <= 2e6)?test[delta]:0);
            test[tab[i+1] + alpha]--;
            test[tab[j]+alpha]++;
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        cout << dp[a][b] << endl;
    }
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("threesum"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
