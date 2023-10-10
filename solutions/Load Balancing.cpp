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
    int n;
    cin >> n;
    
    vii tab(n);
    
    for(auto &i : tab) cin >> i.first >> i.second;
    
    vi xs;
    vi ys;
    
    for(auto &i : tab){
        xs.pb(i.first);
        ys.pb(i.second);
    }
    
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    
    sort(tab.begin(), tab.end());
    
    int q = (int)tab.size()/4;
    
    int ans = INT_MAX;
    
    for(int i = q; i < 3*q; i++){
        for(int j = q; j < 3*q; j++){
            pii fence = {xs[i] + 1, ys[i] + 1};
            
            vi r(4, 0);
            
            for(auto &cow : tab){
                if(cow.first < fence.first){
                    if(cow.second < fence.second) r[0]++;
                    else r[1]++;
                }else{
                    if(cow.second < fence.second) r[2]++;
                    else r[3]++;
                }
            }
            
            ans = min(ans, max({r[0], r[1], r[2], r[3]}));
            
        }
    }
    
    cout << ans << endl;
}

int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    fx();
}
