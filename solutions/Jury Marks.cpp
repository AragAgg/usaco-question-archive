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

void fx() {
    int k, n;
    cin >> k >> n;
    
    vi deltaScores(k);
    usi offsets;
    
    for(int i = 0; i < k; i++){
        cin >> deltaScores[i];
        deltaScores[i] += deltaScores[i-1];
        offsets.insert(deltaScores[i]);
    }
    
    usi juryScores;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        juryScores.insert(temp);
    }
    
    usi confirmedSus;
    
    usi suspects;
    for(auto &i : juryScores){
        for(auto &j : offsets){
            int temp = i - j;
            
            if(!suspects.count(temp)){
                //check for temp
                bool flag = true;
                for(auto &item: juryScores){
                    if(!offsets.count(item-temp)){
                        flag = false;
                        break;
                    }
                }
                
                if(flag){
                    confirmedSus.insert(temp);
                }
                
                suspects.insert(temp);
            }
        }
    }
    
    cout << confirmedSus.size() << endl;
    
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
