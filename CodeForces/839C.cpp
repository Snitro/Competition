#include <iostream>
#include <cstdio>

using namespace std;

double ans = 0;

bool vis[100005];

int n, head[100005], edge_len, tot[100005];

struct Edge {
	int to;
	int next;
} edges[200005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x, double exp, long long now) {
	int to;
	bool flag = false;
	vis[x] = true;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!vis[to]) {
			flag = true;
			dfs(to, exp / ((double)tot[x] - (x == 1 ? 0 : 1)), now + 1);
		}
	}
	
	vis[x] = false;
	
	if (!flag)
		ans += now * exp;
}

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	
	int u, v;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		
		add(u, v);
		add(v, u);
		tot[u]++;
		tot[v]++;
	}
	
	dfs(1, 1.0, 0);
	
	printf("%.16f", ans);
	
	return 0;
}
