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

const ll mod = 1e9+7;


ll powmod(ll num, ll expo){
    ll res = 1;
    while(expo){
        if(expo&1) res = (res * num) %mod;
        num = num * num %mod;
        expo = expo/2;
    }

    return res;
}

void fx() {
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<pii>words(n);
    for(auto &i: words) cin >> i.f >> i.s, --i.s;

    map<char, int>freq;
    for(int i = 0; i < m; i++){
        char ch;
        cin >> ch;

        freq[ch]++;
    }

    vector<int>f;
    for(auto &i: freq) f.pb(i.s);

    vector<ll>dp(k+1, 0), ways(n, 0);
    dp[0] = 1;

    for(int i = 1; i < k+1; i++){
        for(auto word: words){
            if(i >= word.f){ 
                dp[i] = (dp[i] + dp[i - word.f]) %mod;
                if(i == k) ways[word.s] = (ways[word.s] + dp[i - word.f]) %mod;
            }
        }
    }

    ll res = 1;
    for(auto fre: f){
        ll t = 0;
        for(auto way: ways){
            if(way == 0) continue;

            t = (t + powmod(way, fre)) %mod;
        }

        res = (res * t) %mod;
    }

    cout << res << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("poetry"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
