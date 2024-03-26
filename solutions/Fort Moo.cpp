//#pragma GCC optimize("03,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define p push
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long
//#define int ll
#define endl "\n"
#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

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


void fx() {
    // Functionality for fx
    int n, m;
    int res = 0;
    cin >> n >> m;

    vvi tab(n, vi(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;

            if (ch == '.') tab[i][j]++;
        }
    }

    for(int i  = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i > 0) tab[i][j] += tab[i-1][j];
            if(j > 0) tab[i][j] += tab[i][j-1];
            if(i > 0 and j > 0) tab[i][j] -= tab[i-1][j-1];
        }
    }

    auto isFreeSpace = [&](int fr, int fc, int tr, int tc){
        int rect = tab[tr][tc];
        if(fr > 0) rect -= tab[fr-1][tc];
        if(fc > 0) rect -= tab[tr][fc-1];
        if(fr > 0 and fc > 0) rect += tab[fr-1][fc-1];

        return (rect == ((tr - fr + 1)*(tc - fc + 1)));
    };

    //vvi top(m, vi(m, INT_MAX)), bottom(m, vi(m, INT_MIN));

    for(int start = 0; start < m; start++){
        for(int end = start+1; end < m; end++){
            int top = 0, bottom = 0;

            for(int i = 0; i < n; i++){
                bottom = i;
                if(!isFreeSpace(bottom, start, bottom, end) or top == bottom) continue;

                if(isFreeSpace(top, start, top, end) and isFreeSpace(top, start, bottom, start) and isFreeSpace(top, end, bottom, end)) res = max(res, (bottom-top+1)*(end-start+1));
                else top = bottom;
            }

            /*

            for(int i = 0; i < n; i++){
                top[start][end] = min(top[start][end], (isFreeSpace(i, start, i, end)?i:INT_MAX));
                bottom[start][end] = max(bottom[start][end], (isFreeSpace(i, start, i, end)?i:INT_MIN));
            }

            */
        }
    }



    /*
    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            if(top[i][j] == INT_MAX or bottom[i][j] == INT_MIN) continue;
            if(isFreeSpace(top[i][j], i, bottom[i][j], i) and isFreeSpace(top[i][j], j, bottom[i][j], j)) res = max(res, (bottom[i][j] - top[i][j] +1)*(j-i+1));
        }
    }

    */
    cout << res << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    iofile(string("fortmoo"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
