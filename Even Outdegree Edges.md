---
Question Link: https://cses.fi/problemset/task/2179
Problem Set:
  - CSES
Last edited time: 2023-10-20T01:00
Status: Nice Question
tags:
  - DFS
  - Greedy
  - MST
  - Observation
Key Takeaway: "When solving a question on graph, consider solving it first on a tree (imagine DFS tree of the graph - without back_edges), and once you solve that version of the problem, try adjusting your solution to work with trees with back edges. "
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

\#define pb push_back
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
```

### Video Editorial [at timeStamp]

> [!info] Solving INTRIGUING Programming Problems from CSES Additional Section  
> too lazy  
> [https://youtu.be/U0zjn9Vk6KQ?t=1716](https://youtu.be/U0zjn9Vk6KQ?t=1716)  

  

### Editorial

> [!info] Solution - Even Outdegree Edges (CSES)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/cses-2179-even-outdegree-edges/solution](https://usaco.guide/problems/cses-2179-even-outdegree-edges/solution)  

  

No Solution Explanation because chatGPT doesn’t understand the provided solution. [It explained well in the editorial.

  

  

---

### Really nice resource

  

- CF Blogpost by is-this-fft
    
    > [!info] [Tutorial] The DFS tree and its applications: how I found out I really didn't understand bridges - Codeforces  
    > Codeforces.  
    > [https://codeforces.com/blog/entry/68138](https://codeforces.com/blog/entry/68138)