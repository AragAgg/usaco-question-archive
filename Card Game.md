---
Question Link: https://codeforces.com/contest/1882/problem/C
Problem Set:
  - Code Forces
  - DIV2C
Last edited time: 2023-10-10T13:12
Status: Nice Question
tags:
  - Dynamic-Programming
  - Game
  - Greedy
  - Math
  - Observation
What's up: Solved without DP.
Key Takeaway: "The basic idea is to take action (remove the curr or take it) at EVERY step, and then offset it later on. The answer is the best of all curr(S) [SEE: Explaination]"
---
### Solution History

- Code 1 (just copy paste) `[WA on TC2]`
    
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
    \#define ll long long
    
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
    
    void fx() {
        int n;
        cin >> n;
        
        vi tab(n);
        for(auto &i: tab) cin >> i;
        
        bool isEven = (n%2?false:true);
        
        stack<int>rem;
        ll remSum = 0;
        ll ans = 0;
        
        for(int i = n-1; i >= 0; i--){
            // cout << "remsum: " << remSum << endl;
            if(!isEven){
                if(tab[i] >= 0){
                    // cout << "c1 " << endl;
                    ans += tab[i];
                    ans += remSum;
                    // rem.clear();
                    while(!rem.empty()) rem.pop();
                }else{
                    // cout << "c2 " << endl;
                    if(abs(tab[i]) < remSum){
                        ans += remSum + tab[i];
                        remSum = -tab[i];
                        rem.push(-tab[i]);
                    }
                }
            }else{
                if(tab[i] >= 0){
                    // cout << "c3 " << endl;
                    remSum += tab[i];
                    rem.push(tab[i]);
                }else{
                    // cout << "c4 " << endl;
                    ans += remSum;
                    while(!rem.empty()) rem.pop();
                }
            }
            
            isEven = !isEven;
        }
        
        if(rem.size()) ans += remSum - rem.top();
        
        cout << ans << endl;
        
        
    }
    
    int main() {
        // Uncomment the following lines for file I/O
        // iofile(string("hello"));
        
        // Uncomment the following lines for multiple test cases
        int t; cin >> t;
        while(t--) fx();
        
        // Single test case
        // fx();
        
        return 0;
    }
    ```
    
- Code 2 (Working)
    
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
    \#define ll long long
    
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
    
    void fx() {
        // Functionality for fx
        
        //work backwards in the deck of cards, as taking the ith card doesn't affect the parity of and of 1...i-1th card...
        int n;
        cin >> n;
        
        vector<ll> tab(n);
        
        for(auto &i: tab) cin >> i;
        
        ll rem = 0;
        ll curr = 0;
        ll ans = 0;
        
        bool isEven = ((n%2)?false:true);
        
        for(int i = n-1; i >= 0; i--){
            if(isEven){
                // take action
                curr += rem;
                rem = 0;
                
                if(tab[i] > 0) rem = tab[i]; // if this was a positive card, make sure to take it if we take an action in future
            }else{
                //take action
                curr += rem + tab[i];
                rem = 0;
                
                if(tab[i] < 0) rem = -tab[i]; //if this was a negative card, we took it, so if we take an action in future, offset it.
            }
            
            isEven = !isEven;
            
            ans = max(ans, curr); //ans is max of all curr, as we might leave the game "early"
        }
        
        cout << ans << endl;
    }
    
    int main() {
        // Uncomment the following lines for file I/O
        // iofile(string("hello"));
        
        // Uncomment the following lines for multiple test cases
        int t; cin >> t;
        while(t--) fx();
        
        // Single test case
        // fx();
        
        return 0;
    }
    ```
    

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
\#define ll long long

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

void fx() {
    // Functionality for fx
    
    //work backwards in the deck of cards, as taking the ith card doesn't affect the parity of and of 1...i-1th card...
    int n;
    cin >> n;
    
    vector<ll> tab(n);
    
    for(auto &i: tab) cin >> i;
    
    ll rem = 0;
    ll curr = 0;
    ll ans = 0;
    
    bool isEven = ((n%2)?false:true);
    
    for(int i = n-1; i >= 0; i--){
        if(isEven){
            // take action
            curr += rem;
            rem = 0;
            
            if(tab[i] > 0) rem = tab[i]; // if this was a positive card, make sure to take it if we take an action in future
        }else{
            //take action
            curr += rem + tab[i];
            rem = 0;
            
            if(tab[i] < 0) rem = -tab[i]; //if this was a negative card, we took it, so if we take an action in future, offset it.
        }
        
        isEven = !isEven;
        
        ans = max(ans, curr); //ans is max of all curr, as we might leave the game "early"
    }
    
    cout << ans << endl;
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("hello"));
    
    // Uncomment the following lines for multiple test cases
    int t; cin >> t;
    while(t--) fx();
    
    // Single test case
    // fx();
    
    return 0;
}
```

### Solution Explanation

**This solution is a clever approach to the problem, focusing on working backwards through the deck of cards.** The main insight is that taking the i-th card doesn't affect the parity of any of the 1 to (i-1)-th cards. This observation is crucial as it allows the algorithm to make decisions based on future knowledge, which wouldn't be possible if iterating from the beginning to the end.

### Core Logic:

1. **Working Backwards:** The algorithm starts from the end of the array and moves to the start. This reverse iteration allows it to make decisions based on future cards, optimizing the score effectively.
2. **Handling Parity:** The algorithm keeps track of whether the current index is even or odd. This is used to decide whether to add the card value to the score or not.
3. **Accumulating Values:**
    - If the current index is even, the algorithm adds any accumulated positive values to the current score and resets the accumulation. If the current card has a positive value, it is stored for future accumulation.
    - If the current index is odd, the algorithm adds the card value and any accumulated negative values to the current score and resets the accumulation. If the current card has a negative value, its absolute value is stored for future accumulation.
4. **Maximizing Score:** At each step, the algorithm updates the answer to be the maximum of the current score and the previously calculated maximum score. This ensures that the maximum possible score is always kept as the answer.

### Observations and Insights:

- **Parity Insight:** The parity of the index plays a crucial role in decision making. This insight is used to decide whether to add or ignore the card value at each step.
- **Future Knowledge:** Working backwards allows the algorithm to use future knowledge to make optimal decisions at each step.
- **Accumulation:** Storing accumulated positive and negative values separately allows the algorithm to effectively add or offset values, optimizing the score.

### Key Takeaways:

- **Reverse Iteration:** Sometimes iterating backwards through a dataset can provide additional insights or simplify the problem-solving process.
- **Parity Consideration:** Considering the parity of indices or values can be a valuable tool in problem-solving, especially in problems involving sequences or arrays.
- **Dynamic Decision Making:** The algorithm dynamically makes decisions at each step based on current and future values, showcasing the power of dynamic decision making in algorithm design.

In summary, this solution effectively utilizes reverse iteration, parity consideration, and dynamic decision making to solve the problem, providing a clear example of these concepts in action.

### Solution Inspiration

**Observations:**

1. **Effect of Removing Cards:**
    - Notice that removing a card affects the index of all cards that come after it. This is a hint that working backward might be a good approach since it avoids this re-indexing issue.
    - Observing that removing cards from the end does not affect the indices of the remaining cards could inspire the backward iteration approach.
2. **Parity:**
    - The problem has a clear distinction between odd and even indices, which affects the actions you can take. This should lead you to think about how to handle these two cases differently in your solution.
    - Observing that the parity of the indices plays a role in decision making could lead you to consider keeping track of parity in your solution.
3. **Score Calculation:**
    - The goal is to maximize the score, and you have the freedom to choose which cards to remove. This should lead you to think about how to make decisions that will maximize your score at each step.
    - Observing that you can choose to end the game at any time could inspire the approach of keeping track of the maximum score at each step.

**Thought Process:**

1. **Working Backwards:**
    - Ask yourself: “What if I start from the end? Will it make the problem easier to solve?”
    - Consider how working backward affects the re-indexing of cards and how it allows you to make decisions based on future knowledge.
2. **Handling Different Cases:**
    - Think about how to handle odd and even indices differently.
    - Consider keeping track of accumulated positive and negative values separately to optimize the score.
3. **Dynamic Decision Making:**
    - Think about how to make decisions at each step to maximize the final score.
    - Consider keeping track of the maximum score at each step and updating it dynamically.

**Tips for Future Problems:**

1. **Consider Different Iteration Directions:**
    - Don’t limit yourself to forward iteration. Consider how iterating backward or in other directions might simplify the problem.
2. **Focus on the Goal:**
    - Keep the goal of the problem (maximizing the score) in mind and think about how to make decisions at each step to achieve this goal.
3. **Pay Attention to Details:**
    - Pay close attention to the problem constraints and details. Small details like the distinction between odd and even indices can play a crucial role in the solution.
4. **Think Dynamically:**
    - Consider using dynamic programming or greedy strategies to make decisions at each step based on current and future values.

By making these observations and following this thought process, you can increase your chances of coming up with similar innovative solutions in future problems.

### Editorial unofficial

> [!info] Codeforces Round 899 Div 2 | Video Solutions - A to D | by Ankit | TLE Eliminators  
> Here are the video solutions in the form of a post-contest discussion for problems A, B, C, D of Codeforces Educational Round 155 .  
> [https://www.youtube.com/watch?v=OHIx_vjBTxM&t=1742](https://www.youtube.com/watch?v=OHIx_vjBTxM&t=1742)