#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define endl "\n"

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

// cin.tie(0)->sync_with_stdio(0);

#define UNREACH 1000000000000

int h, g;
vector<pii>hs, gr;
ll dp[1001][1001][2];

ll fx2(int i, int j, bool atHol){

    if(i == h and j == g){
        if(!atHol) return UNREACH;
        else return 0;
    }
    
    if(dp[i][j][atHol] != UNREACH) return dp[i][j][atHol];

    if(i < h){
        ll dist = 0;
        if(atHol) dist = (hs[i+1].f - hs[i].f) * (hs[i+1].f - hs[i].f) + (hs[i+1].s - hs[i].s) * (hs[i+1].s - hs[i].s);
        else dist = (hs[i+1].f - gr[j].f) * (hs[i+1].f - gr[j].f) + (hs[i+1].s - gr[j].s) * (hs[i+1].s - gr[j].s);
        dp[i][j][atHol] = min(dp[i][j][atHol], fx2(i+1, j, true) + dist);
    }

    if(j < g){
        ll dist = 0;
        if(atHol) dist = (gr[j+1].f - hs[i].f) * (gr[j+1].f - hs[i].f) + (gr[j+1].s - hs[i].s) * (gr[j+1].s - hs[i].s);
        else dist = (gr[j+1].f - gr[j].f) * (gr[j+1].f - gr[j].f) + (gr[j+1].s - gr[j].s) * (gr[j+1].s - gr[j].s);
        dp[i][j][atHol] = min(dp[i][j][atHol], fx2(i, j+1, false) + dist);
    }

    return dp[i][j][atHol];
}

void fx() {
    // Functionality for fx
    cin >> h >> g;

    int x, y;

    for(int i = 0; i < h; i++){
        cin >> x >> y;
        if(hs.size() == 0) hs.pb({x, y});
        hs.pb({x, y});
    }

    for(int i = 0; i < g; i++){
        cin >> x >> y;
        if(gr.size() == 0) gr.pb({x, y});
        gr.pb({x, y});
    }

    for(int i = 0; i <= h; i++) for(int j = 0; j <= g; j++) dp[i][j][0] = UNREACH, dp[i][j][1] = UNREACH;
    cout << fx2(1, 0, true) << endl;

}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("checklist"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
