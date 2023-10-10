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

struct event{
    int q, t, x, n;
    
    void trans(){
        int temp = x;
        x += t;
        t = t - temp;
    }
};

bool cpr(event &a, event &b){ 
    if(a.t == b.t) return (a.q == 1);
    return (a.t < b.t);
} // <- possibly buggy


void fx() {
    // Functionality for fx
    int q;
    cin >> q;
    
    multimap<int, event>cows;
    
    vector<event>events;
    
    while(q--){
        event e;
        cin >> e.q >> e.t >> e.x >> e.n;
        e.trans();
        events.pb(e);
    }
    
    sort(all(events), cpr);
    
    int ans = 0;
    
    for(auto &e : events){
        // cout << "executing: " << e.q << " " << e.t << " " << e.x << " " << e.n << endl;
        if(e.q == 1){
            cows.insert({e.x, e});
        }else{
            while(e.n){
                // cout << e.n << endl;
                auto iter = cows.upper_bound(e.x);
            
                if(iter == cows.begin()) break; // <- check
                
                --iter;
                
                int take = min((*iter).s.n, e.n);
                // cout << "taking: " << take << endl;
                
                e.n -= take;
                ans += take;
                
                if(((*iter).s.n - take) == 0) cows.erase(iter);
                else (*iter).s.n -= take;
                
            }
        }
    }
    
    
    cout << ans << endl;
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
