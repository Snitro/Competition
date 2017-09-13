void tarjan(int x) {
	dfn[x] = low[x] = ++dfs_num;
	vis[x] = true;
	stack[++top] = x;
	
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!dfn[to]) {
			tarjan(to);
			
			if (low[to] < low[x])
				low[x] = low[to];
		} else if (vis[to] && dfn[to] < low[x])
			low[x] = dfn[to];
	}
	
	if (dfn[x] == low[x]) {
		belong[x] = ++col_num;
		vis[x] = false;
		
		while (stack[top] != x) {
			belong[stack[top]] = col_num;
			vis[stack[top--]] = false;
		}
		
		top--;
	}
}
