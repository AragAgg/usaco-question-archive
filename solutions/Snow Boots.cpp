#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

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

// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

int n, k;
vi tab;
vii boots;

void fx() {
    cin >> n >> k;
    tab.assign(n, 0);
    
    for(auto &i: tab) cin >> i;
    boots.assign(k, {0, 0});
    
    for(auto &i: boots) cin >> i.f >> i.s;
    queue<pii>q;
    q.push({0, 0});
    
    int ans = k-1;
    vi visited(n, 0);
    set<pii>s;
    
    while(!q.empty()){
        if(ans == 0) break;
        
        pii curr = q.front();
        q.pop();
        visited[curr.f] = true;
        
        if(curr.f == n-1) ans = min(ans, curr.s);
        for(int step = 1; step <= min(boots[curr.s].s, n - curr.f -1); step++){
            if(tab[curr.f + step] <= boots[curr.s].f){
                if(s.count({curr.f+step, curr.s})) continue; 
                q.push({curr.f+step, curr.s}); 
                s.insert({curr.f+step, curr.s});
            }
        }
        
        if(!q.size() and curr.s < k-1){
            for(int i = 0; i < n; i++){
                if(!visited[i]) continue;
                if(tab[i] <= boots[curr.s+1].f){ 
                    if(s.count({i, curr.s+1})) continue; 
                    q.push({i, curr.s+1}); 
                    s.insert({i, curr.s+1});
                }
            }
        }
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("snowboots"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
