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
    int n;
    cin >> n;
    
    vii tab(n);
    for(auto &i: tab){ cin >> i.f >> i.s;}
    
    sort(all(tab));
    
    unordered_map<long long, long long>mpx;
    
    const int offset = 100000;
    
    for(int i = 0; i < n; i++){
        mpx[offset*tab[i].f + tab[i].s] = 0;
        
        int counter = 0;
        
        int t = i+1;
        
        while(t < n and tab[t].f == tab[i].f){
            mpx[offset*tab[i].f + tab[i].s] += tab[t].s - tab[i].s;
            counter++;
            t++;
        }
        
        t = i+1;
        
        while(t < n and tab[t].f == tab[i].f){
            mpx[offset*tab[t].f + tab[t].s] = mpx[offset*tab[t].f + tab[t-1].s] + (tab[t].s - tab[t-1].s)*(t-i) - (tab[t].s - tab[t-1].s)*(counter--);
            t++;
        }
        i = t-1;
    }
    
  
    sort(all(tab), [](auto &a, auto &b){if(a.s == b.s) return (a.f < b.f); else return (a.s < b.s);});
    
    unordered_map<long long, long long>mpy;
    
    for(int i = 0; i < n; i++){
        mpy[offset*tab[i].f + tab[i].s] = 0;
        
        int counter = 0;
        
        int t = i+1;
        
        while(t < n and tab[t].s == tab[i].s){
            mpy[offset*tab[i].f + tab[i].s] += tab[t].f - tab[i].f;
            counter++;
            t++;
        }
        
        t = i+1;
        
        while(t < n and tab[t].s == tab[i].s){
            mpy[offset*tab[t].f + tab[t].s] = mpy[offset*tab[t-1].f + tab[t].s] + (tab[t].f - tab[t-1].f)*(t-i) - (tab[t].f - tab[t-1].f)*(counter--);
            t++;
        }
        i = t-1;
    }
    
    long long ans = 0;
    const long long mod = 1e9+7;
    
    for(auto &i: tab){
        long long curr = (mpx[offset*i.f + i.s] * mpy[offset*i.f + i.s])%mod;
        ans += curr;
        
        ans %= mod;
        
    }
    
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("triangles"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
