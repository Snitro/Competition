#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int n, m, sta_m, ans;

int low[10005];

int dfn[10005];

int temp[10005];

int top[10005];

int du[10005];

int ins[10005];

int belong[10005];

int f[10005];

stack <int> st;

int cnt, bk;

struct Edge {
	int next;
	int to;
};

struct Map {
	Edge edges[100005];
	int head[10005];
	int value[10005];
	int id;
	
	void add(int from, int to) {
		id++;
		edges[id].to = to;
		edges[id].next = head[from];
		head[from] = id;
	}
} map1, map2;

void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	ins[u] = 1;
	st.push(u);
	int v;
	
	for (int i = map1.head[u]; i; i = map1.edges[i].next) {
		v = map1.edges[i].to;
		
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (ins[v])
			low[u] = min(low[u], low[v]);
	}
	
	if (dfn[u] == low[u]) {
		bk++;
		
		do {
			v = st.top();
			st.pop();
			ins[v] = 0;
			belong[v] = bk;
		} while (u != v);
	}
}

void dfs(int u, int pre) {
	dfn[u] = 0;
	f[u] = max(f[u], map2.value[u] + pre);
	ans = max(ans ,f[u]);
	int v;
	for (int i = map2.head[u]; i; i = map2.edges[i].next)
		dfs(map2.edges[i].to, f[u]);
}

int main() {
//	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &map1.value[i]);
		
	int a, b;
		
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		
		map1.add(a, b);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) {
			cnt = 0;
			tarjan(i);
		}
		
	cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		map2.value[belong[i]] += map1.value[i];
		
		for (int j = map1.head[i]; j; j = map1.edges[j].next) {
			int to = belong[map1.edges[j].to];
			
			if (belong[i] != to) {
				map2.add(belong[i], to);
				du[to]++;
			}
		}
	}
	
	for (int u = 1; u <= bk; u++)
		if (dfn[u])
			dfs(u, 0);
	
	cout << ans ;
	
	return 0;
}
