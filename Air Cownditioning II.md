---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1276
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Complete-Search
  - Subset-Generation
---
### Solution

```C++
\#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef stack<int> si;
typedef queue<int> qi;
typedef stack<pii> sii;
typedef queue<pii> qiai;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

\#define pb push_back
\#define eb emplace_back

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

template<typename T> void print_vector(const vector<T>& v) {
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
}

struct range{
    int s = 0;
    int e = 0;
    int c = 0;
};

int N, M;
vector<range>cowRange;
vector<pair<int, range>>coolingRange;




void fx(){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        range cow;
        cin >> cow.s >> cow.e >> cow.c;
        
        cow.c *= -1;
        
        cowRange.pb(cow);
    }
    for(int i = 0; i < M; i++){
        range cool;
        int p;

        cin >> cool.s >> cool.e >> cool.c >> p;
        
        cool.c *= -1;
        
        coolingRange.pb({p, cool});
    }
    
    int ans = INT_MAX;
    
    for(int i = 0; i < (1 << M); i++){
        
        vector<int>tab(102, 0);
        int currAns = 0;
        
        for(int j = 0; j < M; j++){
            if( !(i & (1 << j)) ) continue;
            
            tab[coolingRange[j].second.s] += coolingRange[j].second.c;
            tab[coolingRange[j].second.e +1] -= coolingRange[j].second.c;
            currAns += coolingRange[j].first;
        }
        
        
        for(int j = 1; j < 102; j++) tab[j] += tab[j-1];
        
        bool flag = true;
        
        for(auto &cow : cowRange){
            for(int ri = cow.s; ri <= cow.e; ri++){
                if(cow.c < tab[ri]){
                    flag = false;
                    break;
                }
            }
            
            if(!flag) break;
        }
        
        if(flag){
            ans = min(ans, currAns);
        }
        
    }
    
    cout << ans << endl;
    
}


int main()
{
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);
    fx();
}
```