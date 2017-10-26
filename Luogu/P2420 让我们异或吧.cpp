#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int deep[100005], p[100005][25], fa[100005], XOR[100005];

int head[100005], edge_len;

struct Edge {
	int to;
	int next;
	int value;
} edges[200005];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x) {
	p[x][0] = fa[x];
	
	for (int i = 1; p[x][i - 1]; i++)
		p[x][i] = p[p[x][i - 1]][i - 1];
		
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (to != fa[x]) {
			XOR[to] = XOR[x] ^ edges[i].value;
			deep[to] = deep[x] + 1;
			fa[to] = x;
			dfs(to);
		}
	}
}

int LCA(int a, int b) {
	if (deep[a] > deep[b])
		swap(a, b);
		
	int f = deep[b] - deep[a];
	for (int i = 0; (1 << i) <= f; i++)
        if((1 << i) & f)
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
	
	scanf("%d", &n);
	
	int from, to, value;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &from, &to, &value);
		
		add(from, to, value);
		add(to, from, value);
	}
	
	dfs(1);
	
	scanf("%d", &m);
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &from, &to);
		
		value = LCA(from, to);
		
		printf("%d\n", (XOR[from] ^ XOR[value]) ^ (XOR[to] ^ XOR[value]));
	}
	
	return 0;
}
