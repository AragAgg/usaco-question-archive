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
    
    vi ori(n);
    
    for(auto &i : ori) cin >> i;
    
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    
    vii oriSorted;
    for(int i = 0; i < n; i++){
        oriSorted.pb({ori[i], i});
    }
    
    sort(oriSorted.begin(), oriSorted.end());
    
    long long ans = 0;
    for(auto i: oriSorted){auto item = i.first; ans += abs(item - oriSorted[0].first) +1;}
    
    unordered_map<long long, long long> anss;
    
    anss.insert({oriSorted[0].second, ans});
    
    long long c = 0;
    
    for(int i = 1; i < n; i++){
        ans += abs(i*(c + oriSorted[i].first - oriSorted[i-1].first));
        ans -= abs((n-i)*(c + oriSorted[i].first - oriSorted[i-1].first));
        
        // cout << "got: " << i << " " << ans << endl;
         
        anss.insert({oriSorted[i].second, ans});
    }
    
    for(int i = 0; i < n; i++) cout << anss[i] << " ";
    cout<<endl;
    
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
