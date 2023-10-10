---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=813
Problem Set:
  - Gold
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Constructive
  - Implementation
  - Optimisation
  - Sorting
  - Structure
What's up: Solved with help of editorial.
Key Takeaway: Iterative Elimination.
---
### Solution (from: Editorial)

```C++
\#include <bits/stdc++.h>
using namespace std;

struct Boot {
	int max_depth, max_steps, index;
};

int main() {
	freopen("snowboots.in", "r", stdin);

	int tile_num;
	int boot_num;
	cin >> tile_num >> boot_num;

	vector<int> tiles(tile_num);
	for (int &t : tiles) { cin >> t; }

	vector<Boot> boots(boot_num);
	for (int i = 0; i < boot_num; ++i) {
		cin >> boots[i].max_depth >> boots[i].max_steps;
		boots[i].index = i;
	}
	// sort the boots from greatest depth to least depth
	sort(boots.begin(), boots.end(), [&](const Boot &a, const Boot &b) {
		return a.max_depth > b.max_depth;
	});

	vector<int> tiles_by_depth;  // list of tile indices, sorted by snow depth
	for (int i = 1; i < tile_num - 1; i++) { tiles_by_depth.push_back(i); }
	sort(tiles_by_depth.begin(), tiles_by_depth.end(),
	     [&](int a, int b) { return tiles[a] > tiles[b]; });

	set<int> valid_tiles;
	for (int i = 0; i < tile_num; i++) { valid_tiles.insert(i); }

	// the deepest tile that can still be traversed with the boot we're at
	int tile_at = 0;
	// the min step a boot needs to be able to take to reach the barn
	int needed_step = 1;
	vector<bool> can_reach(boot_num);
	for (const Boot &b : boots) {
		/*
		 * remove all the tiles that this boot can't traverse
		 * & update tile_at & needed_step accordingly
		 */
		while (tile_at < tiles_by_depth.size() &&
		       tiles[tiles_by_depth[tile_at]] > b.max_depth) {
			auto removed = valid_tiles.find(tiles_by_depth[tile_at]);
			needed_step = max(needed_step, *next(removed) - *prev(removed));
			valid_tiles.erase(removed);
			tile_at++;
		}
		can_reach[b.index] = b.max_steps >= needed_step;
	}

	freopen("snowboots.out", "w", stdout);
	for (bool b : can_reach) { cout << b << '\n'; }
}
```

### Solution Explanation

### 1. **Struct Definition**:

```C++
struct Boot {
	int max_depth, max_steps, index;
};
```

This struct is a simple representation of a boot. The `index` is crucial because after sorting the boots based on their depth, we still need to output the results in the original order.

### 2. **Sorting the Boots**:

```C++
sort(boots.begin(), boots.end(), [&](const Boot &a, const Boot &b) {
	return a.max_depth > b.max_depth;
});
```

Sorting the boots by their maximum depth in descending order is a strategic move. By considering the boots that can handle the most snow first, we can efficiently eliminate tiles that are too deep for subsequent boots.

### 3. **Preparing Tiles by Depth**:

This step is about creating a list of tile indices (excluding the first and last tiles) and sorting them based on their snow depth. This will help us quickly identify which tiles are too deep for a given boot.

### 4. **Main Logic**:

The main logic is the heart of the solution. Let's break it down:

- **valid_tiles Set**:  
    This set keeps track of tiles that are currently valid (i.e., tiles that can be stepped on). Initially, all tiles are valid.
- **tile_at & needed_step**:  
    `tile_at` is an index that points to the current tile in `tiles_by_depth` that we're considering. `needed_step` keeps track of the minimum step size required to traverse the remaining valid tiles.
- **Removing Tiles**:  
    As we process each boot, we remove tiles from `valid_tiles` that the boot can't traverse. This is done by checking the snow depth of the tile against the boot's maximum depth.

```C++
while (tile_at < tiles_by_depth.size() &&
       tiles[tiles_by_depth[tile_at]] > b.max_depth) {
	auto removed = valid_tiles.find(tiles_by_depth[tile_at]);
	needed_step = max(needed_step, *next(removed) - *prev(removed));
	valid_tiles.erase(removed);
	tile_at++;
}
```

Here, for each tile that's too deep for the boot, we find the gap between the valid tiles before and after the removed tile. This gap represents the minimum step size required to traverse the path. If the gap is larger than the boot's maximum step size, then the boot can't traverse the path.

- **Updating can_reach**:  
    After processing the tiles for a boot, we update the `can_reach` vector to indicate whether the boot can traverse the path.

### 5. **Output**:

Finally, the code outputs the results in the original order of the boots.

### Key Takeaways:

- The solution cleverly uses sorting and set operations to efficiently process each boot.
- By considering the boots that can handle the most snow first, we can reduce the number of tiles we need to consider for subsequent boots.
- The use of a set allows us to efficiently find the gap between valid tiles, which is crucial for determining whether a boot can traverse the path.

### from an observational POV

### **1. Problem Observation:**

The problem essentially asks which boots can traverse a path with varying snow depths. Two main properties define each boot: the maximum snow depth it can handle and the maximum step size it can take.

### **2. Data Structures Used:**

- **Structs**: The use of a struct for boots helps in keeping related data together. This is a common technique when dealing with objects that have multiple attributes.
- **Vectors**: Used for storing the tiles and boots. Vectors are dynamic arrays and are useful when the size of the data is unknown beforehand.
- **Set**: The `valid_tiles` set is a key component of the solution. Sets maintain elements in a sorted order and allow for efficient insertions, deletions, and lookups. The use of a set here is strategic because it helps in quickly finding gaps between valid tiles.

### **3. Sorting as a Strategy:**

The solution sorts both the boots and tiles. Sorting is a powerful technique that can simplify many problems. By sorting:

- Boots by their maximum depth, the solution can process the most capable boots first and efficiently eliminate tiles.
- Tiles by their snow depth, the solution can quickly identify which tiles are too deep for a given boot.

### **4. Iterative Elimination:**

The main logic revolves around iteratively eliminating tiles that can't be traversed by the current boot. This is a strategic move because once a tile is eliminated for a boot, it remains eliminated for all subsequent boots (since they can handle even less snow depth).

### **5. Efficient Gap Finding with Sets:**

The solution uses the properties of sets to efficiently find the gap between valid tiles. By erasing a tile from the set and then checking the difference between its neighboring tiles, the solution can quickly determine the minimum step size required.

### **6. Output in Original Order:**

Even though the boots are processed in a different order, the solution maintains the original order for output. This is achieved by storing the original index of each boot in the struct and using a separate `can_reach` vector to store the results.

### **Techniques to Remember for Other Problems:**

- **Sorting as a Simplification Tool**: Sorting can often simplify problems and make them more manageable. It's a technique worth considering, especially when dealing with multiple objects with varying attributes.
- **Iterative Elimination**: In problems where you need to process items based on some criteria, consider iteratively eliminating items that no longer meet the criteria. This can reduce the problem size as you progress.
- **Use of Sets for Efficient Lookups and Operations**: Sets are powerful data structures that allow for efficient operations. In this solution, the set was used to quickly find gaps between valid tiles, but sets can be used in many other scenarios where you need quick lookups, insertions, or deletions.
- **Storing Original Indices**: When processing items out of order but needing to output results in the original order, consider storing the original indices of the items. This can be done using structs or separate arrays/vectors.

### More about Iterative Elimination

### **Generalizing Iterative Elimination**:

At its core, iterative elimination involves:

1. **Identifying and sorting** the elements based on some criteria.
2. **Processing elements** in a specific order.
3. **Eliminating elements** that no longer meet the criteria or are no longer relevant.
4. **Repeating** the process until a solution is found or all elements are processed.

### **Common Scenarios for Iterative Elimination**:

1. `**Selection Algorithms**`: When you need to find the kth smallest or largest element in a list, iterative elimination can be used to discard elements that can't be the answer.
2. `**Game Strategies**`: In games where players take turns and have multiple options, iterative elimination can be used to discard non-optimal moves at each step.
3. **Network Flow Algorithms**: In algorithms like the Ford-Fulkerson method for computing the maximum flow in a flow network, paths are iteratively found and eliminated until no augmenting paths remain.
4. **Linear Programming**: The Simplex method iteratively eliminates non-optimal vertices of the feasible region until the optimal solution is found.
5. `**Decision-making under Constraints**`: When you have multiple options but constraints that prevent all options from being viable, iterative elimination can be used to discard non-viable options.

### **Signs that Suggest Iterative Elimination Might be Helpful**:

1. **Ordered or Sortable Elements**: If the elements in the problem can be ordered or sorted based on some criteria, iterative elimination might be applicable.
2. `**Criteria-based Elimination**`: If there's a clear criteria that determines whether an element should be considered or discarded, iterative elimination can be used to process and discard elements.
3. **Reducible Problem Space**: If the problem space can be reduced with each iteration, making the problem simpler or more manageable, iterative elimination is a potential strategy.
4. **Multiple Possible Solutions**: If there are multiple possible solutions or paths, but only a subset of them are viable or optimal, iterative elimination can be used to discard non-viable or non-optimal solutions.
5. `**Constraints that Invalidate Options**`: If certain constraints invalidate options or paths as the problem progresses, iterative elimination can be used to discard these options.

  

### Official Editorial

![[Screenshot_2023-09-14_at_3.41.24_PM.png]]

`*Uses Linked List`

  

### Editorial (from: USACO)

> [!info] Solution - Snow Boots (USACO Gold 2018 February)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/usaco-813-snow-boots/solution](https://usaco.guide/problems/usaco-813-snow-boots/solution)