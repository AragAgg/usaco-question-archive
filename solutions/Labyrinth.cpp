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

void fx() {
    // Functionality for fx
    int n, m;
    cin >> n >> m;

    pii start = {0, 0}, end = {0, 0};

    vector<string>tab;
    for(int i = 0; i < n; i++){
        tab.pb("");
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;

            tab[i].pb(ch);
            if(ch == 'A') start = {i, j};
            if(ch == 'B') end = {i, j};
        }
    }

    queue<pii>q;
    q.push(start);
    vvi visited(n, vi(m, 0));
    vector<vector<pii>> parent(n, vii(m, {-1, -1}));
    visited[start.f][start.s] = 1;
    bool found = false;

    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        
        if(tab[curr.f][curr.s] == 'B'){
            found = true;
            break;
        }

        for(int i = 0; i < 4; i++){
            pii next = {curr.f + dx[i], curr.s + dy[i]};
            if(next.f >= 0 and next.f <= n-1 and next.s >= 0 and next.s <= m-1 and tab[next.f][next.s] != '#' and !visited[next.f][next.s]){
                visited[next.f][next.s] = 1;
                parent[next.f][next.s] = curr;
                q.push(next);
            }
        }
    }

    if(found){
        yes();

        vii loc;
        while(end.f != -1 and end.s != -1){
            loc.pb(end);
            end = parent[end.f][end.s];
        }

        cout << (loc.size()-1) << endl;
        reverse(all(loc));
        for(int i = 1; i < loc.size(); i++){
            for(int j = 0; j < 4; j++){
                if(loc[i-1].f + dx[j] == loc[i].f and loc[i-1].s + dy[j] == loc[i].s){
                    if(j == 0) cout << "R";
                    else if(j == 1) cout << "D";
                    else if(j == 2) cout << "L";
                    else cout << "U";
                }
            }
        }
        
    }
    else no();
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
