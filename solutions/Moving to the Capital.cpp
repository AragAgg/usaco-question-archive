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
int n, m;
vvi graph, dp;
vi cost;

void dfs(int node, int depth){
    if(cost[node] <= depth) return;
    cost[node] = depth;
    for(auto neigh: graph[node]) dfs(neigh, depth+1);
}

int fx2(int node, bool used){
    if(dp[node][used] != INT_MAX) return dp[node][used];
    dp[node][used] = cost[node];

    for(auto neigh: graph[node]){
        if(cost[neigh] > cost[node]) dp[node][used] = min(dp[node][used], fx2(neigh, used));
        else if(!used) dp[node][used] = min(dp[node][used], cost[neigh]);
    }

    return dp[node][used];
}
void fx() {
    // Functionality for fx
    cin >> n >> m;
    graph.clear(), cost.clear(), dp.clear();
    graph.assign(n, {}), cost.assign(n, INT_MAX), dp.assign(n, {INT_MAX, INT_MAX});

    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b;
        graph[--a].pb(--b);
    }

    dfs(0, 0);

    dp[0] = {0, 0};
    for(int i = 0; i < n; i++) cout << fx2(i, 0) << " ";
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    
    
    return 0;
}
