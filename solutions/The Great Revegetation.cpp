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

vii tab[200000];
vi colorOf;

bool dfs(int x, bool col){
    colorOf[x] = col;
    
    for(auto &neigh: tab[x]){
        
        if(colorOf[neigh.f] == -1){ if(!dfs(neigh.f, (neigh.s?!col:col))) return false;}
        else if(colorOf[neigh.f] != ((neigh.s)?(!col):(col))) return false;
    }
    
    return true;
}

void fx() {
    int n, m;
    cin >> n >> m;
    
    colorOf.assign(n, -1);
    
    for(int i = 0; i < m; i++){
        char c;
        int a, b;
        cin >> c >> a >> b;
        
        a--;
        b--;
        
        tab[a].pb({b, ((c == 'D')?1:0)});
        tab[b].pb({a, ((c == 'D')?1:0)});
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        if(colorOf[i] != -1) continue;
        
        if(!dfs(i, 1)){
            cout << 0 << endl;
            return;
        }
        
        ans++;
    }
    
    cout << 1;
    for(int i = 0; i < ans; i++) cout << 0;
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("revegetate"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
