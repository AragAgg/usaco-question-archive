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

int n, m;

vvi tab;
vvi tabReversed;
vb visited;

void dfs(int x){
    if(visited[x]) return;
    
    visited[x] = true;
    
    for(auto &neigh: tab[x]) dfs(neigh);
}

void fx() {
    cin >> n >> m;
    tab.assign(n+1, {});
    tabReversed.assign(n+1, {});
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        tab[a].pb(b);
        tabReversed[b].pb(a);
    }
    
    visited.assign(n+1, false);
    
    dfs(1);
    
    for(int i = 2; i < n+1; i++){
        if(!visited[i]){
            no();
            cout << 1 << " " << i << endl;
            return;
        }
    }
    
    tab = tabReversed;
    
    visited.assign(n+1, false);
    dfs(1);
    
    for(int i = 2; i < n+1; i++){
        if(!visited[i]){
            no();
            cout << i << " " << 1 << endl;
            return;
        }
    }
    
    yes();
    
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
