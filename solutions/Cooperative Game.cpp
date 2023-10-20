#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define ll long long

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

int num;
vector<string> tab;

void isDone(){
    string s;
    cin >> s;
    if(s == "stop"){
        exit(0);
    }else num = stoi(s);
    
    tab.assign(num, "");
    for(auto &i: tab){
        cin >> s;
        i = s;
    }
}


void fx() {
    cout << "next 1 2 3 4 5 6 7 8 9" << endl;
    isDone();
    cout << "next 2 3 4 5 6 7 8 9" << endl; 
    isDone();
    
    while(tab.size() != 2){
        cout << "next 1 2 3 4 5 6 7 8 9" << endl;
        isDone();
        cout << "next 2 3 4 5 6 7 8 9" << endl;
        isDone();
    }
    
    while(tab.size() != 1){
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        isDone();
    }
    
    cout << "done" << endl;
    
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
