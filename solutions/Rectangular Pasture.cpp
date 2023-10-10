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
