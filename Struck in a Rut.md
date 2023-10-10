---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1064
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Case-Work
  - DFS
  - DS-Union
  - Dependencies
  - Implementation
  - Observation
  - Simulation
  - Sorting
What's up: Already AC. Could try optimising blame propagation and collision detection.
Key Takeaway: Simulation with Sorting is a powerful technique.Could have used a priority queue (on the basis of event timestamp) for simulating the construct on the basis of individual event sorted on timestamp.Such transitive relationships could be manages with the shitty approach that I used or implementing a lightweight DSU or by first maintaining an adjacencyList and then doing a simple DFS at the end.
---
### What I’ve thought of till now

1. First store every possible collision as an event {cow_a, cow_b, time}
2. there could be a max of (2000*2000) or `~ 4*10^6`
3. and also store the current status of every cow as either `still going` or `struck`.
4. at each collision, if any cow was already stopped, continue,
5. else check to see for three cases:
    1. either cow_a outruns cow_b → stop cow_b and blame cow_b’s parent (cow_a)
    2. or cow_b outruns cow_a → stop cow_a and blame cow_a’s parent (cow_b)
    3. or lastly, they come into the collision spot at the exact same time → disregard
6. following this does not break any of the previous (of future) dependencies, as we are simulating every collision (every possible event) in the order that they happen.
7. finally output the number of blames for every cow.
8. we also need to keep track of who stopped who (like parent) as to be able to correctly blame the right cow.
9. time complexity should be just fine
10. space complexity should not be a problem

  

  

### Solution Version History (scratch pad) [ignore]

- code (first submission, the one with comments)
    
    ```C++
    \#include <bits/stdc++.h>
    
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
    \#define pb push_back
    \#define ppb pop_back
    \#define f first
    \#define s second
    \#define all(x) (x).begin(), (x).end()
    
    // Debugging macros
    \#define debug(x) cerr << \#x << " = " << (x) << '\n'
    \#define debug_vector(v) _debug_vector(\#v, v)
    template<typename T>
    void _debug_vector(const string& name, const vector<T>& a) {
        cerr << name << " = [ ";
        for(const auto &x : a) cerr << x << ' ';
        cerr << "]\n";
    }
    
    // I/O redirection for local testing
    \#define iofile(io) \
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
        
        // for(auto cow: cows) cout << cow.x << " " << cow.y << " " << ((cow.dirNorth)?'N':'E') << endl;
        
        // cout << "cows: " << cows.size() << " ";
        
        for(int i = 0; i < n-1; i++){
            cow &a = cows[i];
            
            for(int j = i+1; j < n; j++){
                cow &b = cows[j];
                
                if(a.y < b.y or a.dirNorth or !b.dirNorth or (b.x - a.x == a.y - b.y)) continue;
                
                collision x;
                x.a = i;
                x.b = j;
                
                x.t = max((b.x - a.x), (a.y - b.y));
                
                // cout << "collision at t = " << x.t << " between: " << i << " and " << j << endl; 
                
                collisions.pb(x);
            }
        }
        
        sort(all(collisions), [](collision &x, collision&y){return x.t < y.t;});
        
        // cout << "collisions: " << collisions.size() << endl;
        
        for(auto const &collision: collisions){
            // cout << "collision at t = " << collision.t << " between: " << collision.a << " and " << collision.b << endl; 
            cow &a = cows[collision.a];
            cow &b = cows[collision.b];
            
            if(a.stopped and b.stopped){ continue;}
            else if (a.stopped and !b.stopped and (a.x >= b.x)){
                b.stopped = true;
                b.y = a.y-1;
                
                // b.whoStopped = a.whoStopped;
                // cows[b.whoStopped].blame++;
                // a.blame++;
                int whoToBlame = collision.a;
                b.whoStopped = collision.a;
                
                while(cows[whoToBlame].whoStopped != -1){
                    cows[whoToBlame].blame += b.blame + 1;
                    whoToBlame = cows[whoToBlame].whoStopped;
                }
                // cout << "a stopped b\n";
            }else if(!a.stopped and b.stopped and (b.y >= a.y)){
                a.stopped = true;
                a.x = b.x-1;
                
                int whoToBlame = collision.b;
                a.whoStopped = collision.b;
                
                while(cows[whoToBlame].whoStopped != -1){
                    cows[whoToBlame].blame += a.blame +1;
                    whoToBlame = cows[whoToBlame].whoStopped;
                }
                
                // a.whoStopped = b.whoStopped;
                // cows[a.whoStopped].blame++;
                // b.blame++;
                // cout << "b stopped a\n";
            }else if (!a.stopped and !b.stopped){
                //both are moving
                
                if(b.x - a.x < a.y - b.y){
                    //a stops b
                    b.stopped = true;
                    // b.whoStopped = collision.a;
                    
                    b.whoStopped = collision.a;
                    a.blame += b.blame +1;
                    
                    // a.blame++;
                    b.y = a.y-1;
                    // cout << "a stopped... b\n";
                    
                }else{
                    //b stops a
                    a.stopped = true;
                    a.whoStopped = collision.b;
                    b.blame += a.blame +1;
                    a.x = b.x-1;
                    // cout << "b stopped... a\n";
                }
            }
            
            // for(auto &c: cows) cout << c.stopped;
            // cout << endl;
            
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
    ```
    
- code (without comments)
    
    ```C++
    \#include <bits/stdc++.h>
    
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
    \#define pb push_back
    \#define ppb pop_back
    \#define f first
    \#define s second
    \#define all(x) (x).begin(), (x).end()
    
    // Debugging macros
    \#define debug(x) cerr << \#x << " = " << (x) << '\n'
    \#define debug_vector(v) _debug_vector(\#v, v)
    template<typename T>
    void _debug_vector(const string& name, const vector<T>& a) {
        cerr << name << " = [ ";
        for(const auto &x : a) cerr << x << ' ';
        cerr << "]\n";
    }
    
    // I/O redirection for local testing
    \#define iofile(io) \
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
                
                while(cows[whoToBlame].whoStopped != -1){
                    cows[whoToBlame].blame += b.blame + 1;
                    whoToBlame = cows[whoToBlame].whoStopped;
                }
            }else if(!a.stopped and b.stopped and (b.y >= a.y)){
                a.stopped = true;
                a.x = b.x;
                
                int whoToBlame = collision.b;
                a.whoStopped = collision.b;
                
                while(cows[whoToBlame].whoStopped != -1){
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
    ```
    

  

  

### Badcases

```C++
3
E 10 10
N 12 5
E 0 9
```

### Solution (AC) [lengthy]

- code
    
    ```C++
    \#include <bits/stdc++.h>
    
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
    \#define pb push_back
    \#define ppb pop_back
    \#define f first
    \#define s second
    \#define all(x) (x).begin(), (x).end()
    
    // Debugging macros
    \#define debug(x) cerr << \#x << " = " << (x) << '\n'
    \#define debug_vector(v) _debug_vector(\#v, v)
    template<typename T>
    void _debug_vector(const string& name, const vector<T>& a) {
        cerr << name << " = [ ";
        for(const auto &x : a) cerr << x << ' ';
        cerr << "]\n";
    }
    
    // I/O redirection for local testing
    \#define iofile(io) \
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
    ```
    

### Code Explanation

- **Data Structures**:
    - `struct cow`: Represents a cow with its position `(x, y)`, direction (north or east), whether it has stopped or not, who stopped it, and a blame counter.
    - `struct collision`: Represents a potential collision between two cows and the time it would take for that collision to occur.
- **Initialization**:
    - Read the number of cows `n`.
    - For each cow, read its direction and position, and store it in the `cows` vector.
- **Finding Potential Collisions**:
    - The cows are sorted based on their x-coordinates.
    - For each pair of cows `(a, b)`, if `a` is to the left of `b`, and `a` is facing east while `b` is facing north, then there's a potential for `a` to collide with `b` or vice versa. The time for this potential collision is calculated as the maximum of the horizontal and vertical distances between them. This potential collision is stored in the `collisions` vector.
    - The potential collisions are then sorted based on the time they would occur.
- **Processing Collisions**:
    - For each potential collision in the sorted `collisions` vector:
        - If both cows have already stopped, skip this collision.
        - If cow `a` has stopped but cow `b` hasn't, and `a` is to the right of `b`, then `b` stops at `a`'s y-coordinate. The blame is then propagated: cow `b` blames cow `a`, and if cow `a` was stopped by another cow, that cow also gets the blame, and so on.
        - Similarly, if cow `b` has stopped but cow `a` hasn't, and `b` is above `a`, then `a` stops at `b`'s x-coordinate. The blame is propagated in a similar manner.
        - If neither cow has stopped, then the one that would reach the collision point first stops, and the other cow gets the blame.
- **Output**:
    - The cows are sorted back to their original order based on their IDs.
    - The blame for each cow is printed.

  

**Core Idea**:  
The core idea behind this solution is to pre-calculate all potential collisions between cows and sort them based on the time they would occur. Then, process each collision in order, updating the state of the cows (whether they've stopped and who they blame). By processing the collisions in order, the solution ensures that earlier collisions are accounted for before later ones. The blame is propagated using a simple while loop, ensuring that if a cow stops another cow, and that cow had previously been stopped by a third cow, the third cow also gets the blame.

The solution efficiently handles the transitive nature of the blame relationship by using the `whoStopped` attribute of each cow to propagate blame up the chain of stopped cows. This ensures that if cow A stops cow B, and cow B stops cow C, then cow A also gets the blame for stopping cow C.