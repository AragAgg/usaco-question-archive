---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=569
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Complete-Search
  - Implementation
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


void fx(){
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    
    vector<vector<unordered_set<int>>>tab(101, vector<unordered_set<int>>(n+1));
    vector<unordered_set<int>>milkMap(m+1);
    
    for(int i = 0; i < d; i++){
        int p, m, t;
        cin >> p >> m >> t;
        
        tab[t][p].insert(m);
        milkMap[m].insert(p);
        
    }
    
    for(int t = 2; t <= 100; t++){
        for(int p = 1; p <= n; p++){
            //if(tab[t-1][p].size() == tab[t][p].size()) continue;
            for(auto &item : tab[t-1][p]) tab[t][p].insert(item);
        }
    }
    
    unordered_set<int>sus;
    for(int i = 1; i < m+1; i++) sus.insert(i);
    
    for(int i = 0; i < s; i++){
        int p, t;
        cin >> p >> t;
        
        unordered_set<int>&tempSus = tab[t-1][p];
        
        // for(auto &item : tempSus) cout << "# " << p << ":" << item << endl;
        
        vi temp;
        
        for(auto item : sus){
            if(!tempSus.count(item)) temp.push_back(item);
        }
        
        for(auto i: temp) sus.erase(i);
        
        if(sus.size() == 1) break;
    }
    
    int ans = 0;
    
    // for(auto &item: sus) cout << item << " ";
    
    for(auto &item: sus) ans = max(ans, (int)milkMap[item].size());
    
    
    cout << ans << endl;
    
    
}



int main()
{
    
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    fx();
    return 0;
}
```