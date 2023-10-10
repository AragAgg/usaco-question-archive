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

int m;

void fx2(int n, map<int, int>&curr, bool toAdd){
    for(int i = 1; i <= sqrt(n); i++){
        if(i > m) break;
        if(n%i != 0) continue;

        if(toAdd) curr[i]++;
        else{
            curr[i]--;
            if(curr[i] == 0) curr.erase(i);
        }

        int j = n/i;

        if(j <= m and j != i){
            if(toAdd) curr[j]++;
            else{
                curr[j]--;
                if(curr[j] == 0) curr.erase(j);
            }
        }
    }
}

void fx() {
    // Functionality for fx
    int n;
    cin >> n >> m;

    vi tab(n, 0);
    for(auto &i: tab) cin >> i;
    
    
    sort(all(tab));
    map<int, int>curr;
    
    if(n == 1){
        fx2(tab[0], curr, true);
        cout <<  ((curr.size() == m)?0:-1) << endl;
        return;
    }

    int left = 0, right = -1, ans = INT_MAX;


    // fx2(tab[0], curr, true);

    while(left < n-1 and right < n){ // <- possibly buggy
        while(right < n-1){
            right++;
            fx2(tab[right], curr, true);
            if(curr.size() >= m) break;
        }
        
        while(left < right){
            if(curr.size() >= m) ans = min(ans, tab[right] - tab[left]);
            fx2(tab[left++], curr, false);
            if(curr.size() < m) break;
        }
        
        if(curr.size() >= m) ans = min(ans, tab[right] - tab[left]);
    }

    cout << ((ans == INT_MAX)?-1:ans) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("herding"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
