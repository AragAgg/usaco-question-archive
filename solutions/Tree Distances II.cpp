#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long

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

int n;
vvi tab;
vi nodesUnder;
ll totalDist = 0;

vector<ll> res;

int dfs(int v, int parent, int depth){
    int res = 1;
    totalDist += depth;
    
    for(auto neigh: tab[v]){
        if(neigh == parent) continue;
        
        res += dfs(neigh, v, depth+1);
    }
    
    nodesUnder[v] = res;
    
    return res;
}

void dfs2(int v, int parent, ll contibution){
    res[v] = contibution;
    
    for(auto neigh: tab[v]){
        if(neigh == parent) continue;
        
        dfs2(neigh, v, contibution + nodesUnder[0] - 2*nodesUnder[neigh]);
    }
}

void fx() {
    cin >> n;
    tab.assign(n, {});
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        
        tab[--a].pb(--b);
        tab[b].pb(a);
    }
    
    nodesUnder.assign(n, 0);
    res.assign(n, 0);
    
    dfs(0, -1, 0);
    
    dfs2(0, -1, totalDist);
    
    for(auto item: res) cout << item << " ";
    cout << endl;
    
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
