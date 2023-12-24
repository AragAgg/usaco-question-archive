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

    vvi adj(n);
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;

        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    int res = INT_MAX;

    int dist[n];
    for(int start = 0; start < n; start++){
        memset(dist, -1, sizeof dist);
        queue<pii>q;
        dist[start] = 0;
        q.push({start, -1});

        while(!q.empty()){
            int curr = q.front().f;
            int parent = q.front().s;
            q.pop();

            for(auto &neigh: adj[curr]){
                if(dist[neigh] != -1){ if(neigh != parent) res = min(res, dist[neigh] + dist[curr] + 1);}
                else dist[neigh] = dist[curr] + 1, q.push({neigh, curr});
            }
        }
    }
    
    cout << ((res == INT_MAX)?-1:res) << endl;
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
