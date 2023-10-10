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
    vi tab(3);
    
    for(auto &i: tab) cin >> i;
    
    sort(tab.begin(), tab.end());
    
    int a = tab[0];
    int b = tab[1];
    int c = tab[2];
    
    int mini = ((b-a == 2) or (c-b == 2))?1:2;
    int maxi = max((b-a), (c-b)) - 1;
    
    if(b-a == 1 and c-b == 1){ mini = 0; maxi = 0;}
    
    cout << mini << "\n" << maxi << "\n";
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
