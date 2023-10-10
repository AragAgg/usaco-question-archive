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

void fx(){
    int N;
    cin >> N;
    
    vector<string>cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    
    sort(cows.begin(), cows.end());
    
    vector<pair<string, string>>dependencies(N);
    
    for(auto &item: dependencies){
        cin >> item.first;
        for(int i = 0; i < 5; i++) cin >> item.second;
        
        
        //cout << "depen: " << item.first <<" " << item.second << endl;
    }
    
    do{
        
        bool isValid = true;
        
        for(auto &dep: dependencies){
            bool flag = false;
            
            for(int i = 0; i < 7; i++){
                if((cows[i] == dep.first and cows[i+1] == dep.second) or (cows[i] == dep.second and cows[i+1] == dep.first)){
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                isValid = false;
                break;
            }
        }
        
        if(isValid){
            for(auto &item: cows){
                cout << item << endl;
            }
            
            return;
        }
        
    }while(next_permutation(cows.begin(), cows.end()));
}


int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    fx();
}
