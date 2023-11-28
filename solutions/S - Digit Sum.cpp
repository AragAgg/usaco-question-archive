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

string s;
int d;
const ll mod = 1e9+7;
void fx() {
    // Functionality for fx

    cin >> s >> d;
    
    if(d == 1){
        int index = max((int)s.size() - 18, 0);
        string num = s.substr(index, min((int)s.size(), (int)s.size() - index + 1));
        cout << (stoll(num) % mod) << endl;
        return;
    }
    
    ll dp[(int)s.size() +10][d+10][2];
    for(int i = 0; i < (int)s.size() + 10; i++) for(int j = 0; j < d + 10; j++) dp[i][j][0] = 0, dp[i][j][1] = 0;

    for(int i = 0; i < min(10, d); i++){
        if(i == (int)(s[0] - '0')){
            dp[1][i][1] = 1;
            break;
        }

        dp[1][i][0] = 1;
    }
    
    for(int i = 1; i < (int)s.size(); i++){
        
        for(int j = 0; j < d; j++){
            bool isTight = (dp[i][j][1]);
            for(int delta = 0; delta < 10; delta++){
                int xi = j + delta;
                while(xi >= d) xi -= d;
                if(isTight and delta <= (int)((s[i] - '0'))) dp[i+1][xi][(delta == (int)((s[i] - '0')))] = (dp[i+1][xi][delta == (int)((s[i] - '0'))] + dp[i][j][1]) %mod;

                dp[i+1][xi][0] = (dp[i+1][xi][0] + dp[i][j][0]) %mod;
                
            }
        }
    }


    cout << (((dp[(int)s.size()][0][0] -1) %mod + mod))%mod << endl;

    
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
