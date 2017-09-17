#include <iostream>
#include <cstdio>

using namespace std;

int n, m, du[10005], to_root[10005];

int fa[10005], p[10005][25], deep[10005];

int head[10005], edge_len;

struct Edge {
	int to;
	int value;
	int next;
} edges[20005];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void DFS(int x) {
	p[x][0] = fa[x];
	
	for (int i = 1; p[x][i - 1]; i++)
		p[x][i] = p[p[x][i - 1]][i - 1];
		
	int to;
		
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x]) {
			to_root[to] = to_root[x] + edges[i].value;
			deep[to] = deep[x] + 1;
			fa[to] = x;
			DFS(to);
		}
	}
}

int LCA(int a, int b) {
	if (deep[a] > deep[b])
		swap(a, b);
		
	int f = deep[b] - deep[a];
	
	for (int i = 0; (1 << i) <= f; i++)
		if ((1 << i) & f)
			b = p[b][i];
			
	if (a != b) {
		for (int i = 25; i >= 0; i--)
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
	
	scanf("%d%d", &n, &m);
	
	int from, to, value;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &from, &to, &value);
		
		du[to]++;
		
		add(from, to, value);
		add(to, from, value);
	}
	
	int begin = -1;
	
	for (int i = 1; i <= n; i++)
		if (!du[i]) {
			begin = i;
			break;
		}
	
	DFS(begin);
	
	long long tot_count = 0, tot_time = 0;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &from, &to);
		
		if (LCA(from, to) == from) {
			tot_count++;
			tot_time += to_root[to] - to_root[from];
		}
	}
	
	cout << tot_count << endl << tot_time;
	
	return 0;
}
