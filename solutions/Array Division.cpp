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
 
ll N, T;
vi tab;
 
bool isViable(ll t){
    int num = T;
    
    int iter = 0;
    ll curr = 0;
    while(iter < N and num){
        if(tab[iter] > t) return false;
        
        if(curr + tab[iter] > t){
            num--;
            curr = tab[iter];
        }else curr += tab[iter];
        
        iter++;
    }
    
    return (iter == N and curr <= t and num > 0);
    
}
 
void fx() {
    // Functionality for fx
    cin >> N >> T;
    tab.assign(N, 0);
    
    ll lo = 0;
    ll hi = 0;
    
    for(auto &i: tab){ cin >> i; hi += i;}
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)) hi = mid;
        else lo = mid +1;
    }
    
    cout << lo << endl;
    
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
