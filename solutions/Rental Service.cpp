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

int n, m, r;
vi cows;
vii store;
vi neigh;

void fx(){
    cin >> n >> m >> r;
    
    cows.assign(n, 0);
    store.assign(m, {0,0});
    neigh.assign(r, 0);
    
    for(auto &i: cows) cin >> i;
    for(auto &i: store) cin >> i.s >> i.f;
    for(auto &i: neigh) cin >> i;
    
    sort(all(cows));
    reverse(all(cows));
    sort(all(store));
    reverse(all(store));
    sort(all(neigh));
    reverse(all(neigh));
    
    int sPtr = 0;
    int nPtr = 0;
    long long totalEarnings = 0;
    int fPtr = -1;
    vector<long long> sellValue(n, 0);
    
    for(int i = 0; i < n; i++){
        while(cows[i] != 0 and sPtr != m){
            long long curr = min(cows[i], store[sPtr].s);
            cows[i] -= curr;
            store[sPtr].s -= curr;
            sellValue[i] += curr*store[sPtr].f;
            totalEarnings += curr*store[sPtr].f;
            if(store[sPtr].s == 0) sPtr++;
            fPtr = i;
        }
        
        if(sPtr == m and nPtr != r and !sellValue[i]) totalEarnings += neigh[nPtr++];
    }
    
    while(fPtr >= 0 and nPtr != r){
        long long curr = totalEarnings;
        curr -= sellValue[fPtr--];
        curr += neigh[nPtr++];
        totalEarnings = max(totalEarnings, curr);
    }
    
    cout << totalEarnings << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("rental"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
