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

int n, m;
set<int>excluded[200000];
set<int>notYetIncluded;
vb visited;

int curr;

void dfs(int i){
    if(visited[i]) return;
    
    notYetIncluded.erase(i);
    visited[i] = true;
    
    curr++;
    
    // vi temp;
    // for(auto x: notYetIncluded) temp.pb(x);
    
    // for(auto x: temp){
    //     if(excluded[i].count(x)) continue;
        
    //     dfs(x);
    // }
    
    auto iter = notYetIncluded.begin();
    
    while(iter != notYetIncluded.end()){
        if(excluded[i].count(*iter)) iter++;
        else{
            int thisNode = *iter;
            
            notYetIncluded.erase(iter);
            
            dfs(thisNode);
            
            iter = notYetIncluded.upper_bound(thisNode);
        }
    }
}

void fx() {
    // Functionality for fx
    cin >> n >> m;
    
    // excluded.assign(n, {}); // <- does that work???
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        excluded[a].insert(b);
        excluded[b].insert(a);
    }
    
    visited.assign(n, false);
    for(int i = 0; i < n; i++) notYetIncluded.insert(i);
    
    vi ans;
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        
        curr = 0;
        dfs(i);
        ans.pb(curr);
        
    }
    
    sort(all(ans));
    cout << ans.size() << endl;
    for(auto &i: ans) cout << i << " ";
    cout << endl;
    
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
