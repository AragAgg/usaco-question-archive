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

#define int long long
// cin.tie(0)->sync_with_stdio(0);
vector<pii>tmp;
int x, n;
int ans = -1;

void fx2(int i, int given){
   if(i == tmp.size()){
       //check curr...
       int rem = x - n*given;
       if(rem >=0 and rem%given == 0) ans= max(ans, given);
       return;
    }

   for(int j = tmp[i].s; j >=0; j--){
       int currRes = given;
       for(int x = 0; x < j; x++) currRes *= tmp[i].f;
       fx2(i+1, currRes);
    }
}

void fx() {
    ans = -1;
    tmp.clear();
    cin >> x >> n;
    vi tab;

    int tx = x;
    for(int i = 2; i*i <= tx+100; i++){
        while(tx % i == 0){
            tab.pb(i);
            tx /= i;
        }
    }
    
    if(tx > 1) tab.pb(tx);

    umii t;
    for(auto &i: tab) t[i]++;

    for(auto &i: t) tmp.pb({i.f, i.s});

    int given = 1;
    fx2(0, given);

    cout << max(ans, 1LL) << endl;
    
}

signed main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
     int t; cin >> t;
     while(t--) fx();
    
    // Single test case
    
    
    return 0;
}
