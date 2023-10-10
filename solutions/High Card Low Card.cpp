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
    
    set<int>s;
    for(int i = 1; i <= 2*n; i++) s.insert(i);
    
    vi tab(n);
    for(auto &i: tab){
        cin >> i;
        s.erase(i);
    }
    
    int score = 0;
    
    //second half...
    priority_queue<int, vi, greater<int>>a;
    for(int i = n/2; i < n; i++) a.push(tab[i]);
    
    priority_queue<int, vi, greater<int>>b;
    for(auto &i: s) b.push(i);
    
    while(!a.empty()){
        if(b.top() < a.top()){
            score++;
            s.erase(b.top());
            b.pop();
        }
        
        a.pop();
    }
    
    //first half...
    priority_queue<int>c;
    for(int i = 0; i < n/2; i++) c.push(tab[i]);
    
    priority_queue<int>d;
    for(auto &i: s) d.push(i);
    
    while(!c.empty()){
        if(d.top() > c.top()){
            score++;
            d.pop();
        }
        
        c.pop();
    }
    
    cout << score << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("cardgame"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
