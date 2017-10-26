#include <iostream> 
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k, e;

int f[105];

bool use[25][105], flag[25], tf[25];

int init[105][105], dist[30];

int head[30], edge_len;

struct Edge {
	int to;
	int next;
	int value;
} edges[500];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	edges[edge_len].value = value;
	head[from] = edge_len;
}

int spfa() {
	queue <int> que;
	int from, to;

	memset(dist, 0x7f, sizeof(dist));
	
	que.push(1);
	flag[1] = true;
	dist[1] = 0;
	
	while (que.size()) {
		from = que.front();
		que.pop();
		flag[from] = false;
		
		for (int i = head[from]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (dist[from] + edges[i].value < dist[to]) {
				dist[to] = dist[from] + edges[i].value;
				
				if (!flag[to]) {
					flag[to] = true;
					que.push(to);
				}
			}
		}
	}
	
	return dist[m];
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d%d", &n, &m, &k, &e);
	
	int a, b, c, d;
	
	for (int i = 1; i <= e; i++) {
		scanf("%d%d%d", &a, &b, &c);
		
		add(a, b, c);
		add(b, a, c);
	}
	
	scanf("%d", &d);
	
	for (int i = 1; i <= d; i++) {
		scanf("%d%d%d", &a, &b, &c);
		
		for (int i = b; i <= c; i++)
			use[a][i] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		memset(tf, 0, sizeof(tf));
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= m; k++)
				if (use[k][j])
					tf[k] = true;
			
			memcpy(flag, tf, sizeof(tf));
			
			init[i][j] = spfa();
		}
	}
	
	f[0] = -k;
	
	for (int i = 1; i <= n; i++) {
		f[i] = 999999999;
		
		for (int j = 0; j < i; j++)
			if (init[j + 1][i] != dist[0])
				f[i] = min(f[i], f[j] + init[j + 1][i] * (i - j) + k);
	}
	
	cout << f[n];
	
	return 0;
}
