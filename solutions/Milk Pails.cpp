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

int x, y, k, m;
vvi visited;

bool isValid(int i, int j){
    return (i >= 0 and i <= 100 and j >= 0 and j <= 100);
}

void fx() {
    cin >> x >> y >> k >> m;
    
    visited.assign(101, vi(101, INT_MAX));
    queue<pair<int, pii>>q;
    q.push({0, {0, 0}});
    
    int ans = INT_MAX;
    
    while(!q.empty()){
        int i = q.front().s.f;
        int j = q.front().s.s;
        int currDepth = q.front().f;
        
        q.pop();
        
        if(!isValid(i, j) or (visited[i][j] <= currDepth) or (currDepth > k)) continue;
        
        visited[i][j] = currDepth;
        
        ans = min(ans, abs(i+j - m));
        
        q.push({currDepth+1, {i - min(i, y - j), j + min(i, y - j)}});
        q.push({currDepth+1, {i + min(j, x - i), j - min(j, x - i)}});
        q.push({currDepth+1, {0, j}});
        q.push({currDepth+1, {i, 0}});
        q.push({currDepth+1, {i, y}});
        q.push({currDepth+1, {x, j}});
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("pails"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
