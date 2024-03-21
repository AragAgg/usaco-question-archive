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

void mstack(vi &tab, vi &res){
    int n = tab.size();
    stack<int>s;
    for(int i = 0; i < n; i++){
        while(!s.empty() and tab[s.top()] >= tab[i]) s.pop();

        res[i] += s.empty()?(i+1):(i - s.top());
        s.push(i);
    }

    while(!s.empty()) s.pop();

    for(int i = n-1; i >= 0; i--){
        while(!s.empty() and tab[s.top()] >= tab[i]) s.pop();

        res[i] += s.empty()?(n-i):(s.top() - i);
        s.push(i);
    }
}

void fx() {
    int n;
    cin >> n;

    vi tab(n);
    for(auto &i: tab) cin >> i;
    vi res(n, -1);

    mstack(tab, res);

    vi str(n, 0);
    for(int i = 0; i < n; i++){
        str[res[i]-1] = max(str[res[i]-1], tab[i]);
    }

    for(int i = n-2; i >= 0; i--){
        str[i] = max(str[i], str[i+1]);
    }
                                      
    for(auto &i: str) cout << i << " ";

    cout << endl;
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
