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

int n;
vvi color, region;
vi occupancy;
map<pii, set<pair<pii, pii>>>edges;

void fx() {
    cin >> n;
    color.assign(n, vi(n, 0));
    region.assign(n, vi(n, -1));
    
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> color[i][j];
    
    int rCounter = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if(region[i][j] != -1) continue;
            queue<pii>q;
            q.push({i, j});
            int occupants = 0;
            
            while(!q.empty()){
                pii curr = q.front(); q.pop();
                if(region[curr.f][curr.s] != -1) continue;
                region[curr.f][curr.s] = rCounter;
                occupants++;
                
                for(int d = 0; d < 4; d++){
                    int x = curr.f + dx[d];
                    int y = curr.s + dy[d];
                    
                    if(x < 0 or x >= n or y < 0 or y >= n) continue;
                    else if(color[curr.f][curr.s] != color[x][y]){
                        edges[{color[curr.f][curr.s], color[x][y]}].insert({{curr.f, curr.s}, {x, y}});
                        continue;
                    }
                
                    q.push({x, y});
                }
            }
            
            rCounter++;
            occupancy.pb(occupants);
        }
    }                               
    
    int ans = 0;
    
    for(auto nodePair: edges){
        
        int i = nodePair.f.f;
        int j = nodePair.f.s;
        
        map<int, set<int>>tree;     
        int pairAns = 0;           
        set<int>notVisited;      
        unordered_set<int>vis;    
        
        for(auto edge: nodePair.s){
            int r1 = region[edge.f.f][edge.f.s];
            int r2 = region[edge.s.f][edge.s.s];
            
            tree[r1].insert(r2);
            tree[r2].insert(r1);
            
            notVisited.insert(r1);
            notVisited.insert(r2);
        }                          
        
        for(auto node: notVisited){

            if(vis.count(node)) continue;
            
            int compAns = 0;
            queue<int>q;
            q.push(node);
            
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                
                if(vis.count(curr)) continue;
                vis.insert(curr);
                compAns += occupancy[curr];
                
                for(auto neigh: tree[curr]) q.push(neigh);
            }
            
            pairAns = max(pairAns, compAns);
        }
        
        ans = max(ans, pairAns);
        
    }
    
    cout << *max_element(all(occupancy)) << endl;
    cout << ans << endl;
}

int main() {
    iofile(string("multimoo"));
    fx();
}
