struct update{
    int l, r, delta;
};

struct query{
    int l, r;
};

vector<update>updates;
vector<query>queries;

map<int, int>mp;


void fx() {
    // Functionality for fx
    int n, q;
    cin >> n >> q;
    
    while(n--){
        update u;
        cin >> u.l >> u.r >> u.delta;
        
        mp[u.l+1] = 0;
        mp[u.r+1] = 0;
        
        updates.pb(u);
    }
    
    while(q--){
        query q;
        cin >> q.l >> q.r;
        
        mp[q.l] = 0;
        mp[q.r] = 0;
        
        queries.pb(q);
    }
    
    int counter = 1;
    
    umii revmp;
    
    for(auto &i: mp){ i.s = counter++; revmp[i.s] = i.f;}
    
    vector<long long> tab(counter, 0);
    
    for(auto &u: updates){
        tab[mp[u.l+1]] += u.delta;
        tab[mp[u.r+1]] -= u.delta;
    }
    
    long long offset = 0;
    
    for(int i = 1; i < tab.size(); i++){
        long long temp = tab[i];
        tab[i] += tab[i-1] + offset*(revmp[i] - revmp[i-1]); // try i+1, i;
        offset += temp;
    }
    
    for(auto &q: queries){
        cout << tab[mp[q.r]] - tab[mp[q.l]] << endl;
    }
}
