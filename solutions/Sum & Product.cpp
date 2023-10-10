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
    int n;
    cin >> n;
    
    map<long long, long long> tab;
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        
        tab[t]++;
    }
    
    vector<long long> res;
    
    int q; cin >> q;
    
    long long c = 0;
    
    while(q--){
        long long x, y;
        cin >> x >> y;
        
        long long ans = 0;
        
        if(x*x - 4*y < 0 or sqrt(x*x - 4*y) != ceil(sqrt(x*x - 4*y))) ans = 0;
        else if(x*x - 4*y == 0 ){
            int r1 = (x - sqrt(x*x - 4*y))/2;
            
            int c1 = x - r1;
            
            if(r1 == c1) ans = (tab[r1]*(c+tab[c1]-1))/2;
            else ans = tab[r1] * (c+tab[c1]);
        }else {
            int r1 = (x - sqrt(x*x - 4*y))/2;
            
            int c1 = x - r1;
            
            int r2 = (x + sqrt(x*x - 4*y))/2;
            
            int c2 = x - r2;
            
            if(r1 == c2) ans = (tab[r1]*(c+tab[c1])); //<- just fixed
            else{
                if(r1 == c1) ans += (tab[r1]*(c+tab[c1]-1))/2;
                else ans += tab[r1]*(c+tab[c1]);
                
                if(r2 == c2) ans += (tab[r2]*(c+tab[c2]-1))/2;
                else ans += tab[r2]*(c+tab[c2]);
            }
        }
        
        res.pb(ans);
    }
    
    for(auto item : res) cout << item << " ";
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
