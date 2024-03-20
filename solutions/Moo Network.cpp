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

struct DSU{
    vi e;
    int comps;
    DSU(int n){
        e.assign(n, -1);
        comps = n;
    }

    int get(int node){ return (e[node]<0)?node:(e[node] = get(e[node])); }
    void merge(int a, int b){
        int x = get(a), y = get(b);
        if(x==y)return;
        comps--;
        if(e[x]>e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
};


void fx() {
    int n;
    cin >> n;

    vii tab(n);
    for(auto &i: tab) cin >> i.f >> i.s;

    sort(all(tab));

    vector<tuple<ll, int, int>>edges;

    for(int i = 0; i < n-1; i++) edges.pb({pow(tab[i].f - tab[i+1].f, 2) + pow(tab[i].s - tab[i+1].s, 2), i, i+1});

    for(int i = 0; i  < n; i++){
        for(int j = i+1; j < min(n, i + 22); j++){
            edges.pb({pow(tab[i].f - tab[j].f, 2) + pow(tab[i].s - tab[j].s, 2), i, j});
        }
    }

    sort(all(edges));

    DSU sys(n);
    int ptr = 0;
    ll res = 0;

    while(sys.comps > 1 and ptr < edges.size()){
        auto [len, i, j] = edges[ptr];
        if(sys.get(i) != sys.get(j)){
            sys.merge(i, j);
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
