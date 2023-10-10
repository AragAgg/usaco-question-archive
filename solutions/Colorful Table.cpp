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

void fx() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for(auto &i: a) cin >> i;
    
    map<ll, ll>forwards;
    
    for(ll i = 0; i < n; i++){
        if(forwards.count(a[i])) continue;
        if(forwards.upper_bound(a[i]) != forwards.end()){
            
            forwards[a[i]] = (*forwards.upper_bound(a[i])).s;

        }else{
            // bestYet = i;
            // bestYetNum = a[i];
            
            forwards[a[i]] = i;
        }
    }
    
    
    
    map<ll, ll>backwards;
    for(ll i = n-1; i >= 0; i--){
        if(backwards.count(a[i])) continue;
        if(backwards.upper_bound(a[i]) != backwards.end()){

            backwards[a[i]] = (*backwards.upper_bound(a[i])).s;

        }else{
            // bestYet = i;
            // bestYetNum = a[i];
            
            backwards[a[i]] = i;
        }
    }
    
    for(ll i = 1; i <= k; i++){
        if(!forwards.count(i)){
            cout << 0 << " ";
        }else{
            cout << ((backwards[i] - forwards[i] + 1)*2) << " ";
        }
        
        
    }
    
    cout << endl;
    
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
