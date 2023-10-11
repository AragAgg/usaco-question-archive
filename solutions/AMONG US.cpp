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

struct edge{ int to, isSameAsMe; };

vector<vector<edge>>edges;
vi colors;
int currHuman, currParasite;

bool dfs(int x, bool isHuman){
    if(colors[x] != -1) return (colors[x] == isHuman);
    
    colors[x] = isHuman;
    
    if(isHuman) currHuman++;
    else currParasite++;
    
    for(auto &neigh: edges[x]) if(!dfs(neigh.to, (neigh.isSameAsMe?isHuman:!isHuman))) return false;
    return true;
}

void fx() {
    int n, q;
    cin >> n >> q;
    
    edges.assign(n, {});
    colors.assign(n, -1);
    
    for(int i = 0; i < q; i++){
        int from;
        edge e;
        
        cin >> e.isSameAsMe >> from >> e.to;
        from--; e.to--; e.isSameAsMe--;
        
        edges[from].pb(e);
        swap(e.to, from);
        edges[from].pb(e);
    }
    
    int bestAns = 0;
    
    for(int i = 0; i < n; i++){
        if(colors[i] != -1) continue;
        
        currParasite = 0;
        currHuman = 0;
        
        if(!dfs(i, true)){
            cout << -1 << endl;
            return;
        }
        
        bestAns += max(currHuman, currParasite);
    }
    
    cout << bestAns << endl;

}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
