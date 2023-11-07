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
ll mod = 1e9+7;
vector<ll> tab(1000005, 0);
vector<ll>modinv(1000005, 0);


ll fastExpo(ll n, ll m){
    ll res = 1;
    while(m){
        if(m&1) res = res * n % mod;
        n = n * n % mod;
        m /= 2;
    }
    return res;
}

void fx() {
    // Functionality for fx
    ll n, k;
    cin >> n >> k;

    tab[0] = 1;

    ll temp = (tab[n] * modinv[k] % mod) * modinv[n-k] % mod;
    cout << temp << endl;
}

int main() {
    tab[0] = 1;
    for(int i = 1; i < 1000005; i++) tab[i] = tab[i-1]*i % mod;
    modinv[1000004] = fastExpo(tab[1000004], mod-2);
    for(int i = 1000003; i >= 0; i--) modinv[i] = modinv[i+1] * (i+1) % mod;
    int t; cin >> t;
    while(t--) fx();
    return 0;
}
