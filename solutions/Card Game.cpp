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
    
    //work backwards in the deck of cards, as taking the ith card doesn't affect the parity of and of 1...i-1th card...
    int n;
    cin >> n;
    
    vector<ll> tab(n);
    
    for(auto &i: tab) cin >> i;
    
    ll rem = 0;
    ll curr = 0;
    ll ans = 0;
    
    bool isEven = ((n%2)?false:true);
    
    for(int i = n-1; i >= 0; i--){
        if(isEven){
            // take action
            curr += rem;
            rem = 0;
            
            if(tab[i] > 0) rem = tab[i]; // if this was a positive card, make sure to take it if we take an action in future
        }else{
            //take action
            curr += rem + tab[i];
            rem = 0;
            
            if(tab[i] < 0) rem = -tab[i]; //if this was a negative card, we took it, so if we take an action in future, offset it.
        }
        
        isEven = !isEven;
        
        ans = max(ans, curr); //ans is max of all curr, as we might leave the game "early"
    }
    
    cout << ans << endl;
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
