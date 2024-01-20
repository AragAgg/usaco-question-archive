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
    cin >> n;

    vi tab(n, 0);
    vi a(n, 0);
    vi b(n, 0);
    for(int i = 0; i < n; i++){

        cin >> tab[i];
    }

    for(int i = 1 ; i < n; i++){
        a[i] += a[i-1];
        if(i >= 2 and abs(tab[i] - tab[i-1]) < abs(tab[i-1] - tab[i-2])) a[i] += 1;
        else if(i == 1) a[i] += 1;
        else a[i] += abs(tab[i] - tab[i-1]);
    }

    for(int i = n-2; i >= 0; i--){
        b[i] += b[i+1];
        if(i <= n-3 and abs(tab[i] - tab[i+1]) < abs(tab[i+1] - tab[i+2])) b[i] += 1;
        else if( i == n-2) b[i] += 1;
        else b[i] += abs(tab[i] - tab[i+1]);
    }

    cin >> m;

    while(m--){
        int x, y;
        cin >> x >> y;
        x--; y--;

        if(x < y){
            //case 1
            cout << ( a[y] - a[x]) << endl;
        }else{
            cout << (b[y] - b[x]) << endl;
        }
    }
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
     int t; cin >> t;
     while(t--) fx();
    
    // Single test case
    return 0;
}
