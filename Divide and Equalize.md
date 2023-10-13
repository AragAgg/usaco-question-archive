---
Question Link: https://codeforces.com/contest/1881/problem/D
Problem Set:
  - Code Forces
  - DIV3D
Last edited time: 2023-10-13T20:50
Status: Nice Question
tags:
  - Math
  - Number-Theory
What's up: Solved. The most important observation needed here is that the operation described in the question is basically that we can take any prime_factor of any element the array and transfer it to any other element.
Key Takeaway: When using the Sieve Technique (and you want to store the number of each individual factors), consider using a map, not an array, because using an array, even for a factorising a number as small as 1e6 would require your array to be at least 1e6 in size ( if the number is a prime). Using a map would generally more than enough make up for the time lost in overhead.One more important observation (but slightly more trivial one) is the fact that if two numbers are equal, their prime_factorisations are also equal.
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

map<int, ll>facts;

void primeFactors(int n) 
{ 
    while ((n % 2 == 0) and (n > 0)) 
    { 
        facts[2]++;
        n = n/2; 
    } 
    
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while ((n % i == 0)) 
        { 
            facts[i]++;
            n = n/i; 
        } 
    } 
 
    if(n > 1)facts[n]++;
} 


void fx() {
    facts.clear();
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        
        primeFactors(t);
    }
    
    for(auto &i: facts){
        if(i.s%n != 0){
            no();
            return;
        }
    }
    
    yes();
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

### Core Logic:

1. **Prime Factorization:**  
    The solution uses the concept of prime factorization. For every number in the array, it finds its prime factors and keeps a count of each prime factor in a map named `facts`.
2. **Checking for Equalization:**  
    After processing all numbers in the array, it checks whether the count of each prime factor is divisible by `n` (the size of the array). If it is, it implies that the operations can be performed in such a way that all numbers can be made equal, otherwise not.

### Observations and Insights:

- **Common Factors:**  
    The key observation here is that if all numbers in the array can be made equal, then the prime factors of all numbers should be distributable evenly among all elements. This is because when we choose a divisor `x` for `a_i` and multiply it to `a_j`, the prime factors of `x` are distributed between `a_i` and `a_j`.
- **Distribution of Prime Factors:**  
    If the total count of a prime factor (say `p`) in all numbers is `k`, and if `k` is divisible by `n`, then we can distribute `k/n` count of the prime factor `p` to each number in the array through a series of operations. If `k` is not divisible by `n`, then it's impossible to distribute `p` evenly among all numbers.

### Explanation of Code:

- **Function** `**primeFactors(int n)**`**:**  
    This function takes an integer `n` and populates the `facts` map with its prime factors and their respective counts. It uses a standard algorithm to find the prime factors: divide by 2 until it's odd, then try to divide by odd numbers starting from 3.
- **Function** `**fx()**`**:**
    - `facts.clear()`: Clears the map to ensure no previous data affects the current test case.
    - It reads the size `n` of the array and then reads `n` numbers, finding their prime factors using `primeFactors(t)`.
    - It then iterates through the `facts` map and checks whether the count of each prime factor is divisible by `n`. If any are not, it outputs "NO" and returns. If all are divisible, it outputs "YES".
- **Function** `**main()**`**:**
    - Reads the number of test cases `t` and then runs `fx()` for each test case.

### Key Takeaways:

- **Factorization and Distribution:**  
    Understanding how the prime factors of numbers can be distributed among other numbers is crucial. The problem essentially revolves around ensuring that the prime factors can be evenly distributed among all numbers.
- **Efficient Factorization:**  
    Efficiently finding the prime factors is key to solving this problem within time limits. The solution uses a standard sqrt(n) approach which is quite efficient.
- **Count and Check:**  
    Keeping a count of prime factors and then checking their divisibility provides a clear and concise solution to the problem.

### Conclusion:

The solution cleverly uses the principle of prime factorization and distribution to check the possibility of equalizing all numbers in the array. It doesn’t try to perform the operations explicitly but uses mathematical insights to determine the possibility, which is a valuable approach in competitive programming.

### Solution Inspiration

### Observational Insights:

1. **Operations on Pairs:**
    - The problem allows you to select a pair of numbers and perform operations on them. This might hint at the relationship between the numbers in the array and how they can influence each other.
2. **Divisor and Multiplier:**
    - The operation involves choosing a divisor `x` for one number and multiplying the other number by the same `x`. This implies that the prime factors of the chosen `x` will be distributed between the two numbers.
3. **Equalizing Numbers:**
    - The goal is to make all numbers equal. This implies that all numbers should have the same prime factors, and the power of each prime factor should be the same across all numbers.

### Key Observations:

1. **Prime Factor Distribution:**
    - When you divide one number and multiply another by the same value, you’re essentially redistributing the prime factors between them. This is a key observation that could lead you to think about how the prime factors are distributed among all numbers in the array.
2. **Equal Prime Factor Powers:**
    - For all numbers to be equal, they must have the same prime factors raised to the same power. This means that the total count of each prime factor must be divisible by `n` to be distributed evenly among all `n` numbers.
3. **Test Small Cases:**
    - Trying out small test cases and observing how the prime factors change with each operation might reveal that the solution revolves around the distribution of prime factors.

### Strategies for Similar Problems:

1. **Identify Key Elements:**
    - Identify the key elements that are being manipulated in the problem (in this case, the numbers in the array through multiplication and division).
2. **Understand Relationships:**
    - Understand the relationship and interaction between these elements (here, how prime factors are distributed among numbers).
3. **Manipulation of Key Elements:**
    - Understand how you can manipulate these elements to achieve the desired outcome (making all numbers equal by ensuring they have the same prime factors).
4. **Mathematical Properties:**
    - Consider mathematical properties related to the operations involved. Here, understanding the properties of prime factorization and how multiplication/division affects them is crucial.
5. **Simplify the Problem:**
    - Try to simplify the problem. Instead of trying to perform operations to make numbers equal, think about the end state (all numbers having the same prime factors) and work backward to see if it’s achievable.
6. **Efficiency:**
    - Always consider the most efficient way to perform calculations. For example, using a sqrt(n) approach for prime factorization instead of trying all numbers up to `n`.

### Conclusion:

The inspiration for such a solution comes from understanding the mathematical properties of the operations involved and observing how they affect the elements in the problem. Always try to observe patterns, especially in smaller or simpler test cases, and consider how you might generalize these patterns to a solution. And remember, practice is key to recognizing and applying these patterns in competitive programming!