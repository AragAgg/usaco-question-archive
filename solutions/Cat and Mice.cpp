#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
int n;
vector<vector<float>>dist; vector<float>dur, speed;
vector<pii>m;
float mul, eps = 0.0001;

bool isFeasible(float s){
    vector<vector<float>>dp((1 << n), vector<float>(n, FLT_MAX));
    //the base cases goes here
    for(int i = 0; i < n; i++) if(dist[n][i]/s <= dur[i] - eps) dp[(1 << i)][i] = dist[n][i]/s;
    for(int i = 0; i < n; i++) speed[i] = s, s *= mul;

    for(int mask = 0; mask < (1 << n); mask++){
        for(int pos = 0; pos < n; pos++){
            for(int bit = 0; bit < n; bit++){
                if((mask & (1<<pos)) == 0 or dp[mask][pos] == FLT_MAX or (mask & (1<<bit))) continue;
                float tOfArrival = dp[mask][pos] + dist[pos][bit]/speed[__builtin_popcount(mask)];
                if(tOfArrival <= dur[bit] - eps) dp[mask|(1<<bit)][bit] = min(dp[mask|(1<<bit)][bit], tOfArrival);
            }
        }
    }

    for(int i = 0; i < n; i++) if(dp[(1 << n) - 1][i] <= dur[i] - eps) return true;
    return false;
}

void fx() {
    // Functionality for fx
    cin >> n;
    dist.assign(n+1, vector<float>(n, 0));
    dur.assign(n, 0);
    m.assign(n+1, {0, 0});
    speed.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> m[i].f >> m[i].s >> dur[i];
    cin >> mul;
    m[n] = {0, 0};

    for(int i = 0; i <= n; i++) for(int j = 0; j < n; j++) dist[i][j] = sqrt((m[i].f - m[j].f)*(m[i].f - m[j].f) + (m[i].s - m[j].s)*(m[i].s - m[j].s));
    
    float lo = 0, hi = 200000000;
    int cnt = 40;
    
    while(hi - lo >= eps and hi > lo){
        float mid = (lo + hi)/2;
        if(isFeasible(mid)) hi = mid;
        else lo = mid;

        cnt--;
    }

    cout << setprecision(8) << hi << endl;
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
