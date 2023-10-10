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



void fx(){
    int n, m;
    cin >> n >> m;
    
    multiset<int>att, att2;
    multiset<int>def, def2;
    
    for(int i = 0; i < n; i++){
        string type;
        int power;
        cin >> type >> power;
        
        ((type == "ATK")?att:def).insert(power);
        ((type == "ATK")?att2:def2).insert(power);
    }
    
    multiset<int>fox, fox2;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        
        fox.insert(t);
        fox2.insert(t);
    }
    
    //deal partial cards
    
    int damage = 0;
    
    while(fox.size() and att.size()){
        if(*att.begin() > *fox.rbegin()) break;
        
        damage += *fox.rbegin() - *att.begin();
        fox.erase(prev(fox.end()));
        att.erase(att.begin());
        
    }
    
    //deal all cards
    
    int damage2 = 0;
    
    while(def2.size()){
        int i = *def2.begin();
        auto iter = fox2.upper_bound(i);
        if(iter == fox2.end()) break;
        def2.erase(def2.begin());
        fox2.erase(iter);
    }
    
    while(att2.size()){
        auto iter = fox2.lower_bound(*att2.begin());
        if(iter == fox2.end()) break;
        damage2 +=  *iter - *att2.begin();
        att2.erase(att2.begin());
        fox2.erase(iter);
    }
    
    if(!att2.size() and !def2.size()) for(auto &i: fox2) damage2 += i;
    
    
    cout << max(damage2, damage) << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("berries"));

    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
