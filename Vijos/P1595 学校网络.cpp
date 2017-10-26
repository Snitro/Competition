#include <iostream>
#include <cstdio>

using namespace std;

int n;

int dfn[105], low[105], stack[105], belong[105], top, dfs_num, col_num;

int r[105], c[105];

bool vis[105];

struct Edge {
	int to;
	int next;
};

struct Map {
	int head[105], m;
	Edge edges[10005];
	
	Map() {
		m = 0;	
	}
	void add(int from, int to) {
		edges[++m].to = to;
		edges[m].next = head[from];
		head[from] = m;
	}
} map1;

struct Map_2 {
	bool map[105][105];
	
	void add(int from, int to) {
		map[from][to] = true;
	}
} map2;

void tarjan(int x) {
	dfn[x] = low[x] = ++dfs_num;
	vis[x] = true;
	stack[++top] = x;
	
	int to;
	
	for (int i = map1.head[x]; i; i = map1.edges[i].next) {
		to = map1.edges[i].to;
		
		if (!dfn[to]) {
			tarjan(to);
			
			if (low[to] < low[x])
				low[x] = low[to];
		} else if (vis[to] && dfn[to] < low[x]) 
			low[x] = dfn[to];
	}
	
	if (dfn[x] == low[x]) {
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
//	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	int to;
	
	for (int i = 1; i <= n; i++)
		while (scanf("%d", &to)) {
			if (!to)
				break;
			map1.add(i, to);
		}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
			
	for (int i = 1; i <= n; i++)
		for (int j = map1.head[i]; j; j = map1.edges[j].next) {
			to = map1.edges[j].to;
			
			if (belong[i] != belong[to] && !map2.map[i][to]) {
				map2.add(belong[i], belong[to]);
				c[belong[i]]++;
				r[belong[to]]++;
			}
		}
	
	int tot_c = 0;
	int tot_r = 0;
	
	for (int i = 1; i <= col_num; i++) {
		if (c[i] == 0)
			tot_c++;
		if (r[i] == 0)
			tot_r++;
	}
	
	if (col_num == 1) {
		cout << 1 << endl << 0;
		return 0;
	}
	
	cout << tot_r << endl << max(tot_r, tot_c);
	
	return 0;
}
