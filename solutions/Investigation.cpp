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

const ll INF = 1e15;
const ll mod = 1e9+7;

unordered_map<int, tuple<ll, int, int>>memo;

tuple<ll, int, int> fx2(int node, ll d, vll &dist, vector<vector<pll>> &graph){

    if(memo.count(node)) return memo[node];

     ll routes = 0;
     int mi = INT_MAX;
     int ma = INT_MIN;

     if(node == 0) return {1, 0, 0};

     for(auto [_neigh, _cost]: graph[node]){
         if(dist[_neigh] == d - _cost){
            auto [_routes, _mi, _ma] = fx2(_neigh, d - _cost, dist, graph);

            routes = (routes + _routes)%mod;
            mi = min(mi, _mi + 1);
            ma = max(ma, _ma + 1);
        }
     }

     return memo[node] = {routes, mi, ma};
}

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;

    vector<vector<pll>>adj(n);
    vector<vector<pll>>radj(n);
    vll dist(n, INF);
    priority_queue<pll>pq;
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[--a].pb({--b, c});
        radj[b].pb({a, c});
    }

    dist[0] = 0;
    pq.p({0, 0});

    while(!pq.empty()){
        auto [len, node] = pq.top();
        pq.pop();
        
        len *= -1;

        if(dist[node] < len) continue;

        for(auto [_neigh, _len] : adj[node]){
            if(dist[_neigh] > len + _len){
                dist[_neigh] = len + _len;
                pq.p({-dist[_neigh], _neigh});
            }
        }
    }

    cout << dist[n-1] << " ";

    auto [routes, mi, ma] = fx2(n-1, dist[n-1], dist, radj);

    cout << routes << " " << mi << " " << ma << endl;
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
