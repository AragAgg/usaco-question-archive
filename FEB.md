---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1323
Problem Set:
  - Bronze
Last edited time: 2023-10-10T13:13
Status: Skipped for now
tags:
  - Ad-Hoc
  - Case-Work
  - Implementation
What's up: Couldn’t solve completely. To try implementation.
Key Takeaway: Could have checked for min/max ans, and then isolated the cases where the increment was (1), else it was pretty clear that the increment was (2) in the general case.
---
- [[#Problem Encountered]]
- [[#Editorial Solution]]
- [[#Editorial Code]]
- [[#chatGPT Explanation of the Code]]

### Problem Encountered

```Plain
Did the casework required.

But couldn't figure out how to merge the solution from the different subsections.
```

  

### Editorial Solution

[https://usaco.guide/problems/usaco-1323-feb/solution](https://usaco.guide/problems/usaco-1323-feb/solution)

### Editorial Code

```C++
// Source: https://usaco.guide/general/io

\#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int mn = 0, mx = 0;

	int curIdx = 0;
	while (curIdx < n) {
		if (s[curIdx] == 'F') {
			curIdx++;
			continue;
		}

		int nextIdx = curIdx + 1;
		while (nextIdx < n && s[nextIdx] == 'F') nextIdx++;
		if (nextIdx == n) break;

		int num_F = nextIdx - curIdx - 1;

		if (s[nextIdx] == s[curIdx]) {
			// Case 1: Solve something like BFFFFFB
			int length = num_F + 2;

			// First, solve for mn
			if (length % 2 == 0) {
				// At best we can have something like BEBEBB
				mn += 1;
			} else {
				// We can alternate BEBEB
				mn += 0;
			}

			// Next, solve for mx
			mx += length - 1;
		} else {
			// Case 2: Solve something like BFFFFFE
			int length = num_F + 2;

			// First, solve for mn
			if (length % 2 == 0) {
				// We can alternate BEBEBE
				mn += 0;
			} else {
				// At best we have BEBEE
				mn += 1;
			}

			// Next, solve for mx
			mx += length - 2;
		}

		curIdx = nextIdx;
	}

	// Special case: beginning / ending F's
	int num_beginning_F = 0;
	while (num_beginning_F < n && s[num_beginning_F] == 'F') num_beginning_F++;
	int num_ending_F = 0;
	while (num_ending_F < n && s[n - 1 - num_ending_F] == 'F') num_ending_F++;

	if (num_beginning_F == n) {
		// everything is an F! special case
		mn = 0;
		mx = n - 1;
	} else {
		// mn doesn't change, since we can always alternate the beginning /
		// ending properly
		mx += num_beginning_F;
		mx += num_ending_F;
	}

	vector<int> possible_levels;
	if (num_beginning_F == 0 && num_ending_F == 0) {
		// Special case: We can only change in increments of two
		assert((mx - mn) % 2 == 0);
		for (int i = mn; i <= mx; i += 2) possible_levels.push_back(i);
	} else {
		for (int i = mn; i <= mx; i++) possible_levels.push_back(i);
	}

	cout << possible_levels.size() << endl;
	for (int i : possible_levels) { cout << i << endl; }
}
```

  

### chatGPT Explanation of the Code

  

This C++ solution to the problem reads in a string that contains the letters 'B', 'E', and 'F', representing the communication between Bessie and Elsie and the obfuscation by Farmer John. The goal of the solution is to compute all possible "excitement levels" for the conversation.

  

An "excitement level" is defined as the number of times a cow sends two consecutive messages without being interrupted by the other cow. When a cow sends two consecutive messages, it's represented by either 'BB' or 'EE' in the string.

  

However, Farmer John has introduced uncertainty by replacing some of the messages with 'F'. Since 'F' could represent a message from either Bessie or Elsie, it's not immediately clear how many excitement levels are possible.

  

The solution works by iterating through the string and considering different cases.

  

Let's break it down:

1. First, the solution reads in the length of the string (`n`) and the string itself (`s`).
2. It then initializes the variables `mn` and `mx` to 0. These variables will represent the minimum and maximum possible excitement levels.
3. The solution iterates over the string from the beginning. Whenever it encounters an 'F', it simply moves on to the next character.
4. When it encounters a 'B' or an 'E', it looks ahead to find the next non-'F' character. The number of 'F's between these two characters is calculated as `num_F`.
5. The solution then distinguishes between two cases: if the two non-'F' characters are the same (either 'BB' or 'EE'), or if they are different ('BE' or 'EB'). In the first case, it's possible that all the 'F' characters in between were sent by the same cow, increasing the excitement level. In the second case, the 'F' characters could have been sent by either cow, possibly decreasing the excitement level.
6. The solution calculates the minimum and maximum possible excitement levels for the current segment of the string, based on the number of 'F's and the two non-'F' characters at the ends.
7. After handling the segment, the solution moves on to the next one, until it has processed the entire string.
8. The solution then handles the special case of 'F' characters at the beginning or end of the string separately. If the entire string is made up of 'F' characters, the minimum excitement level is 0 (if each 'F' is a message from a different cow), and the maximum excitement level is `n - 1` (if all 'F's are from the same cow).
9. The solution creates a list of all possible excitement levels between the minimum and maximum levels calculated. Depending on whether there are 'F's at the beginning or end of the string, the excitement levels can increase by either 1 or 2.
10. Finally, the solution outputs the number of possible excitement levels, followed by the levels themselves, in increasing order.