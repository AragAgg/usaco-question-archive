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

    vi tab(n, 0);
    for(auto &i: tab) cin >> i;

    sort(all(tab));
    
    int minimum = INT_MAX, maximum = 0;

    if(((tab[n-2] - tab[0]) == n-2 and (tab[n-1] - tab[n-2] - 1 >= 2)) or (tab[n-1] - tab[1]) == n-2 and (tab[1] - tab[0] - 1 >= 2)) minimum = 2;

    for(int i = 2; i < n-1; i++) maximum += (tab[i] - tab[i-1] -1);

    maximum += max((tab[1] - tab[0] -1), (tab[n-1] - tab[n-2] -1));

    if (minimum != 2) for(int i = 0; i < n; i++){
        int dist = n-(upper_bound(all(tab), (tab[i]+n-1)) - (tab.begin()+i));
        minimum = min(minimum, dist);
    }

    cout << minimum << endl << maximum << endl;


}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("herding"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
