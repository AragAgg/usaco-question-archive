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

int n;
vii tab;

long long ans = INT_MIN;
long long totalArea = 0;

void fx2(){
    vi t(n, 0);
    vi b(n, 0);
    
    t[0] = tab[0].s;
    b[0] = tab[0].s;
    
    for(int i = 1; i < n; i++){
        t[i] = max(t[i-1], tab[i].s);
        b[i] = min(b[i-1], tab[i].s);
    }
    
    totalArea = (1LL)*(abs(tab[n-1].f - tab[0].f)) * (abs(t[n-1] - b[n-1]));
    
    t[n-1] = tab[n-1].s;
    b[n-1] = tab[n-1].s;
    
    for(int i = n-1; i > 0; i--){
        t[i] = max(((i == n-1)?tab[i].s:t[i+1]), tab[i].s);
        b[i] = min(((i == n-1)?tab[i].s:b[i+1]), tab[i].s);
        if(tab[i-1].f == tab[i].f and t[i] >= b[i-1]) continue;
        ans = max(ans, totalArea - (1LL)*(t[i-1] - b[i-1])*(tab[i-1].f - tab[0].f) - (1LL)*(t[i] - b[i])*(tab[n-1].f - tab[i].f));
    }

}

void fx() {
    cin >> n;
    tab.assign(n, {0, 0});
    
    for(auto &i: tab) cin >> i.f >> i.s;
    sort(all(tab), [](pii &a, pii &b){return a.f <= b.f;});
    fx2();
    
    for(auto &i: tab) swap(i.f, i.s);
    sort(all(tab), [](pii &a, pii &b){return a.f <= b.f;});
    fx2();
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("split"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
