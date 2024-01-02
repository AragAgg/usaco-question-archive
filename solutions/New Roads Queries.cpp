#pragma GCC optimize("03,unroll-loops")
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
vi res;

struct DSU{
    vi e; vector<usi>qn;
    void init(int N){ e = vi(N, -1); qn = vector<usi>(N); }
    int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }
    void unite(int a, int b, int merger){
        int x = get(a), y = get(b);
        if(x == y) return;
        if(e[x] > e[y]) swap(x, y);
        for(auto &q: qn[y]){
            if(qn[x].count(q)) res[q] = merger;
            else qn[x].insert(q);
        }
        qn[y].clear();
        e[x] += e[y];
        e[y] = x;
    }
};

void fx() {
    // Functionality for fx
    int n, m, q;
    cin >> n >> m >> q;
    res.assign(q, -1);
    DSU tree;
    tree.init(n);
    
    vii edges(m);
    for(auto &edge: edges) cin >> edge.f >> edge.s, edge.f--, edge.s--;

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        tree.qn[--a].insert(i);
        tree.qn[--b].insert(i);
        if(a == b) res[i] = 0;
    }
    
    int merger = 1;
    for(auto edge: edges) tree.unite(edge.f, edge.s, merger), merger++;

    for(auto &i: res) cout << i << "\n";
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    cin.tie(0)->sync_with_stdio(0);             
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;     
}
