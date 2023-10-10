---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=989
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Ad-Hoc
  - Greedy
  - Observation
Key Takeaway: 1 + 2 +  3 + …. + N + N-1 + N-2 … 1 == N^2
---
### Solution already written

```Plain
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

float n;

int fx2(float alpha, float x){
    int c = (x*(x+1))/2 + ((x - alpha)*(x-alpha - 1))/2 + (alpha * (x - alpha));
    
    int ans = 2*x -alpha;
    
    if(c < n) ans += ceil((n-c)/x);
    return (ans);
}

void fx() {
    // Functionality for fx
    cin >> n;
    
    int t;
    cin >> t;
    
    
    
    while(t--){
        int sl;
        cin >> sl;
        
        float alpha = min(int(ceil((sqrt(n)))), sl);
        
        int x = 1;
        int ans = INT_MAX;
        
        while(ceil(x*(x+1))/2 + ceil((x-alpha) * (x-alpha +1))/2 <= n){
            
            // cout << "trying " << x << "...\n";
            
            if(x >= alpha){
                int v =  fx2(alpha, x);
                
                // if(sl == 1) v++;
                ans = min(ans, v);
            }
            
            
            x++;
        }
        
        cout << ans << endl;
    }
    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("race"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Code Explanation

This problem is an optimization problem where the objective is to minimize the time taken to complete a race of length `K` meters given certain constraints.

Let's break down the solution and explain each part:

1. **Variable definitions:** In the program, `n` is used to store the distance of the race. `fx2` is a function that calculates the total time taken given the value of `alpha` (the speed at which Bessie finishes the race) and `x` (the speed that Bessie reaches before decreasing). `fx` is the main function that handles the logic of reading the inputs and calculating the minimum time.
2. **Reading the inputs:** The program first reads the length of the race and the number of test cases. Then it reads the maximum speed for each test case in a loop.
3. **Calculating alpha:** For each test case, the program calculates the value of `alpha`. `alpha` is the speed that Bessie finishes the race at and is the minimum of two values: `floor((sqrt(float(1 + 8*n)) - 1)/2)` (the optimal speed for Bessie to run given the length of the race `n`) and `sl` (the maximum speed she is allowed to go).
4. **Iterating through the speeds:** The program then enters a loop where it iterates through possible speeds for Bessie (`x`), starting from 1 and increasing until the total distance covered when she increases to `x` speed, then decreases back to `alpha` speed, exceeds `n`.
5. **Calculating the minimum time:** If `x` is greater than or equal to `alpha`, it calculates the total time taken (`fx2(alpha, x)`) and updates the minimum time (`ans`) if necessary.
6. **Output:** After the loop finishes, the program outputs the minimum time for Bessie to finish the race.

This program uses mathematical insights to efficiently compute the minimum time, rather than explicitly simulating all possible sequences of Bessie's speed. Specifically, it exploits the fact that the optimal strategy is to increase speed as quickly as possible to a certain point, then decrease as necessary to meet the speed constraint. The mathematics of triangular numbers is used to quickly compute the total distance covered given a sequence of speeds.

Please, let me know if you need more details or if you have other questions about the program.

  

### Problems Encountered

```Plain
Can't figure out WA from TC5 onwards.

UPD1: Faulty formula use to calculate the upper_bound of the final (speed at last moment) speed of Bessie.

Wrongly Assumed that final speed was:

min(CEIL(sqrt(t_dist)), given_final_speed_limit)

when it should have been: 

min(floor((sqrt(float(1 + 8*t_dist)) - 1)/2), given_final_speed_limit)
```

  

### Found the right formula by:

- Using the Quadratic Formula,

- Quadratic Formula (ChatGPT)
    
    ```Plain
    The quadratic formula is used to solve a quadratic equation, which is an equation of the form ax^2 + bx + c = 0. The formula is:
    
    x = [ -b ± sqrt(b^2 - 4ac) ] / (2a)
    
    Here,
    "x" are the solutions of the equation,
    "a" is the coefficient of the x^2 term,
    "b" is the coefficient of the x term,
    "c" is the constant term,
    sqrt denotes the square root,
    and "±" means that there can be a positive solution and a negative solution.
    ```
    
- Saw that the distance covered in the best case (the case with no speed limit) was: 
    
    ```Plain
    x*(x+1)/2 = t_dist
    ```
    

- Simplifying that and applying the quadratic formula gives (for the higher root) gives upper_limit on the speed limit in the ideal case as: `(sqrt(1+8*t_dist)-1)/2`.

  

### Next tried solution (AC)

```Plain
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

float n;

int fx2(float alpha, float x){
    int c = (x*(x+1))/2 + ((x - alpha)*(x-alpha - 1))/2 + (alpha * (x - alpha));
    int ans = 2*x -alpha;
    if(c < n) ans += ceil((n-c)/x);
    return (ans);
}

void fx() {
    int t;
    cin >> n >> t;
    
    while(t--){
        int sl;
        cin >> sl;
        
        float alpha = min(int(floor((sqrt(float(1 + 8*n)) - 1)/2)), sl);
        
        int dist_covered = 0;
        int time_elapsed = 0;
        
        int curr_speed = 0;
        
        while(curr_speed < alpha or ((t-dist_covered) > curr_speed + 1 + (curr_speed-alpha)*alpha + ((curr_speed-alpha)*curr_speed-alpha+1)/2)){
            //can speed up...
            curr_speed++;
            dist_covered += curr_speed;
            time_elapsed++;
        }
        
        time_elapsed += curr_speed - 
    }
    
}

int main() {
    // Uncomment the following lines for file I/O
    // iofile(string("race"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Editorial Solution

```Plain
\#include <stdio.h>
 
int solve(int dist) {
  int minspeed;
  scanf("%d", &minspeed);
  int lhstravel = 0;
  int rhstravel = 0;
  int timeused = 0;
  for(int currspeed = 1;; currspeed++) {
    lhstravel += currspeed;
    timeused++;
    if(lhstravel + rhstravel >= dist) return timeused;
    if(currspeed >= minspeed) {
      rhstravel += currspeed;
      timeused++;
      if(lhstravel + rhstravel >= dist) return timeused;
    }
  }
}
 
int main() {
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);
  int k, n;
  scanf("%d %d", &k, &n);
  for(int i = 0; i < n; i++) {
    printf("%d\n", solve(k));
  }
}
```

  

### Editorial Explanation

(Analysis by Nick Wu)

Instead of trying to think about the problem in terms of minimizing the amount of time needed to accomplish a certain distance, we can flip the problem around - if Bessie can run for TT seconds and she wants to be running no more than XX meters per second at the end of the TT seconds, what is the furthest distance she can run?

Intuitively, we want her speed to be as high as possible throughout her run. If there were no speed cap at the end, Bessie would consistently increase her speed every second. Because of the presence of the speed cap though, Bessie may need to switch from speeding up to slowing down in order to meet the requirement of traveling no more than XX meters per second at the end.

As a result, for a given speed VV, Bessie will be traveling at that speed for at most 2 seconds - 1 second when she is speeding up, and one second when she is slowing down. We can therefore simulate Bessie's fastest possible run subject to her starting at 0 meters per second and ending with speed no more than XX meters per second as follows - we will track Bessie's distance traveled while she is speeding up and while she is slowing down. We will increment Bessie's speed starting at 1 meter per second until she has traveled enough distance to finish the race. Increment Bessie's distance covered while speeding up by this speed, and check if Bessie's total distance traveled exceeds KK meters. If the distance has not been exceeded, and Bessie could travel at this speed while slowing down, then increment Bessie's distance covered while slowing down by this speed, and perform the total distance check again.

The moment in time when Bessie's theoretical maximum distance traveled exceeds KK meters is the desired answer. It is worth noting that following this specific strategy of speeding up and slowing down may not actually meet the race conditions properly, but it is always possible to construct a strategy that covers exactly the given distance in the asserted time.

There is one final concern - is simulating this one second at a time fast enough? The worst possible case here is where Bessie needs to run 109109meters and she must end the race running at 1 meter per second. In this case, it takes 63245 seconds. Performing one thousand of these simulations should therefore run in time comfortably.

  

  

- Also, the derivation of the Quadratic Equation Part
    
      
    
    The expression `**floor((sqrt(float(1 + 8*n)) - 1)/2)**` calculates an optimal maximum speed for Bessie given the length of the race `**n**`, assuming there were no speed limit.
    
      
    
    Here's why:
    
    This expression is based on the formula for the sum of an arithmetic series. An arithmetic series is a sequence of numbers in which each term after the first is obtained by adding a constant difference to the preceding term.
    
      
    
    When Bessie is increasing her speed by 1 m/s each second, the distances she covers form an arithmetic series. For example, if she reaches a speed of 4 m/s, the distances she covers each second are: 1, 2, 3, 4. The sum of these distances is 10, which can also be calculated by the formula `**n*(n+1)/2**`, where `**n**` is the maximum speed.
    
      
    
    The formula `**n*(n+1)/2**` gives the sum of the first `**n**` natural numbers. By setting this equal to `**n**` (the length of the race) and solving for `**n**`, we get the quadratic equation `**n^2 + n - 2n = 0**`.
    
      
    
    To solve this quadratic equation, we can use the quadratic formula `**n = (-b ± sqrt(b^2 - 4ac))/(2a)**`, where `**a = 1**`, `**b = 1**`, and `**c = -2n**`. Plugging these values in, we get `**n = (-1 ± sqrt(1 + 8n))/2**`.
    
      
    
    However, we can't use the negative square root because speed can't be negative. Therefore, we use `**n = (-1 + sqrt(1 + 8n))/2**`. We also take the floor of this value to ensure it's an integer, as speed can't be a fraction.
    
      
    
    Thus, `**floor((sqrt(float(1 + 8*n)) - 1)/2)**` gives us the optimal maximum speed assuming there were no speed limit. In the program, it's then compared with the actual speed limit to get `**alpha**`, the speed that Bessie should aim for.