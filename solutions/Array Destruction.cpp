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

vi tab;
vii track;

inline bool fx2(int k){
    multiset<int>nums;
    for(auto &i: tab) nums.insert(i);
    
    while(true){
        if(nums.size() == 0) return true;
        
        auto bIter = (nums.end());
        bIter--;
        int b = *bIter;
        nums.erase(bIter);
        
        int a = k - b;
        
        if(max(a, b) > k) return false;
        
        auto aIter = nums.find(a);
        
        if(aIter == nums.end()){
            return false;
        }
        
        nums.erase(aIter);
        
        track.pb({a, b});
        
        k = max(a, b);
    }
}

void fx() {
    // Functionality for fx
    int n;
    cin >> n;
    
    n *= 2;
    
    tab.clear();
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        tab.pb(t);
    }
    
    sort(all(tab));
    
    for(int i = 0; i < n-1; i++){
        int x = tab[i] + tab[n-1];
        
        track.clear();
        if(fx2(x)){
            yes();
            cout << x << endl;
            for(auto &item: track) cout << item.f << " " << item.s << endl;
            return;
        } 
    }
    
    no();
    
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
