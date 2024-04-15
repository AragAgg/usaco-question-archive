const ll mod = 1e9+7;

ll fx() {
    int n;
    cin >> n;
    vector<string>tab(n);
    for(auto &i: tab) cin >> i;

    vvll prev(n+5, vll(n+5, 0));
    vvll ways(n+5, vll(n+5, 0));

    for(int i = 0; i < n; i++) prev[i][i] = 1;

    for(int layer = 1; layer < n; layer++){

        ways.assign(n+5, vll(n+5, 0));

        for(int r1 = 0; r1 < n; r1++){

            for(int r2 = 0; r2 < n; r2++){

                int c1 = n - 1 - layer - r1;
                int c2 = n - 1 + layer - r2;

                if(r1 > r2 or c1 > c2 or r1 < 0 or c1 < 0) continue;

                if(tab[r1][c1] != tab[r2][c2]) continue;

                ways[r1][r2] = prev[r1][r2];

                if(r1 + 1 < n) ways[r1][r2] += prev[r1+1][r2];
                if(r2 - 1 >= 0) ways[r1][r2] += prev[r1][r2-1];
                if(r1 + 1 < n and r2 -1 >= 0) ways[r1][r2] += prev[r1+1][r2-1];
                
                /*
                if(c1 > 0 and c2 < n-1 and tab[r1][c1-1] == tab[r2][c2+1]) ways[r1][r2] += prev[r1][r2];
                if(c1 > 0 and r2 < n-1 and tab[r1][c1-1] == tab[r2+1][c2]) ways[r1][r2+1] += prev[r1][r2];
                if(r1 > 0 and r2 < n-1 and tab[r1-1][c1] == tab[r2+1][c2]) ways[r1-1][r2+1] += prev[r1][r2];
                if(r1 > 0 and c2 < n-1 and tab[r1-1][c1] == tab[r2][c2+1]) ways[r1-1][r2] += prev[r1][r2];
                */

                ways[r1][r2] %= mod;
            }
        }

        swap(prev, ways);
    }


    return prev[0][n-1];
    
}
