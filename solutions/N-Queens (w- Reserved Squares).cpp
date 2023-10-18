#include <bits/stdc++.h>

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

#define pb push_back
#define eb emplace_back

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

template<typename T> void print_vector(const vector<T>& v) {
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
}

vvi tab(8, vector<int>(8, 0));

bool isCompatible(vvi &tab, int i, int j){
    int x, y;
    
    for(int a = 0; a < 8; a++){
        if(a != i and tab[a][j] == 1) return false;
        if(a != j and tab[i][a] == 1) return false;
    }
    
    x = i+1; y = j+1;
    while(x >= 0 and y >= 0 and x < 8 and y < 8){
        if(tab[x][y] == 1) return false;
        
        x++; y++;
    }
    
    x = i-1; y = j+1;
    while(x >= 0 and y >= 0 and x < 8 and y < 8){
        if(tab[x][y] == 1) return false;
        
        x--; y++;
    }
    
    x = i+1; y = j-1;
    while(x >= 0 and y >= 0 and x < 8 and y < 8){
        if(tab[x][y] == 1) return false;
        
        x++; y--;
    }
    
    x = i-1; y = j-1;
    while(x >= 0 and y >= 0 and x < 8 and y < 8){
        if(tab[x][y] == 1) return false;
        
        x--; y--;
    }
    
    
    return true;
    
}

int fx(vvi &tab, int x = 0){
    if(x == 8){return 1;}
    
    int counter = 0;
    
    // for(int i = 0; i < 8; i++){
    //     for(int j = 0; j < 8; j++){
    //         if(tab[i][j] != 0) continue;
            
    //         tab[i][j] = 1;
            
    //         // counter += (isCompatible(tab, i, j)?fx(tab, i+1):0);
    //         if(isCompatible(tab, i, j)) counter += fx(tab, x+1);
            
    //         tab[i][j] = 0;
    //     }
    // }
    
    for(int i = 0; i < 8; i++){
        if(tab[x][i] != 0) continue;
        
        tab[x][i] = 1;
        
        if(isCompatible(tab, x, i)) counter += fx(tab, x+1);
        
        tab[x][i] = 0;
    }
    
    
    return counter;
    
}


int main()
{
    for(int i = 0; i < 8; i++){
        string s;
        cin >> s;
        
        for(int j = 0; j < 8; j++) tab[i][j] = (s[j]=='.'?0:-1);
    }
    cout << fx(tab) << endl;
}
