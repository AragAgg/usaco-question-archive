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

vvi tab;
vi visited;
string s;

void dfs(int x, int comp){
    if(visited[x]) return;
    
    visited[x] = comp;
    
    for(auto neigh: tab[x]){
        if(s[x] != s[neigh] or visited[neigh]) continue;
        
        dfs(neigh, comp);
    }
}

void fx() {
    int n, m;
    cin >> n >> m;
    
    cin >> s;
    
    tab.assign(n, {});
    visited.assign(n, 0);
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        tab[--a].pb(--b);
        tab[b].pb(a);
    }
    
    int comp = 1;
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        
        dfs(i, comp++);
    }
    
    while(m--){
        int a, b;
        char c;
        
        cin >> a >> b >> c;
        
        a--; b--;
        
        if(visited[a] == visited[b]) cout << (c == s[a]);
        else cout << 1;
    }
    
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("milkvisits"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
