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

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, char>>>adj(n);
    queue<pair<pii, int>>q;
    vvi dist(n, vi(n, INT_MAX));

    for(int i = 0; i < n; i++) dist[i][i] = 0, q.push({{i, i}, 0}); 

    for(int i = 0; i < m; i++){
        int a, b;
        char ch;
        cin >> a >> b >> ch;

        adj[--a].pb({--b, ch});
        adj[b].pb({a, ch});
        dist[a][b] = dist[b][a] = (a != b);
        q.push({{a, b}, (a != b)});
        q.push({{b, a}, (a != b)});
    }
   
    int res = INT_MAX;
    while(!q.empty()){
        auto [curr, len] = q.front();
        q.pop();

        if((curr.f == 0 and curr.s == n-1) or (curr.f == n-1 and curr.s == 0)) res = min(res, len);

        for(auto &n1: adj[curr.f]){
            for(auto &n2: adj[curr.s]){
                if(n1.s == n2.s and dist[n1.f][n2.f] > len + 2){
                    q.push({{n1.f, n2.f}, len+2});
                    dist[n1.f][n2.f] = len+2;
                }
            }
        }
    }

    cout << ((dist[n-1][0] == INT_MAX)?-1:dist[n-1][0]) << endl;


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
