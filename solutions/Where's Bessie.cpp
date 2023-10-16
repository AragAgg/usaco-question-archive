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
vector<pair<pii, pii>>PCLS;
vvi visited; 
int lxBound, lyBound, hxBound, hyBound;

void dfs(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = 1;
    
    for(int d = 0; d < 4; d++){
        int x = i + dx[d], y = j + dy[d];
        if(x < lxBound or x > hxBound or y < lyBound or y > hyBound or tab[x][y] != tab[i][j]) continue;
        dfs(x, y);
    }
}

bool isPCL(int i, int j, int x, int y){
    visited.assign(n, vi(n, 0));
    lxBound = i, lyBound = j, hxBound = x, hyBound = y;
    map<int, int> colors;
    int comps = 0;
    
    for(int l = i; l <= x; l++){
        for(int m = j; m <= y; m++){
            if(visited[l][m]) continue;
            comps++;
            colors[tab[l][m]]++;
            dfs(l, m);
            if(colors.size() > 2) return false;
        }
    }
    
    if(comps < 3) return false;
    for(auto item: colors) if(item.s == 1) return true;
    return false;
}

bool isUnique(int i, int j, int x, int y){
    bool f = true;
    bool add = false;
    vi toErase;
    
    for(int p = 0; p < PCLS.size(); p++){
        auto pcl = PCLS[p];
        
        if(pcl.f.f >= i and pcl.s.f <= x and pcl.f.s >= j and pcl.s.s <= y){
            f = false;
            add = true;
            toErase.pb(p);
        }
        
        if(i >= pcl.f.f and x <= pcl.s.f and j >= pcl.f.s and y <= pcl.s.s) f = false;
    }
    
    for(int p = toErase.size()-1; p >= 0; p--) PCLS.erase(PCLS.begin()+toErase[p]);
    if(add) PCLS.pb({{i, j}, {x, y}});
    return f;
}

void fx() {
    cin >> n;
    tab.assign(n, vi(n, 0));
    
    for(auto &r: tab) for(auto &c: r){ char ch; cin >> ch; c = (ch - 'A');}
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int x = i; x < n; x++){
                for(int y = j; y < n; y++){
                    if(isPCL(i, j, x, y) and isUnique(i, j, x, y)) PCLS.pb({{i, j}, {x, y}});
                }
            }
        }
    }
    
    cout << PCLS.size() << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("where"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
