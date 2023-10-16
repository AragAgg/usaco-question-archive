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

int k;
int n = 3000;
vvi tab(3000, vi(3000, 0));
vvi visited(3000, vi(3000, 0));
set<pii>addedCows;

bool isComfy(int i, int j){
    int neighs = 0;
    
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        
        if(tab[x][y]) neighs++;
    }
    
    return (neighs == 3);
}

void fixIt(int &i, int &j){
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        
        if(!tab[x][y]){
            i = x;
            j = y;
            
            tab[x][y] = 1;
            addedCows.insert({x, y});
            return;
        }
    }
}

void fixAllViolated(int i, int j){
    
    if(isComfy(i, j)){
        int x = i, y = j;
        fixIt(x, y);
        
        fixAllViolated(x, y);
    }
    
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        
        if(tab[x][y] and isComfy(x, y)){
            fixIt(x, y);
            fixAllViolated(x, y);
        }
    }
}

void fx() {
    cin >> k;
    
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        
        a += 1000; b += 1000;
        tab[a][b] = 1;
        
        if(addedCows.count({a, b})) addedCows.erase({a, b});
        
        fixAllViolated(a, b);
        cout << addedCows.size() << endl;
    }
    
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
