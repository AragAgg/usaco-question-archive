---
Question Link: Survival of the Weakest (easy version)
Problem Set:
  - Code Forces
  - DIV2F
Last edited time: 2023-10-10T13:13
Status: Skipped for now
tags:
  - Binary-Search
  - IDK
What's up: Can’t understand how the editorial’s solution is working
Key Takeaway: If we have a function, that works on large input (running into risks of overflow) or (exponential explosion 💥 ), try to lower the input values, and the offset those changes directly to answer in const time.
---
### What I’ve thought of till now

```Plain
we can simulate (no idea where binary search comes in) [maybe in: priority_queue?]


do this N times:

use bfs to find the smallest N number pairs.

This causes overflow even when using ll, only after (n = 40), but the constraints of the problem is (n <= 3000).

The editorial manages to transform the function f(smt..) to f(smt else...) + offset.

Can't understand how the offset thing is working.
```