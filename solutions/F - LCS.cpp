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

vector<vector<pair<int, int>>>dp(3001, vector<pii>(3001, {-1, -1}));
vector<int> last(3001, 0);
string a, b;

pii fx2(int x, int y){
    if(x < 0 or y < 0) return {0, -1};
    if(dp[x][y].f != -1) return dp[x][y];

    if(a[x] == b[y]){ 
        pii res = fx2(x-1, y-1);
        last[x] = res.s;
        return dp[x][y] = {res.f+1, x};
    }

    pii res1 = fx2(x, y-1);
    pii res2 = fx2(x-1, y);

    if(res1.f >= res2.f) return dp[x][y] = res1; 
    else return dp[x][y] = res2;
}

void fx() {
    for(int i = 0; i < 3001; i++) last[i] = -1;
    cin >> a >> b;
    pii res = fx2(a.size()-1, b.size()-1);
    string t = "";
    if(res.f == 0){
        cout << t << endl;
        return;
    }

    while(res.f--){
        t += a[res.s];
        res.s = last[res.s];
        if(res.s == -1 or res.s < 0) break;
    }

    reverse(all(t));
    cout << t << endl;
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
