#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

int head[100005], edge_len, b_head[100005], b_edge_len;

int MIN[100005], MAX[100005], value[100005];

bool flag[100005];

struct Edge {
	int to;
	int next;
} edges[500005], b_edges[500005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void b_add(int from, int to) {
	b_edges[++b_edge_len].to = to;
	b_edges[b_edge_len].next = b_head[from];
	b_head[from] = b_edge_len;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &value[i]);
	
	int x, y, f;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &f);
		
		add(x, y);
		b_add(y, x);
		
		if (f == 2) {
			add(y, x);
			b_add(x, y);
		}
	}
	
	memset(MIN, 0x7f, sizeof(MIN));
	
	queue <int> que;
	int from, to;
	
	que.push(1);
	flag[1] = true;
	MIN[1] = value[1];
	
	while (que.size()) {
		from = que.front();
		que.pop();
		flag[from] = false;
		
		for (int i = head[from]; i; i = edges[i].next) {
			to = edges[i].to;
			if (value[to] < MIN[to]) {
				MIN[to] = value[to];
				
				if (!flag[to]) {
					flag[to] = true;
					que.push(to);
				}
			}
			
			if (MIN[from] < MIN[to]) {
				MIN[to] = MIN[from];
				
				if (!flag[to]) {
					flag[to] = true;
					que.push(to);
				}
			}
		}
	}
	
	memset(flag, 0, sizeof(flag));
	
	que.push(n);
	flag[n] = true;
	MAX[n] = value[n];
	
	while (que.size()) {
		from = que.front();
		que.pop();
		flag[from] = false;
		
		for (int i = b_head[from]; i; i = b_edges[i].next) {
			to = b_edges[i].to;
			if (value[to] > MAX[to]) {
				MAX[to] = value[to];
				
				if (!flag[to]) {
					flag[to] = true;
					que.push(to);
				}
			}
			
			if (MAX[from] > MAX[to]) {
				MAX[to] = MAX[from];
				
				if (!flag[to]) {
					flag[to] = true;
					que.push(to);
				}
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++)
		ans = max(ans, MAX[i] - MIN[i]);
	
	printf("%d", ans);
	
	return 0;
}
