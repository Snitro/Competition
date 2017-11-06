#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

bool flag[1005];

int head[1005], dis[1005], pre[1005], pre_id[1005], edge_len, n, m, ans;

struct Edge {
	int to;
	int next;
	int value;
} edges[1000005];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void _spfa(){ 
	memset(dis, 0x7f, sizeof(dis));
	memset(flag, 0, sizeof(flag));

	queue <int> que;
	int from, to;
	
	que.push(1);
	flag[1] = true;
	dis[1] = 0;
	
	while (que.size()) {
		from = que.front();
		que.pop();
		flag[from] = false;
		
		for (int i = head[from]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (dis[from] + edges[i].value < dis[to]) {
				dis[to] = dis[from] + edges[i].value;
				
				if (!flag[to]) {
					flag[to] = true;
					que.push(to);
				}
			}
		}
	}
}

void spfa() {
	memset(dis, 0x7f, sizeof(dis));
	memset(flag, 0, sizeof(flag));
	
	queue <int> que;
	int from, to;
	
	que.push(1);
	flag[1] = true;
	dis[1] = 0;
	
	while (que.size()) {
		from = que.front();
		que.pop();
		flag[from] = false;
		
		for (int i = head[from]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (dis[from] + edges[i].value < dis[to]) {
				dis[to] = dis[from] + edges[i].value;
				pre[to] = from;
				pre_id[to] = i;
				
				if (!flag[to]) {
					flag[to] = true;
					que.push(to);
				}
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int u, v, temp;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &temp);
		
		add(u, v, temp);
		add(v, u, temp);
	}
	
	spfa();
	
	ans = dis[n];
	
	for (int i = n; i != 1; i = pre[i]) {
		temp = edges[pre_id[i]].value;
		edges[pre_id[i]].value = 2000;
		
		_spfa();
		
		ans = max(ans, dis[n]);
		edges[pre_id[i]].value = temp;
	}
	
	printf("%d", ans);
	
	return 0;
}
