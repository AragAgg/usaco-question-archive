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

#define id second
#define x first.first
#define y first.second



inline void fx(){
    int n;
    cin >> n;
    
    vector<pair<pii, int>>tab;
    
    for(int i = 0; i < 2*n; i+=2){
        tab.pb({{0, 0}, 0});
        tab.pb({{0, 0}, 0});
        cin >> tab[i].x >> tab[i].y;
        tab[i].id = i/2;
        tab[i+1].id = tab[i].id;
        tab[i+1].x = tab[i].y;
        tab[i+1].y = tab[i].x;
    }
    
    vi ans(n, -1);
    sort(all(tab));
    int low = 0;
    int cachedTemp = 0;
    
    for(int i = 1; i < 2*n; i++){
        
        for(int temp = cachedTemp; temp < i; temp++){
            if(tab[temp].x != tab[i].x and tab[temp].y < tab[low].y) low = temp;
            cachedTemp = temp;
            if(tab[temp].x == tab[i].x) break;
        }
        
        if((tab[low].x < tab[i].x and tab[low].y < tab[i].y)) ans[tab[i].id] = tab[low].id;
        
    }
    
    for(int i = 0; i < n; i++) cout << ((ans[i] == -1)?-1:ans[i]+1) << " ";
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
