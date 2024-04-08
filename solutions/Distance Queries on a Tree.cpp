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
#define int ll
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

vector<vii> neighs;
vll tour, first, last;
vii lca;
vi lcaFirst;
vector<array<int, 3>>edges;

void euler_tour(int node, int parent, int depth, int cost){
    tour.pb(cost);
    first[node] = tour.size() -1;

    lca.pb({depth, node});
    lcaFirst[node] = lca.size()-1;

    for(auto [neigh, toll]: neighs[node]){
        if(neigh == parent) continue;
        euler_tour(neigh, node, depth+1, toll);
        lca.pb({depth, node});
    }

    tour.pb(-cost);
    last[node] = tour.size()-1;
}

struct RMQ{
    vii v;
    vvi jmp;
    int lvl(int x){ return 31 - __builtin_clz(x); }
    int cmp(int a, int b){
        return ((v[a].f == v[b].f)?min(a, b):((v[a].f < v[b].f)?a:b));
    }
    RMQ(vii &_v){
        v = _v;
        jmp.pb(vi(v.size(), 0));
        iota(all(jmp[0]), 0);

        for(int j = 1; (1<<j) <= v.size(); j++){
            jmp.pb(vi(v.size() - (1<<j) +1, 0));
            for(int i = 0; i < jmp[j].size(); i++){
                jmp[j][i] = cmp(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]); // <- confirm
            }
        }
    }
    int LCA(int starta, int startb){
        if(starta > startb) swap(starta, startb);
        int d = lvl(startb - starta +1);
        return v[cmp(jmp[d][starta], jmp[d][startb - (1 << d) + 1])].s;
    }
};


struct fenwickTree{
    int n;
    vll v;
    fenwickTree(int _n): n(_n+1), v(_n+1, 0) {}
    void update(int idx, ll delta){
        idx++;
        while(idx < n){
            v[idx] += delta;
            idx += idx & -idx;
        }
    }
    ll query(int idx){
        idx++;
        ll res = 0;
        while(idx > 0){
            res += v[idx];
            idx -= idx & -idx;
        }

        return res;
    }

};


void fx() {
    int n, q;
    cin >> n;

    neighs.assign(n, {});
    first.assign(n, 0);
    last.assign(n, 0);
    lcaFirst.assign(n, 0);

    for(int i = 0; i < n-1; i++){
        int from, to, toll;

        cin >> from >> to >> toll;
        --from, --to;

        neighs[from].pb({to, toll});
        neighs[to].pb({from, toll});
        edges.pb({from, to, toll});
    }
        
    cin >> q;

    euler_tour(0, -1, 0, 0);
    RMQ t(lca);

    for(auto &[from, to, toll] : edges){
        if(first[from] > first[to]) swap(from, to);
    }

    fenwickTree dist(tour.size());

    for(int i = 0; i < tour.size(); i++) dist.update(i, tour[i]);

    for(int i = 0; i < q; i++){

        int type;
        cin >> type;

        if(type == 1){
            int edgeID, changeTo;
            cin >> edgeID >> changeTo;
            --edgeID;

            int toNode = edges[edgeID][1];

            dist.update(first[toNode], changeTo - edges[edgeID][2]);
            dist.update(last[toNode], edges[edgeID][2] - changeTo);

            edges[edgeID][2] = changeTo;
        }else{
            int a, b;
            cin >> a >> b;
            --a, --b;

            cout << ((dist.query(first[a]) + dist.query(first[b])) - 2LL*(dist.query(first[t.LCA(lcaFirst[a], lcaFirst[b])])))  << endl;
        }
    }

    
    /*

    for(int i = 0; i < n; i++){
        cout << "cost to get to node: " << (i+1) << " is: " << ((dist.query(first[i]))) << endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "LCA(" << (i+1) <<", " << (j+1) << ") = " << (t.LCA(lcaFirst[i], lcaFirst[j])+1) << endl;
        }
    }

    */
    

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
