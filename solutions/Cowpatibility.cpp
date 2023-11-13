#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
//===================================
unordered_map<string, int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    ll n; cin >> n;
    ll tot = n*(n-1)/2;
    for (int i = 1; i <= n; i++){
        vector<string> v(5); for (string &x: v) cin >> x; sort(all(v));
        for (int mask = 1; mask < 1<<5; mask++){
            string s = "";
            for (int j = 0; j < 5; j++) if (mask&(1<<j)) s += v[j]+'|';
            tot -= (__builtin_popcount(mask)&1? 1 : -1) * (cnt[s]++);
        }
    }
    cout << tot << "\n";
}
