---
Question Link: https://codeforces.com/contest/1857/problem/G
Problem Set:
  - DIV3G
Last edited time: 2023-10-10T13:15
Status: "Very Interesting "
tags:
  - DS-Union
  - Divide-&-Conquer
  - Greedy
  - Kruskal's-MST
  - Optimisation
What's up: To try implementation
Key Takeaway: Adding an edge between two vertices with weight less than any edge_weights on the original path between the two vertices in a undirected acyclic graph changes the MST of the given graph. Also the contrapositive of the statement is true.
---
  

### Main Observations

1. The graphs will have exactly `_n_` vertices because the MST is fixed. So, the graphs will look like the given tree with some additional edges.
2. For any new edge between vertices `_u_` and `_v_`, the possible weights of this edge are in the range `[``_P_``(``_u_``,``_v_``)+1,``_S_``]`, where `_P_``(``_u_``,``_v_``)` is the maximum weight on the simple path from `_u_` to `_v_`. This is because if the edge has a weight less than or equal to `_P_``(``_u_``,``_v_``)`, the MST will change by taking the new edge instead of the edge with the maximal weight on the path.

### Main Idea for the Solution

The main idea is to calculate the product for all pairs of vertices:

$$∏_{1≤u<v≤n}(S−P(u,v)+1)$$

This is because for each pair of vertices, we can assign a new weight from the range, which gives `_S_``−``_P_``(``_u_``,``_v_``)` cases, or we can choose not to add any edge, which is one more case.

### Key Takeaways

The problem "Counting Graphs" presents a complex and interesting challenge that requires a deep understanding of graph theory, combinatorics, and efficient algorithms. Here are some key takeaways from this question:

1. **Understanding MST Constraints:** The problem emphasizes the importance of understanding the properties of Minimum Spanning Trees (MSTs) and how adding new edges with specific weights can or cannot change the MST.
2. **Combinatorial Thinking:** The solution involves counting the number of valid graphs that meet specific criteria. This requires careful combinatorial reasoning and an understanding of how to count possibilities without overcounting.
3. **Efficient Graph Algorithms:** The problem requires the use of efficient algorithms like sorting, binary exponentiation, and Disjoint Set Union (DSU) to handle the constraints of the problem within the given time limits.
4. **Path Queries in Trees:** The solution involves preprocessing the tree to answer maximum-weight queries between any two nodes efficiently. This highlights the importance of techniques like Lowest Common Ancestor (LCA) and binary lifting in handling tree-based queries.
5. **Edge Cases and Constraints:** The problem's constraints, such as no multiple edges and no self-loops, play a crucial role in shaping the solution. Understanding and handling these constraints is key to solving the problem correctly.
6. **Modular Arithmetic:** The problem requires working with large numbers and taking the result modulo a given value. This emphasizes the importance of understanding modular arithmetic in competitive programming.
7. **Problem Decomposition:** The solution involves breaking down the problem into smaller, more manageable subproblems (e.g., sorting edges, finding the maximum weight on a path, calculating the number of paths through an edge) and then combining these subproblems to form the final solution.
8. **Real-World Relevance:** While the problem itself is abstract, the concepts it touches on, such as MSTs and combinatorial counting, have real-world applications in network design, optimization, and other areas.

### Editorial

![[Screenshot_2023-08-09_at_6.44.59_PM.png]]