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
    string s;
    cin >> s;
    
    int n = s.size();
    
    if(n == 2 and s == "()"){
        no();
        return;
    }
    
    yes();
    
    bool alt = true;
    
    bool f = (s[0] == '(')?true:false;
    
    for(int i = 1; i < n; i++){
        if((s[i] == '(' and f) or (s[i] == ')' and !f)){
            alt = false;
            break;
        }
        
        f = !f;
    }
    
    string res = "";
    
    if(alt){
        for(int i = 0; i < n; i++) res += '(';
        for(int i = 0; i < n; i++) res += ')';
    }else{
        for(int i = 0; i < n; i++) res += "()";
    }
    
    cout << res << endl;
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
