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
    ll aSum = 0, bSum = 0;
    med(int _k){ k = _k; }
    void insert(int _num){
        a.insert(_num);
        aSum += _num;
        normalize();
    }
    void erase(int _num){
        if(a.count(_num)) a.erase(a.find(_num)), aSum -= _num;
        else b.erase(b.find(_num)), bSum -= _num;

        normalize();
    }   
    
    void normalize(){
        if(a.size() - b.size() == 2){
            b.insert(*a.rbegin());
            bSum += *a.rbegin();
            aSum -= *a.rbegin();
            a.erase(--a.end());
        }

        if(b.size() - a.size() == 1){
            a.insert(*b.begin());
            aSum += *b.begin();
            bSum -= *b.begin();
            b.erase(b.begin());
        }

        while((a.size() and b.size()) and *a.rbegin() > *b.begin()){
            int elem_a = *a.rbegin(), elem_b = *b.begin();

            aSum = aSum - elem_a + elem_b;
            bSum = bSum + elem_a - elem_b;
            a.erase(--a.end());
            a.insert(elem_b);
            b.erase(*b.begin());
            b.insert(elem_a);
        }

    }

    int median(){
        return *a.rbegin();
    }
    
};

void fx() {
    // Functionality for fx
    int n, k;
    cin >> n >> k;
    vi tab(n);
    med str(k);

    for(int i = 0; i < k-1; i++){
        cin >> tab[i];
        str.insert(tab[i]);
    }

    for(int i = k-1; i < n; i++){
        cin >> tab[i];
        str.insert(tab[i]);
        if(i >= k) str.erase(tab[i-k]);
        ll median = str.median();
        cout << (median*str.a.size() - str.aSum + str.bSum - median*str.b.size()) << " ";
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
