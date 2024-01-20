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

// cin.tie(0)->sync_with_stdio(0);
vi visited, topSort;
vvi adj;
bool isCycle = false;

void dfs(int node){
    visited[node] = -1;
    for(auto &neigh: adj[node]){
        if(visited[neigh] == -1) isCycle = true;
        if(!visited[neigh]) dfs(neigh);
    }

    visited[node] = 1;
    topSort.pb(node);
}

void fx() {
    // Functionality for fx
    int n;
    cin >> n;

    vector<string>tab(n);
    for(auto &i: tab) cin >> i;
    adj.assign(26, {});
    
    set<pii>edges;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(tab[i] == tab[j]) continue;
            if(tab[i].size() > tab[j].size() and tab[i].substr(0, tab[j].size()) == tab[j]){
                cout << "Impossible" << endl;
                return;
            }
            int p1 = 0, p2 = 0;
            while(p1 < tab[i].size() and p2 < tab[j].size()){
                if(tab[i][p1] == tab[j][p2]) p1++, p2++;
                else{
                    edges.insert({((int)(tab[j][p2] - 'a')), ((int)(tab[i][p1] - 'a'))});
                    break;
                }
            }
        }
    }

    for(auto &[a, b]: edges) adj[a].pb(b);

    visited.assign(26, 0);
    for(int i = 0; i < 26; i++) if(!visited[i]) dfs(i);

    if(isCycle){
        cout << "Impossible" << endl;
        return;
    }

    for(auto &i: topSort) cout << ((char)(i + 'a')) << "";
    cout << endl;
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
