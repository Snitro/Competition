#include <iostream>
#include <cstdio>

using namespace std;

int n, head[100005], edge_len;

long long ans, blue;

struct Edge {
	int to;
	int next;
} edges[200005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x, int father, bool t) {
	if (t)
		blue++;
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != father)
			dfs(to, x, !t);
	}
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
	}
	
	dfs(1, 0, false);
	
	cout << (blue) * (n - blue) - (n - 1);
	
	return 0;
}
