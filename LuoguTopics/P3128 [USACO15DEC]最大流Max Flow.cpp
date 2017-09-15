#include <iostream>
#include <cstdio>

using namespace std;

int n, k;

int value[50005], ans = -999999999;

int p[50005][25], fa[50005], deep[50005];

int head[50005], edge_len;

struct Edge {
	int to;
	int next;
} edges[50005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void value_dfs(int x) {
	int to;
    for (int i = head[x]; i; i = edges[i].next) {
        to = edges[i].to;

        if (to != fa[x]) {
            value_dfs(to);
            value[x] += value[to];
            
            if (value[x] > ans)
            	ans = value[x];
        }
    }
}

void LCA_dfs(int x) {
	p[x][0] = fa[x];
	
	for (int i = 1; p[x][i - 1]; i++)
		p[x][i] = p[p[x][i - 1]][i - 1];
		
	int to;
		
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x]) {
			deep[to] = deep[x] + 1;
			fa[to] = x;
			LCA_dfs(to);
		}
	}
}

int lca(int a, int b) {
	if (deep[a] > deep[b])
		swap(a, b);
	
	int f = deep[b] - deep[a];
	for (int i = 0; (1 << i) <= f; i++)
		if ((1 << i) & f)
			b = p[b][i];
	
	if (a != b) {
		for (int i = 20; i >= 0; i--)
			if (p[a][i] != p[b][i]) {
				a = p[a][i];
				b = p[b][i];
			}
			
		a = p[a][0];
	}
	return a;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &k);
	
	int from, to;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &from, &to);
		
		add(from, to);
		add(to, from);
	}
	
	LCA_dfs(1);
	
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &from, &to);
		
		value[from]++;
		value[to]++;
		value[lca(from, to)]--;
		value[fa[lca(from, to)]]--;
	}
	
	value_dfs(1);
	
	cout << ans;
	
	return 0;
}
