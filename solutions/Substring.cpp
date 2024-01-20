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
vvi adj;
vi topSort, visited;
bool isCycle = false;

void dfs(int node){
    visited[node] = -1;
    for(auto &neigh: adj[node]){
        if(visited[neigh] == -1) isCycle = true;
        if(!visited[neigh]) dfs(neigh);

    }
    visited[node] = 1;
    topSort.pb(node);
}

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;
    adj.assign(n, {});
    string s;
    cin >> s;

    visited.assign(n, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[--a].pb(--b);
    }

    for(int i = 0; i < n; i++) if(!visited[i]) dfs(i);

    unordered_set<int>temp;
    for(auto &i: topSort) temp.insert(i);

    if(temp.size() != n or isCycle){
        cout << -1 << endl;
        return;
    }

    vvi pathCst = vector<vi>(n, vi(26, 0));

    reverse(all(topSort));
    int res = 0;

    for(int i = 0; i < n; i++){
        int node = topSort[i];

        pathCst[node][s[node] - 'a']++;

        for(auto &neigh: adj[node]){
            for(int j = 0; j < 26; j++) pathCst[neigh][j] = max(pathCst[neigh][j], pathCst[node][j]);
        }

        for(int j = 0; j < 26; j++) res = max(res, pathCst[node][j]);
    }

    cout << res << endl;
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
