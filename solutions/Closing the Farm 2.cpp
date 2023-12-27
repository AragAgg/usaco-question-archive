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
    unordered_map<int, int>e;
    int comps = 0;
    void add(int x){
        comps++;
        e[x] = -1;
    }

    int get(int x){
        return (e[x] < 0)?x : e[x] = get(e[x]);
    }

    void unite(int a, int b){
        int x = get(a), y = get(b);
        if(x == y) return;
        if(e[x] > e[y]) swap(x, y);
        comps--;
        e[x] += e[y];
        e[y] = x;
    }
};
void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;

    vvi adj(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vb res;
    vi q(n);
    for(auto &i: q) cin >> i, i--;
    reverse(all(q));

    DSU s;

    for(auto &i: q){
        s.add(i);
        for(auto neigh: adj[i]){
            if(s.e.count(neigh) == 0) continue;
            s.unite(i, neigh);
        }
        
        res.pb((s.comps == 1));
    }

    reverse(all(res));
    for(auto i: res){
        if(i) yes();
        else no();
    } 
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("closing"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
