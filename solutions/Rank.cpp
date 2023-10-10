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

int n, k;
vvi tab;

set<int>cantDetermine;

vb visited;

void dfs(int i, int root){
    if(visited[i]) return;
    
    visited[i] = true;
    
    for(auto &neigh : tab[i]){
        if(neigh == root) cantDetermine.insert(root);
        
        dfs(neigh, root);
    }
}

void fx() {
    // Functionality for fx
    cin >> n >> k;
    tab.assign(n+1, {});
    
    for(int i = 0; i < k; i++){
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        
        if(sa > sb) tab[a].pb(b);
        else tab[b].pb(a);
    }
    
    
    for(int i = 1; i < n+1; i++){
        visited.assign(n+1, false);
    
        dfs(i, i);
    }
    
    cout << cantDetermine.size() << endl;
    
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
