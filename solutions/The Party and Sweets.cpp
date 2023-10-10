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
    int n, m;
    cin >> n >> m;
    
    long long ans = 0;
    
    priority_queue<pii>pq;
    long long boysMax = 0;
    
    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        ans += (t*m);
        pq.push({t, m-1});
        boysMax = max(boysMax, t);
    }
    
    bool violated = false;
    
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        
        if(t < boysMax or (t < boysMax and !pq.size())){ violated = true; continue;}
        else if(t == boysMax) continue;
        
        pii curr = pq.top();
        pq.pop();
        
        ans += (t - curr.f);
        curr.s--;
        
        if(curr.s) pq.push(curr);
        
    }
    
    if(violated) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("cardgame"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
