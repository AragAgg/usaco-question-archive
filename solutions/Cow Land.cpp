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

int n, q;
vi tab, s, e, tour;
vi lcas;
vii lca;
vvi adj;

void euler_tour(int node, int parent, int depth){
    tour.pb(tab[node]);
    lca.pb({depth, node});
    lcas[node] = lca.size() - 1;

    s[node] = tour.size() - 1;
    for(auto neigh: adj[node]){
        if(neigh == parent) continue;
        euler_tour(neigh, node, depth+1);
        lca.pb({depth, node});
    }
    tour.pb(tab[node]);
    e[node] = tour.size() -1;

}

struct RMQ{
    vii v;
    vvi jmp;
    int lvl(int x){ return 31 - __builtin_clz(x); }
    int cmp(int a, int b){
        return ((v[a].f == v[b].f)?min(a, b):(v[a].f < v[b].f)?a:b);
    }
    RMQ(vii &_v){
        v = _v;
        jmp = {vi(v.size(), 0)};
        iota(all(jmp[0]), 0);
        for(int j = 1; (1 << j) <= v.size(); j++){
            jmp.pb(vi(v.size() - (1 << j) +1, 0));
            for(int i =  0; i < jmp[j].size(); i++){
                jmp[j][i] = cmp(jmp[j-1][i], jmp[j-1][i + (1 << (j-1)) ]); // <- sure?
            }
        }
    }
    int LCA(int starta, int startb){
        if(starta > startb) swap(starta, startb);
        int d = lvl(startb - starta +1);
        return v[cmp(jmp[d][starta], jmp[d][startb - (1 << d) +1])].s;
    }
};

template<class T>
struct fenwickTree{
    int n;
    vector<T> v;
    fenwickTree(int n) : n(n+1), v(n+1, 0) {}
    void update(int idx, int prev, int next){
        idx++;
        while(idx < n){
            v[idx] ^= prev;
            v[idx] ^= next;
            idx += idx & -idx;
        }
    }
    T query(int idx){
        idx++;
        T res = 0;
        while(idx > 0){
            res ^= v[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

void fx() {
    cin >> n >> q;
    tab.assign(n, 0);
    s.assign(n, 0);
    e.assign(n, 0);
    lcas.assign(n, 0);
    adj.assign(n, {});

    for(auto &i: tab) cin >> i;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    euler_tour(0, -1, 0);

    fenwickTree<ll> t((int)tour.size());
    for(int i = 0; i < tour.size(); i++){
        t.update(i, 0, tour[i]);
    }

    RMQ t2(lca);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int node, changeTo, delta;
            cin >> node >> changeTo;
            node--;
            t.update(s[node], tab[node], changeTo);
            t.update(e[node], tab[node], changeTo);
            tab[node] = changeTo;
        }else{
            int a, b;
            cin >> a >>  b;
            --a, --b;

            cout << (t.query(s[a]) ^ t.query(s[b]) ^ tab[t2.LCA(lcas[a], lcas[b])]) << endl;
        }
    }
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
     iofile(string("cowland"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
