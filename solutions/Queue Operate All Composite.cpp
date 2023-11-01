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
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;


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

ll mod = 998244353;

ll fastExp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    
    return res;
}

ll modInv(ll a){ return fastExp(a, mod-2);}

void fx() {
    ll Q; cin >> Q;
    queue<pii>q;
    ll coeff = 1, constt = 0;
    
    while(Q--){
        int type;
        cin >> type;
        
        if(type == 0){
            ll a, b;
            cin >> a >> b;
            q.push({a, b});
            
            coeff = (coeff * a) % mod;
            constt = ((constt * a) + b) % mod;
        }else if(type == 1){
            auto [a, b] = q.front();
            q.pop();
            
            coeff = (coeff * modInv(a)) % mod;
            constt = ((constt - (coeff * b) % mod) + mod) % mod;
        }else{
            ll x;
            cin >> x;
            cout << ((coeff * x  + constt) % mod) << endl;
        }
    }
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
