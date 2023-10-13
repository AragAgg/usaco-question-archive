---
Question Link: https://codeforces.com/contest/1881/problem/C
Problem Set:
  - Code Forces
  - DIV3C
Last edited time: 2023-10-13T20:23
Status: Nice Question
tags:
  - Brute-Force
  - Implementation
  - Matrix
Key Takeaway: Matrix Rotation is a powerful technique. For an element at pos (i, j) in a n*n square matrix it would go end up at (j, -i + n -1) after a clockwise rotation.Similarly we could come up with such position transformations for all type of semantic matrix manipulations. (anti-clockwise rotation and flipping and stuff).One more nice observation (or optimisation) about matrix rotation is that every time (out of the four) you rotate a cell, it goes from one quadrant to other.
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
    int n;
    cin >> n;
    
    vector<string>tab;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        tab.pb(s);
    }
    
    
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            vector<char>res = {tab[i][j], tab[j][(-i + n - 1)], tab[(-i + n - 1)][(-j + n -1)], tab[(-j + n -1)][-(-i + n - 1) + n-1]};
            
            
            sort(all(res));
            
            ans += res[3] - res[0];
            ans += res[3] - res[1];
            ans += res[3] - res[2];
        }
    }
    
    cout << (ans/4) << endl;
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

### Core Logic

The problem is to make the matrix a "perfect square" by rotating it 90 degrees clockwise and ensuring it remains the same. The solution provided takes a clever approach to minimize the number of operations needed to achieve this.

1. **Observation**: When the matrix is rotated 90 degrees, each element at position \((i, j)\) in the original matrix will be swapped with \((j, n-i-1)\) in the rotated matrix. Similarly, the element at \((j, n-i-1)\) will be swapped with \((n-i-1, n-j-1)\), and so on, forming a cycle of 4 elements.
2. **Key Insight**: To make the matrix a perfect square, all 4 elements in the cycle should be the same after rotation. Therefore, the solution focuses on ensuring that all 4 elements in each cycle are equal with the minimum number of operations.
3. **Calculating Minimum Operations**: For each cycle of 4 elements, the solution calculates the minimum number of operations needed to make all 4 elements equal. It does this by finding the maximum character (in terms of ASCII value) among the 4 and then calculating the difference between this maximum character and each of the other 3 characters in the cycle. The sum of these differences is the minimum number of operations needed to make all 4 characters equal.

### Detailed Breakdown

- **Input Reading**: The matrix is read into a 2D vector of strings, `tab`.
- **Iterating Through Each Element**: The solution iterates through each element of the matrix using two nested loops.
- **Finding the Cycle**: For each element at position \((i, j)\), it finds the other 3 elements in its cycle by calculating their positions after 90-degree rotations. These 4 elements are stored in the `res` vector.
- **Calculating Operations**: The `res` vector is sorted, and then the differences between the maximum character and the other 3 characters are calculated and added to the `ans` variable.
- **Output**: Finally, `ans/4` is output, as each operation was counted 4 times (once for each element in the cycle).

### Key Takeaways

- **Efficient Calculation**: The solution efficiently calculates the minimum operations without actually rotating the matrix by understanding the positions of elements after rotation.
- **Minimizing Operations**: By focusing on making all elements in each cycle equal, the solution ensures the minimum number of operations.
- **Mathematical Insight**: The solution leverages mathematical insight into the positions of elements after rotation to solve the problem without actual rotation.
- **Optimization**: The solution avoids unnecessary operations and calculations, ensuring it runs efficiently even for larger matrices.

### Final Thoughts

This solution is a great example of how mathematical insights and understanding the problem can lead to optimized and efficient solutions. It avoids unnecessary matrix rotations and directly calculates the minimum operations needed, showcasing the power of analytical thinking in problem-solving.

### Solution Inspiration

### Observational Insights:

1. **Symmetry and Rotation:**
    - **Observation**: The problem talks about making the matrix identical even after a 90-degree rotation, which directly points towards a symmetric structure.
    - **Insight**: This should lead you to think about how elements are positioned symmetrically in a matrix and how they move upon rotation.
2. **Character Changes:**
    - **Observation**: You can change characters to their subsequent characters in the alphabet, implying a cost associated with changing one character to another.
    - **Insight**: This should hint towards a solution where you minimize this cost by choosing optimal characters to change into, which is often the maximum or minimum in a set of choices.

### Implementational Strategy:

1. **Handling Rotations Without Actual Rotations:**
    - **Observation**: Actual rotations or creating new matrices for each rotation can be computationally expensive.
    - **Insight**: You might realize that you don’t actually need to rotate the matrix. You can find which elements would swap places upon rotation and compare them directly.
2. **Minimizing Changes:**
    - **Observation**: The problem asks for the minimum number of operations to achieve the goal.
    - **Insight**: This should lead you to think about how you can minimize the changes. A common strategy, as used in the solution, is to change all elements to be the same as the largest one in a set, minimizing the total “distance” or changes needed.
3. **Iterating Through the Matrix:**
    - **Observation**: The matrix is \( n \times n \) and \( n \) is even.
    - **Insight**: This should hint that you can iterate through the matrix and compare each element with its corresponding element upon rotation. Since \( n \) is even, you don’t have to worry about a center element that doesn’t move upon rotation.

### Problem-Solving Approach:

1. **Breaking Down the Problem:**
    - **Observation**: The problem can be broken down into smaller parts: finding corresponding elements, calculating the cost of changes, and ensuring symmetry.
    - **Insight**: This should inspire a solution where you handle these parts separately, making the problem more manageable.
2. **Optimizing Operations:**
    - **Observation**: The solution requires optimizing the number of operations.
    - **Insight**: This should lead you to think about how you can perform operations efficiently and avoid unnecessary calculations, like avoiding actual rotations and minimizing character changes.

### Final Thoughts:

- **Practice**: The more problems you solve, the more patterns you’ll recognize in new problems.
- **Backtracking**: If a straightforward solution seems too complex or computationally expensive, think about how you can achieve the same results with fewer or simpler operations.
- **Divide and Conquer**: Breaking down a problem into smaller, more manageable parts can often provide clearer insights into a solution.
- **Optimization Insight**: Always keep an eye out for what needs to be optimized or minimized, as this often provides a clue towards the solution.

Remember, competitive programming and problem-solving are as much about practicing and recognizing patterns as they are about knowing algorithms and data structures. So, keep practicing and reflecting on problems and solutions to build your intuition and problem-solving skills!