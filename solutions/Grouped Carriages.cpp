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

vector<pair<pii, int>>tab;

bool isViable(ll x){
    priority_queue<pii, vector<pii>, greater<pii>>q;
    
    int counter = 0;
    int tme = 0;
    
    while(tme < N and ((counter < N) or (q.size()))){
        while(counter < N and tab[counter].first.first <= tme){
            if(tab[counter].second) q.push({tab[counter].first.second, tab[counter].second});
            counter++;
        }
        
        if(q.size() and q.top().f < tme) return false;
        ll take = 0;
        
        while(q.size() and (x - take)){
            pii curr = q.top();
            q.pop();
            
            ll temp = min((ll)curr.s, (x - take));
            curr.s -= temp;
            take += temp;
            
            if(curr.s > 0) q.push(curr);
        }
        
        tme++;
    }
    
    return (q.size() == 0);
}

void fx() {
    cin >> N;
    
    vector<ll> a(N, 0), d(N, 0);
    
    for(auto &i: a) cin >> i;
    for(auto &i: d) cin >> i;
    
    for(int i = 0; i < N; i++) tab.pb({{max(0LL, i - d[i]), min(N-1LL, i + d[i])}, a[i]});
    
    sort(all(tab));
    
    ll lo = 0;
    ll hi = 1e9+100; 
    
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(isViable(mid)){ hi = mid;}
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
