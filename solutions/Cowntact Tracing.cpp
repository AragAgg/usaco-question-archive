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
