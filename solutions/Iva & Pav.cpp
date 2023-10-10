#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long

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

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }


class SegmentTree {
public:
    int n;
    vi tree;
    
    SegmentTree(const vi& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    int q(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }


    void build(const vi& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, node * 2, start, mid);
            build(data, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] & tree[node * 2 + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return -1;
        }
        if (l <= start && r >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(node * 2, start, mid, l, r);
        int p2 = query(node * 2 + 1, mid + 1, end, l, r);
        return p1 & p2;
    }
};




void fx() {
    int n;
    cin >> n;
    
    vi tab(n);
    for(auto &i: tab) cin >> i;
    
    SegmentTree segTree(tab);
    
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        l--;
        
        int lo = l-1;
        int hi = n-1;
        
        while(lo < hi){
            int mid = lo + (hi - lo+1)/2;
            
            if(segTree.q(l, mid) >= k) lo = mid;
            else hi = mid -1;
        }
        
        if(segTree.q(l, lo) >= k) cout << (lo+1) << " ";
        else cout << -1 << " ";
        
    }
    
    cout << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
