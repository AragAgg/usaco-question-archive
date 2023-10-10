---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1063
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - 2D-Prefix-Sum
  - Coordinate-Compression
  - Observation
What's up: Pretty Annoying Problem
Key Takeaway: Coordinate compression could be a great optimisation when working with a sparse grid/line. Use helper function for stuff related to grid prefix fetch / calculations requiring complex formulas (≥ 3 terms).Always start off with a simple solution, then make a guess on the expected time complexity, then iteratively search for bottlenecks, and optimise those.Whenever a question feels overwhelming, make up some test-cases and do those by hand to familiarise yourself with the problem constraints and get an intuitive sense of the problem constuct.
---
### Solution

```C++
void fx() {
    // Functionality for fx
    int n; cin >> n;
    
    map<int, int>xs;
    map<int, int>ys;
    
    vii cows;
    
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        
        xs.insert({x, 0});
        ys.insert({y, 0});
        
        cows.pb({x, y});
    }
    
    int counter = 1;
    for(auto &i: xs) i.s = counter++;
    counter = 1;
    for(auto &i: ys) i.s = counter++;
    
    tab.assign(n+1, vi(n+1, 0));
    
    for(auto cow: cows){
        tab[xs[cow.f]][ys[cow.s]]++;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) tab[i][j] += tab[i-1][j] + tab[i][j-1] - tab[i-1][j-1];
    }
    
    long long ans = n+1;
    
    sort(all(cows));
    
    for(int i = 0; i < n-1; i++){
        pii a = {xs[cows[i].f], ys[cows[i].s]};
        
        for(int j = i+1; j < n; j++){
            pii b = {xs[cows[j].f], ys[cows[j].s]};
            
            int l = min(a.s, b.s);
            int r = max(a.s, b.s);
            
            int top = min(a.f, b.f);
            int bottom = max(a.f, b.f);
            
            int low = rsum(1, l, top, r);
            int high = rsum(bottom, l, n, r);
            
            ans += low*high;
        }
    }
    
    cout << ans << endl;
    
    
}
```

### Editorial

[https://usaco.guide/problems/usaco-1063-rectangular-pasture/solution](https://usaco.guide/problems/usaco-1063-rectangular-pasture/solution)

### Video Editorial (starCoder)

[https://www.youtube.com/watch?v=oYyh-492pL0&pp=ygUdc3RhcmNvZGVyIHJlY3Rhbmd1bGFyIHBhc3R1cmU=](https://www.youtube.com/watch?v=oYyh-492pL0&pp=ygUdc3RhcmNvZGVyIHJlY3Rhbmd1bGFyIHBhc3R1cmU=)