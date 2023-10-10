---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=941#
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Dependencies
  - Graph
  - Tree
Key Takeaway: Simplify the Question Requirements
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
void yes() { cout << "yes" << '\n'; }
void no() { cout << "no" << '\n'; }

int propsCounter = 0;
unordered_map<string, int>props;
vector<unordered_set<int>>deps; //dependencies of dependencies...
vector<unordered_set<int>>tracks; //dependencies of a certian evolution track

bool check(int a){
    
    for(auto d: tracks[a]){
        for(auto &dep : deps[d]){
            if(!tracks[a].count(dep)) return false;
        }
    }
    
    return true;
    
    // while(!q.empty()){
        
    //     int curr = q.front();
    //     q.pop();
        
    //     if(ok.count(curr)) continue;
        
    //     bool flag = true;
    //     for(auto &dep: deps[curr]){
    //         if(!ok.count(dep)){
    //             q.push(dep);
    //             bool flag = false;
                
    //         }
    //     }
        
    //     if(flag){
    //         ok.insert(curr);
    //     }else{
    //         q.push(curr);
    //     }
        
    // }
}

void fx() {
    int n;
    cin >> n;
    
    tracks.assign(n, {});
    
    for(int i = 0; i < n; i++){
        
        int features; cin >> features;
        
        for(int j = 0; j < features; j++){
            string feature; cin >> feature;
            
            if(!props.count(feature)){
                props.insert({feature, propsCounter++});
            }
            
            tracks[i].insert(props[feature]);
        }
    }
    
    deps.assign(propsCounter, {});
    
    for(int a = 0; a < n-1; a++){
        for(int b = a+1; b < n; b++){
            //check for contradictions in a's dependencies
            //check for contradictions in b's dependencies
            
            if(!check(a)) {
                no();
                return;
            };
            if(!check(b)){
                no();
                return;
            };
            
            unordered_set<int>similar;
            
            for(auto p : tracks[a]) if(tracks[b].count(p)) similar.insert(p);
                
            for(auto p : tracks[a]){
                if(!similar.count(p)){
                    for(auto dep: similar) deps[p].insert(dep);
                }
            }
            
            for(auto p : tracks[b]){
                if(!similar.count(p)){
                    for(auto dep: similar) deps[p].insert(dep);
                }
            }
            
            
        }
    }
    
    yes();
}

int main() {
    // Uncomment the following lines for file I/O
    iofile(string("evolution"));
    
    // Uncomment the following lines for multiple test cases
    // int t; cin >> t;
    // while(t--) fx();
    
    // Single test case
    fx();
    
    return 0;
}
```

### Idea behind the solution

This C++ solution follows a graph-theoretical approach to determine if a proper evolutionary tree can be built based on the given sub-populations. Let's break down the code and explain how it works:

  

- _**check(int a):**_
    - This function checks if the dependencies of a given sub-population's properties are satisfied. If a sub-population has a property, then all of its dependencies (ancestral properties) must be present in that sub-population.
- _**fx():**_
    - The main logic of the program is contained within this function.
    - First, the program reads `n` which is the number of sub-populations.
    - Then, for each sub-population, the program reads its properties and updates the `tracks`.
    - After reading all the properties for all sub-populations, the program constructs dependencies among the properties based on the shared and unique properties among pairs of sub-populations.
    - If there is a contradiction in the dependencies, the program outputs "no" and returns. If all pairs of sub-populations are checked without contradiction, the program outputs "yes".

  

- **How the Solution Works:**
    
    1. For every pair of sub-populations `a` and `b`:
        - Identify properties/features that are common between them (stored in `similar`).
        - For every property in `a` not in `similar`, add the properties from `similar` as its dependencies because it's a newer evolution.
        - Do the same for every property in `b`.
        - After setting dependencies, check the validity of the dependencies for both `a` and `b` using the `check()` function. If there's a contradiction, print "no" and return.
    2. If all pairs are processed without any contradiction, print "yes".
    
    The code is designed to handle the described problem efficiently by using unordered sets for faster lookups and inserts and by avoiding redundant checks.
    

  

  

### An optimization over this solution

  

In this problem, we're trying to construct an evolutionary tree based on properties (features) of sub-populations. Once we gather all information about dependencies among properties from all pairs of sub-populations, the dependencies should fully represent the hierarchical evolutionary relationships among properties.

  

- Now, let's analyze the code's logic regarding contradictions:
    
    1. Dependencies are set based on shared and unique properties among pairs of sub-populations. Specifically, for every property in a sub-population not in `similar` (the shared features with another sub-population), the code assumes that property evolved after the shared features. Therefore, it adds the shared properties as dependencies of that newer property.
    2. Given these dependencies, it's crucial to ensure that the sub-populations respect these evolutionary relationships. This is where the `check` function comes into play. It checks if a sub-population, which has a certain property, also has all the ancestral properties (dependencies) for that property.
    3. When constructing the dependencies among properties, if there's an inherent contradiction in the input data, it will manifest in the dependency graph. The `check` function will catch this.
    4. The reason we only need to check once for every sub-population after constructing the entire dependency tree is that any violation of the proper evolutionary tree would have been captured in the dependencies. Thus, a single check against the fully-formed dependencies is sufficient to verify the correctness of the entire structure.
    
      
    

  

  

### A more streamlined solution (from: Editorial)

```C++
\#include <iostream>
\#include <fstream>
\#include <vector>
using namespace std;
 
int N;
vector<string> characteristics[25];
vector<string> all_characteristics;
 
// Do two sets "cross" -- I.e., are there elements in A, B, and A intersect B?
bool crossing(int a, int b)
{
  int A=0, B=0, AB=0;
  for (int i=0; i<N; i++) {
    vector<string> &v = characteristics[i];
    bool has_a = false, has_b = false;
    for (int j=0; j<v.size(); j++) {
      if (v[j]==all_characteristics[a]) has_a = true;
      if (v[j]==all_characteristics[b]) has_b = true;
    }
    if (has_a && has_b) AB++;
    else if (has_a) A++;
    else if (has_b) B++;
  }
  return AB>0 && A>0 && B>0;
}
 
int main(void)
{
  ifstream fin ("evolution.in");
  fin >> N;
  string s;
  for (int i=0; i<N; i++) {
    int K;
    fin >> K;
    for (int j=0; j<K; j++) {
      fin >> s;
      characteristics[i].push_back(s);
      bool found = false;
      for (int k=0; k<all_characteristics.size(); k++)
	if (all_characteristics[k] == s) found = true;
      if (!found) all_characteristics.push_back(s);
    }
  }
    
  int M = all_characteristics.size();
  bool ok = true;
  for (int a=0; a<M; a++)
    for (int b=a+1; b<M; b++)
      if (crossing(a, b)) ok = false;
 
  ofstream fout ("evolution.out");
  if (ok) fout << "yes\n";
  else fout << "no\n";
  return 0;
}
```

### Idea behind this solution

This solution adopts a simpler and more direct approach than the previous one. It primarily focuses on pairs of characteristics to determine if they follow the rules that ensure an evolutionarily proper tree.

  

1. **Checking for Proper Tree Structure**:
    
    - Iterate through every unique pair of characteristics from the `all_chars` vector. For each pair, (let's call the characteristics a and b), the code checks if there exists:
        1. A sub-population having only characteristic `a`.
        2. Another sub-population having only characteristic `b`.
        3. A third sub-population having both characteristics `a` and `b`.
    - If all three types of sub-populations exist for any pair of characteristics, then it violates the rules of the evolutionary tree, because it means that the characteristics evolved independently and then combined, which is not allowed. As a result, the program will output "no".
    - If no such violations are found after examining all pairs of characteristics, it implies that the sub-populations can be organized into an evolutionarily proper tree. The program will then output "yes".
    
      
    

This solution cleverly reduces the problem to examining pairs of characteristics. It understands that if the rules hold true for all pairs, they will hold true for the overall tree structure. This is much simpler than building the actual tree or dependency graph, making the solution efficient and easier to understand.

  

The core insight that drives this solution is: If you ever find a situation where two features (`a` and `b`) appear separately in different sub-populations and then appear together in another sub-population, then they violate the rules of evolutionary progression. This insight simplifies the problem to just checking pairs of features rather than analyzing all combinations or building full dependency structures.

  

  

### A more intuitive solution (applicable to real world problems)

---

### Idea: **Evolutionary Trait Insight**

### **Preliminary Insight:**

- Consider two traits A and B.
    - **Trait A:** Appears in 4 populations.
    - **Trait B:** Appears in 17 populations.
- Implication:
    - The edge introducing Trait A (+A) cannot precede the edge introducing Trait B (+B) in the evolutionary tree.
    - Reason: If it did, every population with Trait B would also possess Trait A, which contradicts our observation.
    - General Principle: Traits found in larger sets of populations appear higher up in the tree. The root split is based on the most prevalent trait.

### **Tree Construction Method:**

1. **Initial Split:** Divide based on the trait with the highest population count.
2. **Subsequent Splits:** For the resulting groups, continue splitting based on the next most prevalent trait.

- **Handling Ties:** If two traits have equal population counts:
    - If they're disjoint, pick either.
    - If they overlap, a choice may lead to issues later. If they have the same size, they can't be nested.
    - Note: If a trait is added in two different places in the tree, a valid tree is unattainable.

### **Analogy: Sorting Binary Numbers**

- **Goal:** Sort 3-digit binary numbers.
    - First, sort by the leading digit.
        
        ```Plain
        010
        000
        011
        ---
        110
        100
        101
        ```
        
    - Next, sort within each block using the second digit.
        
        ```Plain
        000
        ---
        011
        010
        ---
        100
        101
        ---
        110
        ```
        
    - Lastly, sort by the least significant digit.
- **Relation to Populations and Traits:**
    - Each population is represented as a binary number, with the presence (1) or absence (0) of each trait.
        
        ```Plain
                TraitA TraitB TraitC TraitD TraitE...
        Population1    1      0      0      1      0
        Population2    0      1      1      0      1
        Population3    1      1      0      0      0
        Population4    0      1      1      0      1
        ```
        
    - Sorting these binary numbers is analogous to the tree construction method.
    - Sorting by leading digits separates populations based on the most prevalent trait.

### **Real-world Relevance:**

- The problem maps directly to challenges faced by evolutionary biologists.
- The constructed tree represents evolutionary pathways and is termed a "phylogenetic tree."

  

  

- Official Editorial
    
    [http://www.usaco.org/current/data/sol_evolution_bronze_open19.html](http://www.usaco.org/current/data/sol_evolution_bronze_open19.html)
    
- Note that
    
    The idea used in the first solution is more general and extendable to more versatile variants of the question which the editorial solution is more streamlined to suit the exact question construct.