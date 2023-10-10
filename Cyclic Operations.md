---
Question Link: https://codeforces.com/contest/1867/problem/D
Problem Set:
  - DIV2D
Last edited time: 2023-10-10T13:15
Status: "Very Interesting "
tags:
  - Cycle
  - Graph
  - Implementation
What's up: Couldn’t solve completely.
---
### What i’ve thought of till now

1. This seem like it could be solved by first dfs(ing) till depth k from every node not currently deemed to be in a cycle. and then for every cycle we find, we could check if it’s size is equal to k. If not we could conclude that transforming a → b is not possible.

  

- Pseudo Code (possible missing edge cases)
    
    ```C++
    //So Basically...
    
    set<int>nodes;
    for(node: all_nodes) nodes.insert(node);
    
    for(node: nodes){
    	dfs(node, depth: k);
    
    	if(found_cycle){
    		if(cycle.size() != k) no();
    		for(cnode in cycle) nodes.erase(cnode);
    
    	}
    
    }
    
    yes();
    ```