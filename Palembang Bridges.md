---
Question Link: https://oj.uz/problem/view/APIO15_bridge
Problem Set:
  - APIO
Last edited time: 2024-03-26T13:09
Status: Solved with Help
tags:
  - Implementation
  - Optimisation
  - Problem-Decomposition
  - Two-Pointer
What's up: Implementation heavy question. Had to tackle bit-by-bit.
---
### Solution (WRONG)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define p push
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
//\#define int ll
\#define endl "\n"
\#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

// Debugging macros
\#define debug(x) cerr << \#x << " = " << (x) << '\n'
\#define debug_vector(v) _debug_vector(\#v, v)
template<typename T>
void _debug_vector(const string& name, const vector<T>& a) {
    cerr << name << " = [ ";
    for(const auto &x : a) cerr << x << ' ';
    cerr << "]\n";
}

// I/O redirection for local testing
\#define iofile(io) \
        freopen((io + ".in").c_str(), "r", stdin); \
        freopen((io + ".out").c_str(), "w", stdout);

// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

struct person{
    bool hz, oz, consider, isSet;
    int home, office;
    person(char _ch, int _home, char _ch2, int _office){
        hz = (_ch - 'A');
        oz = (_ch2 - 'A');
        consider = hz^oz;
        isSet = false;

        home = min(_home, _office);
        office = max(_home, _office);
    }

    bool operator < (const person &otherPerson) const {
        return (home <= otherPerson.home);
    }
};

void fx() {
    // Functionality for fx
    int k, n;
    cin >> k >> n;
    int home, office;
    char h, o;

    vector<person>tab;
    for(int i = 0; i < n; i++){
        cin >> h >> home >> o >> office;
        person th(h, home, o, office);

        tab.pb(th);
    }

    sort(all(tab));

    vi delta(n, 0);
    int bridgeA = 0;
    priority_queue<int>pq;

    for(int i = 0; i < n; i++){
        auto &per = tab[i];
        if(!per.consider) continue;
        delta[i]++;
        pq.push(-per.office);

        while(!pq.empty() and -pq.top() < per.home) pq.pop(), delta[i]--;
    }

    for(int i = 1; i < n; i++) delta[i] += delta[i-1]; 
    for(int i = 0; i < n; i++) if(delta[i] > delta[bridgeA]) bridgeA = i;

    for(int i = 0; i < n; i++) if(tab[i].consider and tab[i].home <= tab[bridgeA].home and tab[i].office >= tab[bridgeA].home) tab[i].isSet = true;

    int bridgeB = bridgeA;

    if(k == 2){

        delta.assign(n, 0);
        while(!pq.size()) pq.pop();

        for(int i = 0; i < n; i++){
            auto &per = tab[i];
            if(!per.consider or per.isSet) continue;
            delta[i]++;
            pq.push(-per.office);

            while(!pq.empty() and -pq.top() < per.home) pq.pop(), delta[i]--;
        }


        //for(auto &per: tab) if(per.consider and !per.isSet) delta[per.home]++, delta[per.office+1]--;
        for(int i = 1; i < n; i++) delta[i] += delta[i-1]; 
        for(int i = 0; i < n; i++) if(delta[i] > delta[bridgeB]) bridgeB = i;
    }

    ll res = 0;
    for(int i = 0; i < n; i++){
        auto per = tab[i];
        if(per.consider) res += min(abs(per.home - tab[bridgeA].home) + abs(tab[bridgeA].home - per.office), abs(per.home - tab[bridgeB].home) + abs(tab[bridgeB].home - per.office)) + 1;
        else res += per.office - per.home;
        debug(res);
    }

    debug(bridgeA);
    debug(bridgeB);

    cout << res << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution (AC)

```C++

//\#pragma GCC optimize("03,unroll-loops")

\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define p push
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
//\#define int ll
\#define endl "\n"
\#define sz(x) (int)x.size()

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<pii> vii;

// Debugging macros
\#define debug(x) cerr << \#x << " = " << (x) << '\n'
\#define debug_vector(v) _debug_vector(\#v, v)
template<typename T>
void _debug_vector(const string& name, const vector<T>& a) {
    cerr << name << " = [ ";
    for(const auto &x : a) cerr << x << ' ';
    cerr << "]\n";
}

// I/O redirection for local testing
\#define iofile(io) \
        freopen((io + ".in").c_str(), "r", stdin); \
        freopen((io + ".out").c_str(), "w", stdout);

// delta for floodfill
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

// extended deltas for floodfill
vi edx = {0, 1, 0, -1, 1, 1, -1, -1};
vi edy = {1, 0, -1, 0, 1, -1, 1, -1};

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

struct person{
    ll home, office;
    bool homeZone, officeZone;

    person(ll _home, ll _office, char _homeZone, char _officeZone){
        home = min(_home, _office);
        office = max(_home, _office);
        homeZone = (_homeZone - 'A');
        officeZone = (_officeZone - 'A');
    }

    bool operator < (const person &per) const { return ((home+office) < (per.home+per.office)); }
};

struct med{
    priority_queue<ll>a;
    priority_queue<ll, vll, greater<ll>>b;
    ll _a = 0, _b = 0;

    void insert(int num){
        a.p(num);
        _a += num;

        if(a.size() > b.size()+1){
            _a -= a.top();
            _b += a.top();
            b.p(a.top());
            a.pop();
        }

        while(a.size() and b.size() and a.top() > b.top()){
            _a = _a + b.top() - a.top();
            _b = _b + a.top() - b.top();
            auto item = a.top();
            a.pop();
            a.p(b.top());
            b.pop();
            b.p(item);
        }
    }

    ll res(){ return (a.top() * a.size() - _a + _b - a.top() * b.size()); }
};

void fx() {
    int k, n;
    cin >> k >> n;
    ll res = 1e18;

    vector<person>people;
    med str;

    ll sameSide = 0;

    for(int i = 0; i < n; i++){
        ll h, o;
        char hz, oz;
        cin >> hz >> h >> oz >> o;

        person per(h, o, hz, oz);

        if(per.homeZone^per.officeZone) people.pb(per);
        else sameSide += (per.office - per.home);
    }

    sort(all(people));
    n = people.size();
    vll precost(n, 0);

    for(int i = 0; i < n; i++) str.insert(people[i].home), str.insert(people[i].office), precost[i] = str.res();

    while(!str.a.empty()) str.a.pop();
    while(!str.b.empty()) str.b.pop();
    str._a = 0; str._b = 0;

    if(k == 1 or n == 0){ cout << (((n > 1)?precost[n-1]:0) + sameSide + n) << endl; return; }

    for(int i = n-1; i >= 1; i--) str.insert(people[i].home), str.insert(people[i].office), res = min(res, precost[i-1] + str.res());

    res = min(res, precost[n-1]);
    cout << (res + sameSide + n) << endl;
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t; while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

  

  

- Case One
    
    ```C++
    1 5 
    B 0 A 4 
    B 1 B 3 
    A 5 B 7 
    B 2 A 6 
    B 1 A 7
    ```
    
- Case Two
    
    ```C++
    2 5 
    B 0 A 4 
    B 1 B 3 
    A 5 B 7 
    B 2 A 6 
    B 1 A 7
    ```