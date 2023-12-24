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

    vi parent(n, -2);
    queue<int>q;
    
    vvi adj(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    parent[0] = -1;
    int lvl = 1;
    bool found = false;
    q.push(0);

    while(!q.empty()){
        queue<int>que;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n-1){ found = 1; break; }

            for(auto neigh: adj[curr]){
                if(parent[neigh] == -2){
                    parent[neigh] = curr;
                    que.push(neigh);
                }
            }
        }

        if(found) break;
        swap(que, q);
    }

    if(!found){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vi path;
    int curr = n-1;
    while(curr != -1){
        path.pb(curr);
        curr = parent[curr];
    }

    reverse(all(path));
    cout << path.size() << endl;
    for(auto node: path) cout << (node + 1) << " ";
    cout << endl;
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
