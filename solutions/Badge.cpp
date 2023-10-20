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

unordered_map<int, int>currEdges;
vi res, visited, tab;

void dfs(int v){
    if(visited[v]){
        int a = v;
        
        while(true){
            res[a] = a;
            a = currEdges[a];
            if(a == v) return;
        }
    }
    visited[v] = true;
    
    if(res[tab[v]] != -1){ res[v] = res[tab[v]]; return;}
    
    currEdges.insert({v, tab[v]});
    dfs(tab[v]);
    if(res[v] == -1) res[v] = res[tab[v]];
}

void fx() {
    int n;
    cin >> n;
    
    res.assign(n, -1);
    visited.assign(n, 0);
    tab.assign(n, 0);
    
    for(auto &i: tab){ cin >> i; i--;}
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        currEdges.clear();
        dfs(i);
    }
    
    for(auto &i: res) cout << (i + 1) << " ";
    
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
