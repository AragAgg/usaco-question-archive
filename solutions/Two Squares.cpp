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

bool pointIn(pii p, pii a, pii b){ return (p.f >= min(a.f, b.f) and p.f <= max(a.f, b.f) and p.s >= min(a.s, b.s) and p.s <= max(a.s, b.s));}
void transform(vii &a){
    for(auto &i: a){
        int t = i.f;
        i.f += i.s;
        i.s = t - i.s;
    }
}

void fx() {
    // Functionality for fx
    vii a(4), b(4);
    for(auto &i: a) cin >> i.f >> i.s;
    for(auto &i: b) cin >> i.f >> i.s;
    
    for(auto &p: b){
        if(pointIn(p, a[0], a[2])){
            yes();
            return;
        }
    }
    if(pointIn({(b[0].f + b[2].f)/d2, (b[0].s + b[2].s)/2}, a[0], a[2])){ yes(); return; };
    transform(a);
    transform(b);
    if(pointIn({(a[0].f + a[2].f)/2, (a[0].s + a[2].s)/2}, b[0], b[2])){ yes(); return;};
    for(auto &p: a){
        if(pointIn(p, b[0], b[2])){
            yes();
            return;
        }
    }
    
    no();
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
