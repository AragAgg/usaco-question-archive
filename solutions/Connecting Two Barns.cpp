#include <bits/stdc++.h>
    
    using namespace std;
    
    // Type definitions for convenience
    
    #define ll long long
    typedef vector<ll> vi;
    typedef vector<bool> vb;
    typedef pair<ll, ll> pii;
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
    
    ll n, m;
    vi comp;
    vvi comps;
    vvi tab;
    
    void dfs(ll x, ll cnt){
        if(comp[x] != -1) return;
        
        comp[x] = cnt;
        
        for(auto &i: tab[x]) dfs(i, cnt);
    }
    
    ll cost(ll a, ll b){
        
        ll ans = 1e5;
        
        for(auto node : comps[a]){
            auto iter = lower_bound(comps[b].begin(), comps[b].end(), node);
            
            if(iter != comps[b].end()) ans = min(ans, abs(*iter - node));
            
            if(iter != comps[b].begin()) ans = min(ans, abs(*prev(iter) - node));
        }
    
        return (ll)ans*ans;
    }
    
    void fx() {
        cin >> n >> m;
        comp.clear();
        comps.clear();
        tab.clear();
        comp.assign(n, -1);
        tab.assign(n, {});
        
        for(int i = 0; i < m; i++){
            ll a, b;
            cin >> a >> b;
            
            tab[--a].pb(--b);
            tab[b].pb(a);
        }
        
        int cnt = -1;
        
        for(int i = 0; i < n; i++){
            if(comp[i] != -1) continue;
            
            dfs(i, ++cnt);
        }
        
        comps.assign(cnt+1, {});
        
        for(int i = 0; i < n; i++) comps[comp[i]].pb(i);
        
        ll ans = cost(comp[0], comp[n-1]);
        
        for(int i = 0; i < comps.size(); i++) ans = min(ans, cost(comp[0], i) + cost(i, comp[n-1]));
        
        cout << ans << endl;
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
