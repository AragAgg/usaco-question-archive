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

int N;
unordered_map<int, vector<ll>>m;
ll globalOffset = 0;
unordered_map<int, ll>localOffset;

void fx() {
    cin >> N;
    vector<ll> a(N, 0), c(N, 0);
    
    for(auto &i: a) cin >> i;
    for(auto &i: c) cin >> i;
    
    for(int i = 0; i < N; i++) m[c[i]].pb(a[i]);
    
    for(auto &i: m){
        ll offset = 0;
        for(auto &item : i.s){
            offset += item;
            item = offset;
        }
    }
    
    int q;
    cin >> q;
    
    while(q--){
        ll type, col, x;
        cin >> type >> col >> x;
        
        if(type == 1){
            globalOffset += x;
            localOffset[col] += x;
        }else{
            const auto &list = m[col];
            int lo = 0;
            int hi = list.size()-1;
            
            while(lo < hi){
                int mid = lo + (hi - lo + 1)/2;
                
                if(list[mid] + globalOffset*(mid+1) - localOffset[col]*(mid+1) <= x) lo = mid;
                else hi = mid -1;
            }
            
            cout << ((list[lo] + globalOffset*(lo+1) - localOffset[col]*(lo+1) <= x)?(lo+1):0) << endl;
            
        }
    }
    
    
    
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
