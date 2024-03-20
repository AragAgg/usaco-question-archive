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

ll expo(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a)%mod;
        b = b >> 1;
        a = (a*a)%mod;
    }
    return res;
}

struct DSU{
    vi e;
    int comps;
    DSU(int n){
        e.assign(n, -1);
        comps = n;
    }
    int get(int node){ return (e[node] < 0)?node:(e[node] = get(e[node]));}
    void merge(int a, int b){
        int x = get(a), y = get(b);
        if(x == y) return;
        if(e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
};

void fx() {
    // Functionality for fx
    ll n, m;
    cin >> n >> m;

    vll tab(n);
    for(auto &i: tab) cin >> i;

    //vector<vector<pll>>dist(n, vll(n));
    vector<tuple<ll, int, int>>edges;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++) edges.pb({-(expo(tab[i], tab[j], m) + expo(tab[j], tab[i], m))%m, i, j});
    }

    sort(all(edges));
    DSU sys(n);
    int ptr = 0;
    ll res = 0;

    while(ptr < edges.size() and sys.comps > 1){
        auto [len, a, b] = edges[ptr];
        len *= -1;

        if(sys.get(a) != sys.get(b)){
            sys.merge(a, b);
            res += len;
        }

        ptr++;
    }

    cout << res << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
