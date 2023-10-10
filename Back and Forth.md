---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=857
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

vector<int> a(10);
vector<int> b(10);

usi final;

void fx(){
    for(auto &item : a) cin >> item;
    for(auto &item : b) cin >> item;
    
    
    
    for(int i = 0; i < 10; i++){
        
        int curr = 1000;
        
        int firstItem = a[i];
        swap(a[i], a[9]);
        a.pop_back();
        b.push_back(firstItem);
        
        curr -= firstItem;
        
        for(int j = 0; j < 11; j++){
            int secondItem = b[j];
            swap(b[j], b[10]);
            b.pop_back();
            a.push_back(secondItem);
            
            curr += secondItem;
            
            for(int x = 0; x < 10; x++){
                int thirdItem = a[x];
                swap(a[x], a[9]);
                a.pop_back();
                b.push_back(thirdItem);
                
                curr -= thirdItem;
                
                for(int y = 0; y < 11; y++){
                    final.insert(curr + b[y]);
                }
                
                curr += thirdItem;
                
                b.pop_back();
                a.push_back(thirdItem);
                swap(a[x], a[9]);
            }
            
            curr -= secondItem;
            
            a.pop_back();
            b.push_back(secondItem);
            swap(b[j], b[10]);
        }
        
        curr += firstItem;
        
        b.pop_back();
        a.push_back(firstItem);
        swap(a[i], a[9]);
    }
    
    cout << final.size() << endl;
}


int main()
{
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    fx();
}
```