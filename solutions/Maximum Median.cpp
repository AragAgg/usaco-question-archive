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

vector<ll> tab;
ll k;

bool viable(ll mid){
    long long needed = 0;
    
    for(auto &i: tab){
        if(i >= mid or needed > k) break;
        
        needed += (mid - i);
    }
    
    return (needed <= k);
}

void fx(){
    int n;
    cin >> n >> k;
    
    tab.assign(n/2+1, 0);
    
    vi tab2(n, 0);
    for(auto &i: tab2) cin >> i;
    
    sort(all(tab2));
    
    for(int i = n/2; i < n; i++) tab[i-n/2] = tab2[i];
    
    ll low = tab[0] -1;
    ll high = 1e12+1000;
    
    while(low < high){
        int mid = low + (high - low +1)/2;
        
        if(viable(mid)) low = mid;
        else high = mid -1;
    }
    
    cout << low << endl;
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
