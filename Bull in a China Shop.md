---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=640
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
typedef vector<vb> vvb;

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

struct img{
    vvb image;
    int moveL = 0, moveT = 0;
    
    int moveR = 0, moveB = 0;
    
    img(vvb original){
        image = original;
        bool lFlag = true, tFlag = true;
        
        while(moveL < image.size()){
            for(int j = 0; j < (int)image.size(); j++){
                if(!image[j][moveL]) continue;
                else{
                    lFlag = false;
                    break;
                }
            }
            
            if(!lFlag) break;
            else moveL++;
        }
        
        while(moveT < image.size()){
            for(int j = 0; j < (int)image.size(); j++){
                if(!image[moveT][j]) continue;
                else{
                    tFlag = false;
                    break;
                }
            }
            
            if(!tFlag) break;
            else moveT++;
        }
        
        vvb transformed_image(image.size(), vector<bool>(image.size(), false));
        
        for(int i = 0; i < (image.size() - moveT); i++){
            for(int j = 0; j < (image.size() - moveL); j++){
                transformed_image[i][j] = image[moveT + i][moveL + j];
            }
        }
        
        image = transformed_image;
        
        bool bFlag = true;
        bool rFlag = true;
        
        while(moveB < image.size()){
            for(int j = 0; j < image.size(); j++){
                if(image[image.size() - moveB -1][j]){
                    bFlag = false;
                    break;
                }
            }
            
            if(!bFlag) break;
            else moveB++;
        }
        
        while(moveR < image.size()){
            for(int j = 0; j < image.size(); j++){
                if(image[j][image.size() -moveR -1]){
                    rFlag = false;
                    break;
                }
                
            }
            
            if(!rFlag) break;
            else moveR++;
        }
        
    }
    
    vvb move(int moveB, int moveR){
        vvb transformed_image(image.size(), vector<bool>(image.size(), false));
        
        for(int i = moveB; i < (image.size()); i++){
            for(int j = moveR; j < (image.size()); j++){
                transformed_image[i][j] = image[i - moveB][j - moveR];
            }
        }
        
        return transformed_image;
        
    }
};

bool works(img ori, vvb p1, vvb p2){
    
    bool flag = true;
    
    for(int i = 0; i < ori.image.size(); i++){
        for(int j = 0; j < ori.image.size(); j++){
            if((p1[i][j] and p2[i][j]) or (ori.image[i][j] != (p1[i][j] or p2[i][j]))){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    
    //cout << "works retured: " << (flag?"yes":"no") << endl;
    
    
    return flag;
}

void fx(){
    int N, K;
    cin >> N >> K;
    
    vvb original(N, vector<bool>(N));
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            original[i][j] =((s[j] == '#')?true:false);
        }
    }
    
    img ori = img(original);
    
    vector<img>tab;
    
    for(int x = 0; x < K; x++){
        vvb temp(N, vector<bool>(N));
        
        for(int i = 0; i < N; i++){
            string s;
            cin >> s;
            
            for(int j = 0; j < N; j++){
                temp[i][j] = ((s[j] == '#')?true:false);
            }
        }
        
        
        img tempImg = img(temp);
        tab.pb(tempImg);
        
    }
    
    for(int i = 0; i < tab.size(); i++){
        for(int j = 0; j < tab.size(); j++){
            
            if(i == j) continue;
            
            auto &p1 = tab[i];
            auto &p2 = tab[j];
            
            //cout << "hey" << endl;
            
            for(int moveB = 0; moveB <= p2.moveB; moveB++){
                for(int moveR = 0; moveR <= p2.moveR; moveR++){
                    //cout <<"trying: " << i << " " << j << endl;
                    //cout << "move: " << moveB << "/" << p2.moveB << " " << moveR << "/" << p2.moveR  << endl;
                    
                    if(works(ori, tab[i].image, tab[j].move(moveB, moveR))){
                        if(i > j) swap(i, j);
                        cout << i+1 << " " << j+1 << endl;
                        return;
                    }
                    
                    //cout << endl;
                }
            }
            
        }
    }
    
    //cout << "hello" << endl;
    
}

int main()
{
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    fx();
}
```