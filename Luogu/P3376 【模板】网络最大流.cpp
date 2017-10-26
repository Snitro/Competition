#include <iostream>
#include <cstdio>
#include <cstring>

#define count(x) (((x) % 2) ? (x) + 1 : (x) - 1)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int n, m, s, t;

int queue[10005], que_front, que_tail;

bool vis[10005];

int time[10005];

int head[10005], edge_len;

struct Edge {
	int to;
	int next;
	int w;
} edges[200005];

void add(int from, int to, int w) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	edges[edge_len].w = w;
	head[from] = edge_len;
	
	edges[++edge_len].to = from;
	edges[edge_len].w = 0;
	edges[edge_len].next = head[to];
	head[to] = edge_len;
}

bool bfs() {
	memset(vis, 0, sizeof(vis));
	que_front = que_tail = 1;
	time[s] = 0;
	queue[que_tail++] = s;
	vis[s] = true;
	int from, to;
	
	while (que_front < que_tail) {
		from = queue[que_front++];
		
		for (int i = head[from]; i; i = edges[i].next) {
			if (edges[i].w) {
				to = edges[i].to;
				
				if (!vis[to]) {
					vis[to] = true;
					time[to] = time[from] + 1;
					queue[que_tail++] = to;
				}
			}
		}
	}
	
	return vis[t];
}

int dfs(int v, int f) {
	if (v == t)
		return f;
		
	int to, d;
	vis[v] = true;
	
	for (int i = head[v]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (time[to] == time[v] + 1 && !vis[to] && edges[i].w > 0) {
			d = dfs(to, min(f, edges[i].w));
			
			if (d > 0) {
				edges[i].w -= d;
				edges[count(i)].w += d;
				return d;
			}
		}
	}
	
	return 0;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d%d", &n, &m, &s, &t);
	
	int a, b, c;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		
		add(a, b, c);
	}
	
	int f, ans = 0;
	
	while (bfs()) {
		memset(vis, 0, sizeof(vis));
		f = dfs(s, 999999999);
		
		if (f == 0)
			break;
		
		ans += f;
	}
	
	cout << ans;
	
	return 0;
}
