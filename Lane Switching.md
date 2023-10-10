---
Question Link: https://open.kattis.com/problems/laneswitching
Problem Set:
  - Kattis
Last edited time: 2023-10-10T13:13
Status: Skipped for now
tags:
  - Binary-Search
  - Connected-Components
  - Implementation
What's up: Got the basic idea of graph modelling but implementation was too tough.
---
### what i’ve thought of till now

```C++
1. Its a graph problem, we could see each lane and each segment between two cars as a node and weather or not we could travel between those as an edge (with edge cost as the space btw. the two cars), this way the problem basically becomes the min cost to travel from a -> b. (solve maybe using dijkstra's)
```

### Editorial (from USACO)

> [!info] Solution - Lane Switching (ACPC 2017)  
> A free collection of curated, high-quality competitive programming resources to take you from USACO Bronze to USACO Platinum and beyond.  
> [https://usaco.guide/problems/kattis-lane-switching/solution](https://usaco.guide/problems/kattis-lane-switching/solution)