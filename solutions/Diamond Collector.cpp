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
    int n, k;
    cin >> n >> k;
    
    vi tab(n, 0);
    vi beg(n, 1);
    vi end(n, 1);
    
    for(auto &i: tab) cin >> i;
    
    sort(all(tab));
    
    int left = 0, right = 0, ans = 0;
    
    while(left < n-1){
        while(right < n-1){
            right++;
            if((tab[right] - tab[left]) > k) break;
            
            beg[left] = end[right] = right - left+1;
        }
        
        while(left < right){
            left++;
            end[left] = max(end[left], end[left-1]);
            beg[left] = right - left + ((tab[right - tab[left] <= k])?1:0);
            if(tab[right] - tab[left] <= k) break;
        }
    }
    
    for(int i = 1; i < n; i++) ans = max(ans, beg[i] + end[i-1]);
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("diamond"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
