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

void fx() {
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<pll>>adj(n+1);
    vi sigma(n+1, 0);
    vll dist(n+1, INF);
    priority_queue<pair<ll, int>>pq;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        adj[--a].pb({--b, c});
        adj[b].pb({a, c});
    }

    for(int i = 0; i < k; i++){
        int spot, tastiness;
        cin >> spot >> tastiness;
        sigma[--spot] = tastiness;
    }

    dist[n-1] = 0;
    pq.p({0, n-1});

    while(!pq.empty()){
        auto [len, node] = pq.top();
        pq.pop();
        
        len *= -1;

        if(dist[node] < len) continue;

        for(auto [_neigh, _len]: adj[node]){
            if(dist[_neigh] > len + _len){
                dist[_neigh] = len + _len;
                pq.p({-(dist[_neigh]), _neigh});
            }
        }
    }

    for(int i = 0; i < n; i++) if(sigma[i]) adj[n].pb({i, dist[i] - sigma[i]});

    vll dist2(n+1, INF);
    dist2[n] = 0;
    pq.p({0, n});

    while(!pq.empty()){
        auto [len, node] = pq.top();
        pq.pop();

        len *= -1;

        if(dist2[node] < len) continue;

        for(auto [_neigh, _len]: adj[node]){
            if(dist2[_neigh] > len + _len){
                dist2[_neigh] = len + _len;
                pq.p({-(dist2[_neigh]), _neigh});
            }
        }
    }

    for(int i = 0; i < n-1; i++) cout << (dist2[i] <= dist[i]) << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("dining"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
