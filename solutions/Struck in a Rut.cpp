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
    
    
    struct cow{
        int x, y, blame = 0;
        bool stopped = false;
        int whoStopped = -1;
        bool dirNorth = false;
        int id = -1;
    };
    
    struct collision{
        int a, b;
        long long t = 0;
    };
    
    void fx(){
        int n;
        cin >> n;
        
        vector<cow>cows;
        vector<collision>collisions;
        
        for(int i = 0; i < n; i++){
            char ch; cin >> ch;
            cow c;
            
            cin >> c.x >> c.y;
            c.dirNorth = (ch == 'N');
            c.id = i;
            cows.pb(c);
        }
        
        sort(all(cows), [](cow&a, cow&b){return a.x < b.x;});
        
        for(int i = 0; i < n-1; i++){
            cow &a = cows[i];
            
            for(int j = i+1; j < n; j++){
                cow &b = cows[j];
                if(a.y < b.y or a.dirNorth or !b.dirNorth or (b.x - a.x == a.y - b.y)) continue;
                
                collision x;
                x.a = i;
                x.b = j;
                
                x.t = max((b.x - a.x), (a.y - b.y));
                
                collisions.pb(x);
            }
        }
        
        sort(all(collisions), [](collision &x, collision&y){return x.t < y.t;});
        
        for(auto const &collision: collisions){
            cow &a = cows[collision.a];
            cow &b = cows[collision.b];
            
            if(a.stopped and b.stopped){ continue;}
            else if (a.stopped and !b.stopped and (a.x >= b.x)){
                b.stopped = true;
                b.y = a.y;
                int whoToBlame = collision.a;
                b.whoStopped = collision.a;
                
                while(whoToBlame != -1){
                    cows[whoToBlame].blame += b.blame + 1;
                    whoToBlame = cows[whoToBlame].whoStopped;
                }
            }else if(!a.stopped and b.stopped and (b.y >= a.y)){
                a.stopped = true;
                a.x = b.x;
                
                int whoToBlame = collision.b;
                a.whoStopped = collision.b;
                
                while(whoToBlame != -1){
                    cows[whoToBlame].blame += a.blame +1;
                    whoToBlame = cows[whoToBlame].whoStopped;
                }
            }else if (!a.stopped and !b.stopped){
                if(b.x - a.x < a.y - b.y){
                    b.stopped = true;
                    
                    b.whoStopped = collision.a;
                    a.blame += b.blame +1;
                    b.y = a.y;
                }else{
                    a.stopped = true;
                    a.whoStopped = collision.b;
                    b.blame += a.blame +1;
                    a.x = b.x;
                }
            } 
        }
        
        sort(all(cows), [](cow&a, cow&b){return a.id < b.id;});
        
        for(auto &c: cows){
            cout << c.blame << endl;
        }
        
        
    }
    
    
    int main() {
        // Uncomment the following lines for file I/O
        // iofile(string("mountains"));
        
        // Uncomment the following lines for multiple test cases
        // int t; cin >> t;
        // while(t--) fx();
        
        // Single test case
        fx();
        
        return 0;
    }
