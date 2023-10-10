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

void fx(){
    int n;
    cin >> n;
    
    vi tab(n);
    
    for(auto &i : tab) cin >> i;
    
    sort(tab.begin(), tab.end());
    
    int ans = 0;
    
    for(int begin = 0; begin < tab.size(); begin++){
        int blastR = 1;
        int l = begin;
        int r = begin;
        
        while(l > 0 and tab[l-1] >= tab[l] - blastR){
            int temp = l;
            while(l > 0 and tab[l-1] >= tab[temp] - blastR) l--;
            blastR++;
        }
        
        blastR = 1;
        while(r < tab.size()-1 and tab[r+1] <= tab[r] + blastR){
            int temp = r;
            while(r < tab.size()-1 and tab[r+1] <= tab[temp] + blastR) r++;
            blastR++;
        }
        
        ans = max(ans, (r-l+1));
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile("cowqueue");
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    freopen("angry.in", "r", stdin); 
    freopen("angry.out", "w", stdout);
    
    // Single test case
    fx();
    
    return 0;
}
