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

int n;
vi a, b;

vvi dp;

bool isValid(int i, int j){
    return (abs(a[i] - b[j]) <= 4);
}

int fx2(int i, int j){
    if(i == n or j == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    if(isValid(i, j)) dp[i][j] = 1 + fx2(i+1, j+1);
    else dp[i][j] = max({dp[i][j], fx2(i+1, j), fx2(i, j+1)});

    return dp[i][j];

}

void fx() {
    // Functionality for fx
    cin >> n;
    for(int i = 0; i < 2*n; i++){
        int x;
        cin >> x;

        if(i < n) a.pb(x);
        else b.pb(x);
    }

    dp.assign(n, vi(n, -1));
    cout << fx2(0, 0) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("nocross"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
