---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=787
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Custom-Comparator
  - Greedy
  - Sorting
Key Takeaway: In greedy solutions it’s always better to use pre-defined structures then to use custom structs (or classes) as we could use pre-defined sorting mechanisms to sort those. This is even applicable if it comes at a relatively minor cost to code complexity.
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

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
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()

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

// Common outputs
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }

int n, m, r;
vi cows;
vii store;
vi neigh;

void fx(){
    cin >> n >> m >> r;
    
    cows.assign(n, 0);
    store.assign(m, {0,0});
    neigh.assign(r, 0);
    
    for(auto &i: cows) cin >> i;
    for(auto &i: store) cin >> i.s >> i.f;
    for(auto &i: neigh) cin >> i;
    
    sort(all(cows));
    reverse(all(cows));
    sort(all(store));
    reverse(all(store));
    sort(all(neigh));
    reverse(all(neigh));
    
    int sPtr = 0;
    int nPtr = 0;
    long long totalEarnings = 0;
    int fPtr = -1;
    vector<long long> sellValue(n, 0);
    
    for(int i = 0; i < n; i++){
        while(cows[i] != 0 and sPtr != m){
            long long curr = min(cows[i], store[sPtr].s);
            cows[i] -= curr;
            store[sPtr].s -= curr;
            sellValue[i] += curr*store[sPtr].f;
            totalEarnings += curr*store[sPtr].f;
            if(store[sPtr].s == 0) sPtr++;
            fPtr = i;
        }
        
        if(sPtr == m and nPtr != r and !sellValue[i]) totalEarnings += neigh[nPtr++];
    }
    
    while(fPtr >= 0 and nPtr != r){
        long long curr = totalEarnings;
        curr -= sellValue[fPtr--];
        curr += neigh[nPtr++];
        totalEarnings = max(totalEarnings, curr);
    }
    
    cout << totalEarnings << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("rental"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Solution Explanation

- **Type Definitions and Macros**:
    - The code starts with type definitions for convenience, such as `vi` for `vector<int>`, `pii` for `pair<int, int>`, and so on.
    - There are also some shortcuts defined for common operations, like `pb` for `push_back`.
    - Debugging macros are defined to help with debugging, but they aren't used in the main solution.
    - I/O redirection macros are provided for reading from and writing to files.
- **Global Variables**:
    - `n`, `m`, and `r` are the number of cows, stores, and neighboring farmers, respectively.
    - `cows` is a vector storing the milk production of each cow.
    - `store` is a vector of pairs storing the amount of milk each store wants and the price they offer.
    - `neigh` is a vector storing the rental price offered by each neighboring farmer.
- **Function** `**fx()**`: This is the main function that solves the problem.
    - **Input Reading**: The function starts by reading the input values and resizing the vectors.
    - **Sorting**: The cows, stores, and neighbors are sorted in descending order. This is crucial for the greedy approach used later.
    - **Calculating Earnings from Selling Milk**:
        - The code uses two pointers, `sPtr` for stores and `nPtr` for neighbors.
        - For each cow, the code calculates how much money can be earned by selling its milk to the stores. This is done using a while loop that runs until all the milk from the cow is sold or all stores have been considered.
        - The earnings from selling the milk of each cow are stored in the `sellValue` vector.
    - **Calculating Earnings from Renting Cows**:
        - If a cow's milk couldn't be sold (because all stores have been considered) and it hasn't been considered for selling, it's rented out to a neighbor.
    - **Maximizing Total Earnings**:
        - The code then tries to maximize the total earnings by considering whether it's more profitable to rent out a cow (even if its milk was sold) and replace its earnings with a higher rental offer from a neighbor.
        - This is done using a while loop that decrements the `fPtr` (pointing to the last cow whose milk was sold) and increments the `nPtr` (pointing to the next neighbor's rental offer).
- **Main Function**:
    - The main function sets up file I/O and then calls the `fx()` function to solve the problem.
- **Analysis of the Solution**:
    - **Why it works**: The solution uses a greedy approach. By sorting the cows, stores, and neighbors in descending order, the solution ensures that the highest milk-producing cows are matched with the highest paying stores first. Similarly, cows are rented out to the highest paying neighbors first. This greedy approach ensures that the maximum profit is achieved.
    - **Elegance**: The solution is relatively clean and uses a straightforward greedy approach. The use of type definitions and macros makes the code concise. However, the function name `fx()` is not very descriptive, and more meaningful variable names could improve readability.
    - **Efficiency**: The solution is efficient. Sorting takes \(O(n \log n)\), \(O(m \log m)\), and \(O(r \log r)\) for cows, stores, and neighbors, respectively. The while loops run in linear time. Thus, the overall complexity is dominated by the sorting operations.
    - **Improvements**:
        - The code could benefit from more comments explaining the logic, especially in the `fx()` function.
        - Using more descriptive variable and function names would make the code more readable.
        - The debugging macros are defined but not used in the solution. They could be removed or commented out to declutter the code.

### In-depth analysis of solution

### 1. Preparation and Input Reading:

- The solution starts by reading the number of cows (`n`), stores (`m`), and neighboring farmers (`r`).
- It then reads the milk production of each cow, the amount of milk each store wants to buy and the price they offer, and the rental price offered by each neighboring farmer.

### 2. Sorting:

- The cows are sorted in descending order based on their milk production. This ensures that the cows that produce the most milk are considered first.
- The stores are sorted in descending order based on the price they offer for milk. This ensures that the highest paying stores are considered first.
- The neighbors are sorted in descending order based on their rental offers. This ensures that the highest paying rental offers are considered first.

### 3. Calculating Earnings from Selling Milk:

- The solution uses two pointers: `sPtr` for stores and `nPtr` for neighbors.
- For each cow (starting from the highest milk-producing cow):
    - The solution calculates how much money can be earned by selling its milk to the stores.
    - This is done using a while loop that runs until all the milk from the cow is sold or all stores have been considered.
    - The earnings from selling the milk of each cow are stored in the `sellValue` vector.
    - If all the stores have been considered and a cow hasn't been able to sell its milk, the solution moves to the next step.

### 4. Calculating Earnings from Renting Cows:

- If a cow's milk couldn't be sold (because all stores have been considered) and it hasn't been considered for selling, it's rented out to a neighbor.
- The solution continues renting out cows to neighbors until all cows have been considered or all rental offers have been used.

### 5. Maximizing Total Earnings:

- The solution then tries to maximize the total earnings.
- It considers whether it would be more profitable to rent out a cow (even if its milk was sold) and replace its earnings with a higher rental offer from a neighbor.
- This is done using a while loop:
    - The loop starts with the last cow whose milk was sold (`fPtr`) and the next neighbor's rental offer (`nPtr`).
    - For each iteration, the solution calculates the total earnings if the cow's milk selling earnings were replaced by the rental offer.
    - If the new total earnings are higher, the solution updates the total earnings.
    - The loop continues until all cows whose milk was sold have been considered or all rental offers have been used.

### 6. Output:

- The solution outputs the maximum total earnings.

### Why This Solution Works:

- **Greedy Approach**: The solution uses a greedy approach to maximize earnings. By sorting the cows, stores, and neighbors in descending order, the solution ensures that:
    - The highest milk-producing cows are matched with the highest paying stores first.
    - Cows are rented out to the highest paying neighbors first.
- **Maximizing Earnings**: After selling the milk, the solution tries to further maximize earnings by considering whether renting out a cow would be more profitable than the earnings from its milk. This ensures that the solution explores all possible ways to maximize profit.
- **Efficiency**: The solution efficiently calculates earnings by using pointers and loops that run in linear time. By considering cows, stores, and neighbors in descending order, the solution ensures that the most profitable decisions are made first.

In summary, the solution works because it systematically and efficiently explores all possible ways to maximize profit using a greedy approach. It first maximizes earnings from selling milk and then tries to further maximize earnings by considering rental offers.