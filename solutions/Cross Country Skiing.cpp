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

int n, m;
vector<vector<ll>>tab, dist;
set<pii>wayPoints;

// bool isValid(int i, int j){
//     return (i >= 0 and i < n and j >= 0 and j < m);
// }

void dfs(int i, int j, ll cost){
    dist[i][j] = cost;
    
    for(int d = 0; d < 4; d++){
        int delta_x = dx[d];
        int delta_y = dy[d];
        if( (i + delta_x) >= 0 and (i +delta_x) < n and (j + delta_y) >= 0 and (j + delta_y) < m  
        and max(cost, (ll)abs(tab[i][j] - tab[i+delta_x][j+delta_y])) < dist[i+delta_x][j+delta_y]){
            dfs(i+delta_x, j+delta_y, max(cost, (ll)abs(tab[i][j] - tab[i+delta_x][j+delta_y])));
        } 

    }
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    
    tab.assign(n, vector<ll>(m, 0));
    dist.assign(n, vector<ll>(m, 1e9));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> tab[i][j];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool f;
            cin >> f;
            
            if(f) wayPoints.insert({i, j});
        }
    }
    
    pii root = *wayPoints.begin();
    
    dfs(root.f, root.s, 0);
    
    ll ans = INT_MIN;
    
    for(auto elem: wayPoints) ans = max(ans, dist[(elem).f][(elem).s]);
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("ccski"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
