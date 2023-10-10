---
Question Link: https://codeforces.com/contest/1882/problem/D
Problem Set:
  - Code Forces
  - DIV2D
Last edited time: 2023-10-10T13:15
Status: "Very Interesting "
tags:
  - Bitwise
  - IDK
What's up: Couldn’t solve the whole problem.
---
### What i’ve thought of till now

```Plain
If we had only one tree, (imagine a fixed root), then we could just try to xor each root node with it child(S). until every node in the tree becomes equal. [can be done with : DFS]

But in the given problem, we have to calulate the ans with every node as root. This suggests that there must be some sort of offseting mechanism which woudl allow us to first calculate the ans for one node and then modify our ans quickly to suit a different node.
```

  
  

  

### Editorial (haven’t seen still)

> [!info] Codeforces Round 899 Div 2 | Video Solutions - A to D | by Ankit | TLE Eliminators  
> Here are the video solutions in the form of a post-contest discussion for problems A, B, C, D of Codeforces Educational Round 155 .  
> [https://www.youtube.com/watch?v=OHIx_vjBTxM&t=1742](https://www.youtube.com/watch?v=OHIx_vjBTxM&t=1742)