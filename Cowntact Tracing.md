---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1037
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Complete-Search
  - Implementation
---
### Solution Already Written

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

unordered_map<int, int>currSus;
unordered_set<int>finalSus;
unordered_map<int, pair<int, int>>tab;

bool isInfected(int &a){
    return (currSus.count(a));
}

void fx(){
    
    currSus.clear();
    finalSus.clear();
    tab.clear();
    
    int n, t;
    cin >> n >> t;
    
    string st;
    cin >> st;
    
    for(int i = 0; i < n; i++){
        if(st[i] == '1') finalSus.insert(i+1);
    }
    
    if(finalSus.size() == (int)0) cout << 0 << 0 << 0 << endl;
    
    for(int i = 0; i < t; i++){
        int t, x, y;
        cin >> t >> x >> y;
        
        tab.insert({t, {x, y}});
    }
    
    unordered_set<int>totalSus;
    int low = 251;
    int high = 0;
    
    for(int susZero = 1; susZero <= n; susZero++){
        
        if(!finalSus.count(susZero)) continue;
        
        for(int k = 0; k < 251; k++){
            currSus.clear();
            
            currSus.insert({susZero, k});
            
            bool violated = false;
            
            for(int currT = 1; currT < 251; currT++){
                if(!tab.count(currT)) continue;
                
                int a = tab[currT].first;
                int b = tab[currT].second;
                
                if(isInfected(a) and isInfected(b)){
                    currSus[a]--;
                    currSus[b]--;
                    continue;
                    
                }else if(!isInfected(a) and !isInfected(b)) continue;
                
                if(isInfected(a)) swap(a, b);
                
                if(currSus[b] <= 0) continue;
                
                if(!finalSus.count(a)){ violated = true; break;}
                
                currSus.insert({a, k});
                currSus[b]--;
            }
            
            if(violated) break;
            
            if(finalSus.size() != currSus.size()) continue;
            
            totalSus.insert(susZero);
            low = min(low, k);
            high = max(high, k);
            
        }
    }
    
    string temp = to_string(high);
    
    cout << totalSus.size() << " " << low << " " << ((high >= 250)?"Infinity":temp) << endl;
}


int main()
{
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    fx();
}
```

  

### Problems Encountered

```Plain
Can't fix WA on Test Case 11.
```

  

### Final Solution (AC)

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
    string final;
    int totalInfectedCount = 0;
    int N, T;
    cin >> N >> T;
    cin >> final;
    
    map<int, pii>interactions;
    
    for(int i = 0; i < T; i++){
        int t, x, y;
        cin >> t >> x >> y;
        
        interactions.insert({t, {x, y}});
    }
    
    for(auto &ch : final) if(ch == '1') totalInfectedCount++;
    
    int lK = 251;
    int uK = 0;
    unordered_set<int>xZeroSus;
    
    for(int xZero = 1; xZero <= N; xZero++){
        
        if(final[xZero-1] == '0') continue;
        
        for(int k = 0; k <= 251; k++){
            
            unordered_map<int, int>currentlyInfected;
            currentlyInfected.insert({xZero, 0});
            
            bool violated = false;
            
            for(auto &interaction: interactions){
                
                int x = interaction.second.first;
                int y = interaction.second.second;
                
                if(currentlyInfected.count(x)) currentlyInfected[x]++;
                if(currentlyInfected.count(y)) currentlyInfected[y]++;
                
                if(currentlyInfected.count(x) and currentlyInfected.count(y)) continue;
                else if(!currentlyInfected.count(x) and !currentlyInfected.count(y)) continue;
                
                
                if(currentlyInfected.count(y)) swap(x, y);
                
                if(currentlyInfected[x] > k) continue;
                
                if(final[y-1] == '0'){
                    violated = true;
                    break;
                }
                
                currentlyInfected.insert({y, 0});
            }
            
            if(violated) continue;
            
            if((int)currentlyInfected.size() == totalInfectedCount){
                // cout << xZero <<  endl;
                xZeroSus.insert(xZero);
                lK = min(lK, k);
                uK = max(uK, k);
            }
            
            
        }
    }
    
    string temp;
    if(uK == 251) temp = "Infinity";
    else temp = to_string(uK);
    
    cout << xZeroSus.size() << " " <<  lK << " " << temp << endl;
    
}

int main()
{
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    fx();
}
```