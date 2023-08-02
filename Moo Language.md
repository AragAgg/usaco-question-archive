---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1324
Problem Set:
  - Bronze
Date: 2023-07-18
Last edited time: 2023-08-03T01:42
Status: Solved
tags:
  - Complete-Search
  - Implementation
What's up: Can’t figure out WA on select TCs and TLE on others :(
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


// type 1: simple, 2: complex, 3: compound.

struct sentence{
    int n = 0, i = 0, t = 0, cn = 0, co = 0, type = 0;
};
struct state{
    int n = 0, i = 0, t = 0, cn = 0, co = 0, p = 0;
    
    state minus(sentence st){
        state temp;
        temp.n = n - st.n;
        temp.i = i - st.i;
        temp.t = t - st.t;
        temp.cn = cn - st.cn;
        temp.co = co - st.co;
        temp.p = p - 1;
        
        return temp;
    }
    bool isCompatable(sentence &st){
        return ((st.n <= n) and (st.i <= i) and (st.t <= t) and (st.cn <= cn) and (st.co <= co) and p);
    }
};
sentence joinSentences(sentence &a, sentence &b){
    sentence temp;
    temp.n = a.n + b.n;
    temp.i = a.i + b.i;
    temp.t = a.t + b.t;
    temp.cn = a.cn + b.cn;
    temp.co = a.co + b.co;
    
    return temp;
}

int ans, tatalWords;
vector<sentence>tab;
vector<string>nouns;
vector<string>transitive;
vector<string>intransitive;
vector<string>conjunctionn;

//function prototype:
void fxCaller(vector<sentence>currTab, sentence sen, state s);
void fx2(vector<sentence>currTab, state s);
void fx();
//function prototype ends here

void fxCaller(vector<sentence>currTab, sentence sen, state s){
    currTab.pb(sen);
    fx2(currTab, s.minus(sen));
    currTab.pop_back();
}

void fx2(vector<sentence>currTab, state s){
    
    //cout << s.n << " " << s.i << " " << s.t <<" " << s.cn << endl;
    if((tatalWords - (s.n + s.i + s.t + s.cn)) > ans){
        ans = tatalWords - (s.n + s.t + s.i + s.cn);
        tab = currTab;
    }
    
    if(!((s.n >= 1 and s.i >= 1 and s.p >= 1) or (s.n >= 2 and s.t >= 1 and s.p >= 1))) return;
    
    sentence simpleOne;
    simpleOne.n = 1;
    simpleOne.i = 1;
    simpleOne.type = 1;
    
    sentence simpleCompound = joinSentences(simpleOne, simpleOne);
    simpleCompound.cn++;
    simpleCompound.type = 2;
    
    if(s.isCompatable(simpleOne)) fxCaller(currTab, simpleOne, s);
    
    if(s.isCompatable(simpleCompound)) fxCaller(currTab, simpleCompound, s);
    
    vector<sentence>complex;
    
    for(int i = 2; i <= min(s.co + 2, s.n); i++){
        sentence c;
        c.n = i;
        c.co = i-2;
        c.t = 1;
        c.type = 3;
        
        complex.pb(c);
        
        if(s.isCompatable(c)) fxCaller(currTab, c, s);
        
        sentence simpleComplex = joinSentences(simpleOne, c);
        simpleComplex.cn++;
        simpleComplex.type = 4;
        
        if(s.cn and s.isCompatable(simpleComplex)) fxCaller(currTab, simpleComplex, s);
        
    }
    
    for(int i = 0; i < (int)complex.size()-1; i++){
        for(int j = i+1; j < (int)complex.size(); j++){
            sentence complexComplex = joinSentences(complex[i], complex[j]);
            complexComplex.cn++;
            complexComplex.type = 5;
            
            if(s.cn and s.isCompatable(complexComplex)) fxCaller(currTab, complexComplex, s);
        }
    }
}

void print_sentences(){
    int nc = 0;
    int tc = 0;
    int ic = 0;
    int cnc = 0;
    
    for(int i = 0; i < tab.size(); i++){
        
        auto s = tab[i];
        
        if(s.type == 1){
            cout << nouns[nc++] << " " << intransitive[ic++] <<".";
        }else if(s.type == 2){
            cout << nouns[nc++] << " " << intransitive[ic++] << " " << conjunctionn[cnc++] << " " << nouns[nc++] << " " << intransitive[ic++] << ".";
        }else if(s.type == 3){
            int sentenceComma = s.n - 2;
            
            cout << nouns[nc++] << " " << transitive[tc++] << " " << nouns[nc++];
            while(sentenceComma--){
                cout << ", " << nouns[nc++];
            }
            
            cout << ".";
        }else if(s.type == 4){
            int sentenceComma = s.n -3;
            
            cout << nouns[nc++] << " " << intransitive[ic++] << " " << conjunctionn[cnc++] << " " << nouns[nc++] << " " << transitive[tc++] << " " << nouns[nc++];
            
            while(sentenceComma--){
                cout << ", " << nouns[nc++];
            }
            cout << ".";
        }else{
            cout << nouns[nc++] << " " << transitive[tc++] << " " << nouns[nc++] <<" " <<conjunctionn[cnc++] << " " << nouns[nc++] << " " << transitive[tc++] <<" " <<nouns[nc++];
            
            int sentenceComma = s.n - 4;
            
            while(sentenceComma--){
                cout << ", " << nouns[nc++];
            }
            
            cout << ".";
            
        }
        
        if(i != (int)tab.size()-1) cout << " ";
        
        
    }
    cout << endl;
}

void fx(){
    
    nouns.clear();
    transitive.clear();
    intransitive.clear();
    conjunctionn.clear();
    
    int N, C, P;
    cin >> N >> C >> P;
    
    state original;
    
    for(int i = 0; i < N; i++){
        string word, type;
        cin >> word >> type;
        
        if(type == "noun") nouns.pb(word);
        else if(type == "transitive-verb") transitive.pb(word);
        else if(type == "intransitive-verb") intransitive.pb(word);
        else conjunctionn.pb(word);
    }
    
    original.n = nouns.size();
    original.i = intransitive.size();
    original.t = transitive.size();
    original.cn = conjunctionn.size();
    
    original.p = P;
    original.co = C;
    
    tab.clear();
    ans = 0;
    tatalWords = N;
    
    fx2({}, original);
    
    cout << ans << endl;
    print_sentences();
    
}

int main(){
    int t;
    cin >> t;
    while(t--) fx();
}
```