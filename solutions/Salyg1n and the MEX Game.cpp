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
void yes() { printf("YES\n"); }
void no() { printf("NO\n"); }

int mex(set<int> &mp){
    int counter = 0;
    
    while(true){
        if(!mp.count(counter)) return counter;
        counter++;
    }
    
    return -1;
}

void fx(){
    int n;
    scanf("%d", &n);
    
    set<int> tab;
    for(int i = 0; i < n; i++){ 
        int t; 
        scanf("%d", &t); 
        tab.insert(t);
    }
    
    int temp;
    temp = mex(tab);
    printf("%d\n", temp);
    fflush(stdout);
    tab.insert(temp);
    
    while(true){
        int res;
        scanf("%d", &res);
        
        if(res == -1) return;
        else if (res == -2) exit(0);
        else{
            tab.erase(res);
            
            int t;
            t = mex(tab);
            printf("%d\n", t);
            fflush(stdout);
            tab.insert(t);
        }
    }
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("convention2"));
    
    // Uncomment the following lines for multiple test cases
    int t; scanf("%d", &t);
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
