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

int N, K;
vi tab;
queue<int>q;
vi hands;

ll ans = 0;

void fx2(int x){
    cout << "Called fx2(" << x << ")\n";
    if(K == 0) return;
    
    while(q.size() and K){
        int hi = min(K, (int)hands.size())-1;
        int lo = 0;
        while(lo < hi){
            int mid = lo + (hi - lo +1)/2;
            
            if(q.front() > )
        }
        
        if(q.front() <= x + hands[take] - (take == 0)?0:hands[take-1]) break;
        
        ans += q.front();
        q.pop();
        K--;
    }
    
    if(K == 0) return;
    
    int tk = min(K, (int)hands.size());
    
    ans += x*(tk) + hands[tk-1];
    K -= tk;
    q.push(2*x);
    hands.pb(hands.back()+x);
    hands.pb(hands.back()+x);
}

void fx() {
    // Functionality for fx
    cin >> N >> K;
    tab.assign(N, 0);
    for(auto &i: tab) cin >> i;
    
    sort(tab.rbegin(), tab.rend());
    
    hands.pb(tab.front());
    hands.pb(tab.front()*2);
    q.push(tab.front()*2);
    
    for(int i = 1; i < N; i++){ fx2(tab[i]); cout << "Ans : " << ans << endl;}
    
    while(q.size() and K){
        ans += q.front();
        q.pop();
        K--;
    }
    
    cout << ans << endl;
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
