#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int du[1505];

bool vis[1505];

int head[1505], edge_len;

struct Node {
	int y;
	int n;
} nodes[1505];

struct Edge {
	int to;
	int next;
} edges[3005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x) {
	vis[x] = true;
	nodes[x].y = 1;
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (vis[to])
			continue;
			
		dfs(to);
		nodes[x].n += nodes[to].y;
		nodes[x].y += min(nodes[to].n, nodes[to].y);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	int a, b, c;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		
		du[a] = b;
		
		while (b--) {
			scanf("%d", &c);
			add(a, c);
			add(c, a);
		}
	}
	
	dfs(0);
	
	cout << min(nodes[0].n, nodes[0].y);
	
	return 0;
}
