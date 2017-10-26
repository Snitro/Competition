#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int du[100005];

int head[100005];

int dfn[100005], low[100005], stack[100005], belong[100005], dfs_num, col_num, top;

bool vis[100005];

struct Edge {
	int to;
	int next;
} edges[500005];

void add(int from, int to, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	head[from] = id;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++dfs_num;
	vis[x] = true;
	stack[++top] = x;
	
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!dfn[to]) {
			tarjan(to);
			
			if (low[to] < low[x])
				low[x] = low[to];
		} else if (vis[to] && dfn[to] < low[x])
			low[x] = dfn[to];
	}
	
	if (low[x] == dfn[x]) {
		vis[x] = false;
		belong[x] = ++col_num;
		
		while (stack[top] != x) {
			belong[stack[top]] = col_num;
			vis[stack[top--]] = false;
		}
		
		top--;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int from, to;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &from, &to);
		
		add(from, to, i);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
			
	for (int i = 1; i <= n; i++)
		for (int j = head[i]; j; j = edges[j].next) {
			to = edges[j].to;
			
			if (belong[i] != belong[to])
				du[belong[to]]++;
		}
		
	int ans = 0;
	
	for (int i = 1; i <= col_num; i++)
		if (!du[i])
			ans++;
	
	cout << ans;
	
	return 0;
}
