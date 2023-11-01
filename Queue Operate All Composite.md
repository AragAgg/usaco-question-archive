---
Question Link: https://judge.yosupo.jp/problem/queue_operate_all_composite
Problem Set:
  - Library Checker (YS)
Last edited time: 2023-11-02T01:15
Status: Nice Question
tags:
  - Implementation
  - Math
  - Mod
Key Takeaway: The precedence of the % operator in cpp is the same as / or * operator. So use it with braces if you’re working with an expression with multiple operators of different precedence.
---
### Solution (AC)

```C++
\#include <bits/stdc++.h>

using namespace std;

// Shortcuts for common operations
\#define pb push_back
\#define ppb pop_back
\#define f first
\#define s second
\#define all(x) (x).begin(), (x).end()
\#define ll long long
\#define endl "\n"

// Type definitions for convenience
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umii;


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

// cin.tie(0)->sync_with_stdio(0);

ll mod = 998244353;

ll fastExp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    
    return res;
}

ll modInv(ll a){ return fastExp(a, mod-2);}

void fx() {
    ll Q; cin >> Q;
    queue<pii>q;
    ll coeff = 1, constt = 0;
    
    while(Q--){
        int type;
        cin >> type;
        
        if(type == 0){
            ll a, b;
            cin >> a >> b;
            q.push({a, b});
            
            coeff = (coeff * a) % mod;
            constt = ((constt * a) + b) % mod;
        }else if(type == 1){
            auto [a, b] = q.front();
            q.pop();
            
            coeff = (coeff * modInv(a)) % mod;
            constt = ((constt - (coeff * b) % mod) + mod) % mod;
        }else{
            ll x;
            cin >> x;
            cout << ((coeff * x  + constt) % mod) << endl;
        }
    }
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial

> [!info] Solution - Queue Composite (YS)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/ys-queue-composite/solution](https://usaco.guide/problems/ys-queue-composite/solution)  

### Solution Explanation

The provided solution is for the "Queue Operate All Composite" problem, which involves a sequence of linear functions and a series of queries that manipulate or retrieve information from this sequence. Let's break down the core logic and key insights of the solution:

### Core Logic:

1. **Maintaining Global Coefficients:**  
    The solution maintains two global variables, `coeff` and `constt`, which represent the cumulative coefficient and constant term, respectively, of the composite function formed by the sequence of linear functions in the queue. Initially, both are set to their identity values (`coeff = 1` and `constt = 0`), which represent the function \( f(x) = x \).
2. **Processing Queries:**
    - **Type 0 (Add Function):** When a new linear function \( \lambda x. ax + b \) is added to the queue, the global `coeff` and `constt` are updated to reflect the addition of this function to the composite. This is done by multiplying the current `coeff` by `a` and updating `constt` to `constt * a + b`, all modulo `mod`.
    - **Type 1 (Remove Function):** When the first function in the queue is removed, the global `coeff` and `constt` are updated to reflect its removal. This involves dividing `coeff` by `a` of the removed function, which is achieved by multiplying by the modular inverse of `a`. The `constt` is updated by subtracting `b` times the updated `coeff`, ensuring to keep the result positive by adding `mod` before taking modulo `mod`.
    - **Type 2 (Evaluate Composite):** To evaluate the composite function at a given value `x`, the solution simply applies the global composite function to `x`, which is computed as `coeff * x + constt`, all modulo `mod`.

### Valuable Insights:

1. **Modular Arithmetic:**  
    The problem involves operations under a modulus. The solution uses modular arithmetic properties, such as distributing modulo over addition, subtraction, and multiplication. It also uses the concept of modular inverse for division.
2. **Efficiency in Function Composition:**  
    Instead of applying each function in the sequence individually, the solution efficiently maintains the composite function's coefficient and constant term. This approach significantly reduces the computational complexity, especially when the number of functions in the sequence is large.
3. **Queue Operations:**  
    The solution uses a queue data structure to represent the sequence of functions, allowing efficient addition of new functions to the end and removal of the first function.

### Key Takeaways:

1. **Efficient Data Structure Usage:**  
    Choosing the right data structure (in this case, a queue) is crucial for efficiently solving problems involving sequential operations.
2. **Modular Arithmetic Proficiency:**  
    Understanding and correctly applying modular arithmetic is essential in many algorithmic problems, especially those involving large numbers or constraints.
3. **Cumulative Representation:**  
    Representing a sequence of operations (like function compositions) cumulatively can significantly optimize performance, reducing the need for repetitive calculations.
4. **Mathematical Insights:**  
    Leveraging mathematical properties, such as the modular inverse for division under modulus, can be a powerful tool in algorithm design.

In summary, the solution to the "Queue Operate All Composite" problem demonstrates efficient data structure usage, modular arithmetic proficiency, and the power of cumulative representation and mathematical insights in algorithmic problem-solving.

### Solution Explanation

From an observational standpoint, several cues in the problem statement and the nature of the operations involved could inspire a solution like the one provided. Here are some observations and thought processes that could lead you to a similar solution:

1. **Observation of Composite Functions:**  
    The problem involves creating a composite function from a sequence of linear functions. Observing that the composition of linear functions is still a linear function (i.e., the composition of \( ax + b \) and \( cx + d \) is still a linear function) is crucial. This means you can represent the entire sequence of functions by just two parameters (coefficient and constant), regardless of the number of functions in the sequence.
2. **Modular Arithmetic Constraints:**  
    The problem explicitly states that all operations are to be performed modulo 998244353. This is a common constraint in algorithmic problems to prevent overflow and ensure that the numbers stay within manageable bounds. Recognizing the need for modular arithmetic early on is key to implementing functions like `fastExp` and `modInv`.
3. **Efficiency Requirement:**  
    The constraint \( 1 \leq Q \leq 500,000 \) suggests that the solution must handle a large number of queries efficiently. This should immediately signal the need for an approach that avoids repetitive and unnecessary computations, especially since each query could potentially involve the entire sequence of functions.
4. **Queue Operations:**  
    The problem describes operations that involve adding to the end and removing from the beginning of a sequence. This is characteristic of a queue data structure. Noticing this should lead you to consider using a queue or a similar structure.
5. **Simplification of Operations:**  
    Observing that adding a function to the sequence corresponds to updating the global composite function and that removing a function requires you to "undo" its effect could lead you to maintain global coefficients for the composite function.
6. **Test Cases and Examples:**  
    Often, example inputs and outputs provided in the problem statement can give insights into how the solution should behave. Observing patterns in these examples can guide your thought process.
7. **Familiarity with Common Techniques:**  
    Having prior knowledge of common techniques such as fast exponentiation, modular inverse, and the properties of linear functions can significantly aid in recognizing when and how to apply them.

To implement a similar solution in future problems, you should:

- Carefully analyze the problem for patterns and constraints.
- Consider the implications of large input sizes on the efficiency of your solution.
- Think about how different operations affect the system as a whole.
- Look for ways to simplify or cumulatively represent the problem.
- Draw from a toolbox of common techniques and data structures.

By honing your observational skills, practicing pattern recognition, and building a strong foundation in algorithmic concepts, you'll be well-equipped to devise efficient solutions to similar problems in the future.