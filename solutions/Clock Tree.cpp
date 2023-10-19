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
    cout << name << " = [ ";
    for(const auto &x : a) cout << x << ' ';
    cout << "]\n";
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

int n, a, b, ans = 0;
vvi tab;
vi t;

int dfs(int v, int parent){
    int burden = 0;
    for(auto neigh: tab[v]) if(neigh != parent) burden += dfs(neigh, v);
    return ((12 - t[v] - burden)%12 + 12)%12;
}

void fx() {
    cin >> n;
    
    t.assign(n, 0);
    tab.assign(n, {});
    
    for(auto &i: t) cin >> i;
    
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tab[--a].pb(--b);
        tab[b].pb(a);
    }
    
    for(int i = 0; i < n; i++){
        int rs = (dfs(i, -1));
        if(rs == 0 or rs == 11) ans++;
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("clocktree"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
