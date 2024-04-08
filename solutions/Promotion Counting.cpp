//#pragma GCC optimize("03,unroll-loops")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

//template<typename T>
//using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int n;
vvi neighs;
vi res, tab, ori;
vi tour, first, end;

struct fenwickTree{
    int n;
    vi v;
    fenwickTree(int _n) : n(_n+1), v(_n+1, 0) {}
    void update(int idx, int delta){
        idx++;
        while(idx < n){
            v[idx] += delta;
            idx += idx & -idx;
        }
    }
    int query(int idx){
        idx++;
        int res = 0;
        while(idx > 0){
            res += v[idx];
            idx -= idx & -idx;
        }

        return res;
    }
};

void euler_tour(int node, int parent){
    tour.pb(node);

    for(auto neigh: neighs[node]){
        if(neigh == parent) continue;
        euler_tour(neigh, node);
    }

    tour.pb(-1-node);
}


void fx() {
    cin >> n;

    neighs.assign(n, {});
    res.assign(n, 0);
    ori.assign(n, 0);
    tab.assign(n, 0);

    map<int, int>s;
    
    for(auto &i: ori) cin >> i, s.insert({i, 0});

    int cnt = 0;
    for(auto &[item, counter] : s) counter = cnt++;

    for(int i = 0; i < n; i++) tab[i] = s[ori[i]];

    for(int i = 1; i < n; i++){
        int parent;
        cin >> parent;
        parent--;

        neighs[i].pb(parent);
        neighs[parent].pb(i);
    }

    euler_tour(0, -1);

    vi temp(n, 0);

    fenwickTree t(n);

    for(int i = 0; i < tour.size(); i++){
        if(tour[i] > 0){
            //insert
            int node = tour[i];
            temp[node] = t.query(n-1) - t.query(tab[node]);
            t.update(tab[node], 1);
        }else{
            //process
            int node = -1*(tour[i]+1);
            res[node] = t.query(n-1) - t.query(tab[node]) - temp[node];
        }

    }

    for(int i = 0; i < n; i++) cout << res[i] << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("promote"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
