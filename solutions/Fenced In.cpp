#pragma GCC optimize("03,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define p push
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long
//#define int ll
#define endl "\n"
#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

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

const ll INF = 1e15;

void fx() {
    ll A, B, n, m;
    cin >> A >> B >> n >> m;
    vll vert(n);
    vll hor(m);

    for(auto &i: vert) cin >> i;
    for(auto &i: hor) cin >> i;

    vert.pb(0); 
    vert.pb(A);
    hor.pb(B);
    hor.pb(0);

    sort(all(vert));
    sort(all(hor));

    ll res = 0;
    int nEdges = 0;

    vll dist((n+1)*(m+1), INF);
    vb taken((n+1)*(m+1), 0);

    priority_queue<tuple<ll, int>>pq;
    pq.p({0, 0});

    while(!pq.empty() and nEdges != (n+1)*(m+1) ){
        auto [len, node] = pq.top();
        pq.pop();
        len *= -1;

        if(taken[node]) continue;
        taken[node] = true;

        dist[node] = len;
        res += len;
        nEdges++;

        int alpha = node / (n+1);
        int beta = node - alpha*(n+1);

        if(beta + 1 < n+1 and !taken[node+1]){
            //connect to right
            pq.p({-(hor[alpha +1] - hor[alpha]), node+1});
            //cout << (hor[alpha +1] - hor[alpha]) << " is the dist between: " << node << " and " << (node + 1) << endl;
        }

        if(beta -1 >= 0 and !taken[node-1]){
            //connect to left
            pq.p({-(hor[alpha +1] - hor[alpha]), node-1});
            //cout << (hor[alpha +1] - hor[alpha]) << " is the dist between: " << node << " and " << (node - 1) << endl;
        }

        if(alpha +1 < m+1 and !taken[node + n+1]){
            //connect to up
            pq.p({-(vert[beta+1] - vert[beta]), node + n+1});
            //cout << (vert[beta+1] - vert[beta])<< " is the dist between: " << node << " and " << (node + n+1) << endl;
        }

        if(alpha -1 >= 0 and !taken[node - n -1]){
            //connect to down
            pq.p({-(vert[beta+1] - vert[beta]), node -n -1});
            //cout << (vert[beta+1] - vert[beta]) << " is the dist between: " << node << " and " << (node - n - 1) << endl;
        }
    }

    cout << res << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
     iofile(string("fencedin"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
