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


set<long long>term_bs;

long long calcAns(long long term_a){
    auto iter = term_bs.lower_bound(term_a);
    if(iter == term_bs.end()) return abs(term_a - *((--term_bs.end())));
    if(*iter == term_a or iter == term_bs.begin()) return abs(*iter - term_a);
    return min(abs(*iter - term_a), abs(term_a - *prev(iter)));
}

void fx() {
    // Functionality for fx
    long long n, m, q;
    cin >> n >> m >> q;
    
    vector<long long> a(n), b(m);
    
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    
    long long term_a = 0, ods = 0, evs = 0;
    bool neg = false;
    
    for(auto &i: a){
        term_a += (neg?-1:1)*i;
        neg = !neg;
    }
    
    neg = false;
    
    for(int j = 0; j < n; j++){
        (neg?ods:evs) += b[j];
        neg = !neg;
    }
    
    term_bs.insert(evs - ods);
    neg = false;
    
    for(int j = 1; j <= m-n; j++){
        (neg?ods:evs) -= b[j-1];
        
        if(n%2) (neg?evs:ods) += b[n+j-1];
        else (neg?ods:evs) += b[n+j-1];
        
        term_bs.insert((neg?(evs - ods):(ods - evs)));
        neg = !neg;
    }
    
    cout << calcAns(term_a) << endl;
    
    for(int i = 0; i < q; i++){
        long long l, r, x;
        cin >> l >> r >> x;
        
        if((r-l+1)%2){
            term_a += (l%2?+1:-1)*x;
        }
        
        cout << calcAns(term_a) << endl;
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
