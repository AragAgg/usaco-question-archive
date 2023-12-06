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

void fx() {
    // Functionality for fx

    int n, k;
    cin >> n >> k;

    vector<ll> tab(n);
    for(auto &i: tab) cin >> i;

    vector<int>twos(n, 0), fives(n, 0);
    for(int i = 0; i < n; i++){
        ll item = tab[i]; 
        while(item and item %2 == 0) twos[i]++, item /= 2;
        while(item and item %5 == 0) fives[i]++, item /= 5; 
    }
    
    vector<vector<ll>>dp(k+1, vector<ll>(6000, -1));

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            for(int x = 5999 - fives[i]; x >= 0; x--) if(dp[j][x] != -1) dp[j-1][x + fives[i]] = max(dp[j-1][x + fives[i]], dp[j][x] + twos[i]);
        }
        dp[k-1][fives[i]] = max(dp[k-1][fives[i]], (ll)twos[i]);
    }

    ll res = 0;

    for(int i = 0; i < 6000; i++){
        res = max(res, min((ll)i, dp[0][i]));
    }
    cout << res << endl;


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
