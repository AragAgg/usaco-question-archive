---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=896
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:12
Status: Solved with Help
tags:
  - Custom-Comparator
  - Interval-Scheduling
  - Sorting
What's up: Viewed the Editorial (couldn’t figure out how to check for overlap)
Key Takeaway: "1. Geometric Interpretation: The problem requires a geometric interpretation of the given data. Understanding that the mountains can be represented as triangles on the xy-plane and that their visibility can be determined by comparing their base intervals is crucial.2. Data Transformation: Instead of working directly with the given peak coordinates, the solution transforms the data into a more useful format (start and end points of the mountain base). This transformation simplifies the problem and makes it more tractable.3. Sorting for Simplification: Sorting is a powerful technique that can simplify many problems. In this case, sorting the mountains based on their start points (and widths in case of a tie) allows for a linear-time solution to determine visibility."
---
### Solution from the Editorial

```C++
\#include <bits/stdc++.h>
using namespace std;

struct Mountain {
	int start, end;
};

bool operator<(const Mountain &m1, const Mountain &m2) {
	// sort by start and tiebreak by putting the larger mountains first
	if (m1.start == m2.start) { return m1.end > m2.end; }
	return m1.start < m2.start;
}

int main() {
	std::ifstream read("mountains.in");
	int mountain_num;
	read >> mountain_num;

	vector<Mountain> mountains;
	for (int m = 0; m < mountain_num; m++) {
		int x, y;
		read >> x >> y;
		// store the mountains by the interval they cover
		mountains.push_back({x - y, x + y});
	}
	sort(mountains.begin(), mountains.end());

	int rightmost = -1;
	int visible_num = 0;
	for (const Mountain &m : mountains) {
		if (m.end > rightmost) {
			visible_num++;
			rightmost = m.end;
		}
	}

	std::ofstream("mountains.out") << visible_num << endl;
}
```

### Solution Explanation (chatGPT)

  

```C++
\#include <bits/stdc++.h>
using namespace std;
```

  

This includes the necessary libraries and sets the namespace to `std` for convenience.

  

```C++
struct Mountain {
	int start, end;
};
```

  

This defines a structure `Mountain` with two integer members: `start` and `end`. These represent the leftmost and rightmost x-coordinates where the mountain touches the x-axis.

  

```C++
bool operator<(const Mountain &m1, const Mountain &m2) {
	// sort by start and tiebreak by putting the larger mountains first
	if (m1.start == m2.start) { return m1.end > m2.end; }
	return m1.start < m2.start;
}
```

  

This is an overloaded `<` operator for the `Mountain` structure. It's used to sort the mountains. If two mountains have the same `start` value, the mountain with the larger `end` value (i.e., the wider mountain) comes first. Otherwise, mountains are sorted by their `start` value.

  

```C++
int main() {
	std::ifstream read("mountains.in");
	int mountain_num;
	read >> mountain_num;
```

  

The code reads from the input file "[mountains.in](http://mountains.in/)". It then reads the number of mountains.

  

```C++
	vector<Mountain> mountains;
	for (int m = 0; m < mountain_num; m++) {
		int x, y;
		read >> x >> y;
		// store the mountains by the interval they cover
		mountains.push_back({x - y, x + y});
	}
```

  

For each mountain, the code reads its peak's x and y coordinates. It then calculates the `start` and `end` values for the mountain (i.e., where the mountain touches the x-axis) and stores the mountain in the `mountains` vector.

  

```C++
	sort(mountains.begin(), mountains.end());
```

  

The mountains are sorted based on the overloaded `<` operator defined earlier.

  

```C++
	int rightmost = -1;
	int visible_num = 0;
	for (const Mountain &m : mountains) {
		if (m.end > rightmost) {
			visible_num++;
			rightmost = m.end;
		}
	}
```

  

The code then iterates through the sorted list of mountains. The variable `rightmost` keeps track of the rightmost x-coordinate of the last mountain that was visible. If the current mountain's `end` value is greater than `rightmost`, then this mountain is visible, and the count of visible mountains (`visible_num`) is incremented. The `rightmost` value is then updated.

  

```C++
	std::ofstream("mountains.out") << visible_num << endl;
}
```

  

Finally, the code writes the number of visible mountains to the output file "mountains.out".

  

**Why this solution works:**

1. By sorting the mountains based on their `start` value and then by their width (in case of a tie), the code ensures that it processes the mountains from left to right.
2. The `rightmost` variable ensures that if a mountain's peak is within the triangular shape of a previously processed mountain, it's not counted as visible.
3. The solution is efficient because it processes each mountain only once and uses sorting to organize the mountains for easy comparison.