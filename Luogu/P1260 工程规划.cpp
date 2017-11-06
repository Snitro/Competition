#include <iostream> 
#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

int n, m, times[1005], dis[1005];

int head[1005], edge_len;

bool flag[1005];

struct Edge {
	int to;
	int next;
	int value;
} edges[5005];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void spfa(int x) {
	queue <int> que;
	int to;
	
	que.push(x);
	flag[x] = true;
	dis[x] = 0;
	times[x] = 1;
	
	while (que.size()) {
		x = que.front();
		que.pop();
		flag[x] = false;
		
		for (int i = head[x]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (dis[x] + edges[i].value < dis[to]) {
				dis[to] = dis[x] + edges[i].value;
				
				if (!flag[to]) {
					que.push(to);
					times[to]++;
					flag[to] = true;
					
					if (times[to] >= n + 1) {
						puts("NO SOLUTION");
						exit(0);
					}
				}
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int u, v, value;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &value);
		
		add(v, u, value);
	}
	
	for (int i = 1; i <= n; i++)
		if (!times[i])
			spfa(i);
			
	int MIN = 999999999;
	for (int i = 1; i <= n; i++)
		if (dis[i] < MIN)
			MIN = dis[i];
	
	for (int i = 1; i <= n; i++)
		printf("%d\n", dis[i] - MIN);
	return 0;
}
