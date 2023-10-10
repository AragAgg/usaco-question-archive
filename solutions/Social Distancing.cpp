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

int n, m;
vector<pair<ll, ll>> locs;
vector<pair<ll, ll>> locsOri;

bool isViable(ll delta){
    locs = locsOri;
    int iter = 0;
    
    int cows = n;
    
    ll prevLoc = -delta;
    while(cows and iter != m){
        ll newLoc = max((prevLoc + delta), (locs[iter].f));
        
        if(locs[iter].s < newLoc){iter++;}
        else{
            locs[iter].f = newLoc+1;
            
            prevLoc = newLoc;
            
            if(locs[iter].f > locs[iter].s) iter++;
            
            cows--;
        }
    }
    return (!cows);
}

void fx(){
    cin >> n >> m;
    while(m--){
        pair<ll, ll> t;
        cin >> t.f >> t.s;
        
        locsOri.pb(t);
    }
    
    m = locsOri.size();
    
    sort(all(locsOri));
    
    ll lo = 0;
    ll hi = 1e18+100;
    
    while(lo < hi){
        ll mid = lo + (hi - lo+1)/2;
        
        if(isViable(mid)) lo = mid;
        else hi = mid -1;
    }
    
    cout << lo << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("socdist"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
