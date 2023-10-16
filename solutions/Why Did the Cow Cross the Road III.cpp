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

int n, k, r;

set<pair<pii, pii>>notAllowed;
vvi visited;
vvi tab;

void dfs(int i, int j, int &z){
    if(i < 0 or i >= n or j < 0 or j >= n or visited[i][j]) return;
    
    visited[i][j] = 1;
    
    if(tab[i][j] == 1) z++;
    
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        
        if(notAllowed.count({{i, j}, {x, y}})) continue;
        
        dfs(x, y, z);
    }
}

void fx() {
    cin >> n >> k >> r;
    
    visited.assign(n, vi(n, 0));
    tab.assign(n, vi(n, 0));
    
    for(int i = 0; i < r; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        notAllowed.insert({{--a, --b}, {--c, --d}});
        notAllowed.insert({{c, d}, {a, b}});
    }
    
    vii cows;
    
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        cows.pb({a, b});
        tab[a][b] = 1;
    }
    
    vi nCows;
    
    for(auto cow: cows){ 
        if(visited[cow.f][cow.s]) continue;
        int z = 0;
        dfs(cow.f, cow.s, z);
        nCows.pb(z);
    }
    
    int ans = 0;
    for(auto cow: nCows) ans += (k - cow)*cow;
    
    cout << (ans/2) << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("countcross"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
