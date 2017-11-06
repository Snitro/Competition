#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int tot[1000005], head[1000005], dis[1000005], edge_len, n, m;

queue <int> que;

bool vis[1000005];

struct Edge {
	int to;
	int next;
} edges[4000005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int u, v;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		
		add(u, v);
		add(v, u);
	}
	
	memset(dis, 0x7f, sizeof(dis));
	
	que.push(1);
	vis[1] = true;
	tot[1] = 1;
	dis[1] = 0;
	
	int from, to;
	
	while (que.size()) {
		from = que.front();
		que.pop();
		
		for (int i = head[from]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (!vis[to]) {
				vis[to] = true;
				dis[to] = dis[from] + 1;
				tot[to] = tot[from];
				que.push(to);
			} else if (dis[from] + 1 == dis[to]) {
				tot[to] += tot[from];
				tot[to] %= 100003;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d\n", tot[i]);
	
	return 0;
}
