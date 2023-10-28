#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define endl "\n"

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

// cin.tie(0)->sync_with_stdio(0);

#define MAXN 1e6+2

int ans = 1;

int phi[1000002], freq[1000002] = {0};
int visited[1000002] = {0};

inline void allDivisors(vii &factors, int curr, int index){
    if(index == factors.size()-1) for(int i = factors[index].s; i >= 0; i--){
        if(++freq[static_cast<int>(curr*pow(factors[index].f, i))] >= 2){
            visited[static_cast<int>(curr*pow(factors[index].f, i))] += 1;
            ans = max(ans, static_cast<int>(curr*pow(factors[index].f, i)));
        }
    } 
    else for(int i = factors[index].s; i >= 0; i--) allDivisors(factors, curr*pow(factors[index].f, i), index+1);
}

void fx() {
    // Functionality for fx
    
    for(int i = 0; i < MAXN; i++) phi[i] = i;
    for(int i = 2; i < MAXN; i++) if(phi[i] == i) for(int j = i; j < MAXN; j += i) phi[j] = i; 
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int curr;
        cin >> curr;
        
        if(visited[curr] > 1) continue;
        visited[curr] += 1;
        
        vii factors = {};
        
        while(curr > 1){
            int prime = phi[curr];
            int cnt = 0;
            
            while(curr%prime == 0){
                curr /= prime;
                cnt++;
            }
            
            factors.pb({prime, cnt});
        }
        
        if(factors.size()) allDivisors(factors, 1, 0);
        
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
    cin.tie(0)->sync_with_stdio(0);
    fx();
    
    return 0;
}
