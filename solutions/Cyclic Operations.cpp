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
