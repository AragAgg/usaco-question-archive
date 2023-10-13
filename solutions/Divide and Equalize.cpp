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

map<int, ll>facts;

void primeFactors(int n) 
{ 
    while ((n % 2 == 0) and (n > 0)) 
    { 
        facts[2]++;
        n = n/2; 
    } 
    
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while ((n % i == 0)) 
        { 
            facts[i]++;
            n = n/i; 
        } 
    } 
 
    if(n > 1)facts[n]++;
} 


void fx() {
    facts.clear();
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        
        primeFactors(t);
    }
    
    for(auto &i: facts){
        if(i.s%n != 0){
            no();
            return;
        }
    }
    
    yes();
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
