---
Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=643
Problem Set:
  - Silver
Last edited time: 2023-09-04T00:16
Status: Solved
tags:
  - 2D-Prefix-Sum
  - Sorting
  - Structure
---
### What i’ve thought of till now

1. simulating k is not possible
2. lets create a vector<int> denoting each diamond.
3. sort it.
4. now create two additional vectors of same size to denote:
    1. the maximum number of elemnts if the current diamond were the first of / last of k
5. set everything to 0
6. manually set the value of end[0]
7. make two pointers, right and left
8. when we have a window with |size| ≤ k
    1. set the start of left to curr
    2. set the end of right to curr
9. when we come at a new left
    1. make sure to set it’s ending pos to best ending pos yet.
10. now use the start of current + end of last as a potential candidate for our solution
11. maximise the answer over all valid window.