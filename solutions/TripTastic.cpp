#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long

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

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

ll N, M, K;
vector<vector<ll>>tab;

bool isViable(ll r){
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if((tab[i][j] - tab[i][j-1] - tab[i-1][j] + tab[i-1][j-1])){
                ll total = tab[min(i+r, N)][min(j+r, M)] 
                            - tab[min(i+r, N)][max(0LL, j-r-1)]
                            - tab[max(0LL, i-r-1)][min(j+r, M)]
                            + tab[max(0LL, i-r-1)][max(0LL, j-r-1)];

                if(total >= K+1) return true;
            }
        }
    }
    return false;
}

void fx() {
    // Functionality for fx
    cin >> N >> M >> K;
    
    tab.clear();
    tab.assign(N+1, vector<ll>(M+1, 0));
    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++) cin >> tab[i][j];
    }
    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++) tab[i][j] += tab[i-1][j] + tab[i][j-1] - tab[i-1][j-1];
    }
    
    ll lo = 0;
    ll hi = 2 + max(N, M)/2;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)) hi = mid;
        else lo = mid+1;
    }
    
    cout << ((lo == 2 + max(N, M)/2)?-1:lo) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
