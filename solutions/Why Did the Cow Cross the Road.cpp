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
    int c, n;
    cin >> c >> n;
    
    multiset<int>chickens;
    while(c--){
        int t;
        cin >> t;
        
        chickens.insert(t);
    }
    
    int score = 0;
    
    priority_queue<pii, vii, greater<pii>>cows;
    
    while(n--){
        int a, b;
        cin >> b >> a;
        
        cows.push({a, b});
    }
    
    while(!cows.empty()){
        auto iter = chickens.lower_bound(cows.top().s);
        if(iter == chickens.end() or *iter > cows.top().f){
            cows.pop();
            continue;
        }
        
        cows.pop();
        chickens.erase(iter);
        score++;
    }
    
    cout << score << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("helpcross"));

    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
