#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef stack<int> si;
typedef queue<int> qi;
typedef stack<pii> sii;
typedef queue<pii> qii;
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
    int n, k;
    cin >> n >> k;
    
    vi tab(10001, 0);
    
    int np = n;
    
    while(np--){
        int temp;
        cin >> temp;
        
        tab[temp]++;
    }
    
    
    for(int i = 1; i < tab.size(); i++) tab[i] += tab[i-1];
    
    int ans = 0;
    
    for(int i = 10000; i >= 0; i--){
        int ul = tab[i];
        int ll = tab[max(0, i-k-1)];
        
        ans = max(ans, (ul-ll));
    }
    
    cout << ans << endl;
}

int main()
{

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
//   int t;
//   cin >> t;
//   while(t--){
//       fx();
//   }


fx();
}
