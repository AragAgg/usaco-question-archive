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

string a, b;
int dp[5005][5005] = {{0}};

ll fx2(int i, int j){
    if(i == -1) return (j+1);
    if(j == -1) return (i+1);
    if(dp[i][j] != -1) return dp[i][j];
    
    if(a[i] == b[j]) return fx2(i-1, j-1);

    ll t = 1 + fx2(i-1, j);
    t = min(t, 1 + fx2(i-1, j-1));
    t = min(t, 1 + fx2(i, j-1));

    return dp[i][j] = t;
}
void fx() {
    // Functionality for fx
    
    for(int i = 0; i < 5005; i++){
        for(int j = 0; j < 5005; j++) dp[i][j] = -1;
    }
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    cout << fx2(n-1, m-1) << endl;
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
