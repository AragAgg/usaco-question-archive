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
typedef vector<ll> vi;
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

const ll mod = 1e9+7;
vi fact, factInv;

ll binpow(ll num, ll expo){
    ll res = 1;
    while(expo){
        if(expo&1) res = (res * num)%mod;
        num = num * num %mod;
        expo /= 2;
    }
    return res;
}

ll nchoosek(ll n, ll k){
    return (((fact[n] * factInv[n-k])%mod) * factInv[k])%mod;
}

void fx() {
    // Functionality for fx
    fact.assign(501, 1);
    for(ll i = 1; i < 501; i++) fact[i] = i * fact[i-1] %mod;
    factInv.assign(501, 1);
    factInv[500] = binpow(fact[500], mod-2);
    for(ll i = 499; i >= 1; i--) factInv[i] = factInv[i+1] * (i+1) %mod;
    
    string s;
    cin >> s;

    if(s.size()&1){
        cout << 0 << endl;
        return;
    }

    int n = s.size();

    vvi dp(n, vi(n, 0));
    for(int len = 0; len < n; len++){
        for(int i = 0; i < n - len; i++){
            int j = len + i;
            if(!(len&1)){ dp[i][j] = 0; continue;}

            for(int k = i+1; k <= j; k++){
                if(s[i] != s[k]) continue;
                dp[i][j] = (dp[i][j] + (((i+1 > k-1)?1:dp[i+1][k-1])*((k+1 > j)?1:dp[k+1][j])%mod)*nchoosek((j-i+1)/2, (k-i+1)/2))%mod;
            }
        }
    }

    cout << dp[0][n-1] << endl;
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
