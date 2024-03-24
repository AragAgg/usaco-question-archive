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

struct med{
    int k;
    multiset<int>a, b;
    med(int _k){ k = _k; }
    void insert(int num){
        a.insert(num);
        normalize();
    }

    void remove(int num){
        if(a.count(num)) a.erase(a.find(num)), normalize();
        else b.erase(b.find(num)), normalize();
    }

    void normalize(){
        if(a.size() - b.size() == 2){
            b.insert(*a.rbegin());
            a.erase(--a.end());
        }

        if(b.size() - a.size() == 1){
            a.insert(*b.begin());
            b.erase(b.begin());
        }

        while((a.size() and b.size()) and *a.rbegin() > *b.begin()){
            int elem = *a.rbegin();
            a.erase(--a.end());
            a.insert(*b.begin());
            b.erase(b.begin());
            b.insert(elem);
        }
    }

    int median(){
        return *a.rbegin();
    }

    void dump(){
        cout << "dumping a... " << endl;
        for(auto item: a){
            cout << item << " ";
        }

        cout << endl;

        cout << "dumping b... " << endl;
        for(auto item: b){
            cout << item << " ";
        }

        cout << endl;
    }
};

void fx() {
    // Functionality for fx
    int n, k;
    cin >> n >> k;

    vi tab(n);
    med str(k);

    for(int i = 0; i < k - 1; i++){
        cin >> tab[i];
        str.insert(tab[i]);
    }

    for(int i = k-1; i < n; i++){
        cin >> tab[i];
        if(i - k >= 0) str.remove(tab[i-k]);
        str.insert(tab[i]);
        cout << str.median() << " ";

        //debug(i);
        //str.dump();
        //cout << endl << endl;
    }


    cout << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
