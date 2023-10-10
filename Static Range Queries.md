---
Question Link: https://codeforces.com/gym/102951/problem/D
Problem Set:
  - Code Forces
Last edited time: 2023-10-10T13:13
Status: Solved
tags:
  - Coordinate-Compression
  - Implementation
  - Observation
  - Prefix-Sums
  - Segment-Tree
What's up: "Time Spent: 6+ Hours"
Key Takeaway: A lot of the times when range update operations are not dynamic (they can be performed in an arbitrary order, the problem could be solved using prefix sum).A really hard question is basically a combination of two or more simpler problems.
---
### Solution (without coordinate compression) [couldn’t figure out why the segment tree is not working]

  

```C++
//after the template...

long long maxn = 100000000;

// vi arr(maxn, 0);
vi tab(4*maxn, 0);

void update(int node, int left, int right, int start, int end, int value){
    if(left > end or right < start) return;
    
    if(left == right){ tab[node] += value; return;}
    
    int mid = left + (right - left)/2;
    update(2*node +1, left, mid, start, end, value);
    update(2*node +2, mid+1, right, start, end, value);
    
    tab[node] = tab[2*node +1] + tab[2*node +2];
}

long long query(int node, int left, int right, int start, int end){
    if(left > end or right < start) return 0;
    
    if(left >= start and right <= end) return tab[node];
    
    int mid = left + (right - left)/2;
    
    // return (query(2*node+1, left, mid, start, end) + query(2*node +2, mid+1, right, start, end));
    // return query(2*node+1, left, mid, start, end) + query(2*node +2, mid+1, right, start, end);
}

void fx() {
    // Functionality for fx
    int n, q;
    cin >> n >> q;
    
    while(n--){
        int l, r, v;
        cin >> l >> r >> v;
        
        update(0, 0, 100000000-1, l, r, v);
    }
    
    while(q--){
        int l, r;
        cin >> l >> r;
        
        r--;
        
        cout << query(0, 0, 100000000-1, l, r) << endl;
    }
    
}

//the remaining template...
```

### Solution (with prefix sum backed range queries) [couldn’t figure out how to manage offset while forming the prefix sum array]

```C++
struct update{
    int l, r, delta;
};

struct query{
    int l, r;
};

map<int, int> mp;

vector<update> updates;
vector<query> queries;

void fx() {
    // Functionality for fx
    int n, q;
    cin >> n >> q;
    
    while(n--){
        update u;
        cin >> u.l >> u.r >> u.delta;
        
        mp[u.l] = 0;
        mp[u.r] = 0;
        
        updates.pb(u);
    }
    
    while(q--){
        query q;
        cin >> q.l >> q.r;
        
        mp[q.l] = 0;
        mp[q.r] = 0;
        
        queries.pb(q);
    }
    
    int counter = 0;
    
    umii revmp;
    for(auto &m: mp){ m.s = counter++; revmp[m.s] = m.f;}
    
    for(auto &m: mp) cerr << m.f << " -> " << m.s << endl;
    
    // for(auto &update : updates){
    //     update.l = mp[update.l];
    //     update.r = mp[update.r];
    // }
    
    // for(auto &query : queries){
    //     query.l = mp[query.l];
    //     query.r = mp[query.r];
    // }
    
    vi ground(counter+1, 0);
    
    for(auto &u: updates){
        ground[u.l] += u.delta;
        ground[u.r] -= u.delta;
    }
    
    int offset = ground[0];
    
    for(int i = 1; i < ground.size(); i++){
        // offset += ground[i];
        // ground[i] = (ground[i-1] + offset*(revmp[i] - revmp[i-1]));
        // cerr << offset*(revmp[i] - revmp[i-1]) << endl;
        
        int temp = ground[i];
        ground[i] += ground[i-1] + offset*(revmp[i+1] - revmp[i]);
        offset += temp;
        
    }
    
    debug_vector(ground);
    for(auto &q: queries){
        int sum = ground[q.r-1];
        sum -= ground[q.l-1];
        
        cout << sum << endl;
    }
    
    
    
}
```

### Solution (AC) [Using coordinate compression + prefix sum]

```C++
struct update{
    int l, r, delta;
};

struct query{
    int l, r;
};

vector<update>updates;
vector<query>queries;

map<int, int>mp;


void fx() {
    // Functionality for fx
    int n, q;
    cin >> n >> q;
    
    while(n--){
        update u;
        cin >> u.l >> u.r >> u.delta;
        
        mp[u.l+1] = 0;
        mp[u.r+1] = 0;
        
        updates.pb(u);
    }
    
    while(q--){
        query q;
        cin >> q.l >> q.r;
        
        mp[q.l] = 0;
        mp[q.r] = 0;
        
        queries.pb(q);
    }
    
    int counter = 1;
    
    umii revmp;
    
    for(auto &i: mp){ i.s = counter++; revmp[i.s] = i.f;}
    
    vector<long long> tab(counter, 0);
    
    for(auto &u: updates){
        tab[mp[u.l+1]] += u.delta;
        tab[mp[u.r+1]] -= u.delta;
    }
    
    long long offset = 0;
    
    for(int i = 1; i < tab.size(); i++){
        long long temp = tab[i];
        tab[i] += tab[i-1] + offset*(revmp[i] - revmp[i-1]); // try i+1, i;
        offset += temp;
    }
    
    for(auto &q: queries){
        cout << tab[mp[q.r]] - tab[mp[q.l]] << endl;
    }
}
```

### Solution Explanation (chatGPT)

### Problem Statement:

- You have an array `a` of length \(10^9\), initially containing all zeroes.
- You need to perform `N` updates. Each update is of the form: Given integers `l`, `r`, and `v`, add `v` to all values \(a_l, a_{l+1}, …, a_{r-1}\).
- After the updates, you need to answer `Q` queries. Each query is of the form: Given integers `l` and `r`, print the sum \(a_l + a_{l+1} + … + a_{r-1}\).

### Solution Explanation:

1. **Type Definitions and Macros**: The solution starts by defining types and macros for convenience and debugging.
2. **Data Structures**:
    - `updates` is a vector to store all the updates.
    - `queries` is a vector to store all the queries.
    - `mp` is a map to store unique indices from the updates and queries.
3. **Input Reading**:
    - The function `fx()` reads the number of updates `n` and the number of queries `q`.
    - For each update, it reads the values `l`, `r`, and `delta` and stores them in the `updates` vector. It also updates the map `mp` with the indices `l+1` and `r+1`.
    - For each query, it reads the values `l` and `r` and stores them in the `queries` vector. It also updates the map `mp` with the indices `l` and `r`.
4. **Coordinate Compression**:
    - The solution uses a technique called coordinate compression. It assigns a unique number to each unique index in the updates and queries. This is done to reduce the size of the array we need to work with.
    - The map `mp` is used to store these compressed coordinates. `revmp` is its reverse map.
5. **Prefix Sum Technique**:
    - The solution uses the prefix sum technique to efficiently update a range in the array and answer the range sum queries.
    - For each update, it adds the value `delta` to the start index and subtracts the value `delta` from the end index. This ensures that when we calculate the prefix sum, the value `delta` gets added to all the elements in the range.
    - After processing all updates, it calculates the prefix sum of the array.
6. **Answering Queries**:
    - For each query, it calculates the sum of the range by subtracting the prefix sum at the start index from the prefix sum at the end index.

### Analysis of the Solution:

- **Good Points**:
    1. **Efficiency**: The solution uses the prefix sum technique, which allows for efficient updates and queries. This is crucial given the large constraints of the problem.
    2. **Space Optimization**: By using coordinate compression, the solution reduces the size of the array it needs to work with, which saves memory.
- **Potential Drawbacks**:
    1. **Complexity**: The use of coordinate compression and prefix sums might make the solution harder to understand for someone unfamiliar with these techniques.
    2. **Assumptions**: The solution assumes that the input will always be valid. There are no checks for edge cases or invalid input.