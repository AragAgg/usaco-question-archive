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
    // Functionality for fx
    ll n, k;
    cin >> n >> k;
    
    map<ll, ll>m;
    
    for(int i = 0; i < n; i++){
        ll t;
        cin >> t;
        m[t]++;
    }
    
    vector<pair<ll, ll>> tab;
    for(auto &i: m) tab.pb({i.f, i.s});
    
    int start = 0;
    int end = tab.size()-1;
    
    while((end - start) and k > 0){
        if(tab[start].s <= tab[end].s){
            //case one...
            ll take = min(k, tab[start].s*(tab[start+1].f - tab[start].f));
            take = floor(take/tab[start].s)*tab[start].s;
            
            if(take == 0) break;
            
            k -= take;
            
            tab[start].f += take/tab[start].s;
            
            if(tab[start].f == tab[start+1].f){ tab[start+1].s += tab[start].s; start++;}
            
        }else{
            ll take = min(k, tab[end].s*(tab[end].f - tab[end-1].f));
            take = floor(take/tab[end].s)*tab[end].s;
            
            if(take == 0) break;
            
            k -= take;
            
            tab[end].f -= take/tab[end].s;
            
            if(tab[end].f == tab[end-1].f){ tab[end-1].s += tab[end].s; end--;}
        }
    }
    
    cout << (tab[end].f - tab[start].f) << endl;
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
