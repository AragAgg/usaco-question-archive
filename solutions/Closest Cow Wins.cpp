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
    ll k, m, n;
    cin >> k >> m >> n;
    
    map<ll, ll>patches;
    
    for(int i = 0; i < k; i++){
        ll loc, val;
        cin >> loc >> val;
        
        patches[loc] = val;
    }
    
    set<ll>nhoj;
    
    for(int i = 0; i < m; i++){
        ll loc;
        cin >> loc;
        nhoj.insert(loc);
    }
    
    //safety bounds
    nhoj.insert(-100000000000000);  
    nhoj.insert(1e11);
    patches.insert({1e17+100, 0});
    
    auto prev_n = nhoj.begin();
    auto next_n = nhoj.begin();
    
    priority_queue<ll> allProfits;
    
    while(next_n != prev(nhoj.end())){
        next_n++;
        
        ll windowSize = (*next_n - *prev_n)/2;
        
        auto beg_patch = patches.lower_bound(*prev_n);
        auto next_patch = beg_patch;
        
        if((*beg_patch).f > *next_n){
            prev_n++;
            continue;
        }
        
        ll curr = (*beg_patch).s, best = (*beg_patch).s, total = (*beg_patch).s;
        
        while((*next_patch).f < *next_n){
            while((*next_patch).f - (*beg_patch).f <= windowSize){
                if((*next_patch).f - (*beg_patch).f < windowSize) best = max(best, curr);
                
                if((*next(next_patch)).f < *next_n){
                    next_patch++;
                    curr += (*next_patch).s;
                    total += (*next_patch).s;
                }else break;
            }
            
            while(beg_patch != next_patch and ((*next_patch).f - (*beg_patch).f) >= windowSize){
                curr -= (*beg_patch).s;
                beg_patch++;
            }
            
            best = max(best, curr);
            
            if((*next(next_patch)).f > *next_n) break;
        }
        allProfits.push(total - best);
        allProfits.push(best);
        
        prev_n++;
    }
    
    ll ans = 0;
    
    while(n-- and !allProfits.empty()){ ans += allProfits.top(); allProfits.pop();}
    
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
