#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
void no() { cout << "IMPOSSIBLE" << '\n'; }

int n, m;
vvi tab;
vi visited;
set<pii>taken;

bool dfs(int v, int parent){
    int out = 0;
    visited[v] = true;
    
    for(auto neigh: tab[v]){
        if(neigh == parent or taken.count({neigh, v})) continue;
        else if(visited[neigh] or dfs(neigh, v)) taken.insert({v, neigh}), out++;
        else taken.insert({neigh, v});
    }
    
    return ((out%2)?false:true);
}

void fx() {
    cin >> n >> m;
    
    tab.assign(n, {});
    visited.assign(n, false);
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        tab[--a].pb(--b);
        tab[b].pb(a);
    }
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        
        if(!dfs(i, -1)){ 
            no();
            return;
        }
    }
    
    for(auto edge: taken) cout << (edge.f+1) << " " << (edge.s+1) << endl;
}

int main() {
    fx();
    return 0;
}
