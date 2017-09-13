#include <iostream>
#include <cstdio>

using namespace std;

int dfn[1005], stack[1005], low[1005], belong[1005], col_num, dfs_num, top;

int du[1005], tot[1005];

bool vis[1005];

int head[1005];

int n, m;

struct Edge {
	int to;
	int next;
} edges[10005];

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
	
	if (dfn[x] == low[x]) {
		belong[x] = ++col_num;
		vis[x] = false;
		
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
			
	for (int i = 1; i <= n; i++) {
		tot[belong[i]]++;
		
		for (int j = head[i]; j; j = edges[j].next) {
			to = edges[j].to;
			
			if (belong[i] != belong[to]) {
				du[belong[i]]++;
			}
		}
	}
	
	int ans = 0;
	int zero_tot = 0;
	
	for (int i = 1; i <= col_num; i++)
		if (tot[i] > 1) {
			ans++;
			
			if (!du[i])
				zero_tot++;
		}
	
	cout << ans << endl;
	
	if (zero_tot != 1) {
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i <= col_num; i++)
		if (tot[i] > 1 && !du[i]) {
			for (int j = 1; j <= n; j++)
				if (belong[j] == i)
					printf("%d ", j);
					
			return 0;
		}
	
	return 0;
}
