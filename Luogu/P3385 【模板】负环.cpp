#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;

int head[200005], edge_len;

struct Edge {
	int to;
	int value;
	int next;
} edges[400005];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

int dis[200005];

bool vis[200005], flg;

void DFS(int x) {
	if (flg)
		return;
	
	vis[x] = true;
	int to;
	
	for (int i = head[x]; i && !flg; i = edges[i].next) {
		to = edges[i].to;
		if (dis[x] + edges[i].value < dis[to])  {
			dis[to] = dis[x] + edges[i].value;
			
			if (!vis[to])
				DFS(to);
			else
				flg = true;
		}
		
	}
	vis[x] = false;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	int t;
	
	scanf("%d", &t);
	
	while (t--) {
		memset(dis, 0x7f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		memset(head, 0, sizeof(head));
		flg = false;
		edge_len = 0;
		
		scanf("%d%d", &n, &m);
		int from, to, value;
	
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &from, &to, &value);
			
			add(from, to, value);
			
			if (value >= 0)
				add(to, from, value);
		}
		
		for (int i = 1; i <= n; i++)
			DFS(i);
				
		if (flg)
			printf("YE5\n");
		else
			printf("N0\n");
	}
	
	return 0;
}
