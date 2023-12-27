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

struct DSU{
    vi e;
    int comps;
    int best = 1;
    void init(int N){ e = vi(N, -1); comps = N; }
    int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool unite(int x, int y){
        int a = get(x), b = get(y);
        if(a == b) return 0;
        if(e[a] > e[b]) swap(a, b);
        comps--;
        e[a] += e[b];
        e[b] = a;
        best = max(best, -e[a]);
        return 1;
    }
    

};
void fx() {
    DSU s;
    int n, m;
    cin >> n >> m;
    s.init(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        s.unite(a, b);
        cout << s.comps << " " << s.best << endl;
    }
    // Functionality for fx
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
