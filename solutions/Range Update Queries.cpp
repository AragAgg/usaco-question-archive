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


struct fenwickTree{
    vll e;
    int n;

    fenwickTree(int n) : e(n+1, 0), n(n+1) {}

    void update(int idx, ll delta){
        idx++;
        while(idx < n){
            e[idx] += delta;
            idx += idx & -idx;
        }
    }

    ll val(int idx){
        idx++;
        ll res = 0;
        while(idx > 0){
            res += e[idx];
            idx -= idx & -idx; 
        }

        return res;
    }

    void deb(){
        cout << "\n ----- \n";
        debug_vector(e);
        cout << "\n ----- \n";
    }

};

void fx() {
    int n, q;
    cin >> n >> q;

    fenwickTree t(n);
    int till = 0;

    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        t.update(i, l-till);
        till = l;
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int a, b, delta;
            cin >> a >> b >> delta;
            --a; --b;
        
            t.update(a, delta);
            t.update(b+1,  -delta);

        }else{
            int l;
            cin >> l;
            --l;

            cout << t.val(l) << endl;

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
