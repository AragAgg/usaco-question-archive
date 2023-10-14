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

int n, m;

vector<vector<vector<pii>>>tab;

bool isValid(int i, int j){
    return (i >= 0 and i < n and j >= 0 and j < n);
}

void fx() {
    cin >> n >> m;
    
    tab.assign(n, vector<vii>(n));
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        tab[--a][--b].pb({--c, --d});
    }
    
    queue<pii>q;
    q.push({0, 0});
    
    vvi visited(n, vi(n, 0));
    
    //states in visited:
    //0: unvisited
    //1: accessible but not Lit
    //2: is Lit but not accessible
    //3: visited or currently in queue
    
    int ans = 1;
    
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        
        if(visited[curr.f][curr.s] == 4) continue;
        visited[curr.f][curr.s] = 4;
        
        for(auto item: tab[curr.f][curr.s]){
            
            if(visited[item.f][item.s] == 0){
                
                ans++;
                visited[item.f][item.s] = 2;
                
            }else if(visited[item.f][item.s] == 1){
                
                ans++;
                visited[item.f][item.s] = 3;
                q.push({item.f, item.s});
            }
        }
        
        for(int d = 0; d < 4; d++){
            int x = curr.f + dx[d];
            int y = curr.s + dy[d];
            
            if(!isValid(x, y)) continue;
            
            if(visited[x][y] == 0) visited[x][y] = 1;
            else if(visited[x][y] == 2){
                visited[x][y] = 3;
                q.push({x, y});
            }
        }
        
    }
    
    cout << ans << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("lightson"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
