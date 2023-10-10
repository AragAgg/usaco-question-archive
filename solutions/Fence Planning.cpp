#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long

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

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

vii locs;
vvi tab;

int lx = INT_MAX, ly = INT_MAX, hx = INT_MIN, hy = INT_MAX;

vb visited;

void dfs(int x){
    if(visited[x]) return;
    
    visited[x] = true;
    lx = min(lx, locs[x].f);
    hx = max(hx, locs[x].f);
    ly = min(ly, locs[x].s);
    hy = max(hy, locs[x].s);
    
    for(auto &i: tab[x]) dfs(i);
    
}

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;
    
    locs.assign(n+1, {0, 0});
    for(int i = 1; i < n+1; i++){
        int x, y;
        cin >> x >> y;
        
        locs[i] = {x, y};
    }
    
    tab.assign(n+1, {});
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        tab[a].pb(b);
        tab[b].pb(a);
    }
    
    visited.assign(n+1, false);
    
    int ans = INT_MAX;
    
    for(int i = 1; i < n+1; i++){
        if(visited[i]) continue;
        
        lx = INT_MAX, ly = INT_MAX, hx = INT_MIN, hy = INT_MIN;
        dfs(i);
        
        ans = min(ans, (2*(hx-lx+hy-ly)));
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("fenceplan"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
