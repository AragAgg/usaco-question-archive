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

ll mod = 1e9+7;
// cin.tie(0)->sync_with_stdio(0);
ll fastExpo(ll n, ll m){
    ll res = 1;
    while(m){
        if(m&1) res = res * n % mod;
        n = n * n % mod;
        m /= 2;

    }
    return res;
}

ll fact(ll n){
    ll res = 1;
    while(n){
        res = res * n % mod;
        n--;
    }
    return res;
}

void fx() {
    // Functionality for fx
    string s;
    cin >> s;

    vi tab(26, 0);
    
    for(auto ch: s){
        tab[ch - 'a']++;
    }

    ll res = fact((ll) s.size());

    for(auto item: tab) res = res * fastExpo(fact(item), mod-2) %mod;

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
