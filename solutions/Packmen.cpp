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

int N;
string s;
vi food, packmen;

bool isVaible(ll tme){
    set<int>f;
    for(auto &i: food) f.insert(i);
    
    int p = 0;
    auto fIter = f.begin();
    
    while(fIter != f.end() and p < packmen.size()){
        auto foodIter = fIter;
        if(packmen[p] - *foodIter > tme) return false;
        
        if(*foodIter <= packmen[p]){
            auto c1 = f.upper_bound(packmen[p] + max(0LL, tme - 2*(packmen[p] - *foodIter)));
            auto c2 = f.upper_bound(packmen[p] + max(0LL, (tme - (packmen[p] - *foodIter))/2));
            foodIter = c1;
            if(foodIter != f.end() and (c2 == f.end() or *foodIter < *c2)) foodIter = c2;
            
        }else foodIter = f.upper_bound(packmen[p] + tme);
        
        fIter = foodIter;
        p++;
    }
    
    return (fIter == f.end());
}

void fx() {
    cin >> N >> s;
    for(int i =  0; i < N; i++){
        if(s[i] == '*') food.pb(i);
        else if(s[i] == 'P') packmen.pb(i);
    }
    
    ll lo = 0;
    ll hi = 1e6+100;
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        
        if(isVaible(mid)) hi = mid;
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
