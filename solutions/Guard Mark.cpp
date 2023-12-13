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
typedef pair<ll, ll> pii;
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

#define HEI f.s
#define WEI s.f
#define STR s.s

void fx() {
    // Functionality for fx
    int n, h;
    cin >> n >> h;

    vector<pair<pii, pii>> tab(n);
    for(int i = 0; i < n; i++){
        cin >> tab[i].HEI >> tab[i].WEI >> tab[i].STR;
        tab[i].f.f = -(tab[i].WEI + tab[i].STR);
    }

    sort(all(tab));

    unordered_map<ll, ll>dp;
    dp.insert({INT_MAX, 0});

    for(auto cow : tab){
        auto key = cow.f.f, hei = cow.HEI, wei = cow.WEI, str = cow.STR;
        unordered_map<ll, ll>temp;
        for(auto &[saf, thei]: dp){
            temp[saf] = max(temp[saf], thei);
            if(saf >= wei) temp[min(saf - wei, str)] = max(temp[min(saf-wei, str)], temp[saf] + hei);
        }

        swap(temp, dp);
    }

    ll maxSaf = INT_MIN;
    for(auto &[saf, thei]: dp) if(thei >= h) maxSaf = max(maxSaf, saf);

    if(maxSaf == INT_MIN){
        cout << "Mark is too tall" << endl;
    }else{
        cout << maxSaf << endl;
    }
}

int main(){
    // Uncomment the following lines for file I/O
    iofile(string("guard"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
