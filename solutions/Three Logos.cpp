#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;

// Shortcuts for common operations
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()

// Debugging macros
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debug_vector(v) _debug_vector(#v, v)
template<typename T>
void _debug_vector(const string& name, const vector<T>& a) {
    cerr << name << " = [ ";
    for(const auto &x : a) cerr << x << ' ';
    cerr << "]\n";
}

// I/O redirection for local testing
#define iofile(io) \
        freopen((io + ".in").c_str(), "r", stdin); \
        freopen((io + ".out").c_str(), "w", stdout);

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }


int side;
int tArea;

struct sq{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    
    int maxX(sq &b){
        return max(b.x2, x2) - min(b.x1, x1);
    }
    
    int maxY(sq &b){
        return max(b.y2, y2) - min(b.y1, y1);
    }
    
    bool overlaps(sq &b){
        return (max(0, min(b.x2, x2) - max(b.x1, x1)) and  max(0, min(b.y2, y2) - max(b.y1, y1)));
    }
    
    sq flip(){
        sq temp;
        temp.x1 = x1;
        temp.y1 = y1;
        temp.x2 = x1 + (y2-y1);
        temp.y2 = y1 + (x2-x1);
        
        return temp;
    }
    
    // void print(){
    //     cout << "board: (" <<x1 <<", " << y1<<"), (" << x2 << ", " << y2 << ")" << endl;
    // }
    
};

char get(int a){
    if(a == 0) return 'A';
    else if(a == 1) return 'B';
    else return 'C';
}

int tempa, tempb, tempc;

bool fx3(sq sqA, sq sqB, sq sqC){
    if(sqC.overlaps(sqA) or sqC.maxX(sqA) > side or sqC.maxY(sqA) > side) return false;
    
    if(sqC.overlaps(sqB) or sqC.maxX(sqB) > side or sqC.maxY(sqB) > side) return false;
    
    // cout << "done." << endl;
    
    // sqA.print();
    // sqB.print();
    // sqC.print();
    
    cout << side << endl;
    
    vector<vector<char>>tab(side, vector<char>(side, get(tempc)));
    
    for(int i = 0; i < sqA.x2; i++){
        for(int j = 0; j < sqA.y2; j++) tab[i][j] = get(tempa);
    }
    
    for(int i = sqB.x1; i < sqB.x2; i++){
        for(int j = sqB.y1; j < sqB.y2; j++) tab[i][j] = get(tempb);
    }
    
    for(auto &row: tab){
        for(auto &item: row) cout << item;
        cout << endl;
    }
    
    return true;
    
}

bool fx2(sq sqA, pii b, pii c, bool flipped = false){
    
    // cout << "called fx2() with sqA: ";
    // sqA.print();
    // cout << endl;
    
    sq sqB;
    sqB.x2 = sqB.y2 = side;
    sqB.x1 = sqB.x2 - b.f;
    sqB.y1 = sqB.y2 - b.s;
    
    if((!sqA.overlaps(sqB) and sqA.maxX(sqB) <= side and sqA.maxY(sqB) <= side)){
        // cout << "sqB doesn't overlap with sqA" << endl;
        // sqB.print();
        // cout << endl;
        
        sq sqC;
        sqC.x2 = c.f;
        sqC.y2 = sqA.y2 + c.s;
        sqC.y1 = sqA.y2;
        
        if(fx3(sqA, sqB, sqC)) return true;
        if(fx3(sqA, sqB, sqC.flip())) return true;
        
        sqC.x1 = sqA.x2;
        sqC.x2 = sqA.x2 + c.f;
        sqC.y1 = 0;
        sqC.y2 = c.s;
        
        if(fx3(sqA, sqB, sqC)) return true;
        if(fx3(sqA, sqB, sqC.flip())) return true;
    }
    
    if(!flipped){
        
        pii temp = {b.s, b.f};
        
        if(fx2(sqA, temp, c, true)) return true;
    }
    
    return false;
    
}

void fx() {
    
    vector<pair<int, pii>> boards(3, {0, {0, 0}});
    
    for(int i = 0; i < 3; i++){ 
        boards[i].f = i;
        cin >> boards[i].s.f >> boards[i].s.s;
        //cout << x << " " << y << endl;
        tArea += boards[i].s.f*boards[i].s.s;
    }
    
    side = sqrt(tArea);
    
    if(side * side != tArea){
        cout << -1 << endl;
        return;
    }
    
    sort(boards.begin(), boards.end());
    
    do{
        tempa = boards[0].f;
        tempb = boards[1].f;
        tempc = boards[2].f;
        
        sq sqA = {0, boards[0].s.f, 0, boards[0].s.s};
        
        if(fx2(sqA, boards[1].s, boards[2].s)) return;
        
        if(fx2(sqA.flip(), boards[1].s, boards[2].s)) return;
        
    }while(next_permutation(boards.begin(), boards.end()));
    
    cout << "-1" << endl;
    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile("");
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
