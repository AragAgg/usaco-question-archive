//#pragma GCC optimize("03,unroll-loops")

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

#define vT vector<T>

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


struct segTree{
    //quick config
    typedef ll T;
    const T def = INT_MAX; //default value;
    T f(T a, T b){ return min(a, b); } // or any other associative function here.

    vT e;
    int n;

    void build(vT &_e, int node, int l, int r){
        if(l == r) e[node] = _e[l];
        else{
            int mid = (l+r)/2;
            build(_e, node*2 + 1, l, mid);
            build(_e, node*2 + 2, mid+1, r);
            e[node] = f(e[node*2 + 1], e[node*2+2]);
        }
    }
    
    void _update(int node, int l, int r, int pos, T val){
        if(l == r) e[node] = val;
        else{
            int mid = (l+r)/2;
            if(pos <= mid) _update(node*2+1, l, mid, pos, val);
            else _update(node*2+2, mid+1, r, pos, val);
            e[node] = f(e[node*2+1], e[node*2+2]);
        }
    }

    T _query(int node, int l, int r, int start, int end){
        if(l > end or r < start) return def;
        if(l >= start and r <= end) return e[node];
        int mid = (l + r)/2;
        return f(_query(node*2+1, l, mid, start, end), _query(node*2+2, mid+1, r, start, end));
    }

    T query(int start, int end){ return _query(0, 0, n-1, start, end); }
    void update(int pos, int val){ _update(0, 0, n-1, pos, val); }
    segTree(vT &_e) : n(_e.size()), e(4*_e.size(), def){ build(_e, 0, 0, _e.size()-1); }
};

void fx() {
    int n, q;
    cin >> n >> q;
    vll e(n);
    for(auto &i: e) cin >> i;
    segTree tree(e);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            //update
            int pos, val;
            cin >> pos >> val;
            pos--;
            tree.update(pos, val);
        }else{
            //query
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << tree.query(l, r) << endl;
        }
    }
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
